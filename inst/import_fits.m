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
## @deftypefn {} {} import_fits
## Import the fits functions into a fits.xxxxx variable, to emulate importing the fits namespace.
##
## @subsubheading Examples
## @example
## # import the fits functions so don't have to use the full namespace each time
## import_fits;
##
## # open the file
## fd = fits.openFile('tst0012.fits');
##
## # get number of hdus in the file
## n = fits.getNumHDUs (fd);
## # without using the import, we would have to use the long form
## # of function access
## n = matlab.io.fits.getNumHDUs (fd);
##
## # for each hdu, go to it, print out the type
## for j = 1:n
##   hdutype = fits.movAbsHDU (fd, j);
##   printf ('HDU %d:  "%s"\n', j, hdutype);
## endfor
##
## # close the file
## fits.closeFile (fd);
## @end example
##
## @end deftypefn

try
  fits = __get_fits_imports__();
catch
  # pre version 6 octave wont find the private function
  cwd = pwd;
  unwind_protect
    cd (fullfile(fileparts(mfilename ("fullpath")), "private"))
    fits = __get_fits_imports__();
  unwind_protect_cleanup
    cd (cwd);
  end_unwind_protect
end_try_catch

%!test
%! import_fits
%! assert(fits.getVersion(), fits.getConstantValue('CFITSIO_VERSION'), 1e8);
