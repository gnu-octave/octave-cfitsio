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
## @deftypefn {} {[@var{ttype},@var{tbcol},@var{tunit},@var{tform},@var{scale},@var{zero},@var{nulstr},@var{tdisp}]} = getAColParms(@var{file}, @var{colnum})
## Get ASCII table parameters.
##
## This is the equivalent of the cfitsio fits_get_acolparms function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{colnum} - Column to retrieve.
##
## @subsubheading Outputs
## @var{ttype},@var{tbcol},@var{tunit},@var{tform},@var{scale},@var{zero},@var{nulstr},@var{tdisp}
## column information in same format as provided by fits_get_acolparms.
## @end deftypefn
function varargout = getAColParms (file, colnum)
  [varargout{1:nargout}] = __cfitsio_getAColParms__ (file, colnum);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile, "readonly");
%! assert(!isempty(fd));
%! matlab.io.fits.movAbsHDU(fd,2);
%! [ttype,tbcol,tunit,tform,scale,zero,nulstr,tdisp] = matlab.io.fits.getAColParms(fd, 1);
%! assert (ttype, "IDENT");
%! assert (tbcol, 1);
%! assert (tform, "9A");
%! assert (scale, 1);
%! assert (zero, 0);
%! matlab.io.fits.closeFile(fd);
