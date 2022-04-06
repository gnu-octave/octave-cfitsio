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
## @deftypefn {} {@var{files}} = getOpenFiles()
## Get the file handles of all open fits files.
##
## @subsubheading Inputs
## None
##
## @subsubheading Outputs
## @var{files} list of opened fits file handles.
## @seealso {openFile}
## @end deftypefn
function ret = getOpenFiles ()
  ret = __cfitsio_getOpenFiles__ ();
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! assert(isempty(matlab.io.fits.getOpenFiles()));
%! fd = matlab.io.fits.openFile(testfile);
%! of = matlab.io.fits.getOpenFiles();
%! assert(!isempty(of));
%! assert(fd, of);
%! matlab.io.fits.closeFile(fd);
%! of = matlab.io.fits.getOpenFiles();
%! assert(isempty(of));

%!error matlab.io.fits.getOpenFiles(1);

