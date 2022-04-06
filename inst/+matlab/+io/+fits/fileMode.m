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
## @deftypefn {} {@var{mode}} = fileMode(@var{file})
## Return the file mode of the opened fits file.
##
## The is the eqivalent of the fits_file_mode function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @subsubheading Outputs
## @var{mode} - The mode will return as a string 'READWRITE' or 'READONLY'
## @end deftypefn
function ret = fileMode (file)
  ret = __cfitsio_fileMode__ (file);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile, "readonly");
%! assert(!isempty(fd));
%! assert(matlab.io.fits.fileMode(fd), "READONLY")
%! matlab.io.fits.closeFile(fd);

%!error matlab.io.fits.fileMode(1);
%!error matlab.io.fits.fileMode([]);

