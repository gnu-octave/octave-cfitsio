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
## @deftypefn {} {} imgCompress(@var{infile}, @var{outfile})
## Copy HDU and image data from one infile to another, using the outfiles compression type.
##
## This is the equivalent of the cfitsio fits_img_compress function.
##
## @subsubheading Inputs
## @var{infile} - opened input fits file.
##
## @var{outfile} - opened writable output fits file.
##
## @subsubheading Outputs
## None
## @end deftypefn
function imgCompress (infile, outfile)
  __cfitsio_imgCompress__ (infile, outfile);
endfunction

%!test
%! filename1 = tempname();
%! filename2 = tempname();
%! fd1 = matlab.io.fits.createFile(filename1);
%! matlab.io.fits.createImg(fd1,'int16',[256 512]);
%! matlab.io.fits.closeFile(fd1);
%!
%! fd1 = matlab.io.fits.openFile(filename1);
%!
%! fd2 = matlab.io.fits.createFile(filename2);
%! matlab.io.fits.setCompressionType(fd2, "RICE");
%! matlab.io.fits.imgCompress(fd1,fd2);
%! matlab.io.fits.closeFile(fd1);
%! matlab.io.fits.closeFile(fd2);
%!
%! delete (filename1);
%! delete (filename2);
