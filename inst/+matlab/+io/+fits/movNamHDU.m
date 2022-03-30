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
## @deftypefn {Function File} {@var{hdutype} =} movNamHDU(@var{file}, @var{hdutype}, @var{extname}, @var{extver})
## Go to HDU matching @var{hdutype}, @var{extname}, @var{extver}.
##
## Valid hdutype values are 'IMAGE_HDU', 'ASCII_TBL', 'BINARY_TBL', 'ANY_HDU'.
##
## This is the equivalent of the cfitsio fits_movnam_hdu function.
## @end deftypefn
function movNamHDU (file, hdutype, extname, extver)
  __cfitsio_movNamHDU__ (file, hdutype, extname, extver);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile);
%! assert(!isempty(fd));
%! matlab.io.fits.movNamHDU(fd, 'IMAGE_HDU', 'quality', 1);
%! assert(matlab.io.fits.getHDUnum(fd), 4);
%! assert(matlab.io.fits.getHDUtype(fd), 'IMAGE_HDU');
%! matlab.io.fits.movNamHDU(fd, 'BINARY_TBL', 'BinTest', 0);
%! assert(matlab.io.fits.getHDUnum(fd), 2);
%! assert(matlab.io.fits.getHDUtype(fd), 'BINARY_TBL');
%! matlab.io.fits.movNamHDU(fd, 'ANY_HDU', 'Unknown', 1);
%! assert(matlab.io.fits.getHDUnum(fd), 3);
%! fail ("matlab.io.fits.movNamHDU(fd, 'INVALID_HDU', '', 0);");
%! matlab.io.fits.closeFile(fd);

%!error matlab.io.fits.movNamHDU(1);
%!error matlab.io.fits.movNamHDU([]);
