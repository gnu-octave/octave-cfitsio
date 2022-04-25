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
## @deftypefn {} {} writeImg(@var{file}, @var{imagedata})
## @deftypefnx {} {} writeImg(@var{file}, @var{imagedata}, @var{fpixel})
## write imagedata to a FITS file. The rows and column size must match the size of NAXIS, NAXIS etc
##
## This is the equivalent of the cfitsio fits_write_subset function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{imagedata} - Image data.
##
## @var{fpixel} - start pixel to write from.
##
## @subsubheading Outputs
## None
##
## @subsubheading Examples
## Create a fits file and write a 10x10 image in the primary and image ext:
## @example
## import_fits;
## fd = fits.createFile("myfitsfile.fits");
## data = int16(zeros(10,10));
## # primary
## fits.createImg(fd,class(data), size(data));
## fits.writeImg(fd,data);
## # image ext
## fits.createImg(fd,class(data), size(data));
## fits.writeImg(fd,data);
## # close file
## fits.closeFile(fd);
## @end example
## @end deftypefn
function writeImg (file, imagedata, varargin)
  __cfitsio_writeImg__ (file, imagedata, varargin{:});
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! data = int16(zeros(10,10));
%! assert(!isempty(fd));
%! # primary
%! matlab.io.fits.createImg(fd,class(data), size(data));
%! matlab.io.fits.writeImg(fd,data);
%! # image
%! data = int32(ones(2, 5));
%! matlab.io.fits.createImg(fd,class(data), [4 8]);
%! matlab.io.fits.writeImg(fd,data, [2 2]);
%! matlab.io.fits.closeFile(fd);
%!
%! # validate data primary
%! data = fitsread(filename);
%! assert(size(data), [10 10])
%! assert(sum(data(:)), 0);
%!
%! # validate image
%! data = fitsread(filename, "image");
%! assert(size(data), [4 8])
%! assert(sum(data(:)), 10);
%! assert(data(1, :), [0 0 0 0 0 0 0 0]);
%! assert(data(2, :), [0 1 1 1 1 1 0 0]);
%!
%! # cleanup
%! delete (filename);

