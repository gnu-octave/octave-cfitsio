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
## @deftypefn {} {} insertRows(@var{file}, @var{firstrow}, @var{numrows})
## Insert rows into a table.
##
## This is the equivalent of the cfitsio fits_insert_rows function.
## @end deftypefn
function insertRows (file, firstrow, numrows)
  __cfitsio_insertRows__ (file, firstrow, numrows);
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! ttype = {'Col1','Col2','Col3','Col4'};
%! tform = {'A9','A4','A3','A8'};
%! tunit = {'m','s','kg','km'};
%! matlab.io.fits.createImg(fd,'int16',[10 20]);
%! matlab.io.fits.createTbl(fd,'binary',0,ttype,tform,tunit,'table-name');
%! matlab.io.fits.closeFile(fd);
%! fd = matlab.io.fits.openFile(filename, "READWRITE");
%! matlab.io.fits.movRelHDU(fd,1);
%! matlab.io.fits.insertRows(fd, 0, 5);
%! matlab.io.fits.closeFile(fd);
%! delete (filename);
