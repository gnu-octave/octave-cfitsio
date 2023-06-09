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
## @deftypefn {} {} insertCol(@var{file}, @var{colnum}, @var{ttype}, @var{tform})
## Insert a column into a table.
##
## This is the equivalent of the cfitsio fits_insert_col function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{colnum} - Column to delete from current table.
##
## @var{ttype}, @var{tform} - column type to insert
##
## @subsubheading Outputs
## None
## @end deftypefn
function insertCol (file, colnum, ttype, tform)
  __cfitsio_insertCol__ (file, colnum, ttype, tform);
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! ttype = {'Col1','Col2','Col3','Col4'};
%! tform = {'A9','A4','A3','A8'};
%! tunit = {'m','s','kg','km'};
%! matlab.io.fits.createTbl(fd,'binary',0,ttype,tform,tunit,'table-name');
%! matlab.io.fits.insertCol(fd, 1,"ICol","9A");
%! matlab.io.fits.closeFile(fd);
%! delete (filename);

