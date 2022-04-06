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
## @deftypefn {} {@var{type}} = deleteHDU(@var{file})
## Delete the current HDU and go to next HDU.
##
## Returns the newly current HDU type as a string.
##
## This is the equivalent of the cfitsio fits_delete_hdu function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @subsubheading Outputs
## @var{type} - string value for type of the next HDU.
##
## @end deftypefn
function ret = deleteHDU (file)
  ret = __cfitsio_deleteHDU__(file);
endfunction

