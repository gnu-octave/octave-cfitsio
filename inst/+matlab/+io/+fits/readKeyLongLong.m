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
## @deftypefn {} {[@var{value}, @var{comment}] = } readKeyLongLong(@var{file}, @var{recname})
## Read the key value @var{recname} as a long long.
##
## This is the equivalent of the cfitsio fits_read_key_lnglng function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{recname} - keyword name.
##
## @subsubheading Outputs
## @var{value} - int64 value of record.
##
## @var{comment} - comment string
## @end deftypefn
function [value, comment] = readKeyLongLong (file, recname)
  [value, comment] = __cfitsio_readKeyLongLong__ (file, recname);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile);
%! assert(!isempty(fd));
%! [val, com] = matlab.io.fits.readKeyLongLong(fd, 'NAXIS');
%! assert(class(val), 'int64');
%! assert(val, int64(2));
%! assert(!isempty(com));
%! fail ("matlab.io.fits.readKeyLongLong(fd);");
%! fail ("matlab.io.fits.readKeyLongLong(fd, 1);");
%! matlab.io.fits.closeFile(fd);
