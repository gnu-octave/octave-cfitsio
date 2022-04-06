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
## @deftypefn {} {@var{filename}} = fileName(@var{file})
## Return the file name of the opened fits file.
##
## The is the eqivalent of the fits_file_name function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @subsubheading Outputs
## @var{filename} - name of the fits file.
## @end deftypefn
function ret = fileName (file)
  ret = __cfitsio_fileName__ (file);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile);
%! assert(!isempty(fd));
%! assert(matlab.io.fits.fileName(fd), testfile)
%! matlab.io.fits.closeFile(fd);

%!error matlab.io.fits.fileName(1);
%!error matlab.io.fits.fileName([]);

