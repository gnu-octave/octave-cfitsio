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
## @deftypefn {} {} deleteFile(@var{file})
## Force a close and delete of a fits file.
##
## This is the equivalent of the fits_delete_file function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @subsubheading Outputs
## None
## @end deftypefn
function deleteFile (file)
  __cfitsio_deleteFile__(file);
endfunction

%!shared testfile
%! testfile = file_in_loadpath("demos/tst0012.fits");

%!test
%! tmp = tempname();
%! copyfile(testfile,tmp);
%! assert(exist(tmp, "file"), 2);
%!
%! fd = matlab.io.fits.openFile(tmp);
%! matlab.io.fits.deleteFile(fd);
%! assert(exist(tmp, "file"), 0);

%!error matlab.io.fits.deleteFile();
%!error matlab.io.fits.deleteFile(1);
%!error matlab.io.fits.deleteFile("");
%!error matlab.io.fits.deleteFile([]);

