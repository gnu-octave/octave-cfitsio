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
## @deftypefn {} {@var{num}} = getHDUnum(@var{file})
## Return the index of the current HDU.
##
## This is the equivalent of the cfitsio fits_get_hdu_num function.
## @end deftypefn
function ret = getHDUnum (file)
  ret = __cfitsio_getHDUnum__ (file);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile);
%! assert(!isempty(fd));
%! assert(matlab.io.fits.getHDUnum(fd), 1);
%! matlab.io.fits.movAbsHDU(fd, 1);
%! assert(matlab.io.fits.getHDUnum(fd), 1);
%! matlab.io.fits.movAbsHDU(fd, 2);
%! assert(matlab.io.fits.getHDUnum(fd), 2);
%! matlab.io.fits.closeFile(fd);

%!error matlab.io.fits.getHDUnum(1);
%!error matlab.io.fits.getHDUnum([]);

