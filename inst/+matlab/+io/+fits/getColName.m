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
## @deftypefn {} {[@var{colnum},@var{colname}]} = getColName(@var{file}, @var{template})
## @deftypefnx {} {[@var{colnum},@var{colname}]} = getColName(@var{file}, @var{template}, @var{casesens})
## Get column name.
##
## This is the equivalent of the cfitsio fits_get_colname function.
##
## @subsubheading Inputs
## @var{file} - opened fits file.
##
## @var{template} - template string for matching column name.
##
## @var{casesens} - boolean whether to be case sensitive in match.
##
## @subsubheading Outputs
## @var{colnum} - column number of match.
##
## @var{colname} - column name of match.
##
## @subsubheading Examples
## @example
## import_fits;
## filename = file_in_loadpath("demos/tst0012.fits");
## fd = fits.openFile(filename);
## fits.movAbsHDU(fd,2);
## [colnum, colname] = fits.getColName(fd,"C*");
## # returned 3, "COUNTS"
## fits.closeFile(fd);
## @end example
## @end deftypefn
function [colnum, colname] = getColName (file, template, varargin)
  [colnum, colname] = __cfitsio_getColName__ (file, template, varargin{:});
endfunction

%!test
%! testfile = file_in_loadpath("demos/tst0012.fits");
%! fd = matlab.io.fits.openFile(testfile);
%! matlab.io.fits.movAbsHDU(fd,2);
%! [colnum, colname] = matlab.io.fits.getColName(fd,"C*");
%! assert(colnum, 3);
%! assert(colname, "COUNTS");
%! matlab.io.fits.closeFile(fd);
