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
## @deftypefn {} {} insertImg(@var{file}, @var{bitpix}, @var{naxis})
## Insert a new primary image or image extension at current HDU position.
##
## This is the equivalent of the cfitsio fits_insert_imgll function.
##
## @subsubheading Inputs
## @var{file} - file previously opened with openFile, openDiskFile
## or createFile.
##
## @var{bitpix} - type for the data as a string in either matlab or cfitsio naming.
##
## @var{naxis} - axis values for the image.
##
## @subsubheading Outputs
## None
## @end deftypefn
function insertImg (file, bitpix, naxis)
  __cfitsio_insertImg__ (file, bitpix, naxis);
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! assert(!isempty(fd));
%! matlab.io.fits.createImg(fd,'int16',[10 20]);
%! matlab.io.fits.insertImg(fd,'int16',[10 20 3]);
%! matlab.io.fits.movAbsHDU(fd,1);
%! matlab.io.fits.insertImg(fd,'int16',[20 30]);
%! matlab.io.fits.closeFile(fd);
%! delete (filename);

