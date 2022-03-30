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
## @deftypefn {} {[@var{ttype},@var{tunit},@var{typechar},@var{repeat},@var{scale},@var{zero},@var{nulval},@var{tdisp}]} = getBColParms(@var{file}, @var{colnum})
## Get binary table paramaters.
##
## This is the equivalent of the cfitsio  fits_get_bcolparms function.
## @end deftypefn
function varargout = getBColParms (file, colnum)
  [varargout{1:nargout}] = __cfitsio_getBColParms__ (file, colnum);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile, "readonly");
%! assert(!isempty(fd));
%! matlab.io.fits.movAbsHDU(fd,2);
%! [ttype,tunit,typechar,repeat,scale,zero,nulval,tdisp] = matlab.io.fits.getBColParms(fd, 1);
%! assert (ttype, "IDENT");
%! assert (typechar, "A");
%! assert (repeat, 9);
%! assert (scale, 1);
%! assert (zero, 0);
%! matlab.io.fits.closeFile(fd);
