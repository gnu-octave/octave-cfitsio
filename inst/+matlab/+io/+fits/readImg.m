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
## @deftypefn {} {@var{data}} = readImg(@var{file})
## @deftypefnx {} {@var{data}} = readImg(@var{file}, @var{firstpix}, @var{lastpix})
## @deftypefnx {} {@var{data}} = readImg(@var{file}, @var{firstpix}, @var{lastpix}, @var{inc})
## Read Image data.
##
## This is the equivalent of the cfitsio fits_read_subset function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{firstpix} - first pile coordinate
##
## @var{lastpix} - last pixel coordinate
##
## @var{inc} -  pixel increment
##
## @subsubheading Outputs
## @var{data} - image data read
## @subsubheading Examples
## @example
## import_fits;
## filename = file_in_loadpath("demos/tst0012.fits");
## fd = fits.openFile(filename);
## imagedata = fits.readImg(fd);
## fits.closeFile(fd);
## @end example
## @end deftypefn
function ret = readImg (file, varargin)
  ret = __cfitsio_readImg__ (file, varargin{:});
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile);
%! assert(!isempty(fd));
%! assert(matlab.io.fits.movAbsHDU(fd, 4), "IMAGE_HDU");
%! data = matlab.io.fits.readImg(fd);
%! assert (size(data), [31 73 5]);
%! matlab.io.fits.closeFile(fd);
