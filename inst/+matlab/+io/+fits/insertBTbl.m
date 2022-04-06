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
## @deftypefn {} {} insertBTbl(@var{file}, @var{nrows}, @var{ttype}, @var{tform}, @var{tunit}, @var{extname}, @var{pcount})
## Insert a new bintable extension.
##
## This is the equivalent of the cfitsio fits_insert_btbl function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{nrows} - initial number of rows (normally 0)
##
## @var{ttype} - cell array of column type
##
## @var{tform} - cell array of column format
##
## @var{tunit} - cell array of column units
##
## @var{extname} - optional extension name
##
## @var{pcount} - heap size.
##
## @var{ttype}, @var{tform}, @var{tunit} are expected to be the same size.
##
## @subsubheading Outputs
## None
## @end deftypefn
function insertBTbl (file, nrows, ttype, tform, tunit, varargin)
  __cfitsio_insertBTbl__ (file, nrows, ttype, tform, tunit, varargin{:});
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! ttype = {'Col1','Col2','Col3','Col4'};
%! tform = {'A9','A4','A3','A8'};
%! tunit = {'m','s','kg','km'};
%! matlab.io.fits.insertBTbl(fd,0,ttype,tform,tunit,'table-name', 0);
%! matlab.io.fits.closeFile(fd);
%! delete (filename);

