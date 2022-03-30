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
## @deftypefn {} {} setTscale(@var{file}, @var{col}, @var{scale}, @var{zero})
## Reset scale and zero to be used with reading and writing table data.
##
## This is the equivalent of the cfitsio fits_set_tscale function.
## @end deftypefn
function setTscale (file, col, scale, zero)
  __cfitsio_setTscale__(file, col, scale, zero);
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! ttype = {'Col1','Col2','Col3','Col4'};
%! tform = {'A9','A4','A3','A8'};
%! tunit = {'m','s','kg','km'};
%! matlab.io.fits.createTbl(fd,'binary',0,ttype,tform,tunit,'table-name');
%! matlab.io.fits.setTscale(fd, 1, 1.0, 0.0);
%! matlab.io.fits.closeFile(fd);
%! delete (filename);
