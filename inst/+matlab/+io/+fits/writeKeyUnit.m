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
## @deftypefn {} {} writeKeyUnit(@var{file}, @var{key}, @var{unit})
## Write a key unit to the fits file.
##
## This is the equivalent of the cfitsio fits_write_key_unit function.
## @end deftypefn
function writeKeyUnit (file, key, unit)
  __cfitsio_writeKeyUnit__ (file, key, unit);
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! assert(!isempty(fd));
%! matlab.io.fits.createImg(fd,'int16',[10 20]);
%! matlab.io.fits.writeKey(fd, 'VELOCITY', 10.0, "Speed");
%! matlab.io.fits.writeKeyUnit(fd, 'VELOCITY', "m/s");
%! matlab.io.fits.closeFile(fd);
%! delete (filename);

%!error matlab.io.fits.writeKeyUnit(1);
%!error matlab.io.fits.writeKeyUnit(1, "VELOCITY");
%!error matlab.io.fits.writeKeyUnit(1, "VELOCITY", "m/s");
