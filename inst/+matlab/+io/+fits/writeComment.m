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
## @deftypefn {} {} writeComment(@var{file}, @var{comment})
## Append a comment to to the fits file.
##
## This is the equivalent of the cfitsio fits_write_comment function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{comment} - comment to append
##
## @subsubheading Outputs
## None
## @end deftypefn
function writeComment (file, comment)
  __cfitsio_writeComment__ (file, comment);
endfunction

%!test
%! filename = tempname();
%! fd = matlab.io.fits.createFile(filename);
%! assert(!isempty(fd));
%! matlab.io.fits.createImg(fd,'int16',[10 20]);
%! matlab.io.fits.writeComment(fd, 'A comment');
%! matlab.io.fits.closeFile(fd);
%! delete (filename);

%!error matlab.io.fits.writeComment(1);
%!error matlab.io.fits.writeComment(1, "comment");
%!error matlab.io.fits.writeComment([]);
%!error matlab.io.fits.writeComment("");
