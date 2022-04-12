## Copyright (C) 2019 John Donoghue <john.donoghue@ieee.org>
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
## @deftypefn {} {@var{info}} = fitsinfo(@var{filename})
## Read information about fits format file
## @subsubheading Inputs
## @var{filename} - filename to open.
##
## @subsubheading Outputs
## @var{info} - a struct containing the structure and information about
## the fits file.
##
## @subsubheading Examples
## @example
## filename = file_in_loadpath("demos/tst0012.fits");
##
## info = fitsinfo(filename);
## @end example
##
## @end deftypefn
function info = fitsinfo (filename)
  import_fits;

  info = {};

  if nargin < 1 || !ischar(filename) || isempty(filename)
    error ("fitsinfo: xpected input filename");
  endif

  fd = fits.openFile(filename);
  unwind_protect

    info.Filename = fits.fileName(fd);
    finfo = stat(filename);

    info.FileSize = finfo.size;
    info.FileModDate = ctime(finfo.mtime);

    N = fits.getNumHDUs(fd);

    contents = {};

    for n = 1:N
      type = fits.movAbsHDU(fd, n);

      hdu = {};
      % keywords
      [nkeys, nspace] = fits.getHdrSpace(fd);

      keywords = cell(nkeys, 3);

      exttype = "";
      slope = 1.0;
      intercept = 0.0;
      pcount = 0;
      gcount = 0;
      axis1 = 1;

      for i=1:nkeys
        # record is 80 char test field
        rec = fits.readRecord(fd, i);
        % keyword is everything before '='
        [~,~,~,~,~,nm,~] = regexp(rec, "^(?<key>[^= ]+) *=.*$");
        if !isempty(nm)
          kw = strtrim(nm.key);
          [v, com] = fits.readKey(fd, kw);
          keywords(i, 1:3) = { kw, v, com};

	  if strcmp(kw, "XTENSION")
            exttype = v;
	  endif
          if strcmp(kw, "BZERO")
            intercept = str2num(v);
          endif
          if strcmp(kw, "BSCALE")
            slope = str2num(v);
          endif
          if strcmp(kw, "NAXIS1")
            axis1 = str2num(v);
          endif
          if strcmp(kw, "PCOUNT")
            pcount = str2num(v);
          endif
          if strcmp(kw, "GCOUNT")
            gcount = str2num(v);
          endif

        else
	  [~,~,~,~,~,nm,~] = regexp(rec, "^(?<key>[^ ]+)[ ]*(?<value>[^\s].*)$");
          if !isempty(nm)
            keywords(i, 1:3) = { nm.key, char([]), nm.value};
          else
            keywords(i, 1:3) = { char([]), char([]), char([])};
          endif
        endif
      endfor

      hdu.Keywords = keywords;

      [hdrstart, datastart, dataend] = fits.getHDUoff(fd);
      hdu.Offset = datastart;
      hdu.DataSize = (dataend - datastart);

      if strcmp(type, "IMAGE_HDU")
        hdu.Intercept = intercept;
        hdu.Slope = slope;
        [bits_per_pixel, ~] = fits.readKeyDbl(fd, "BITPIX");
        if bits_per_pixel < 0
          datasize = -bits_per_pixel;
        else
          datasize = bits_per_pixel;
        endif

        [ndims, ~] = fits.readKeyDbl(fd, "NAXIS");
        dims = zeros(1, ndims);
	for d=1:ndims
          [dims(1,d), ~] = fits.readKeyDbl(fd, sprintf("NAXIS%d", d));
          datasize = datasize * dims(1,d);
	endfor
        hdu.DataSize = datasize/8;

        # matlab shows axis as Y, X ... so need swap 1st 2.
        if ndims > 1
          tmp = dims(1,1);
          dims(1,1) = dims(1,2);
          dims(1,2) = tmp;
        endif
	hdu.Size = dims;

        v = fits.getImgType(fd);
        switch (v)
          case "BYTE_IMG", datatype = "uint8";
          case "SHORT_IMG", datatype = "int16";
          case "LONG_IMG", datatype = "int32";
          case "LONGLONG_IMG", datatype = "int64";
          case "FLOAT_IMG", datatype = "single";
          case "DOUBLE_IMG", datatype = "double";
          case "SBYTE_IMG", datatype = "int8";
          case "USHORT_IMG", datatype = "uint16";
          case "ULONG_IMG", datatype = "uint32";
          case "ULONGLONG_IMG", datatype = "uint64";
          otherwise, datatype="UNKNOWN";
        endswitch
	hdu.DataType = datatype;

        # TODO:
        hdu.MissingDataValue = [];

        if strcmp(type, "IMAGE_HDU") && !isempty(exttype) && !strcmp(exttype, "IMAGE")
          hdu.PCOUNT = pcount;
          hdu.GCOUNT = gcount;
        endif
      elseif strcmp(type, "ASCII_TBL") || strcmp(type, "BINARY_TBL")
        rows = fits.getNumRows(fd);
        cols = fits.getNumCols(fd);
        hdu.Rows = rows;
        hdu.NFields = cols;
        hdu.DataSize = rows*cols;

        if strcmp(type, "ASCII_TBL")
          [rowlen, rows, ttype, tbcol, tform, tunit, extname] = fits.readATblHdr(fd);
          hdu.Rows = rows;
          hdu.RowSize = rowlen;
          hdu.DataSize = rows * rowlen;

          hdu.FieldFormat = {};
          hdu.FieldPrecision = {};
          hdu.Intercept = [];
          hdu.Slope = [];
          hdu.FieldPos = [];
          hdu.FieldWidth=[];
          hdu.MissingDataValue = {};
          for i=1:cols
            [ttype,tbcol,tunit,tform,scale,zero,nulstr,tdisp] = fits.getAColParms(fd,i);
            hdu.FieldFormat{end+1} = tform;
            hdu.Intercept{end+1} = zero;
            hdu.Slope{end+1} = scale;
            hdu.FieldPos{end+1} = tbcol;
            hdu.MissingDataValue{end+1} = nulstr;

            prec = [];
            switch tform(1)
              case {"I", "O", "Z"}
                prec = "Integer";
              case {"E", "F", "G"}
                prec = "Single";
              case {"D"}
                prec = "Double";
              otherwise
                prec = "Char";
            endswitch
            hdu.FieldPrecision{end+1} = prec;

            hdu.FieldWidth{end+1} = sscanf(tform(2:end), "%f");

          endfor

        elseif strcmp(type, "BINARY_TBL")
          [rows, ttype, tform, tunit, extname, pcount] = fits.readBTblHdr(fd);
          hdu.Rows = rows;
          [hdu.RowSize, ~] = fits.readKeyDbl(fd, "NAXIS1");
          hdu.DataSize = rows*hdu.RowSize;

          hdu.ExtensionOffset = hdu.Offset + hdu.DataSize;
          hdu.ExtensionSize = pcount;

          hdu.FieldFormat = {};
          hdu.FieldPrecision = {};
          hdu.Intercept = [];
          hdu.Slope = [];
          #hdu.FieldPos = [];
          hdu.FieldSize=[];
          hdu.MissingDataValue = {};
          for i=1:cols
            [ttype,tunit,tform,repeat,scale,zero,nulstr,tdisp] = fits.getBColParms(fd,i);
            [tformx, ~] = fits.readKey(fd, sprintf("TFORM%d", i));
            hdu.FieldFormat{end+1} = tformx;
            hdu.Intercept{end+1} = zero;
            hdu.Slope{end+1} = scale;
            #hdu.FieldPos{end+1} = tbcol;
            hdu.MissingDataValue{end+1} = nulstr;

            prec = [];
            sz = repeat;
            switch tform(1)
              case {"L"}
                prec = "char"; # logical
              case {"X"}
                # size based on bits
                if repeat <= 8
                  prec = "bit8";
                elseif repeat <= 16
                  prec = "bit16";
                elseif repeat <= 32
                 prec = "bit32";
                else
                  prec = "bit64";
                endif
                sz = 1;
              case {"B"}
                prec = "uint8";
              case {"D"}
                prec = "double";
              case {"C"}
                prec = "single complex"; # single
              case {"M"}
                prec = "double complex"; # double
              case {"J"}
                prec = "int32";
              case {"I"}
                prec = "int16";
              case {"P"}
                prec = "int32"; # 2 int32s
              case {"E", "F", "G"}
                prec = "single";
              otherwise
                prec = "char";
            endswitch
            hdu.FieldPrecision{end+1} = prec;
            hdu.FieldSize{end+1} = sz;
             
          endfor

        endif
      endif

      if n == 1
        info.PrimaryData = hdu;
        contents{end+1} = "Primary";
      else
        # extension
        if strcmp(type, "IMAGE_HDU") && !isempty(exttype) && !strcmp(exttype, "IMAGE")
          type = "Unknown";
        endif

        if strcmp(type, "IMAGE_HDU")
          if isfield(info, 'Image')
            # add to other tables
            # TODO
          else
            info.Image = hdu;
          endif
          contents{end+1} = "Image";
        elseif strcmp(type, "BINARY_TBL")
          if isfield(info, 'BinaryTable')
            # add to other tables
            # TODO
          else
            info.BinaryTable = hdu;
          endif
          contents{end+1} = "Binary Table";
        elseif strcmp(type, "ASCII_TBL")
          if isfield(info, 'AsciiTable')
            # add to other tables
            # TODO
          else
            info.AsciiTable = hdu;
          endif
          contents{end+1} = "ASCII Table";
        else
          if isfield(info, 'Unknown')
            # add to other tables
            # TODO
          else
            info.Unknown = hdu;
          endif
          contents{end+1} = "Unknown";
        endif
      endif
    endfor

    info.Contents = contents;

  unwind_protect_cleanup
    fits.closeFile(fd);
  end_unwind_protect
endfunction

%!shared testfile
%! testfile = file_in_loadpath("demos/tst0012.fits");

%!test
%! a = fitsinfo(testfile);
%! assert(!isempty(a))
%! assert(a.FileSize, 109440);
%! assert(length(a.Contents), 5);
%!
%! assert(a.PrimaryData.DataType, 'single');
%! assert(a.PrimaryData.Size, [109 102]);
%! assert(a.PrimaryData.DataSize, 44472);
%! assert(a.PrimaryData.Intercept, 0);
%! assert(a.PrimaryData.Slope, 1);
%! assert(a.PrimaryData.Offset, 2880);
%!
%! assert(a.Image.DataType, 'int16');
%! assert(a.Image.Size, [31 73 5]);
%! assert(a.Image.DataSize, 22630);
%! assert(a.Image.Intercept, 0);
%! assert(a.Image.Slope, 1);
%! assert(a.Image.Offset, 74880);
%!
%! assert(a.AsciiTable.Rows, 53);
%! assert(a.AsciiTable.RowSize, 59);
%! assert(a.AsciiTable.DataSize, 3127);
%! assert(a.AsciiTable.NFields, 8);
%! assert(a.AsciiTable.Offset, 103680);

%!error fitsinfo
%!error fitsinfo(1)
%!error fitsinfo([])
%!error fitsinfo('')
