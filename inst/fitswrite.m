## Copyright (C) 2022 John Donoghue <john.donoghue@ieee.org>
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
## @deftypefn {Function File} {} fitswrite(@var{data}, @var{filename})
## @deftypefnx {Function File} {} fitswrite(@var{data}, @var{filename}, @var{propertyname}, @var{propertyvalue})
## Write image data @var{data}  to FITS file @var{filename}. If the fie already exists, overwrte it.
##
## Additional properties can be set as @var{propertyname}, @var{propertyvalue} pairs.
## Known property names are:
## @table @asis
## @item WriteMode
## Set mode for writing to image as 'overwrite' (default) ot 'append' to append images.
## @end table
##
## @end deftypefn
function fitswrite (imagedata, filename, varargin)
  import_fits;

  if ! ischar(filename)
    error ("fitswrite: expected filename as a string");
  endif

  if isempty(imagedata) || !isnumeric(imagedata) || !ismatrix(imagedata)
    error ("fitswrite: expected imagedata as a numeric matrix");
  endif

  if mod(length(varargin), 2) != 0
    error ("fitswrite: expected property name, value pairs");
  endif
  if !iscellstr (varargin (1:2:length(varargin)))
    error ("fitswrite: expected property names to be strings");
  endif

  # get additional properties name/values
  
  has_add_param = true;
  try
    p = inputParser();
    p.addParameter("test", 1);
  catch
    has_add_param = false;
  end_try_catch

  p = inputParser();
  p.CaseSensitive = false;
  p.FunctionName = 'fitswrite';
  p.KeepUnmatched = false;
  is_wr_mode = @(x) (ischar(x) && (strcmpi(x, "append") || strcmpi(x, "overwrite")));
  if has_add_param
    p.addParameter('WriteMode', 'overwrite', is_wr_mode);
    p.addParameter('Compression', 'none', @ischar);
  else
    p.addParamValue('WriteMode', 'overwrite', is_wr_mode);
    p.addParamValue('Compression', 'none', @ischar);
  endif
  p.parse(varargin{:});

  # handle compression

  fd = -1;

  if isfile(filename)
    if strcmpi(p.Results.WriteMode, "overwrite")
      fd = fits.createFile(['!' filename]);
    else
      fd = fits.openFile(filename, 'READWRITE');
    endif
  else
    fd = fits.createFile(filename);
  endif

  unwind_protect
    if !strcmpi(p.Results.Compression, 'none')
      fits.setCompressionType(fd, p.Results.Compression);
    endif
    fits.createImg(fd, class(imagedata), size(imagedata));
    fits.writeDate(fd);
    fits.writeImg(fd, imagedata);

  unwind_protect_cleanup
    fits.closeFile(fd);
  end_unwind_protect

endfunction

%!test
%! testfile = tempname();
%! X =  double([1:3;4:6]);
%! fitswrite(X, testfile);
%! a = fitsinfo(testfile);
%! assert(!isempty(a))
%! assert(length(a.Contents), 1);
%!
%! assert(a.PrimaryData.DataType, 'double');
%! assert(a.PrimaryData.Size, [2 3]);
%!
%! X =  int16([1:3;4:6;7:9]);
%! fitswrite(X, testfile, 'WriteMode', 'append');
%! a = fitsinfo(testfile);
%! assert(length(a.Contents), 2);
%!
%! assert(a.Image.DataType, 'int16');
%! assert(a.Image.Size, [3 3]);
%!
%! X =  int16([1:3;4:6;7:9]);
%! fitswrite(X, testfile, 'WriteMode', 'overwrite');
%! a = fitsinfo(testfile);
%! assert(length(a.Contents), 1);
%!
%! assert(a.PrimaryData.DataType, 'int16');
%! assert(a.PrimaryData.Size, [3 3]);
%!
%! delete (testfile);

%!error fitswrite
%!error fitswrite(1)
%!error fitswrite([])
%!error fitswrite('')