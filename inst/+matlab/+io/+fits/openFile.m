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
## @deftypefn {} {@var{file}} = openFile(@var{filename})
## @deftypefnx {} {@var{file}} = openFile(@var{filename}, @var{mode})
## Attempt to open a file of the given input name.
## 
## This is the equivalent of the cfitsio fits_open_file function.
##
## @subsubheading Inputs
## @var{filename} - filename to open.
##
## @var{mode} - If the option mode string 'READONLY' (default) or 'READWRITE' is provided,
## open the file using that mode.
##
## @subsubheading Outputs
## @var{file} - opened file identifier.
##
## @subsubheading Examples
## @example
## import_fits;
## filename = file_in_loadpath("demos/tst0012.fits")
##
## fd = fits.openFile(filename, 'READONLY');
## fits.closeFile(fd);
## @end example
##
## @seealso {matlab.io.fits.openDiskFile, matlab.io.fits.createFile}
## @end deftypefn

function ret = openFile (filename, varargin)
  if !ischar(filename)
    error ("Expected filename as a string.");
  endif

  ret = __cfitsio_openFile__ (filename, varargin{:});
endfunction

%!shared testfile
%! testfile = file_in_loadpath("demos/tst0012.fits");

%!test
%! fd = matlab.io.fits.openFile(testfile);
%! assert(!isempty(fd));
%! matlab.io.fits.closeFile(fd);

%!test
%! fd = matlab.io.fits.openFile(testfile, "readonly");
%! assert(!isempty(fd));
%! matlab.io.fits.closeFile(fd);

%!error <Expected filename as a string> matlab.io.fits.openFile(1);
%!error <Expected filename as a string> matlab.io.fits.openFile([]);

%!error <expected mode as a string> matlab.io.fits.openFile(testfile, 1);
%!error <unknown file mode> matlab.io.fits.openFile(testfile, "badmode");

