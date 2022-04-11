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
## @deftypefn {} {@var{num}} = getNumHDUs(@var{file})
## Return the count of HDUs in the file.
##
## This is the equivalent of the cfitsio fits_get_num_hdus function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @subsubheading Outputs
## @var{num} - return the number of HDUs in the file.
## @subsubheading Examples
## @example
## import_fits;
## testname = file_in_loadpath("demos/tst0012.fits");
## fd = fits.openFile(testname);
## hducount = getNumHDUs(fd), 5);
## fits.closeFile(fd);
## @end example
## @end deftypefn
function ret = getNumHDUs (file)
  ret = __cfitsio_getNumHDUs__ (file);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile);
%! assert(!isempty(fd));
%! assert(matlab.io.fits.getNumHDUs(fd), 5);
%! matlab.io.fits.closeFile(fd);

%!error matlab.io.fits.getNumHDUs(1);
%!error matlab.io.fits.getNumHDUs([]);

