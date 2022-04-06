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
## @deftypefn {} {} insertATbl(@var{file}, @var{rowlen}, @var{nrows}, @var{ttype}, @var{tbcol}, @var{tform})
## @deftypefnx {} {} insertATbl(@var{file}, @var{rowlen}, @var{nrows}, @var{ttype}, @var{tbcol}, @var{tform}, @var{tunit})
## @deftypefnx {} {} insertATbl(@var{file}, @var{tbltype}, @var{nrows}, @var{ttype}, @var{tbcol}, @var{tform}, @var{tunit}, @var{extname})
## Insert a new ASCII table after current HDU.
##
## This is the equivalent of the cfitsio fits_insert_atbl function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{rowlen} - row length. If set to 0, the function will calculate size based on 
## tbcol and ttype.
##
## @var{nrows} - initial number of rows (normally 0)
##
## @var{ttype} - cell array of column type
##
## @var{tbcol} - array containing the start indices for each column.
##
## @var{tform} - cell array of column format
##
## @var{tunit} - cell array of column units
##
## @var{extname} - optional extension name
##
## @subsubheading Outputs
## None
##
## @end deftypefn
function insertATbl (file, rowlen, nrows, ttype, tbcol, tform, varargin)
  __cfitsio_insertATbl__ (file, rowlen, nrows, ttype, tbcol, tform, varargin{:});
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! matlab.io.fits.createImg(fd,'double',[20 30]);
%! matlab.io.fits.createImg(fd,'double',[20 30]);
%! matlab.io.fits.movRelHDU(fd,-1);
%! ttype = {'Col1','Col2','Col3','Col4'};
%! tbcol = [1 10 14 17 ];
%! tform = {'A9','A4','A3','A8'};
%! tunit = {'m','s','kg','km'};
%! matlab.io.fits.insertATbl(fd, 0,0,ttype,tbcol,tform,tunit,'table-name');
%! matlab.io.fits.closeFile(fd);
%! delete (filename);
