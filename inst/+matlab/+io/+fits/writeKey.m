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
## @deftypefn {} {} writeKey(@var{file}, @var{key}, @var{value})
## @deftypefnx {} {} writeKey(@var{file}, @var{key}, @var{value}, @var{comment})
## @deftypefnx {} {} writeKey(@var{file}, @var{key}, @var{value}, @var{comment}, @var{decimals})
## Append or replace a key in the fits file.
##
## This is the equivalent of the cfitsio fits_write_key and fits_update_key function.
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{key} - keyword name.
##
## @var{value} - keyword value.
##
## @var{comment} - keyword comment.
##
## @var{decimals} - number of decimals.
##
## @subsubheading Outputs
## None
## @end deftypefn
function writeKey (file, key, value, varargin)
  __cfitsio_writeKey__ (file, key, value, varargin{:});
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! assert(!isempty(fd));
%! matlab.io.fits.createImg(fd,'int16',[10 20]);
%! matlab.io.fits.writeKey(fd, 'VELOCITY', 10.0, "Speed");
%! matlab.io.fits.writeKey(fd, 'VELOCITY', 10.1, "Speed1");
%! matlab.io.fits.writeKey(fd, 'VELOCITY', 11.0);
%! matlab.io.fits.writeKey(fd, 'AUTHOR', "me");
%! matlab.io.fits.closeFile(fd);
%! delete (filename);
