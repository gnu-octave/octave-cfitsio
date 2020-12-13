## Copyright (C) 2019 John Donoghue
## 
## This program is free software: you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
## 
## This program is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see
## <https://www.gnu.org/licenses/>.

## -*- texinfo -*- 
## @deftypefn {} {fits =} import_fits
## Import the fits functions into a fits.xxxxx variable, to emulate importing the fits namespace.
## @end deftypefn

#file access
fits.createFile = @fits_createFile;
fits.openFile = @fits_openFile;
fits.openDiskFile = @fits_openDiskFile;
fits.fileMode = @fits_fileMode;
fits.fileName = @fits_fileName;
fits.closeFile = @fits_closeFile;
fits.deleteFile = @fits_deleteFile;
# utilities
fits.getConstantValue = @fits_getConstantValue;
fits.getVersion = @fits_getVersion;
fits.getConstantNames = @fits_getConstantNames;
# HDU Access
fits.getHDUnum = @fits_getHDUnum;
fits.getHDUtype = @fits_getHDUtype;
fits.getNumHDUs = @fits_getNumHDUs;
fits.movAbsHDU = @fits_movAbsHDU;
fits.movRelHDU = @fits_movRelHDU;
fits.writeChecksum = @fits_writeChecksum;
fits.deleteHDU = @fits_deleteHDU;
# keywords
fits.readCard = @fits_readCard;
fits.readKey = @fits_readKey;
fits.readKeyDblCmplx = @fits_readKeyDblCmplx;
fits.readKeyDbl = @fits_readKeyDbl;
fits.readKeyLongLong = @fits_readKeyLongLong;
fits.readKeyUnit = @fits_readKeyUnit;
fits.readRecord = @fits_readRecord;
fits.getHdrSpace = @fits_getHdrSpace;

%!test
%! import_fits;
%! assert(fits.getVersion(), fits.getConstantValue("CFITSIO_VERSION"), 1e8);
