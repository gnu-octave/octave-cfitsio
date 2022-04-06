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
## @deftypefn {} {@var{rec} = } readRecord(@var{file}, @var{recidx})
## Read the keyword record at @var{recidx}.
##
## This is the equivalent of the cfitsio fits_read_record function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{recidx} - record number.
##
## @subsubheading Outputs
## @var{rec} - full keyword record
## @end deftypefn
function ret = readRecord (file, recidx)
  ret = __cfitsio_readRecord__ (file, recidx);
endfunction

%!shared testfile
%! testfile = file_in_loadpath("demos/tst0012.fits");

%!test
%! fd = matlab.io.fits.openFile(testfile);
%! assert(!isempty(fd));
%! rec = matlab.io.fits.readRecord(fd, 1);
%! assert(length(rec), 51);
%! rec = matlab.io.fits.readRecord(fd, 2);
%! assert(length(rec), 54);
%! fail ("matlab.io.fits.readRecord(fd);");
%! matlab.io.fits.closeFile(fd);

%!error matlab.io.fits.readRecord(1);
%!error matlab.io.fits.readRecord([]);
%!error matlab.io.fits.readRecord("");

