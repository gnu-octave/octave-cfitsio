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
## @deftypefn {} {} setHCompScale(@var{file}, @var{scale})
## Set scale to be used with HCOMPRESS compression.
##
## This is the equivalent of the cfitsio fits_set_hcomp_scale function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{scale} - scale value
## @subsubheading Outputs
## None
## @end deftypefn
function setHCompScale (file, scale)
  __cfitsio_setHCompScale__(file, scale);
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! matlab.io.fits.setHCompScale(fd, 1.0);
%! matlab.io.fits.createImg(fd,'int16',[10 20]);
%! matlab.io.fits.closeFile(fd);
%! delete (filename);
