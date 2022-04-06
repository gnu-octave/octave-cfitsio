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
## @deftypefn {} {@var{type} =} movAbsHDU(@var{file}, @var{hdunum})
## Goto absolute HDU index @var{hdunum}
##
## Returns the newly current HDU type as a string.
##
## This is the equivalent of the cfitsio fits_movabs_hdu function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{hdunum} - HDU number to move to.
##
## @subsubheading Outputs
## @var{type} - hdu type of the now current HDU. 
## @end deftypefn
function ret = movAbsHDU (file, hdunum)
  ret = __cfitsio_movAbsHDU__ (file, hdunum);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile);
%! assert(!isempty(fd));
%! type = matlab.io.fits.movAbsHDU(fd, 1);
%! assert(matlab.io.fits.getHDUtype(fd), type);
%! assert(matlab.io.fits.getHDUnum(fd), 1);
%! type = matlab.io.fits.movAbsHDU(fd, 2);
%! assert(matlab.io.fits.getHDUtype(fd), type);
%! assert(matlab.io.fits.getHDUnum(fd), 2);
%! type = matlab.io.fits.movAbsHDU(fd, 3);
%! assert(matlab.io.fits.getHDUtype(fd), type);
%! assert(matlab.io.fits.getHDUnum(fd), 3);
%! matlab.io.fits.closeFile(fd);

%!error matlab.io.fits.movAbsHDU(1);
%!error matlab.io.fits.movAbsHDU([]);

