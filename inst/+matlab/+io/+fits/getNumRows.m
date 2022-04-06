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
## @deftypefn {} {@var{nrows}} = getNumRows(@var{file})
## Get number of rows.
##
## This is the equivalent of the cfitsio fits_get_numrowsll function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @subsubheading Outputs
## @var{nrows} - the number of rows in in the current table.
## @end deftypefn
function ret = getNumRows (file)
  ret = __cfitsio_getNumRows__ (file);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile, "readonly");
%! assert(!isempty(fd));
%! matlab.io.fits.movAbsHDU(fd,2);
%! rows = matlab.io.fits.getNumRows(fd);
%! assert (rows, 11);
%! matlab.io.fits.closeFile(fd);
