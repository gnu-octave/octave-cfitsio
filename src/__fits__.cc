// Copyright (C) 2019 John Donoghue <john.donoghue@ieee.org>
//
// This program is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation; either version 3 of the License, or (at your option) any later
// version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// this program; if not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <sstream>
#include <ctype.h>
#include <octave/oct.h>
#include <octave/version.h>
#include <octave/file-info.h>
#include <octave/defun-dld.h>

#ifdef HAVE_CONFIG_H
#  include "./config.h"
#endif

#ifdef HAVE_OCTAVE_INTERPRETER_H
# include <octave/interpreter.h>
#endif

extern "C"
{
#include <fitsio2.h>
}

#include "fits_constants.h"

std::string coltype_to_string (int ct)
{
  switch(ct)
  {
   case TBIT: return "TBIT";
   case TBYTE: return "TBYTE";
   case TSBYTE: return "TSBYTE";
   case TLOGICAL: return "TLOGICAL";
   case TSTRING: return "TSTRING";
   case TUSHORT: return "TUSHORT";
   case TSHORT: return "TSHORT";
   case TUINT: return "TUINT";
   case TINT: return "TINT";
   case TULONG: return "TULONG";
   case TLONG: return "TLONG";
   //case TINT32BIT: return "TINT32BIT"; // same as TULONG
   case TFLOAT: return "TFLOAT";
   case TULONGLONG: return "TULONGLONG";
   case TLONGLONG: return "TLONGLONG";
   case TDOUBLE: return "TDOUBLE";
   case TCOMPLEX: return "TCOMPLEX";
   case TDBLCOMPLEX: return "TDBLCOMPLEX";
  }
  return "TSTRING";
}

int string_to_coltype (const std::string &s)
{
  std::string name = s;
  std::transform (name.begin(), name.end(), name.begin(), ::toupper);
  for (int i=i;i<sizeof(fits_constants)/sizeof(fits_constants_type);i++)
    {
      if(name == fits_constants[i].name)
        {
          return fits_constants[i].value.int_value();
        }
    }
  return TSTRING;
}

static std::string get_fits_error (int status)
{
  char err[32];

  if(status == 0)
  {
    return "";
  }
  ffgerr(status, err);
  return err;
}

template <class ATYPE, typename DTYPE>
octave_value_list read_numeric_row(fitsfile *fp, int col, int dtype, LONGLONG firstrow, LONGLONG nrows, LONGLONG repeat)
{
  ATYPE arr(dim_vector(nrows,repeat));
  DTYPE val;
  DTYPE nulval = 1;
  int anynul;
  int status = 0;

  boolNDArray nuldata(dim_vector(nrows, repeat));

  octave_value_list ret;

  for(LONGLONG i = 0; i<nrows; i++)
    {
      for(LONGLONG r = 0;r<repeat; r++)
        {
          anynul = 0;
          if (fits_read_col(fp, dtype, col, i+firstrow, r+1, 1, &nulval, &val, &anynul, &status) > 0)
            {
              error ("couldnt get data: %s", get_fits_error(status).c_str());
              return ret;
            }

          if(anynul)
            arr(i, r) = 0;
          else
            arr(i, r) = val;

          nuldata(i, r) = (anynul != 0);
	}
    }

  ret(0) = arr;
  ret(1) = nuldata;

  return ret;
}


#define MAX_OPEN_FITS_FILES 20
#define FITS_FD_MASK ( (((uint64_t)'F') << 32) | (((uint64_t)'I') << 24) | (((uint64_t)'T') << 16) )
fitsfile * fits_files[MAX_OPEN_FITS_FILES] = {0};

static void close_all_fits_files()
{
  for (int i=0;i<MAX_OPEN_FITS_FILES; i++)
    {
      if(fits_files[i] != 0)
        {
          int status = 0;

          if ( fits_close_file(fits_files[i], &status ) > 0 )
            {
              fits_report_error( stderr, status );
            }

          fits_files[i] = 0;
	}
    }
}

static int get_free_fits_index()
{
  for (int i=0;i<MAX_OPEN_FITS_FILES; i++)
    {
      if(fits_files[i] == 0)
        {
          return i;
	}
    }

  return -1;
}

static uint64_t add_fits_file(fitsfile *fd)
{
  int idx = get_free_fits_index();
  if(idx >= 0)
    {
      fits_files[idx] = fd;
      return FITS_FD_MASK | (idx+1);
    }

  return 0;
}

static uint64_t remove_fits_file(uint64_t fd)
{
  if ((fd & FITS_FD_MASK) != FITS_FD_MASK)
    return 0;

  uint64_t idx = (fd & ~FITS_FD_MASK);
  if (idx < 1 || idx > MAX_OPEN_FITS_FILES)
    return 0;

  fits_files[idx-1] = 0;
  return fd;
}

static fitsfile * get_fits_file(uint64_t fd)
{
  if ((fd & FITS_FD_MASK) != FITS_FD_MASK)
    return 0;

  uint64_t idx = (fd & ~FITS_FD_MASK);
  if (idx < 1 || idx > MAX_OPEN_FITS_FILES)
    return 0;
  return fits_files[idx-1];
}

#if 0
// NOTE: using this for all tess of this file, so needs be at top of tests
%!shared testfile
%! testfile = urlwrite ( ...
%!   'https://fits.gsfc.nasa.gov/nrao_data/tests/pg93/tst0012.fits', ...
%!   tempname() );
#endif

// PKG_ADD: autoload ("__cfitsio_pkg_lock__", "__fits__.oct");
// PKG_ADD: __cfitsio_pkg_lock__(1);
// PKG_DEL: __cfitsio_pkg_lock__(0);
#ifdef DEFMETHOD_DLD
DEFMETHOD_DLD (__cfitsio_pkg_lock__, interp, args, , "internal function")
{
  octave_value retval;
  if (args.length () >= 1)
    {
      if (args(0).int_value () == 1)
        interp.mlock();
      else if (args(0).int_value () == 0 &&  interp.mislocked("__cfitsio_pkg_lock__"))
        {
          close_all_fits_files();
          interp.munlock("__cfitsio_pkg_lock__");
	}
    }
  return retval;
}
#else
DEFUN_DLD(__cfitsio_pkg_lock__, args, ,  "internal function")
{
  octave_value retval;

  if (args.length () >= 1)
    {
      if (args(0).int_value () == 0)
        {
          close_all_fits_files();
	}
    }

  return retval;
}
#endif

// PKG_ADD: autoload ("fits_getOpenFiles", "__fits__.oct");
DEFUN_DLD(fits_getOpenFiles, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{files}]} = fits_getOpenFiles()\n \
Attempt to create  a file of the gien input name.\n \
\n \
Get the file handles of all open fits files\n \
\n \
@seealso {fits_openFile}\n \
@end deftypefn")
{
  if ( args.length() != 0)
    {
      print_usage ();
      return octave_value();
    }

  int count = 0;
  for (int i=0;i<MAX_OPEN_FITS_FILES; i++)
    {
      if(fits_files[i] != 0)
        {
          count ++;
	}
    }

  uint64NDArray fds(dim_vector(count, 1));

  count = 0;
  for (int i=0;i<MAX_OPEN_FITS_FILES; i++)
    {
      if(fits_files[i] != 0)
        {
	  fds(count, 0) = octave_uint64(FITS_FD_MASK | (i+1));
	  count ++;
	}
    }

  return octave_value(fds);
}
#if 0
%!test
%! assert(isempty(fits_getOpenFiles()));
%! fd = fits_openFile(testfile);
%! of = fits_getOpenFiles();
%! assert(!isempty(of));
%! assert(fd, of);
%! fits_closeFile(fd);
%! of = fits_getOpenFiles();
%! assert(isempty(of));

%!error fits_getOpenFiles(1);
#endif


// PKG_ADD: autoload ("fits_createFile", "__fits__.oct");
DEFUN_DLD(fits_createFile, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{file}]} = fits_createFile(@var{filename})\n \
Attempt to create  a file of the gien input name.\n \
\n \
If the filename starts with ! and the file exists, it will create a new file, otherwise, if the\n \
file exists, the create will fail.\n \
\n \
This is the equivilent of the cfitsio fits_create_file funtion.\n \
@seealso {fits_openFile}\n \
@end deftypefn")
{
  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }
  if ( args.length() != 1 || !args(0).is_string() )
    {
      error( "fits_createFile: filename (string) expected as only argument" );
      return octave_value();
    }

  std::string infile = args(0).string_value ();

  if (get_free_fits_index () < 0)
    {
      error ("Out of space for new open file");
      return octave_value ();
    }

  int status = 0;
  fitsfile *fp;

  if ( fits_create_file( &fp, infile.c_str(), &status) > 0 )
    {
      error ("Couldnt create file: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  uint64_t fd = add_fits_file(fp);

  return octave_value(octave_uint64 (fd));
}

// PKG_ADD: autoload ("fits_openFile", "__fits__.oct");
DEFUN_DLD(fits_openFile, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{file}]} = fits_openFile(@var{filename})\n \
@deftypefnx {Function File} {[@var{file}]} = fits_openFile(@var{filename}, @var{mode})\n \
Attempt to open a a file of the given input name.\n \
\n \
If the opion mode string 'READONLY' (default) or 'READWRITE' is provided, open the file using that mode.\n \
\n \
This is the equivilent of the cfitsio fits_open_file funtion.\n \
@seealso {fits_openDiskFile, fits_createFile}\n \
@end deftypefn")
{
  if ( args.length() != 1 && args.length () != 2)
    {
      print_usage ();
      return octave_value ();
    }
  if ( !args(0).is_string() )
    {
      error( "fits_openFile: expected filename as a string" );
      return octave_value ();
    }

  int mode = READONLY;

  if(args.length() == 2)
    {
      if ( !args(1).is_string() )
        {
          error( "fits_openFile: expected mode as a string" );
          return octave_value ();
        }
      std::string modestr = args(1).string_value();

      std::transform (modestr.begin(), modestr.end(), modestr.begin(), ::tolower);
      if(modestr == "readwrite")
        mode = READWRITE;
      else if(modestr == "readonly")
        mode = READONLY;
      else
        {
          error( "fits_openFile:: unknown file mode" );
          return octave_value ();
        }
    }

  std::string infile = args(0).string_value ();

  if (get_free_fits_index () < 0)
    {
      error ("Out of space for new open file");
      return octave_value ();
    }

  fitsfile *fp;
  int status = 0;
  if ( fits_open_file( &fp, infile.c_str(), mode, &status) > 0 )
    {
      error ("Could not open file: %s", get_fits_error(status).c_str());
    }

  uint64_t fd = add_fits_file(fp);

  return octave_value(octave_uint64 (fd));
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! fits_closeFile(fd);

%!test
%! fd = fits_openFile(testfile, "readonly");
%! assert(!isempty(fd));
%! fits_closeFile(fd);

%!error <expected filename as a string> fits_openFile(1);
%!error <expected filename as a string> fits_openFile([]);

%!error <expected mode as a string> fits_openFile(testfile, 1);
%!error <unknown file mode> fits_openFile(testfile, "badmode");
#endif


// PKG_ADD: autoload ("fits_openDiskFile", "__fits__.oct");
DEFUN_DLD(fits_openDiskFile, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{file}]} = fits_openDiskFile(@var{filename})\n \
@deftypefnx {Function File} {[@var{file}]} = fits_openDiskFile(@var{filename}, @var{mode})\n \
Attempt to open a a file of the given input name, ignoring any special processing of the filename.\n \
\n \
If the option mode string 'READONLY' (default) or 'READWRITE' is provided, open the file using that mode.\n \
\n \
This is the equivilent of the cfitsio fits_open_diskfile funtion.\n \
@seealso {fits_openFile, fits_createFile}\n \
@end deftypefn")
{
  if ( args.length() != 1 && args.length () != 2)
    {
      print_usage ();
      return octave_value();
    }
  if ( !args(0).is_string() )
    {
      error( "fits_openDiskFile: expected filename as a string" );
      return octave_value();
    }

  int mode = READONLY;

  if(args.length() == 2)
    {
      if ( !args(1).is_string() )
        {
          error ( "filts_openDiskFile: expected mode as a string" );
          return octave_value();
        }
      std::string modestr = args(1).string_value();

      std::transform (modestr.begin(), modestr.end(), modestr.begin(), ::tolower);
      if(modestr == "readwrite")
        mode = READWRITE;
      else if(modestr == "readonly")
        mode = READONLY;
      else
        {
          error( "fits_openDiskFile: unknown file mode" );
         return octave_value();
        }
    }

  std::string infile = args(0).string_value ();

  if (get_free_fits_index () < 0)
    {
      error ("Out of space for new open file");
      return octave_value ();
    }

  fitsfile *fp;
  int status = 0;
  if ( fits_open_diskfile( &fp, infile.c_str(), mode, &status) > 0 )
    {
      error ("Couldnt open file: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  uint64_t fd = add_fits_file(fp);

  return octave_value(octave_uint64 (fd));
}

// PKG_ADD: autoload ("fits_fileMode", "__fits__.oct");
DEFUN_DLD(fits_fileMode, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{mode}} = fits_fileMode(@var{file})\n \
Return the file mode of the opened fits file\n \
\n \
The mode will return as a string 'READWRITE' or 'READONLY'\n \
\n \
The is the eqivalent of the fits_file_mode function.\n \
@end deftypefn")
{
  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (args.length() != 1 || !args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int mode, status = 0;

  if (fits_file_mode(fp, &mode, &status) > 0)
    {
      error ("fits_fileMode: couldnt read file mode: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  std::string modestr = "READONLY";
  if(mode == READWRITE)
    modestr = "READWRITE";

  return octave_value (modestr);
}
#if 0
%!test
%! fd = fits_openFile(testfile, "readonly");
%! assert(!isempty(fd));
%! assert(fits_fileMode(fd), "READONLY")
%! fits_closeFile(fd);

%!error fits_fileMode(1);
%!error fits_fileMode([]);
#endif


// PKG_ADD: autoload ("fits_fileName", "__fits__.oct");
DEFUN_DLD(fits_fileName, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{name}} = fits_fileName(@var{file})\n \
Return the file name of the opened fits file\n \
\n \
The is the eqivalent of the fits_file_name function.\n \
@end deftypefn")
{
  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (args.length() != 1 || !args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int status = 0;
  char filename[FLEN_FILENAME];

  if( fits_file_name(fp, filename, &status) > 0)
    {
      error ("fits_fileName: couldnt read file name: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return octave_value (filename);
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! assert(fits_fileName(fd), testfile)
%! fits_closeFile(fd);

%!error fits_fileName(1);
%!error fits_fileName([]);
#endif

// PKG_ADD: autoload ("fits_closeFile", "__fits__.oct");
DEFUN_DLD(fits_closeFile, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} fits_closeFile(@var{file})\n \
Close the opened fits file\n \
\n \
The is the eqivalent of the fits_close_file function.\n \
@end deftypefn")
{
  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (args.length() != 1 || !args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  uint64_t fidx = args(0).uint64_value();
  fitsfile * fp = get_fits_file (fidx);

  if (!fp)
    {
      error ("Not a fits file");
    }
  else
    {
      remove_fits_file(fidx);

      int status = 0;
      if ( fits_close_file(fp, &status ) > 0 )
        {
          fits_report_error( stderr, status );
        }
      
    }

  return octave_value();
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! fits_closeFile(fd);

%!error fits_closeFile();
%!error fits_closeFile(1);
%!error fits_closeFile([]);
#endif


// PKG_ADD: autoload ("fits_deleteFile", "__fits__.oct");
DEFUN_DLD(fits_deleteFile, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} = fits_deleteFile(@var{file})\n \
Force a clode and delete of a fits file.\n \
\n \
The is the eqivalent of the fits_delete_file function.\n \
@end deftypefn")
{
  octave_value retval;  // create object to store return values

  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (args.length() != 1 || !args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  uint64_t fidx = args(0).uint64_value();
  fitsfile * fp = get_fits_file (fidx);

  if (!fp)
    {
      error ("Not a fits file");
    }
  else
    {
      remove_fits_file(fidx);

      int status = 0;

      if ( fits_delete_file(fp, &status ) > 0 )
        {
          error ("Couldnt force close file: %s", get_fits_error(status).c_str());
        }
    }
  return octave_value();
}
#if 0
%!test
%! tmp = tempname();
%! copyfile(testfile,tmp);
%! assert(exist(tmp, "file"), 2);
%!
%! fd = fits_openFile(tmp);
%! fits_deleteFile(fd);
%! assert(exist(tmp, "file"), 0);

%!error fits_deleteFile();
%!error fits_deleteFile(1);
%!error fits_deleteFile("");
%!error fits_deleteFile([]);
#endif


// PKG_ADD: autoload ("fits_getHDUnum", "__fits__.oct");
DEFUN_DLD(fits_getHDUnum, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{num}]} = fits_getHDUnum(@var{file})\n \
Return the index of the current HDU\n \
\n \
This is the equivalent of the cfitsio fits_get_hdu_num function.\n \
@end deftypefn")
{

  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (args.length() != 1 || !args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int hdunum, status = 0;

  fits_get_hdu_num(fp, &hdunum);

  return octave_value (hdunum);
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! assert(fits_getHDUnum(fd), 1);
%! fits_movAbsHDU(fd, 1);
%! assert(fits_getHDUnum(fd), 1);
%! fits_movAbsHDU(fd, 2);
%! assert(fits_getHDUnum(fd), 2);
%! fits_closeFile(fd);

%!error fits_getHDUnum(1);
%!error fits_getHDUnum([]);
#endif


// PKG_ADD: autoload ("fits_getHDUtype", "__fits__.oct");
DEFUN_DLD(fits_getHDUtype, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{type}]} = fits_getHDUtype(@var{file})\n \
Return the current HDUs type as a string\n \
\n \
This is the equivalent of the cfitsio fits_get_hdu_type function.\n \
@end deftypefn")
{

  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (args.length() != 1 || !args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int hdutype, status = 0;

  if(fits_get_hdu_type(fp, &hdutype, &status) > 0)
    {
      error ("fits_getHDUtype: couldnt get hdu type : %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  std::string name = "";
  if(hdutype == IMAGE_HDU) 
    name = "IMAGE_HDU";
  else if(hdutype == ASCII_TBL)
    name = "ASCII_TBL";
  else if(hdutype == BINARY_TBL)
    name = "BINARY_TBL";
  else
    name = "UNKNOWN";

  return octave_value (name);
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! assert(fits_getHDUtype(fd), "IMAGE_HDU");
%! type = fits_movAbsHDU(fd, 2);
%! assert(fits_getHDUtype(fd), type);
%! fits_closeFile(fd);

%!error fits_getHDUtype(1);
%!error fits_getHDUtype([]);
#endif


// PKG_ADD: autoload ("fits_getNumHDUs", "__fits__.oct");
DEFUN_DLD(fits_getNumHDUs, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{num}]} = fits_getNumHDUs(@var{file})\n \
Return the count of HDUs in the file\n \
\n \
This is the equivalent of the cfitsio fits_get_num_hdus function.\n \
@end deftypefn")
{

  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (args.length() != 1 || !args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int cnt, status = 0;

  if(fits_get_num_hdus(fp, &cnt, &status) > 0)
    {
      error ("couldnt get num hdus: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return octave_value(cnt);
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! assert(fits_getNumHDUs(fd), 5);
%! fits_closeFile(fd);

%!error fits_getNumHDUs(1);
%!error fits_getNumHDUs([]);
#endif

// PKG_ADD: autoload ("fits_movAbsHDU", "__fits__.oct");
DEFUN_DLD(fits_movAbsHDU, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{type}]} = fits_moveAbsHDU(@var{file}, @var{hdunum})\n \
Got to absolute HDU index @var{hdunum}\n \
\n \
Returns the newly current HDU type as a string.\n \
\n \
This is the equivalent of the cfitsio fits_movabs_hdu function.\n \
@end deftypefn")
{

  if ( args.length() != 2)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (! args (1).isnumeric () || args (1).isempty())
    {
      error ("fits_movAbsHDU: expected hdu number");
      return octave_value ();  
    }

  int hdu = args(1).int_value();

  int status = 0, hdutype;

  if(fits_movabs_hdu(fp, hdu, &hdutype,&status) > 0)
    {
      error ("fits_movAbsHDU: couldnt move hdus: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  std::string name = "";
  if(hdutype == IMAGE_HDU) 
    name = "IMAGE_HDU";
  else if(hdutype == ASCII_TBL)
    name = "ASCII_TBL";
  else if(hdutype == BINARY_TBL)
    name = "BINARY_TBL";
  else
    name = "UNKNOWN";

  return octave_value (name);
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! type = fits_movAbsHDU(fd, 1);
%! assert(fits_getHDUtype(fd), type);
%! assert(fits_getHDUnum(fd), 1);
%! type = fits_movAbsHDU(fd, 2);
%! assert(fits_getHDUtype(fd), type);
%! assert(fits_getHDUnum(fd), 2);
%! type = fits_movAbsHDU(fd, 3);
%! assert(fits_getHDUtype(fd), type);
%! assert(fits_getHDUnum(fd), 3);
%! fits_closeFile(fd);

%!error fits_movAbsHDU(1);
%!error fits_movAbsHDU([]);
#endif


// PKG_ADD: autoload ("fits_movRelHDU", "__fits__.oct");
DEFUN_DLD(fits_movRelHDU, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{type}]} = fits_movRelHDU(@var{file}, @var{hdunum})\n \
Go to relative HDU index @var{hdunum}\n \
\n \
Returns the newly current HDU type as a string.\n \
\n \
This is the equivalent of the cfitsio fits_movrel_hdu function.\n \
@end deftypefn")
{

  if ( args.length() != 2)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (! args (1).isnumeric () || args (1).isempty())
    {
      error ("fits_movRelHDU: expected hdu number");
      return octave_value ();  
    }

  int hdu = args(1).int_value();

  int status = 0, hdutype;

  if(fits_movrel_hdu(fp, hdu, &hdutype,&status) > 0)
    {
      error ("fits_movRelHDU: couldnt move hdus: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  std::string name = "";
  if(hdutype == IMAGE_HDU) 
    name = "IMAGE_HDU";
  else if(hdutype == ASCII_TBL)
    name = "ASCII_TBL";
  else if(hdutype == BINARY_TBL)
    name = "BINARY_TBL";
  else
    name = "UNKNOWN";

  return octave_value (name);
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! type = fits_movAbsHDU(fd, 1);
%! assert(fits_getHDUnum(fd), 1);
%! type = fits_movRelHDU(fd, 1);
%! assert(fits_getHDUtype(fd), type);
%! assert(fits_getHDUnum(fd), 2);
%! type = fits_movRelHDU(fd, -1);
%! assert(fits_getHDUtype(fd), type);
%! assert(fits_getHDUnum(fd), 1);
%! fail ("fits_movRelHDU(fd, [])");
%! fits_closeFile(fd);

%!error fits_movRelHDU(1);
%!error fits_movRelHDU([]);
#endif


// PKG_ADD: autoload ("fits_movNamHDU", "__fits__.oct");
DEFUN_DLD(fits_movNamHDU, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} fits_movNamHDU(@var{file}, @var{hdutype}, @var{extname}, @var{extver})\n \
Got to HDU matching @var{hdutype}, @var{extname}, @var{extver}\n \
\n \
Returns the newly current HDU type as a string.\n \
\n \
Valid hdytype values are 'IMAGE_HDU', 'ASCII_TBL', 'BINARY_TBL', 'ANY_HDU'.\n \
\n \
This is the equivalent of the cfitsio fits_movnam_hdu function.\n \
@end deftypefn")
{

  if ( args.length() != 4)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (! args (1).is_string ())
    {
      error ("fits_movNamHDU: expected hdu type string");
      return octave_value ();  
    }
  if (! args (2).is_string ())
    {
      error ("fits_movNamHDU: expected extname string");
      return octave_value ();  
    }

  if (! args (3).isnumeric () || args (3).isempty())
    {
      error ("fits_movNamHDU: expected extver number");
      return octave_value ();  
    }

  std::string hdutype = args(1).string_value();
  std::string extname = args(2).string_value();
  int extver = args(3).int_value();
  int hdu;

  if (hdutype == "IMAGE_HDU") hdu = IMAGE_HDU;
  else if(hdutype == "ASCII_TBL") hdu = ASCII_TBL;
  else if(hdutype == "BINARY_TBL") hdu = BINARY_TBL;
  else if(hdutype == "ANY_HDU") hdu = 0;
  else
  {
    error ("Expected hdutype of IMAGE_HDU, ASCII_TBL, BINARY_TBL, ANY_HDU");
    return octave_value();
  }

  int slen = extname.length()+1;
  char extname_c[slen];
  strcpy(extname_c, extname.c_str());

  int status = 0;

  if(fits_movnam_hdu(fp, hdu, extname_c, extver, &status) > 0)
    {
      error ("fits_movNamHDU: couldnt move hdus: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return octave_value ();
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! fits_movNamHDU(fd, 'IMAGE_HDU', 'quality', 1);
%! assert(fits_getHDUnum(fd), 4);
%! assert(fits_getHDUtype(fd), 'IMAGE_HDU');
%! fits_movNamHDU(fd, 'BINARY_TBL', 'BinTest', 0);
%! assert(fits_getHDUnum(fd), 2);
%! assert(fits_getHDUtype(fd), 'BINARY_TBL');
%! fits_movNamHDU(fd, 'ANY_HDU', 'Unknown', 1);
%! assert(fits_getHDUnum(fd), 3);
%! fail ("fits_movNamHDU(fd, 'INVALID_HDU', '', 0);");
%! fits_closeFile(fd);

%!error fits_movNamHDU(1);
%!error fits_movNamHDU([]);
#endif


// PKG_ADD: autoload ("fits_deleteHDU", "__fits__.oct");
DEFUN_DLD(fits_deleteHDU, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{type}]} = fits_deleteHDU(@var{file})\n \
Delete the current HDU and go to next HDU\n \
\n \
Returns the newly current HDU type as a string.\n \
\n \
This is the equivalent of the cfitsio fits_delete_hdu function.\n \
@end deftypefn")
{
  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (args.length() != 1 || !args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int status = 0, hdutype;

  if(fits_delete_hdu(fp, &hdutype,&status) > 0)
    {
      error ("fits_deleteHDU: couldnt delete hdu: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  std::string name = "";
  if(hdutype == IMAGE_HDU) 
    name = "IMAGE_HDU";
  else if(hdutype == ASCII_TBL)
    name = "ASCII_TBL";
  else if(hdutype == BINARY_TBL)
    name = "BINARY_TBL";
  else
    name = "UNKNOWN";

  return octave_value(name);
}

// PKG_ADD: autoload ("fits_writeChecksum", "__fits__.oct");
DEFUN_DLD(fits_writeChecksum, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} fits_writeChecksum(@var{file})\n \
Recalulate the HDU checksum and if required, write the new value\n \
\n \
This is the equivalent of the cfitsio fits_write_chksum function.\n \
@end deftypefn")
{
  octave_value retval;  // create object to store return values

  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (args.length() != 1 || !args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int status = 0;

  if (fits_write_chksum(fp, &status) > 0)
    {
      error ("fits_writeChecksum: couldnt write checksum: %s", get_fits_error(status).c_str());
      return octave_value ();
   }

  return octave_value ();
}

// PKG_ADD: autoload ("fits_getHdrSpace", "__fits__.oct");
DEFUN_DLD(fits_getHdrSpace, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{numkeys}, @var{freekeys}] = } fits_getHdrSpace(@var{file})\n \
Get the number of keyword records used and available\n \
\n \
This is the equivalent of the cfitsio fits_get_hdrspace function.\n \
@end deftypefn")
{
  octave_value_list retval;  // create object to store return values

  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (args.length() != 1 || !args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int status = 0;
  int nexist, nmore;

  if (fits_get_hdrspace(fp, &nexist, &nmore, &status) > 0)
    {
      error ("fits_getHdrSpace: couldnt write checksum: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  retval(0) = octave_value(nexist);
  retval(1) = octave_value(nmore);

  return retval;
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! [numkeys, freekeys] = fits_getHdrSpace(fd);
%! assert(numkeys, 23);
%! assert(freekeys, 12);
%! fits_closeFile(fd);

%!error fits_getHdrSpace(1);
%!error fits_getHdrSpace([]);
#endif


// PKG_ADD: autoload ("fits_readRecord", "__fits__.oct");
DEFUN_DLD(fits_readRecord, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{rec} = } fits_readRecord(@var{file}, @var{recidx})\n \
Read the keyword record at @var{recidx}\n \
\n \
This is the equivalent of the cfitsio fits_read_record function.\n \
@end deftypefn")
{
  if ( args.length() != 2)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (! args (1).isnumeric () || args (1).isempty())
    {
      error ("fits_readRecord: idx should be a value");
      return octave_value ();  
    }
  int idx = args (1).int_value();

  int status = 0;
  char buffer[FLEN_CARD];

  if (fits_read_record(fp, idx, buffer, &status) > 0)
    {
      error ("fits_readRecord: couldnt read record: %s", get_fits_error(status).c_str());
      return octave_value ();
   }

  return octave_value(buffer);
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! rec = fits_readRecord(fd, 1);
%! assert(length(rec), 51);
%! rec = fits_readRecord(fd, 2);
%! assert(length(rec), 54);
%! fail ("fits_readRecord(fd);");
%! fits_closeFile(fd);

%!error fits_readRecord(1);
%!error fits_readRecord([]);
%!error fits_readRecord("");
#endif

// PKG_ADD: autoload ("fits_readCard", "__fits__.oct");
DEFUN_DLD(fits_readCard, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{card} = } fits_readCard(@var{file}, @var{recname})\n \
Read the keyword card for name @var{recname}\n \
\n \
This is the equivalent of the cfitsio fits_read_card function.\n \
@end deftypefn")
{
  if ( args.length() != 2)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (! args (1).is_string ())
    {
      error ("fits_readCard: key should be a string");
      return octave_value ();  
    }

  int status = 0;
  char buffer[FLEN_CARD+1];
  std::string key = args (1).string_value ();

  if (fits_read_card(fp, key.c_str(), buffer, &status) > 0)
    {
      error ("fits_readCard: couldnt read card: %s", get_fits_error(status).c_str());
      return octave_value ();
   }

  return octave_value(buffer);
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! rec = fits_readCard(fd, 'NAXIS');
%! assert(length(rec), 54);
%! fail ("fits_readCard(fd);");
%! fail ("fits_readCard(fd, 1);");
%! fits_closeFile(fd);

%!error fits_readCard(1);
%!error fits_readCard(1, "NAXIS");
%!error fits_readCard([]);
%!error fits_readCard("");
#endif

// PKG_ADD: autoload ("fits_readKey", "__fits__.oct");
DEFUN_DLD(fits_readKey, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{keyvalue}, @var{keycomment}] = } fits_readKey(@var{file}, @var{recname})\n \
Read the keyword value and comment for name @var{recname}\n \
\n \
This is the equivalent of the cfitsio fits_read_key_str function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() != 2)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (! args (1).is_string ())
    {
      error ("fits_readKey: key should be a string");
      return octave_value ();  
    }

  int status = 0;
  char vbuffer[FLEN_VALUE];
  char cbuffer[FLEN_VALUE];
  std::string key = args (1).string_value ();

  if (fits_read_key_str(fp, key.c_str(), vbuffer, cbuffer, &status) > 0)
    {
      error ("fits_readKey: couldnt read key: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  ret(0) = octave_value(vbuffer);
  ret(1) = octave_value(cbuffer);
  return ret;
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! [val, com] = fits_readKey(fd, 'NAXIS');
%! assert(val, "2");
%! assert(!isempty(com));
%! fail ("fits_readKey(fd);");
%! fail ("fits_readKey(fd, 1);");
%! fits_closeFile(fd);

%!error fits_readKey(1);
%!error fits_readKey(1, "NAXIS");
%!error fits_readKey([]);
%!error fits_readKey("");
#endif


// PKG_ADD: autoload ("fits_readKeyUnit", "__fits__.oct");
DEFUN_DLD(fits_readKeyUnit, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{keyunit} = } fits_readKeyUnit(@var{file}, @var{recname})\n \
Read the physical key units value @var{recname}\n \
\n \
This is the equivalent of the cfitsio fits_read_key_unit function.\n \
@end deftypefn")
{
  if ( args.length() != 2)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (! args (1).is_string ())
    {
      error ("fits_readKeyUnit: key should be a string");
      return octave_value ();  
    }

  int status = 0;
  char buffer[FLEN_VALUE];
  std::string key = args (1).string_value ();

  if (fits_read_key_unit(fp, key.c_str(), buffer, &status) > 0)
    {
      error ("fits_readKeyUnit: couldnt read key units: %s", get_fits_error(status).c_str());
      return octave_value ();
    }
  else
    {
	  buffer[0] = '\0';
    }

  return octave_value (buffer);
}

// PKG_ADD: autoload ("fits_readKeyDbl", "__fits__.oct");
DEFUN_DLD(fits_readKeyDbl, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{value}, @var{comment}] = } fits_readKeyDbl(@var{file}, @var{recname})\n \
Read the key value @var{recname} as a double\n \
\n \
This is the equivalent of the cfitsio fits_read_key_dbl function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() != 2)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (! args (1).is_string ())
    {
      error ("key should be a string");
      return octave_value ();  
    }

  int status = 0;

  char cbuffer[FLEN_VALUE];
  double val;

  std::string key = args (1).string_value ();

  if(fits_read_key_dbl(fp, key.c_str(), &val, cbuffer, &status) > 0)
  {
      error ("couldnt read key value: %s", get_fits_error(status).c_str());
      return octave_value ();
  }
  ret(0) = octave_value(val);
  ret(1) = octave_value(cbuffer);

  return ret;
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! [val, com] = fits_readKeyDbl(fd, 'NAXIS');
%! assert(val, 2);
%! assert(!isempty(com));
%! assert(class(val), 'double');
%! fail ("fits_readKeyDbl(fd);");
%! fail ("fits_readKeyDbl(fd, 1);");
%! fits_closeFile(fd);

%!error fits_readKeyDbl(1);
%!error fits_readKeyDbl(1, "NAXIS");
%!error fits_readKeyDbl([]);
%!error fits_readKeyDbl("");
#endif

// PKG_ADD: autoload ("fits_readKeyCmplx", "__fits__.oct");
DEFUN_DLD(fits_readKeyCmplx, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{value}, @var{comment}] = } fits_readKeyCmplx(@var{file}, @var{recname})\n \
Read the key value @var{recname} as a complex double\n \
\n \
This is the equivalent of the cfitsio fits_read_key_dblcmp function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() != 2)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (! args (1).is_string ())
    {
      error ("key should be a string");
      return octave_value ();  
    }

  int status = 0;
  char cbuffer[FLEN_VALUE];
  double val[2];
  std::string key = args (1).string_value ();

  if (fits_read_key_dblcmp(fp, key.c_str(), val, cbuffer, &status) > 0)
    {
      error ("fits_readKeyDblCpmlx: couldnt read key value: %s", get_fits_error(status).c_str());
      return octave_value ();
   }

  ret(0) = octave_value(Complex(val[0], val[1]));
  ret(1) = octave_value(cbuffer);

  return ret;
}

// PKG_ADD: autoload ("fits_readKeyLongLong", "__fits__.oct");
DEFUN_DLD(fits_readKeyLongLong, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{value}, @var{comment}] = } fits_readKeyLongLong(@var{file}, @var{recname})\n \
Read the key value @var{recname} as a long\n \
\n \
This is the equivalent of the cfitsio fits_read_key_lnglng function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() != 2)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (! args (1).is_string ())
    {
      error ("fits_readKeyLongLong: key should be a string");
      return octave_value ();  
    }

  int status = 0;
  char cbuffer[FLEN_VALUE];
  LONGLONG val;
  std::string key = args (1).string_value ();

  if (fits_read_key_lnglng(fp, key.c_str(), &val, cbuffer, &status) > 0)
    {
      error ("fits_readKeyLongLong: couldnt read key value: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  ret(0) = octave_value(octave_int64(val));
  ret(1) = octave_value(cbuffer);

  return ret;
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! [val, com] = fits_readKeyLongLong(fd, 'NAXIS');
%! assert(class(val), 'int64');
%! assert(val, int64(2));
%! assert(!isempty(com));
%! fail ("fits_readKeyLongLong(fd);");
%! fail ("fits_readKeyLongLong(fd, 1);");
%! fits_closeFile(fd);

%!error fits_readKeyLongLong(1);
%!error fits_readKeyLongLong(1, "NAXIS");
%!error fits_readKeyLongLong([]);
%!error fits_readKeyLongLong("");
#endif


// PKG_ADD: autoload ("fits_readKeyLongStr", "__fits__.oct");
DEFUN_DLD(fits_readKeyLongStr, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{value}, @var{comment}] = } fits_readKeyLongStr(@var{file}, @var{recname})\n \
Read the key value @var{recname} as a long\n \
\n \
This is the equivalent of the cfitsio fits_read_key_longstr function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() != 2)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (! args (1).is_string ())
    {
      error ("fits_readKeyLongStr: key should be a string");
      return octave_value ();  
    }

  int status = 0;
  char cbuffer[FLEN_VALUE];
  char * val;
  std::string key = args (1).string_value ();

  if (fits_read_key_longstr(fp, key.c_str(), &val, cbuffer, &status) > 0)
    {
      error ("fits_readKeyLongStr: couldnt read key: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  ret(0) = octave_value(val);
  ret(1) = octave_value(cbuffer);

  // free the key mem
  fits_free_memory(val, &status);

  return ret;
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! [val, com] = fits_readKeyLongStr(fd, 'NAXIS');
%! assert(class(val), 'char');
%! assert(val, '2');
%! assert(!isempty(com));
%! fail ("fits_readKeyLongStr(fd);");
%! fail ("fits_readKeyLongStr(fd, 1);");
%! fail ("fits_readKeyLongStr(fd, 'NOTKEY');");
%! fits_closeFile(fd);

%!error fits_readKeyLongStr(1);
%!error fits_readKeyLongStr(1, "NAXIS");
%!error fits_readKeyLongStr([]);
%!error fits_readKeyLongStr("");
#endif


// PKG_ADD: autoload ("fits_getConstantValue", "__fits__.oct");
DEFUN_DLD(fits_getConstantValue, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{value}]} = fits_getConstantValue(@var{name})\n \
Return the value of a known fits constant.\n \
@seealso {fits_getConstantNames}\n \
@end deftypefn")
{
  if (args.length() != 1)
    {
      error( "fits_getConstantName: expected constant name" );
      return octave_value();
    }
  if (args.length () != 1  || !args(0).is_string() )
    {
      error( "fits_getConstantName: constant name should be a string" );
      return octave_value();
    }

  std::string name = args(0).string_value();
  std::transform (name.begin(), name.end(), name.begin(), ::toupper);
  octave_value value;
  for (int i=i;i<sizeof(fits_constants)/sizeof(fits_constants_type);i++)
    {
      if(name == fits_constants[i].name)
        {
          value = fits_constants[i].value;
	  break;
        }
    }
  if (value.isempty ())
    {
      error ("fits_getConstantValue: Couldnt find constant '%s'", name.c_str());
    }
  return value;
}
#if 0
%!test
%! assert(fits_getVersion(), fits_getConstantValue("CFITSIO_VERSION"), 1e-07);
%! assert(fits_getConstantValue("IMAGE_HDU"), 0);
%! assert(fits_getConstantValue("ASCII_TBL"), 1);
%! assert(fits_getConstantValue("BINARY_TBL"), 2);
%! assert(fits_getConstantValue("ANY_HDU"), -1);

%!error <Couldnt find constant> fits_getConstantValue("UnkownVarName");
%!error <expected constant name> fits_getConstantValue();
%!error <constant name should be a string> fits_getConstantValue(1);
#endif

// PKG_ADD: autoload ("fits_getConstantNames", "__fits__.oct");
DEFUN_DLD(fits_getConstantNames, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{namelist}]} = fits_getConstantNames()\n \
Return the names of all known fits constants\n \
@seealso {fits_getConstantValue}\n \
@end deftypefn")
{
  if ( args.length() != 0)
    {
      print_usage ();
      return octave_value();
    }

  int cnt = sizeof(fits_constants)/sizeof(fits_constants_type);

  Cell namelist(1, cnt);

  for(int i=i; i<sizeof(fits_constants)/sizeof(fits_constants_type); i++)
    {
      namelist(0,i) = octave_value (fits_constants[i].name);
    }

  return octave_value (namelist);
}
#if 0
%!test
%! names = fits_getConstantNames();
%! assert(length(names) > 20);
#endif


// PKG_ADD: autoload ("fits_getVersion", "__fits__.oct");
DEFUN_DLD(fits_getVersion, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{ver}]} = fits_getVersion()\n \
Return the version number fo the cfitsio library used.\n \
\n \
This is the equivalent of the cfitsio fits_get_version function.\n \
@end deftypefn")
{
  if ( args.length() != 0)
    {
      print_usage ();
      return octave_value();
    }

  float ver;

  fits_get_version (&ver);

  return octave_value(ver);
}
#if 0
%!test
%! assert(fits_getVersion(), fits_getConstantValue("CFITSIO_VERSION"), 1e-5);
#endif


// PKG_ADD: autoload ("fits_getHDUoff", "__fits__.oct");
DEFUN_DLD(fits_getHDUoff, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{headtstart}, @var{datastart}, @var{dataend}]} = fits_getHDUoff(@var{file})\n \
Return offsets of the current HDU\n \
\n \
This is the equivalent of the cfitsio fits_get_hduoff function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int status = 0;
  OFF_T headstart, datastart, dataend;

  if(fits_get_hduoff(fp, &headstart, &datastart, &dataend, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("couldnt get offsets: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  ret(0) = octave_value(headstart);
  ret(1) = octave_value(datastart);
  ret(2) = octave_value(dataend);

  return ret;
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! assert(fits_getHDUoff(fd), 0);
%! fits_movAbsHDU(fd,1);
%! assert(fits_getHDUoff(fd), 0);
%! fits_movAbsHDU(fd,2);
%! assert(fits_getHDUoff(fd), 48960);
%! fits_movAbsHDU(fd,4);
%! assert(fits_getHDUoff(fd), 72000);
%! fits_closeFile(fd);

%!error fits_getHDUoff(1);
%!error fits_getHDUoff([]);
%!error fits_getHDUoff("");
#endif

// PKG_ADD: autoload ("fits_getImgSize", "__fits__.oct");
DEFUN_DLD(fits_getImgSize, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{size}} = fits_getImgSize(@var{file})\n \
Return size of a Image HDU\n \
\n \
This is the equivalent of the cfitsio fits_get_img_size function.\n \
@end deftypefn")
{
  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int status = 0;
  long axis[100];
  int naxis;

  if (fits_get_img_dim(fp, &naxis, &status) > 0)
    {
      error ("couldnt get dims: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  if (naxis > 100)
    naxis = 100;

  if(fits_get_img_size(fp, naxis, axis, &status) > 0)
    {
      error ("couldnt get size: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  // need swap first 2 axis 
  if (naxis > 1)
    {
      long tmp = axis[0];
      axis[0] = axis[1];
      axis[1] = tmp;
    }

  Matrix size(1, naxis);

  for (int i=0;i<naxis; i++)
    {
      size(0, i) = axis[i];
    }

  return octave_value(size);
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! type = fits_movAbsHDU(fd, 4);
%! assert(type, 'IMAGE_HDU');
%! assert (fits_getImgSize(fd), [31 73 5]);
%! assert(fits_movAbsHDU(fd, 3), "IMAGE_HDU");
%! assert (fits_getImgSize(fd), [41 17 1 1 1 1 1 1 1 1 1 1 2]);
%! fits_closeFile(fd);

%!error fits_getImgSize();
%!error fits_getImgSize(1);
%!error fits_getImgSize("");
%!error fits_getImgSize([]);
#endif


// PKG_ADD: autoload ("fits_getImgType", "__fits__.oct");
DEFUN_DLD(fits_getImgType, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{type}} = fits_getImgType(@var{file})\n \
Return size of a Image HDU\n \
\n \
This is the equivalent of the cfitsio fits_get_img_type function.\n \
@end deftypefn")
{
  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int status = 0;
  int type;

  if(fits_get_img_type(fp, &type, &status) > 0)
    {
      error ("couldnt get type: %s", get_fits_error(status).c_str());
      return octave_value ();
    }
  octave_value ret;

  switch (type)
    {
      case BYTE_IMG:
        ret = octave_value("BYTE_IMG");
        break;
      case SHORT_IMG:
        ret = octave_value("SHORT_IMG");
        break;
      case LONG_IMG:
        ret = octave_value("LONG_IMG");
        break;
      case LONGLONG_IMG:
        ret = octave_value("LONGLONG_IMG");
        break;
      case FLOAT_IMG:
        ret = octave_value("FLOAT_IMG");
        break;
      case DOUBLE_IMG:
        ret = octave_value("DOUBLE_IMG");
        break;
      default:
        ret = octave_value("UNKNOWN");
        break;
    }

  return ret;
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! assert(fits_movAbsHDU(fd, 4), "IMAGE_HDU");
%! assert (fits_getImgType(fd), "SHORT_IMG");
%! assert(fits_movAbsHDU(fd, 3), "IMAGE_HDU");
%! assert (fits_getImgType(fd), "BYTE_IMG");
%! fits_closeFile(fd);

%!error fits_getImgType();
%!error fits_getImgType(1);
%!error fits_getImgType("");
%!error fits_getImgType([]);
#endif

// PKG_ADD: autoload ("fits_readImg", "__fits__.oct");
DEFUN_DLD(fits_readImg, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{data}} = fits_readImg(@var{file})\n \
@deftypefnx {Function File} {@var{data}} = fits_readImg(@var{file}, @var{fisrtpix}, @var{lastpix})\n \
@deftypefnx {Function File} {@var{data}} = fits_readImg(@var{file}, @var{fisrtpix}, @var{lastpix}, @var{inc})\n \
Read Image data\n \
\n \
This is the equivalent of the cfitsio fits_read_subset function.\n \
@end deftypefn")
{
  if ( args.length() < 1)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int status = 0;

  int num_axis;
  long axis[100];
  if( fits_get_img_param( fp, 100, 0, &num_axis, axis, &status) > 0 )
  {
      fits_report_error( stderr, status );
      error ("fits_readImage: could not get image parameters: %s", get_fits_error(status).c_str());
      return octave_value();
  }

  int type;
  dim_vector dv(num_axis, 1);
  for(int i=0; i<num_axis;i++)
    dv(i) = axis[i];

  NDArray arr(dv);

  int datatype = TDOUBLE;
  long fpixel = 0;
  long lpixel = 0;
  double nulval = 0;
  long inc = 0;

  if(fits_read_subset(fp, datatype, &fpixel, &lpixel, &inc, &nulval, arr.fortran_vec(), 0, &status) > 0)
    {
      error ("couldnt get data: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return octave_value(arr);
}

// PKG_ADD: autoload ("fits_isCompressedImg", "__fits__.oct");
DEFUN_DLD(fits_isCompressedImg, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{data}} = fits_isCompressedImg(@var{file})\n \
Check if Image data is compressed and return true if it is\n \
\n \
This is the equivalent of the cfitsio fits_is_compressed_image function.\n \
@end deftypefn")
{
  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int status = 0;

  int c = fits_is_compressed_image(fp, &status);

  if(status)
    {
      error ("couldnt get compression: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return octave_value(c);
}

// PKG_ADD: autoload ("fits_getAColParms", "__fits__.oct");
DEFUN_DLD(fits_getAColParms, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{ttype},@var{tbcol},@var{tunit},@var{tform},@var{scale},@var{zero},@var{nulstr},@var{tdisp}]} = fits_getAColParms(@var{file}, @var{colnum})\n \
Get ASCII table paramaters\n \
\n \
This is the equivalent of the cfitsio  fits_get_acolparms function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() != 2)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (args.length () < 2
    || !args (1).isnumeric() || args (1).isempty())
    {
      error ("Expected numeric col number");
      return octave_value ();  
    }

  int status = 0;
  int colnum = args (1).int_value();
  double scale, zero;
  long tbcol;
  char ttype[FLEN_CARD];
  char tunit[FLEN_CARD];
  char tform[FLEN_CARD];
  char nullstr[FLEN_CARD];
  char tdisp[FLEN_CARD];

  if(fits_get_acolparms(fp, colnum, ttype, &tbcol, tunit, tform, &scale, &zero, nullstr, tdisp, &status) > 0)
    {
      error ("couldnt get parms: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  ret(0) = octave_value(ttype);
  ret(1) = octave_value(tbcol);
  ret(2) = octave_value(tunit);
  ret(3) = octave_value(tform);
  ret(4) = octave_value(scale);
  ret(5) = octave_value(zero);
  ret(6) = octave_value(nullstr);
  ret(7) = octave_value(tdisp);

  return ret;
}

// PKG_ADD: autoload ("fits_getBColParms", "__fits__.oct");
DEFUN_DLD(fits_getBColParms, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{ttype},@var{tunit},@var{typechar}@var{repeat},@var{scale},@var{zero},@var{nulval},@var{tdisp}]} = fits_getBColParms(@var{file}, @var{colnum})\n \
Get binary table paramaters\n \
\n \
This is the equivalent of the cfitsio  fits_get_bcolparms function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() != 2)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (args.length () < 2
    || !args (1).isnumeric() || args (1).isempty())
    {
      error ("Expected numeric col number");
      return octave_value ();  
    }

  int status = 0;
  int colnum = args (1).int_value();
  double scale, zero;
  long repeat, nullval;
  char ttype[FLEN_CARD];
  char tunit[FLEN_CARD];
  char typechar[FLEN_CARD];
  char tdisp[FLEN_CARD];

  if(fits_get_bcolparms(fp, colnum, ttype, tunit, typechar, &repeat, &scale, &zero, &nullval, tdisp, &status) > 0)
    {
      error ("couldnt get parms: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  ret(0) = octave_value(ttype);
  ret(1) = octave_value(tunit);
  ret(2) = octave_value(typechar);
  ret(3) = octave_value(repeat);
  ret(4) = octave_value(scale);
  ret(5) = octave_value(zero);
  if (nullval == NULL_UNDEFINED)
    ret(6) = Matrix(0,0);
  else
    ret(6) = octave_value(nullval);
  ret(7) = octave_value(tdisp);

  return ret;
}

// PKG_ADD: autoload ("fits_getColName", "__fits__.oct");
DEFUN_DLD(fits_getColName, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{colnum},@var{colname}]} = fits_getColName(@var{file}, @var{template}, @var{casesens})\n \
Get column type\n \
\n \
This is the equivalent of the cfitsio  fits_get_colname function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() < 2)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (args.length () < 2
    || !args (1).is_string())
    {
      error ("Expected string template");
      return octave_value ();  
    }

  std::string t = args(1).string_value ();
  int tlen = t.length()+1;
  char templatestr[tlen];
  strcpy(templatestr, t.c_str());

  int casesense = 0;
  if (args.length () > 2)
  {
    if( !args (2).islogical() && !args (2).isnumeric())
    {
      error ("Expected logical case sense");
      return octave_value ();  
    }
  else {
    casesense = args (2).int_value();
    }
  }

  int status = 0;

  int colnum;
  char colname[FLEN_CARD];

  if(fits_get_colname(fp, casesense, templatestr, colname, &colnum, &status) > 0 && status != COL_NOT_UNIQUE)
    {
      fits_report_error( stderr, status );
      error ("couldnt get column match: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  ret(0) = octave_value(colnum);
  ret(1) = octave_value(colname);

  return ret;
}


// PKG_ADD: autoload ("fits_getColType", "__fits__.oct");
DEFUN_DLD(fits_getColType, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{dtype},@var{repeat},@var{width}]} = fits_getColType(@var{file}, @var{colnum})\n \
Get column type\n \
\n \
This is the equivalent of the cfitsio  fits_get_coltypell function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() != 2)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (args.length () < 2
    || !args (1).isnumeric())
    {
      error ("Expected numeric col number");
      return octave_value ();  
    }

  int status = 0;
  int colnum = args (1).int_value();
  LONGLONG repeat, width;
  int dtype;

  if(fits_get_coltypell(fp, colnum, &dtype, &repeat, &width, &status) > 0)
    {
      error ("couldnt get parms: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  // TODO: should dtype be a string 
  ret(0) = octave_value(dtype);

  ret(1) = octave_value(repeat);
  ret(2) = octave_value(width);

  return ret;
}

// PKG_ADD: autoload ("fits_getEqColType", "__fits__.oct");
DEFUN_DLD(fits_getEqColType, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{dtype},@var{repeat},@var{width}]} = fits_getEqColType(@var{file}, @var{colnum})\n \
Get column type\n \
\n \
This is the equivalent of the cfitsio  fits_get_eqcoltypell function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() != 2)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (args.length () < 2
    || !args (1).isnumeric())
    {
      error ("Expected numeric col number");
      return octave_value ();  
    }

  int status = 0;
  int colnum = args (1).int_value();
  LONGLONG repeat, width;
  int dtype;

  if(fits_get_eqcoltypell(fp, colnum, &dtype, &repeat, &width, &status) > 0)
    {
      error ("couldnt get parms: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  // TODO: should dtype be a string 
  ret(0) = octave_value(dtype);

  ret(1) = octave_value(repeat);
  ret(2) = octave_value(width);

  return ret;
}

// PKG_ADD: autoload ("fits_getNumCols", "__fits__.oct");
DEFUN_DLD(fits_getNumCols, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{ncols}} = fits_getNumCols(@var{file})\n \
Get number of columns\n \
\n \
This is the equivalent of the cfitsio  fits_get_num_cols function.\n \
@end deftypefn")
{

  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int status = 0;
  int ncols;

  if(fits_get_num_cols(fp, &ncols, &status) > 0)
    {
      error ("couldnt get parms: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return octave_value(ncols);
}

// PKG_ADD: autoload ("fits_getNumRows", "__fits__.oct");
DEFUN_DLD(fits_getNumRows, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{nrows}} = fits_getNumRows(@var{file})\n \
Get number of rows\n \
\n \
This is the equivalent of the cfitsio  fits_get_numrowsll function.\n \
@end deftypefn")
{

  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int status = 0;
  LONGLONG nrows;

  if(fits_get_num_rowsll(fp, &nrows, &status) > 0)
    {
      error ("couldnt get parms: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return octave_value(nrows);
}

// PKG_ADD: autoload ("fits_getRowSize", "__fits__.oct");
DEFUN_DLD(fits_getRowSize, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{nrows}} = fits_getRowSize(@var{file})\n \
Get size of a row\n \
\n \
This is the equivalent of the cfitsio  fits_get_rowsize function.\n \
@end deftypefn")
{

  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int status = 0;
  long rowsize;

  if(fits_get_rowsize(fp, &rowsize, &status) > 0)
    {
      error ("couldnt get rowsize: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return octave_value(rowsize);
}

// PKG_ADD: autoload ("fits_readATblHdr", "__fits__.oct");
DEFUN_DLD(fits_readATblHdr, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{rowlen}, @var{nrows}, @var{ttype},@var{tbcol},@var{tform},@var{tunit},@var{extname}]} = fits_readATblHdr(@var{file})\n \
Get ASCII table parameters\n \
\n \
This is the equivalent of the cfitsio  fits_read_atablhdrll function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int status = 0;
  int ncols;
  if(fits_get_num_cols(fp, &ncols, &status) > 0)
    {
      error ("couldnt get cols: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  char ttypebuf[(ncols*FLEN_CARD)+1];
  char tformbuf[(ncols*FLEN_CARD)+1];
  char tunitbuf[(ncols*FLEN_CARD)+1];

  char extname[FLEN_CARD];
  int tfields = 0;
  char * ttype[ncols];
  char * tform[ncols];
  char * tunit[ncols];
  LONGLONG tbcol[ncols];
  LONGLONG rowlen, nrows;

  for (int i=0; i< ncols; i++)
    {
      ttype[i] = &ttypebuf[FLEN_CARD*i];
      tform[i] = &tformbuf[FLEN_CARD*i];
      tunit[i] = &tunitbuf[FLEN_CARD*i];
    }

  if(fits_read_atblhdrll(fp, ncols, &rowlen, &nrows, &tfields, ttype, tbcol, tform, tunit, extname, &status) > 0)
    {
      error ("couldnt get parms: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  Cell ttypev(1, tfields);
  Cell tformv(1, tfields);
  Cell tunitv(1, tfields);

  NDArray tbcolv(dim_vector(tfields, 1));

  for (int i=0; i< tfields; i++)
    {
      ttypev(i) = octave_value(std::string(ttype[i]));
      tformv(i) = octave_value(std::string(tform[i]));
      tunitv(i) = octave_value(std::string(tunit[i]));
      tbcolv(i) = tbcol[i];
    }

  ret(0) = octave_value(rowlen);
  ret(1) = octave_value(nrows);
  ret(2) = octave_value(ttypev);
  ret(3) = octave_value(tbcolv);
  ret(4) = octave_value(tformv);
  ret(5) = octave_value(tunitv);
  ret(6) = octave_value(extname);

  return ret;
}

// PKG_ADD: autoload ("fits_readBTblHdr", "__fits__.oct");
DEFUN_DLD(fits_readBTblHdr, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{nrows}, @var{ttype},@var{tform},@var{tunit},@var{extname}, @var{pcount}]} = fits_readBTblHdr(@var{file})\n \
Get Binary table parameters\n \
\n \
This is the equivalent of the cfitsio  fits_read_btablhdrll function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() != 1)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int status = 0;
  int ncols;
  if(fits_get_num_cols(fp, &ncols, &status) > 0)
    {
      error ("couldnt get cols: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  char ttypebuf[(ncols*FLEN_CARD)+1];
  char tformbuf[(ncols*FLEN_CARD)+1];
  char tunitbuf[(ncols*FLEN_CARD)+1];

  char extname[FLEN_CARD];
  int tfields = 0;
  char * ttype[ncols];
  char * tform[ncols];
  char * tunit[ncols];
  LONGLONG nrows, pcount;

  for (int i=0; i< ncols; i++)
    {
      ttype[i] = &ttypebuf[FLEN_CARD*i];
      tform[i] = &tformbuf[FLEN_CARD*i];
      tunit[i] = &tunitbuf[FLEN_CARD*i];
    }

  if(fits_read_btblhdrll(fp, ncols, &nrows, &tfields, ttype, tform, tunit, extname, &pcount, &status) > 0)
    {
      error ("couldnt get parms: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  Cell ttypev(1, tfields);
  Cell tformv(1, tfields);
  Cell tunitv(1, tfields);

  for (int i=0; i< tfields; i++)
    {
      ttypev(i) = octave_value(std::string(ttype[i]));
      tformv(i) = octave_value(std::string(tform[i]));
      tunitv(i) = octave_value(std::string(tunit[i]));
    }

  ret(0) = octave_value(nrows);
  ret(1) = octave_value(ttypev);
  ret(2) = octave_value(tformv);
  ret(3) = octave_value(tunitv);
  ret(4) = octave_value(extname);
  ret(5) = octave_value(pcount);

  return ret;
}

// PKG_ADD: autoload ("fits_readCol", "__fits__.oct");
DEFUN_DLD(fits_readCol, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{coldata}, @var{nullval}]} = fits_readCol(@var{file}, @var{colnum})\n \
@deftypefnx {Function File} {[@var{coldata}, @var{nullval}]} = fits_readCol(@var{file}, @var{colnum}, @var{firstrow}, @var{numrows})\n \
Get table row data\n \
\n \
This is the equivalent of the cfitsio  fits_read_col function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() < 2)
    {
      print_usage ();
      return octave_value();
    }

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp = get_fits_file (args(0).uint64_value());

  if(!fp)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (!args (1).isnumeric() || args (1).isempty())
    {
      error ("expected numeric col value");
      return octave_value ();  
    }

  int col = args(1).int_value();

  LONGLONG firstrow = 1;
  int status = 0;

  LONGLONG nrows;
  if(fits_get_num_rowsll(fp, &nrows, &status) > 0)
    {
      error ("couldnt get parms: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  if (args.length () > 2)
    {
      if (!args (2).isnumeric() || args (2).isempty())
        {
          error ("expected numeric startrow value");
          return octave_value ();  
        }
      firstrow = args(2).int64_value();
      if (firstrow < 1 || firstrow > nrows)
        {
          error ("start row is outside range of 1 .. %lld", nrows);
	  return octave_value ();
	}
      nrows = nrows - firstrow + 1;
    }

  if (args.length () > 3)
    {
      if (!args (3).isnumeric() || args (3).isempty())
        {
          error ("expected numeric numrows value");
          return octave_value ();  
        }
      LONGLONG rows = args(3).int64_value();
      if (rows < 1)
        {
          error ("numrow sis outside less than 1");
	  return octave_value ();
	}
      if (rows < nrows) nrows = rows;
    }

  // get data type to use,  width etc
  int dtype;
  LONGLONG repeat, width;
  if(fits_get_eqcoltypell(fp, col, &dtype, &repeat, &width, &status) > 0)
    {
      error ("couldnt get parms: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  if(dtype == TBYTE)
    {
      ret = read_numeric_row<uint8NDArray,uint8_t>(fp, col, dtype,firstrow, nrows, repeat);
    }
  else if(dtype == TSBYTE)
    {
      ret = read_numeric_row<int8NDArray,int8_t>(fp, col, dtype,firstrow, nrows, repeat);
    }
  else if(dtype == TSHORT)
    {
      ret = read_numeric_row<int16NDArray,int16_t>(fp, col, dtype,firstrow, nrows, repeat);
    }
  else if(dtype == TUSHORT)
    {
      ret = read_numeric_row<uint16NDArray,uint16_t>(fp, col, dtype,firstrow, nrows, repeat);
    }
  else if(dtype == TLONG)
    {
      ret = read_numeric_row<int32NDArray,int32_t>(fp, col, dtype,firstrow, nrows, repeat);
    }
  else if(dtype == TULONG)
    {
      ret = read_numeric_row<uint32NDArray,uint32_t>(fp, col, dtype,firstrow, nrows, repeat);
    }
  else if(dtype == TUINT)
    {
      ret = read_numeric_row<uint32NDArray,unsigned int>(fp, col, dtype,firstrow, nrows, repeat);
    }
  else if(dtype == TINT)
    {
      ret = read_numeric_row<int32NDArray,int>(fp, col, dtype,firstrow, nrows, repeat);
    }
  else if(dtype == TULONGLONG)
    {
      ret = read_numeric_row<uint64NDArray,uint64_t>(fp, col, dtype,firstrow, nrows, repeat);
    }
  else if(dtype == TLONGLONG)
    {
      ret = read_numeric_row<int64NDArray,int64_t>(fp, col, dtype,firstrow, nrows, repeat);
    }
  else if(dtype == TDOUBLE)
    {
      ret = read_numeric_row<NDArray,double>(fp, col, dtype,firstrow, nrows, repeat);
    }
  else if(dtype == TFLOAT)
    {
      ret = read_numeric_row<FloatNDArray,float>(fp, col, dtype,firstrow, nrows, repeat);
    }
  else if(dtype == TBIT)
    {
      ret = read_numeric_row<int8NDArray,int8_t>(fp, col, dtype,firstrow, nrows, repeat);
    }
  else
    {
      LONGLONG firstel = 1;

      char cdata[FLEN_CARD];
      char ndata[FLEN_CARD];
      char nullstr[] = "*";
      int anynul;
  
      string_vector rowdata;
      boolNDArray nuldata(dim_vector(nrows, repeat));

      for(LONGLONG i = 0;i<nrows;i++)
        {
          anynul = 0;
          char * text = cdata;
          char * nul = nullstr;
          if (fits_read_col(fp, TSTRING, col, firstrow+i, 1, 1, nul, &text, &anynul, &status) > 0)
            {
              error ("couldnt get data: %s", get_fits_error(status).c_str());
              return octave_value ();
            }
          rowdata.append(std::string(cdata));
	  for(LONGLONG r=0; r<repeat; r++)
            nuldata(i, r) = (anynul != 0);
        }

      ret(0) = rowdata;

      if (repeat == 1)
        ret(1) = nuldata.transpose();
      else
        ret(1) = nuldata;
    }

  return ret;
}
#if 0
%!test
%! fd = fits_openFile(testfile);
%! assert(!isempty(fd));
%! assert(fits_movAbsHDU(fd, 2), "BINARY_TBL");
%! [d,n] = fits_readCol(fd, 1);
%! assert(size(d), [11 9])
%! assert(size(n), [11 9])
%! [d,n] = fits_readCol(fd, 1, 11);
%! assert(size(d), [1 9])
%! assert(size(n), [1 9])
%! [d,n] = fits_readCol(fd, 1, 8, 2);
%! assert(size(d), [2 9])
%! assert(size(n), [2 9])
%!
%! [d,n] = fits_readCol(fd, 2);
%! assert(size(d), [11 13])
%! assert(size(n), [11 13])
%!
%! assert(fits_movAbsHDU(fd, 5), "ASCII_TBL");
%! [d,n] = fits_readCol(fd, 1);
%! assert(size(d), [53 9])
%! assert(size(n), [1 53])
%! [d,n] = fits_readCol(fd, 2);
%! assert(size(d), [53 1])
%! assert(size(n), [53 1])
%! fits_closeFile(fd);
#endif


#if 0
// NOTE: delete file shared at top of tests
%!test
%! if exist (testfile, 'file')
%!   delete (testfile);
%! endif
#endif
