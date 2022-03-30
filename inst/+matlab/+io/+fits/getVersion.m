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
## @deftypefn {} {@var{ver}} = getVersion()
## Return the version number of the cfitsio library used.
##
## This is the equivalent of the cfitsio fits_get_version function.
## @end deftypefn
function ret = getVersion ()
  ret = __cfitsio_getVersion__ ();
endfunction

%!test
%! assert(matlab.io.fits.getVersion(), matlab.io.fits.getConstantValue("CFITSIO_VERSION"), 1e-5);
