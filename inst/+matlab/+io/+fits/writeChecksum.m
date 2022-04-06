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
## @deftypefn {} {} writeChecksum(@var{file})
## Recalculate the HDU checksum and if required, write the new value.
##
## This is the equivalent of the cfitsio fits_write_chksum function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @subsubheading Outputs
## None
## @end deftypefn
function writeChecksum (file)
  __cfitsio_writeChecksum__ (file);
endfunction
