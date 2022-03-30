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
## @deftypefn {} {ret =} setBscale ()
## @deftypefnx {} {} setBscale(@var{file}, @var{bscale}, @var{bzero})
## Reset bscale and bzero to be used with reading and writing Images.
##
## This is the equivalent of the cfitsio fits_set_bscale function.
## @end deftypefn
function setBscale (file, bscale, bzero)
  __cfitsio_setBscale__ (file, bscale, bzero);
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! data = uint16([1:3; 4:6; 7:9]);
%! matlab.io.fits.createImg(fd,class(data), size(data));
%! matlab.io.fits.setBscale(fd, 1.0, 0.0);
%! matlab.io.fits.writeImg(fd,data);
%! matlab.io.fits.closeFile(fd);
%! delete (filename);
