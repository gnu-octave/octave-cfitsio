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
## @deftypefn {} {} closeFile(@var{file})
## Close the opened fits file
## 
## The is the eqivalent of the fits_close_file function.
##
## @seealso {matlab.io.fits.openFile}
## @end deftypefn
function closeFile (file)
  __cfitsio_closeFile__ (file);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile);
%! matlab.io.fits.closeFile(fd);

%!error matlab.io.fits.closeFile();
%!error matlab.io.fits.closeFile(1);
%!error matlab.io.fits.closeFile([]);
