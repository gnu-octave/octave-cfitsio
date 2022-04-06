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
## @deftypefn {} {@var{size}} = getImgSize(@var{file})
## Return size of a Image HDU.
##
## This is the equivalent of the cfitsio fits_get_img_size function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @subsubheading Outputs
## @var{size} - vector containing the image dimensions.
## @end deftypefn
function ret = getImgSize (file)
  ret = __cfitsio_getImgSize__ (file);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile);
%! assert(!isempty(fd));
%! type = matlab.io.fits.movAbsHDU(fd, 4);
%! assert(type, 'IMAGE_HDU');
%! assert (matlab.io.fits.getImgSize(fd), [31 73 5]);
%! assert(matlab.io.fits.movAbsHDU(fd, 3), "IMAGE_HDU");
%! assert (matlab.io.fits.getImgSize(fd), [41 17 1 1 1 1 1 1 1 1 1 1 2]);
%! matlab.io.fits.closeFile(fd);

%!error matlab.io.fits.getImgSize();
%!error matlab.io.fits.getImgSize(1);
%!error matlab.io.fits.getImgSize("");
%!error matlab.io.fits.getImgSize([]);

