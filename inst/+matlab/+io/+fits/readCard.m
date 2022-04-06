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
## @deftypefn {} {@var{card} = } readCard(@var{file}, @var{recname})
## Read the keyword card for name @var{recname}
## 
## This is the equivalent of the cfitsio fits_read_card function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{recname} - record name to read
##
## @subsubheading Outputs
## @var{card} - unparsed record value string
## @end deftypefn
function ret = readCard (file, recname)
  ret = __cfitsio_readCard__ (file, recname);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile);
%! assert(!isempty(fd));
%! rec = matlab.io.fits.readCard(fd, 'NAXIS');
%! assert(length(rec), 54);
%! fail ("matlab.io.fits.readCard(fd);");
%! fail ("matlab.io.fits.readCard(fd, 1);");
%! matlab.io.fits.closeFile(fd);

