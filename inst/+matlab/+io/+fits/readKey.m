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
## @deftypefn {} {[@var{keyvalue}, @var{keycomment}] = } readKey(@var{file}, @var{recname})
## Read the keyword value and comment for name @var{recname}.
##
## This is the equivalent of the cfitsio fits_read_key_str function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{recname} - keyword name.
##
## @subsubheading Outputs
## @var{keyvalue} - string value of record.
##
## @var{keycomment} - comment string
## @end deftypefn
function [keyvalue, keycomment] = readKey (file, recname)
  [keyvalue, keycomment] = __cfitsio_readKey__ (file, recname);
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile);
%! assert(!isempty(fd));
%! [val, com] = matlab.io.fits.readKey(fd, 'NAXIS');
%! assert(val, "2");
%! assert(!isempty(com));
%! fail ("matlab.io.fits.readKey(fd);");
%! fail ("matlab.io.fits.readKey(fd, 1);");
%! matlab.io.fits.closeFile(fd);

%!error matlab.io.fits.readKey(1);
%!error matlab.io.fits.readKey(1, "NAXIS");
%!error matlab.io.fits.readKey([]);
%!error matlab.io.fits.readKey("");

