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
## @deftypefn {} {} isCompressedImg(@var{file})
## Return true if image is compressed.
##
## This is the equivalent of the cfitsio fits_is_compressed_image function.
## @end deftypefn
function ret = isCompressedImg (file)
  ret = __cfitsio_isCompressedImg__ (file);
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! assert(!isempty(fd));
%! matlab.io.fits.setCompressionType(fd, "RICE");
%! matlab.io.fits.createImg(fd,'int16',[256 512]);
%! assert(matlab.io.fits.isCompressedImg(fd), true);
%! matlab.io.fits.closeFile(fd);
%!
%! fd = matlab.io.fits.createFile(['!' filename]);
%! matlab.io.fits.createImg(fd,'int16',[256 512]);
%! assert(matlab.io.fits.isCompressedImg(fd), false);
%! matlab.io.fits.closeFile(fd);
%!
%! delete (filename);
