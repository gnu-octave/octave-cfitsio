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
## @deftypefn {} {} deleteRecord(@var{file}, @var{keynum})
## Delete a key in the fits file.
##
## This is the equivalent of the cfitsio fits_delete_record function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{keynum} - Record number to remove.
##
## @subsubheading Outputs
## None
## @end deftypefn
function deleteRecord (file, keynum)
  __cfitsio_deleteRecord__ (file, keynum);
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! assert(!isempty(fd));
%! matlab.io.fits.createImg(fd,'int16',[10 20]);
%! matlab.io.fits.writeDate(fd);
%! matlab.io.fits.closeFile(fd);
%!
%! fd = matlab.io.fits.openFile(filename, 'readwrite');
%! # date record
%! card = matlab.io.fits.readRecord(fd,9);
%! matlab.io.fits.deleteRecord(fd,9);
%! matlab.io.fits.closeFile(fd);
%! delete (filename);
#
