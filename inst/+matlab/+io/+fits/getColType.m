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
## @deftypefn {} {[@var{dtype},@var{repeat},@var{width}]} = getColType(@var{file}, @var{colnum})
## Get column type.
##
## This is the equivalent of the cfitsio  fits_get_coltypell function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{colnum} - Column to delete from current table.
##
## @subsubheading Outputs
## @var{dtype},@var{repeat},@var{width} - column information.
## @end deftypefn
function [dtype, repeat, width] = getColType (file, colnum)
  [dtype, repeat, width] = __cfitsio_getColType__ (file, colnum);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile);
%! matlab.io.fits.movAbsHDU(fd,2);
%! [dtype,repeat,width] = matlab.io.fits.getColType(fd,5);
%! matlab.io.fits.closeFile(fd);
