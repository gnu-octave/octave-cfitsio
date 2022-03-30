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
## @deftypefn {} {@var{value}} = getConstantValue(@var{name})
## Return the value of a known fits constant.
## @seealso {getConstantNames}
## @end deftypefn
function ret = getConstantValue (name)
  ret = __cfitsio_getConstantValue__ (name);
endfunction

%!test
%! assert(matlab.io.fits.getVersion(), matlab.io.fits.getConstantValue("CFITSIO_VERSION"), 1e-07);
%! assert(matlab.io.fits.getConstantValue("IMAGE_HDU"), 0);
%! assert(matlab.io.fits.getConstantValue("ASCII_TBL"), 1);
%! assert(matlab.io.fits.getConstantValue("BINARY_TBL"), 2);
%! assert(matlab.io.fits.getConstantValue("ANY_HDU"), -1);

%!error <Couldnt find constant> matlab.io.fits.getConstantValue("UnkownVarName");
%!error <constant name should be a string> matlab.io.fits.getConstantValue(1);

