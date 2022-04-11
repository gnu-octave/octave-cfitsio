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
## @deftypefn {} {[@var{coldata}, @var{nullval}]} = readCol(@var{file}, @var{colnum})
## @deftypefnx {} {[@var{coldata}, @var{nullval}]} = readCol(@var{file}, @var{colnum}, @var{firstrow}, @var{numrows})
## Get table row data.
##
## This is the equivalent of the cfitsio  fits_read_col function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{firstrow} - Start row
##
## @var{numrows} - Number of rows to read
##
## @subsubheading Outputs
## @var{coldata} - the colmn data rows
##
## @var{nulldata} - the null value flags
## @subsubheading Examples
## @example
## import_fits;
##
## # open file
## filename = file_in_loadpath("demos/tst0012.fits");
## fd = fits.openFile(filename);
##
## # move to binary table and gte column for flux
## fits.movAbsHDU(fd, 2);
## colnum = fits.getColName(fd, 'flux');
##
## # read all rows in column
## fluxdata = fits.readCol(fd, colnum);
## # read data starting at 2nd value
## fluxdata = fits.readCol(fd, colnum, 2);
## # read rows 3 rows starting at row 2
## fluxdata = fits.readCol(fd, colnum, 2, 3);
## fits.closeFile(fd);
## @end example
## @end deftypefn
function [coldata, nullval] = readCol (file, colnum, varargin)
  [coldata, nullval] = __cfitsio_readCol__ (file, colnum, varargin{:});
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile);
%! assert(!isempty(fd));
%! assert(matlab.io.fits.movAbsHDU(fd, 2), "BINARY_TBL");
%! [d,n] = matlab.io.fits.readCol(fd, 1);
%! assert(size(d), [11 9])
%! assert(size(n), [11 9])
%! [d,n] = matlab.io.fits.readCol(fd, 1, 11);
%! assert(size(d), [1 9])
%! assert(size(n), [1 9])
%! [d,n] = matlab.io.fits.readCol(fd, 1, 8, 2);
%! assert(size(d), [2 9])
%! assert(size(n), [2 9])
%!
%! [d,n] = matlab.io.fits.readCol(fd, 2);
%! assert(size(d), [11 13])
%! assert(size(n), [11 13])
%!
%! assert(matlab.io.fits.movAbsHDU(fd, 5), "ASCII_TBL");
%! [d,n] = matlab.io.fits.readCol(fd, 1);
%! assert(size(d), [53 9])
%! assert(size(n), [1 53])
%! [d,n] = matlab.io.fits.readCol(fd, 2);
%! assert(size(d), [53 1])
%! assert(size(n), [53 1])
%! matlab.io.fits.closeFile(fd);
