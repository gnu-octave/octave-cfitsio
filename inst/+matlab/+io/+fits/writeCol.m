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
## @deftypefn {} {} writeCol(@var{file}, @var{colnum}, @var{firstrow}, @var{data})
## Write elements to a table.
##
## This is the equivalent of the cfitsio fits_write_col function.
## @end deftypefn
function writeCol (file, colnum, firstrow, data)
  __cfitsio_writeCol__ (file, colnum, firstrow, data);
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! ttype = {'Col1','Col2','Col3','Col4'};
%! tform = {'3A','3B','1D','1PD'};
%! tunit = {'m/s','kg/m^3','candela','parsec'};
%! matlab.io.fits.createTbl(fd,'binary',0,ttype,tform,tunit,'my-table');
%! matlab.io.fits.writeCol(fd,1,1,['dog'; 'cat']);
%! matlab.io.fits.writeCol(fd,2,1,[0 1 2; 3 4 5; 6 7 8; 9 10 11]);
%! matlab.io.fits.writeCol(fd,3,1,[1; 2; 3; 4]);
%! matlab.io.fits.writeCol(fd,4,1,{1;[1 2];[1 2 3];[1 2 3 4]});
%! matlab.io.fits.closeFile(fd);
%! delete (filename);
