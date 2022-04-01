## Copyright (C) 2020-2022 John Donoghue <john.donoghue@ieee.org>
##
## This program is free software; you can redistribute it and/or modify it under
## the terms of the GNU General Public License as published by the Free Software
## Foundation; either version 3 of the License, or (at your option) any later
## version.
##
## This program is distributed in the hope that it will be useful, but WITHOUT
## ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
## FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
## details.
##
## You should have received a copy of the GNU General Public License along with
## this program; if not, see <http://www.gnu.org/licenses/>.

## -*- texinfo -*-
## @deftypefn {} {@var{data}} = fitsread(@var{filename})
## @deftypefnx {} {@var{data}} = fitsread(@var{filename}, 'raw')
## @deftypefnx {} {@var{data}} = fitsread(@var{filename}, @var{extname})
## @deftypefnx {} {@var{data}} = fitsread(@var{filename}, @var{extname}, @var{index})
## @deftypefnx {} {@var{data}} = fitsread(@var{filename}, ____, @var{propertyname}, @var{propertyvalue})
## Read the primary data, or specifed extenstion data. It scales the data and applied Nan to any undefined values.
##
## @var{exttype} can be  'primary', 'asciitable', 'binarytable', 'image', 'unknown'.
##
## @var{index} can be used to specify which table when more than one of a given type exists.
##
## If the 'raw' keyword is used, the raw data from the file will be used without replacing undefined values with Nan
##
## Known property names are:
## @table @asis
## @end table
##
## @end deftypefn
function out = fitsread (filename, varargin)
  import_fits;

  if nargin < 1 || !ischar(filename) || isempty(filename)
    error ("fitsread: expected input filename");
  endif

  extname = "primary";
  format = "std";
  typeindex = 1;
  propstart = 1;
  tablecols = [];
  tablerows = [];

  # process varargs
  if nargin > 1 && ischar(varargin{1})
    propstart = 1;

    # either ext name (string), 'raw' or start of properties
    if strcmp(varargin{1}, "raw")
      propstart = 2;
      format = "raw";
    elseif !isempty(find((strcmp(varargin{1}, { "primary", "asciitable", "binarytable", "image", "unknown"})) != 0))
      propstart = 2;
      extname = varargin{1};

      # optional index here
      if nargin > 2 && isnumeric(varargin{2})
        typeindex = varargin{2};
        propstart = 3;
      endif
    else
    endif
  endif

  # properties
  propargs = varargin(propstart:end);
  if !isempty(propargs)
    if mod(length(propargs), 2) != 0
      error ("fitsread: expected property name, value pairs");
    endif
    if !iscellstr (varargin (1:2:length(propargs)))
      error ("fitsread: expected property names to be strings");
    endif

    # TODO: actually do something with the properties
    for idx = 1:2:length(propargs)
      prop = propargs{idx};
      val = propargs{idx+1};
      switch(prop)
        case "Info"
          # input fitsinfo data struct
        case "PixelRegion"
          # pixel region
        case "TableColumns"
          if !isnumeric(val) || !isvector(val)
            error ("Expected tablecolumns as a vector");
          endif
          tablecols = val;
          if size(tablecols, 1) > 1
            tablecols = tablecols';
          endif
          if size(tablecols, 1) > 1
            error ("Expected tablecols as a 1d array");
          endif
 
        case "TableRows"
          if !isnumeric(val) || !isvector(val)
            error ("Expected tablerows as a vector");
          endif
          tablerows = val;
          if size(tablerows, 2) > 1
            tablerows = tablerows';
          endif
          if size(tablerows, 2) > 1
            error ("Expected tablerows as a 1d array");
          endif
        otherwise
          warning("Unknown property '%s' ignored", prop);
      endswitch
    endfor
  endif

  fd = fits.openFile(filename);
  unwind_protect

    hdu = -1;
    if strcmp(extname, "primary")
      type = fits.movAbsHDU(fd, 1);
      hdu = 1;
    else
      # find the hdu to use
      N = fits.getNumHDUs(fd);
      for n = 2:N
        type = fits.movAbsHDU(fd, n);
        if strcmp(type, "BINARY_TBL") && strcmp(extname, "binarytable")
          if typeindex > 1
            typeindex = typeindex - 1;
          else
            hdu = n;
	    break;
          endif
	elseif strcmp(type, "ASCII_TBL") && strcmp(extname, "asciitable")
          if typeindex > 1
            typeindex = typeindex - 1;
          else
            hdu = n;
	    break;
          endif
	elseif strcmp(type, "IMAGE_HDU")
          exttype = fits.readKey(fd, "XTENSION");
          if !isempty(exttype) && !strcmp(exttype, "IMAGE")
            type = "UNKNOWN";
	  endif

  	  if strcmp(type, "IMAGE_HDU") && strcmp(extname, "image")
            if typeindex > 1
              typeindex = typeindex - 1;
            else
              hdu = n;
	      break;
            endif
	  elseif strcmp(type, "UNKNOWN") && strcmp(extname, "unknown")
            if typeindex > 1
              typeindex = typeindex - 1;
            else
              hdu = n;
	      break;
            endif
          endif
        endif
      endfor
    endif

    # we find the hdu ?
    if hdu == -1
      error ("Didnt find match hdu for %s", extname);
    endif

    out = [];

    if strcmp(type, "ASCII_TBL")
      ncols = fits.getNumCols(fd);
      out = {};

      if isempty(tablecols)
        tablecols = 1:ncols;
      endif
      for idx = 1:length(tablecols)
        if !isempty(tablerows)
          [x,n] = fits.readCol(fd, tablecols(idx), min(tablerows), max(tablerows));
        else
          [x,n] = fits.readCol(fd, tablecols(idx));
        endif

        if iscell(x)
          # if returned a cell was variable length and no nulls
          # to add ?
          tmp = x;
 
          if !isempty(tablerows)
            tmp = tmp{tablerows(:), :};
          endif
        elseif ischar(x)
          #tmp = {};
          #for i=1:length(x)
          #  if n(i) == 1
          #    tmp{end+1} = NaN;
          #  else
          #    tmp{end+1} = x(i:size(x,1):end);
          #  endif
          #endfor
          #tmp = tmp';

          tmp = x;
          if ! strcmp(format, "raw")
            tmp(find(n==1)) = "\0";
          endif
          if !isempty(tablerows)
            tmp = tmp(tablerows(:), :);
          endif
 
        else
          if ! strcmp(format, "raw")
            tmp = double(x);
            tmp(find(n==1)) = NaN;
          else
            tmp = x;
          endif

          if !isempty(tablerows)
            tmp = tmp(tablerows(:), :);
          endif
        endif

        out{end+1} = tmp;
      endfor
    elseif strcmp(type, "BINARY_TBL")
      ncols = fits.getNumCols(fd);
      out = {};
      if isempty(tablecols)
        tablecols = 1:ncols;
      endif
      for idx = 1:length(tablecols)
        if !isempty(tablerows)
          [x,n] = fits.readCol(fd, tablecols(idx), min(tablerows), max(tablerows));
        else
          [x,n] = fits.readCol(fd, tablecols(idx));
        endif

        if iscell(x)
          # if returned a cell was variable length and no nulls
          # to add ?
          tmp = x;
 
          if !isempty(tablerows)
            tmp = tmp{tablerows(:), :};
          endif
        elseif ischar(x)
          #tmp = {};
          #for i=1:length(x)
          #  if n(i) == 1
          #    tmp{end+1} = NaN;
          #  else
          #    tmp{end+1} = x(i:size(x,1):end);
          #  endif
          #endfor
          #tmp = tmp';
          tmp = x;
          if ! strcmp(format, "raw")
            tmp(find(n==1)) = "\0";
          endif
          if !isempty(tablerows)
            tmp = tmp(tablerows(:), :);
          endif
        else
          if ! strcmp(format, "raw")
            tmp = double(x);
            tmp(find(n==1)) = NaN;
          else
            tmp = x;
          endif
          if !isempty(tablerows)
            tmp = tmp(tablerows(:), :);
          endif
        endif

        out{end+1} = tmp;
      endfor

    elseif strcmp(type, "IMAGE_HDU")
      # image data
      imgsize = fits.getImgSize(fd);
      if isempty(imgsize)
        error ("No data in this HDU");
      endif
      out = fits.readImg(fd);
    endif

  unwind_protect_cleanup
    fits.closeFile(fd);
  end_unwind_protect
endfunction

%!shared testfile
%! testfile = file_in_loadpath("demos/tst0012.fits");

%!test
%! a = fitsread(testfile);
%! assert(!isempty(a))
%! assert(size(a), [109 102]);

%!test
%! a = fitsread(testfile, "raw");
%! assert(!isempty(a))
%! assert(size(a), [109 102]);

%!test
%! a = fitsread(testfile, "primary");
%! assert(!isempty(a))
%! assert(size(a), [109 102]);

%!test
%! a = fitsread(testfile, "primary", 1);
%! assert(!isempty(a))
%! assert(size(a), [109 102]);

%!test
%! a = fitsread(testfile, "image");
%! assert(!isempty(a))
%! assert(size(a), [31 73 5]);

%!test
%! a = fitsread(testfile, "image", 1);
%! assert(!isempty(a))
%! assert(size(a), [31 73 5]);

%!test
%! a = fitsread(testfile, "binarytable");
%! assert(!isempty(a))
%! assert(size(a), [1 13]);
%! assert(size(a{1}), [11, 9]);

%!test
%! a = fitsread(testfile, "binarytable", "TableColumns", [1 2 11]);
%! assert(!isempty(a))
%! assert(size(a), [1 3]);
%! assert(size(a{1}), [11, 9]);

%!test
%! a = fitsread(testfile, "binarytable", "TableRows", [1 2 6]);
%! assert(!isempty(a))
%! assert(size(a), [1 13]);
%! assert(size(a{1}), [3, 9]);

%!test
%! a = fitsread(testfile, "asciitable");
%! assert(!isempty(a))
%! assert(size(a), [1 8]);
%! assert(size(a{1}), [53, 9]);
%! assert(size(a{2}), [53, 1]);

%!test
%! a = fitsread(testfile, "asciitable", "TableColumns", [1 2 6]);
%! assert(!isempty(a))
%! assert(size(a), [1 3]);
%! assert(size(a{1}), [53, 9]);

%!test
%! a = fitsread(testfile, "asciitable", "TableRows", [1 2 6]);
%! assert(!isempty(a))
%! assert(size(a), [1 8]);
%! assert(size(a{1}), [3, 9]);

%!error fitsread
%!error fitsread(1)
%!error fitsread([])
