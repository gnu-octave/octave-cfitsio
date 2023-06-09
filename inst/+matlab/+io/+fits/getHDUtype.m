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
## @deftypefn {} {@var{type}} = getHDUtype(@var{file})
## Return the current HDUs type as a string.
##
## This is the equivalent of the cfitsio fits_get_hdu_type function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @subsubheading Outputs
## @var{type} - current hdu type
## @end deftypefn
function ret = getHDUtype (file)
  ret = __cfitsio_getHDUtype__ (file);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile);
%! assert(!isempty(fd));
%! assert(matlab.io.fits.getHDUtype(fd), "IMAGE_HDU");
%! type = matlab.io.fits.movAbsHDU(fd, 2);
%! assert(matlab.io.fits.getHDUtype(fd), type);
%! matlab.io.fits.closeFile(fd);

%!error matlab.io.fits.getHDUtype(1);
%!error matlab.io.fits.getHDUtype([]);

