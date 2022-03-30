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
## @deftypefn {} {} setCompressionType(@var{file}, @var{comptype})
## Set compression type for writing FITS images.
##
## Valid comptype values are: 'GZIP', 'GZIP2', 'RICE', 'PLIO', 'HCOMPRESS' or 'NOCOMPRESS'.
##
## This is the equivalent of the cfitsio fits_set_compression_type function.
## @end deftypefn
function setCompressionType (file, comptype)
  __cfitsio_setCompressionType__ (file, comptype);
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! assert(!isempty(fd));
%! matlab.io.fits.setCompressionType(fd, "NOCOMPRESS");
%! matlab.io.fits.createImg(fd,'int16',[10 20]);
%! matlab.io.fits.closeFile(fd);
%! delete (filename);
