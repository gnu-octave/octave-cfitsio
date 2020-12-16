## Copyright (C) 2020 John Donoghue <john.donoghue@ieee.org>
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
## @deftypefn {Function File} {[@var{info}]} = fitsdisp(@var{filename})
## @deftypefnx {Function File} {[@var{info}]} = fitsdisp(@var{filename}, @var{propertyname}, @var{propertyvalue})
## Display information about fits format file
##
## Known propertie names are:
## @table @asis
## @item 'Index'
## Value is a scalar or vector of hdu numbers to display
## @item 'Mode'
## display mode of 'standard' (default), 'min' or 'full'
## @end table
##
## 'standard' display mode shows the standard keywords for the selected HDUs.@*
## 'min' display mode shows only the type and size of the selected HDUs.@*
## 'full' display shows all keywords for the selected HDU.
## @end deftypefn
function out = fitsdisp (filename, varargin)
  import_fits;

  output = "";

  if nargin < 1
    error ("expected input filename");
  end

  # get the options if any
  hduindex = [];
  mode = 'standard';
  keywords = [];

  for i=1:2:length(varargin)
    name = tolower(varargin{i});
    value = varargin{i+1};
    switch (name)
      case "index"
       if !isnumeric(value)
         error ("Expected index to be numeric");
       endif
       if ismatrix(value)
         hduindex = value;
       elseif isscalar(value)
         hdrindex = [value];
       else
         error("Expected matrix or scalar");
       endif
      case "mode"
        mode = value;
        if !strcmp(mode, 'min') && !strcmp(mode, 'standard') && !strcmp(mode, 'full')
          error ("Expected mode to be min, standard or full");
        endif
      otherwise
        error ("Unknown property name");
    endswitch
  endfor

  # in standard mode, select keywords that will display
  if strcmp(mode, 'standard')
    # the fits standard keywords
    keywords = { ...
      '        ', 'CROTA',  'EQUINOX', 'NAXIS',    'TBCOL',   'TUNIT', ...
      'AUTHOR', 'CRPIX',   'EXTEND',   'OBJECT',  'TDIM',  'TZERO', ...
      'BITPIX'  'CRVAL'    'EXTLEVEL', 'OBSERVER','TDISP', 'XTENSION', ...
      'BLANK',  'CTYPE',   'EXTNAME',  'ORIGIN',  'TELESCOP', ...
      'BLOCKED','DATAMAX', 'EXTVER',   'PCOUNT',  'TFIELDS', ...
      'BSCALE', 'DATAMIN', 'GCOUNT',   'PSCAL',   'TFORM', ...
      'BUNIT',  'DATE',    'GROUPS',   'PTYPE',   'THEAP', ...
      'BZERO',  'DATE-OBS','HISTORY',  'PZERO',   'TNULL', ...
      'CDELT',  'END',     'INSTRUME', 'REFERENC','TSCAL', ...
      'COMMENT','EPOCH',   'NAXIS',    'SIMPLE',   'TTYPE' ...
    };
  endif

  fd = fits.openFile(filename);
  unwind_protect

    N = fits.getNumHDUs(fd);

    if isempty(hduindex)
      hduindex = 1:N;
    endif

    for n = 1:N
      type = fits.movAbsHDU(fd, n);

      # do we need to display this one ?
      if !isempty(find(n == hduindex))
        if strcmp(mode, 'min')
          if strcmp(type, "IMAGE_HDU")
            dtype = fits.getImgType(fd);
            dims = fits.getImgSize(fd);
            if isempty(dims)
              dims = '[ ]';
            else
              dims = ['[ ' sprintf("%d ",dims) ']'];
            endif
            output = [output sprintf("HDU %2d: %s %s %s\n", n, dtype, type, dims)];
          else
            rows = fits.getNumRows(fd);
            cols = fits_getNumCols(fd);
            output = [output sprintf("HDU %2d: %s [ %d %d ]\n", n, type, rows, cols)];
          endif
        elseif strcmp(mode, 'standard') || strcmp(mode, 'full')
          if n == 1
            output = [output sprintf("HDU %4d: (Primary HDU)\n", n)];
          else
            output = [output sprintf("HDU %4d:\n", n)];
          endif

          [nkeys, nspace] = fits.getHdrSpace(fd);
          for i=1:nkeys
            # record is 80 char test field
            rec = fits.readRecord(fd, i);
            % keyword is first 8
            if length(rec) > 8
              kw = rec(1:8);
            else
              kw = rec;
            endif          

            if !strcmp(kw, '        ')
              kw = strtrim(kw);
            endif

            if !isempty(keywords)
              idx = find (cellfun(@(x) strncmp (x,  kw, length (x)), keywords), 1);
            else
              # show all
              idx = 1;
            endif

            if !isempty(idx)
              output = [output sprintf("         %s\n", rec)];
            endif
          endfor
        endif
      endif
    endfor

    if nargout > 0
      out = output;
    else
      printf("%s", output);
    endif
  unwind_protect_cleanup
    fits.closeFile(fd);
  end_unwind_protect
endfunction
