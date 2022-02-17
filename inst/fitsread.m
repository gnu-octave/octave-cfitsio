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
## @deftypefn {Function File} {@var{data}} = fitsread(@var{filename})
## @deftypefnx {Function File} {@var{info}} = fitsread(@var{filename}, @var{extname})
## @deftypefnx {Function File} {@var{info}} = fitsread(@var{filename}, @var{extname}, @var{index})
## @deftypefnx {Function File} {@var{info}} = fitsread(@var{filename}, @var{propertyname}, @var{propertyvalue})
## Read the primary data, or specifed extenstion data. It scales the data and applied Nan to any undefined values.
##
## @var{exttype} can be  'primary', 'asciitable', 'binarytable', 'image', 'unknown'.
##
## @var{index} can be used to specify which table when more than one of a given type exists.
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

  if nargin < 2
    extname = "primary";
  else
    extname = varargin{1};
  endif
  typeindex = 1;

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
      ncols = fits_getNumCols(fd);
      out = {};
      for idx = 1:ncols
        [x,n] = fits_readCol(fd, idx);
        # TODO: need scale ?

        if ischar(x)
          tmp = {};
          for i=1:length(x)
            if n(i) == 1
              tmp{end+1} = NaN;
            else
              tmp{end+1} = x(i:size(x,1):end);
            endif
          endfor
          tmp = tmp';
        else
          tmp = double(x);
          tmp(find(n==1)) = NaN;
        endif

        out{end+1} = tmp;
      endfor
    elseif strcmp(type, "BINARY_TBL")
      ncols = fits_getNumCols(fd)
      out = {};
      for idx = 1:ncols
        idx
        # error reading col 10 - coz PI(144)
        [x,n] = fits_readCol(fd, idx);
        # TODO: need scale ?

        if ischar(x)
          tmp = {};
          for i=1:length(x)
            if n(i) == 1
              tmp{end+1} = NaN;
            else
              tmp{end+1} = x(i:size(x,1):end);
            endif
          endfor
          tmp = tmp';
        else
          tmp = double(x);
          tmp(find(n==1)) = NaN;
        endif

        out{end+1} = tmp;
      endfor
 
    elseif strcmp(type, "IMAGE_HDU")
      # image data
     imgsize = fits_getImgSize(fd);
     if isempty(imgsize)
       error ("No data in this HDU");
     endif
     out = fits_readImg(fd);
    endif

  unwind_protect_cleanup
    fits.closeFile(fd);
  end_unwind_protect
endfunction

%!shared testfile
%! testfile = urlwrite ( ...
%!   'https://fits.gsfc.nasa.gov/nrao_data/tests/pg93/tst0012.fits', ...
%!   tempname() );

%!test
%! a = fitsread(testfile);
%! assert(!isempty(a))
%! assert(size(a), [109 102]);

%!test
%! a = fitsread(testfile, "primary");
%! assert(!isempty(a))
%! assert(size(a), [109 102]);

%!test
%! a = fitsread(testfile, "image");
%! assert(!isempty(a))
%! assert(size(a), [31 73 5]);

%!test
%! if exist (testfile, 'file')
%!   delete (testfile);
%! endif

%!error fitsread
%!error fitsread(1)
%!error fitsread([])
