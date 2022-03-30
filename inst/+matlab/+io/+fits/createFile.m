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
## @deftypefn {} {@var{file}} = createFile(@var{filename})
## Attempt to create  a file of the given input name.
##
## If the filename starts with ! and the file exists, it will create a new file, otherwise, if the
## file exists, the create will fail.
##
## This is the equivilent of the cfitsio fits_create_file funtion.
## @seealso {openFile}
## @end deftypefn
function ret = createFile (filename)
  ret = __cfitsio_createFile__ (filename);
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! data = int16(zeros(10,10));
%! matlab.io.fits.createImg(fd,class(data), size(data));
%! matlab.io.fits.writeImg(fd,data);
%! matlab.io.fits.closeFile(fd);
%! fail("matlab.io.fits.createFile(filename)");
%! fd = matlab.io.fits.createFile(["!" filename]);
%! matlab.io.fits.createImg(fd,class(data), size(data));
%! matlab.io.fits.writeImg(fd,data);
%! matlab.io.fits.closeFile(fd);
%! delete(filename);

