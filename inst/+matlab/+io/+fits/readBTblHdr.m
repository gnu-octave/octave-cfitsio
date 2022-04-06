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
## @deftypefn {} {[@var{nrows},@var{ttype},@var{tform},@var{tunit},@var{extname},@var{pcount}]} = readBTblHdr(@var{file})
## Get Binary table parameters.
##
## This is the equivalent of the cfitsio  fits_read_btablhdrll function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @subsubheading Outputs
## @var{nrows},@var{ttype},@var{tform},@var{tunit},@var{extname},@var{pcount}] - table properties
## @end deftypefn
function varargout = readBTblHdr (file)
  [varargout{1:nargout}] = __cfitsio_readBTblHdr__ (file);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile, "readonly");
%! assert(!isempty(fd));
%! matlab.io.fits.movAbsHDU(fd,2);
%! [nrows,ttype,tform,tunit,extname,pcount] = matlab.io.fits.readBTblHdr(fd);
%! assert (nrows, 11);
%! assert (pcount, 2731);
%! assert (extname, "BinTest");
%! matlab.io.fits.closeFile(fd);
