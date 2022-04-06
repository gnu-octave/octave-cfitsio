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
## @deftypefn {} {[@var{rowlen},@var{nrows},@var{ttype},@var{tbcol},@var{tform},@var{tunit},@var{extname}]} = readATblHdr(@var{file})
## Get ASCII table parameters.
##
## This is the equivalent of the cfitsio  fits_read_atablhdrll function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @subsubheading Outputs
## @var{rowlen},@var{nrows},@var{ttype},@var{tbcol},@var{tform},@var{tunit},@var{extname} - table properties
## @end deftypefn
function varargout = readATblHdr (file)
  [varargout{1:nargout}] = __cfitsio_readATblHdr__ (file);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile, "readonly");
%! assert(!isempty(fd));
%! matlab.io.fits.movAbsHDU(fd,5);
%! [rowlen,nrows,ttype,tbcol,form,tunit,extname] = matlab.io.fits.readATblHdr(fd);
%! assert (rowlen, 59);
%! assert (nrows, 53);
%! assert (extname, "Asciitable");
%! matlab.io.fits.closeFile(fd);
