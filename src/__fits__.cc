// Copyright (C) 2019-2022 John Donoghue <john.donoghue@ieee.org>
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

static std::string
coltype_to_string (int ct)
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

static int
string_to_coltype (const std::string &s)
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

static int
octave_to_type(const octave_value &value)
{
  if (value.is_string())
    {
      return TSTRING;
    }
  else if (value.islogical())
    {
      return TLOGICAL;
    }
  else if (value.is_uint8_type())
    {
      return TBYTE;
    }
  else if (value.is_int8_type())
    {
      return TSBYTE;
    }
  else if (value.is_uint16_type())
    {
      return TUSHORT;
    }
  else if (value.is_int16_type())
    {
      return TSHORT;
    }
  else if (value.is_uint32_type())
    {
      return TULONG;
    }
  else if (value.is_int32_type())
    {
      return TLONG;
    }
  else if (value.is_int64_type())
    {
      return  TLONGLONG;
    }
  else if (value.is_uint64_type())
    {
      return  TULONGLONG;
    }
  else if (value.isinteger())
    {
      return TINT;
    }
  else if (value.is_double_type())
    {
      return TDOUBLE;
    }
  else if (value.is_single_type())
    {
      return TFLOAT;
    }
  else
    {
       error ("couldnt convert this data type");
    }

  // unknown
  return 0;
}


static std::string
get_fits_error (int status)
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
static int write_numeric_row(fitsfile *fp, int col, int dtype, LONGLONG firstrow, const ATYPE &arr)
{
  DTYPE val;
  int status = 0;
  bool variable = false;

  // TODO: assume only 2 dims here ?
  
  LONGLONG nrows = arr.size(0);
  LONGLONG repeat = arr.size(1);

  int dxtype;
  LONGLONG width;
  if(fits_get_eqcoltypell(fp, col, &dxtype, &repeat, &width, &status) > 0)
    {
      error ("couldnt get col parms: %s", get_fits_error(status).c_str());
      return -1;
    }
  if(dxtype < 0) 
    {
      dxtype = -dxtype;
      variable = true;
    }

  nrows = arr.size(0);
  repeat = arr.size(1);
 
  for(LONGLONG i = 0; i<nrows; i++)
    {
      DTYPE * item = new DTYPE[repeat];
      for(LONGLONG r = 0;r<repeat; r++)
        {
          val = arr(i, r);
	  item[r] = val;
	  //octave_stdout << "(" << i << "," << r << ")=" << val << std::endl; 
	}

      if (fits_write_col(fp, dtype, col, i+firstrow, 1, repeat, item, &status) > 0)
        {
          error ("couldnt write data: %s", get_fits_error(status).c_str());
          return -1;
        }

      delete [] item;
    }

  return 0;
}

static int
write_text_row(fitsfile *fp, int col, int dtype, LONGLONG firstrow, const Array<std::string> &arr)
{
  LONGLONG nrows = arr.size(0);
  int status = 0;
  char nullval = '\0';

  for(LONGLONG i = 0; i<nrows; i++)
    {
      std::string value = arr(i);

      char buffer[value.length()+ 1];
      buffer[value.length()] = 0;

      strcpy(buffer, value.c_str());
      char * ptr[1];
      ptr[0] = buffer;

      if (fits_write_col(fp, TSTRING, col, firstrow+i, 1, 1, ptr, &status) > 0)
        {
          error ("couldnt write str: %s", get_fits_error(status).c_str());
          return -1;
        }
    }
  return 0;
}

template <class ATYPE, typename DTYPE>
static octave_value_list
read_numeric_row(fitsfile *fp, int col, int dtype, 
  LONGLONG firstrow, LONGLONG nrows, LONGLONG repeat, bool variable)
{
  DTYPE val;
  DTYPE nulval = 1;
  int anynul;
  int status = 0;
  long repeatrow = repeat;
  octave_value_list ret;

  if (variable)
    {
      long offset;
      Cell cresults = Cell(dim_vector(nrows, 1));
      Cell nresults = Cell(dim_vector(nrows, 1));

      for(LONGLONG i = 0; i<nrows; i++)
        {
          if (fits_read_descript(fp, col, i+firstrow, &repeatrow, &offset, &status) > 0)
            {
              error ("couldnt read descript %lld, %lld: %s", i+firstrow, 1, get_fits_error(status).c_str());
              return ret;
            }

          ATYPE arr(dim_vector(1,repeatrow));
          boolNDArray nuldata(dim_vector(1, repeatrow));

          if(repeatrow > 0)
            {
              // can we do single ones like elsewhere ?
              DTYPE * item = new DTYPE[repeatrow];
	      char * nulls = new char[repeatrow];
              anynul = 0;
              //if (fits_read_col(fp, dtype, col, i+firstrow, 1, repeatrow, &nulval, item, &anynul, &status) > 0)
              if (fits_read_colnull(fp, dtype, col, i+firstrow, 1, repeatrow, item, nulls, &anynul, &status) > 0)
                {
                  error ("couldnt read %d data %lld, %lld: %s", dtype, i+firstrow, 1, get_fits_error(status).c_str());
                  return ret;
                }
              for(LONGLONG r = 0;r<repeatrow; r++)
                {
                  val = item[r];
                  arr(0, r) = val;
                  //nuldata(0, r) = 0;
                  nuldata(0, r) = (nulls[r] == 1);
	        }
              delete [] item;
	      delete [] nulls;
            }
          cresults(i) = arr;
          nresults(i) = nuldata;
        }
      ret(0) = octave_value(cresults);
      ret(1) = octave_value(nresults);
    }
  else
    {
      // on 0 alloc 1 to store null
      if(repeat == 0) repeatrow = 1;
      ATYPE arr(dim_vector(nrows,repeatrow));
      boolNDArray nuldata(dim_vector(nrows, repeatrow));
      char nulls;

      for(LONGLONG i = 0; i<nrows; i++)
        {
          for(LONGLONG r = 0;r<repeat; r++)
            {
              anynul = 0;
              //if (fits_read_col(fp, dtype, col, i+firstrow, r+1, 1, &nulval, &val, &anynul, &status) > 0)
              if (fits_read_colnull(fp, dtype, col, i+firstrow, r+1, 1, &val, &nulls, &anynul, &status) > 0)
                {
                  error ("couldnt read %d data %lld, %lld: %s", dtype, i+firstrow, r+1, get_fits_error(status).c_str());
                  return ret;
                }

              if(anynul)
                arr(i, r) = 0;
              else
                arr(i, r) = val;

              nuldata(i, r) = (anynul != 0);
	    }
	  if (repeat == 0)
	    {
              arr(i, 0) = 0;
              nuldata(i, 0) = 1;
	    }
        }

      ret(0) = arr;
      ret(1) = nuldata;
    }

  return ret;
}

#define MAX_OPEN_FITS_FILES 20
#define FITS_FD_MASK ( (((uint64_t)'F') << 32) | (((uint64_t)'I') << 24) | (((uint64_t)'T') << 16) )
fitsfile * fits_files[MAX_OPEN_FITS_FILES] = {0};

static void
close_all_fits_files()
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

static int
get_free_fits_index()
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

static uint64_t
add_fits_file(fitsfile *fd)
{
  int idx = get_free_fits_index();
  if(idx >= 0)
    {
      fits_files[idx] = fd;
      return FITS_FD_MASK | (idx+1);
    }

  return 0;
}

static uint64_t
remove_fits_file(uint64_t fd)
{
  if ((fd & FITS_FD_MASK) != FITS_FD_MASK)
    return 0;

  uint64_t idx = (fd & ~FITS_FD_MASK);
  if (idx < 1 || idx > MAX_OPEN_FITS_FILES)
    return 0;

  fits_files[idx-1] = 0;
  return fd;
}

static fitsfile *
get_fits_file(uint64_t fd)
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
%! testfile = file_in_loadpath("demos/tst0012.fits");
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

// PKG_ADD: autoload ("__cfitsio_getOpenFiles__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getOpenFiles__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{files}]} = __cfitsio_getOpenFiles__()\n \
Internal fits function.\n \
\n\
Get the file handles of all open fits files.\n \
\n \
@seealso {__cfitsio_openFile__}\n \
@end deftypefn")
{
  if ( args.length() != 0)
    {
      error ("Unexpected inputs to function.");
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
%! assert(isempty(__cfitsio_getOpenFiles__()));
%! fd = __cfitsio_openFile__(testfile);
%! of = __cfitsio_getOpenFiles__();
%! assert(!isempty(of));
%! assert(fd, of);
%! __cfitsio_closeFile__(fd);
%! of = __cfitsio_getOpenFiles__();
%! assert(isempty(of));

%!error __cfitsio_getOpenFiles__(1);
#endif


// PKG_ADD: autoload ("__cfitsio_createFile__", "__fits__.oct");
DEFUN_DLD(__cfitsio_createFile__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{file}]} = __cfitsio_createFile__(@var{filename})\n \
Internal fits function.\n \
\n \
Attempt to create  a file of the given input name.\n \
\n \
If the filename starts with ! and the file exists, it will create a new file, otherwise, if the\n \
file exists, the create will fail.\n \
\n \
This is the equivilent of the cfitsio fits_create_file funtion.\n \
@seealso {__cfitsio_openFile__}\n \
@end deftypefn")
{
  if ( args.length() == 0)
    {
      error( "createFile: expected filename (string)" );
      return octave_value();
    }
  if ( args.length() != 1 || !args(0).is_string() )
    {
      error( "createFile: filename (string) expected as only argument" );
      return octave_value();
    }

  std::string infile = args(0).string_value ();

  if (get_free_fits_index () < 0)
    {
      error ("createFile: Out of space for new open file");
      return octave_value ();
    }

  int status = 0;
  fitsfile *fp;

  if ( fits_create_file( &fp, infile.c_str(), &status) > 0 )
    {
      error ("createFile: Couldnt create file: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  uint64_t fd = add_fits_file(fp);

  return octave_value(octave_uint64 (fd));
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! data = int16(zeros(10,10));
%! __cfitsio_createImg__(fd,class(data), size(data));
%! __cfitsio_writeImg__(fd,data);
%! __cfitsio_closeFile__(fd);
%! fail("__cfitsio_createFile__(filename)");
%! fd = __cfitsio_createFile__(["!" filename]);
%! __cfitsio_createImg__(fd,class(data), size(data));
%! __cfitsio_writeImg__(fd,data);
%! __cfitsio_closeFile__(fd);
%! delete(filename);
#endif

// PKG_ADD: autoload ("__cfitsio_openFile__", "__fits__.oct");
DEFUN_DLD(__cfitsio_openFile__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{file}]} = __cfitsio_openFile__(@var{filename})\n \
@deftypefnx {Function File} {[@var{file}]} = __cfitsio_openFile__(@var{filename}, @var{mode})\n \
Attempt to open a file of the given input name.\n \
\n \
If the opion mode string 'READONLY' (default) or 'READWRITE' is provided, open the file using that mode.\n \
\n \
This is the equivilent of the cfitsio fits_open_file funtion.\n \
@seealso {__cfitsio_openDiskFile__, __cfitsio_createFile__}\n \
@end deftypefn")
{
  if ( args.length() != 1 && args.length () != 2)
    {
      print_usage ();
      return octave_value ();
    }
  if ( !args(0).is_string() )
    {
      error( "__cfitsio_openFile__: expected filename as a string" );
      return octave_value ();
    }

  int mode = READONLY;

  if(args.length() == 2)
    {
      if ( !args(1).is_string() )
        {
          error( "__cfitsio_openFile__: expected mode as a string" );
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
          error( "__cfitsio_openFile__:: unknown file mode" );
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
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! __cfitsio_closeFile__(fd);

%!test
%! fd = __cfitsio_openFile__(testfile, "readonly");
%! assert(!isempty(fd));
%! __cfitsio_closeFile__(fd);

%!error <expected filename as a string> __cfitsio_openFile__(1);
%!error <expected filename as a string> __cfitsio_openFile__([]);

%!error <expected mode as a string> __cfitsio_openFile__(testfile, 1);
%!error <unknown file mode> __cfitsio_openFile__(testfile, "badmode");
#endif


// PKG_ADD: autoload ("__cfitsio_openDiskFile__", "__fits__.oct");
DEFUN_DLD(__cfitsio_openDiskFile__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{file}]} = __cfitsio_openDiskFile__(@var{filename})\n \
@deftypefnx {Function File} {[@var{file}]} = __cfitsio_openDiskFile__(@var{filename}, @var{mode})\n \
Attempt to open a file of the given input name, ignoring any special processing of the filename.\n \
\n \
If the option mode string 'READONLY' (default) or 'READWRITE' is provided, open the file using that mode.\n \
\n \
This is the equivilent of the cfitsio fits_open_diskfile funtion.\n \
@seealso {__cfitsio_openFile__, __cfitsio_createFile__}\n \
@end deftypefn")
{
  if ( args.length() != 1 && args.length () != 2)
    {
      print_usage ();
      return octave_value();
    }
  if ( !args(0).is_string() )
    {
      error( "__cfitsio_openDiskFile__: expected filename as a string" );
      return octave_value();
    }

  int mode = READONLY;

  if(args.length() == 2)
    {
      if ( !args(1).is_string() )
        {
          error ( "openDiskFile: expected mode as a string" );
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
          error( "openDiskFile: unknown file mode" );
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

// PKG_ADD: autoload ("__cfitsio_fileMode__", "__fits__.oct");
DEFUN_DLD(__cfitsio_fileMode__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{mode}} = __cfitsio_fileMode__(@var{file})\n \
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
      error ("__cfitsio_fileMode__: couldnt read file mode: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  std::string modestr = "READONLY";
  if(mode == READWRITE)
    modestr = "READWRITE";

  return octave_value (modestr);
}
#if 0
%!test
%! fd = __cfitsio_openFile__(testfile, "readonly");
%! assert(!isempty(fd));
%! assert(__cfitsio_fileMode__(fd), "READONLY")
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_fileMode__(1);
%!error __cfitsio_fileMode__([]);
#endif


// PKG_ADD: autoload ("__cfitsio_fileName__", "__fits__.oct");
DEFUN_DLD(__cfitsio_fileName__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{name}} = __cfitsio_fileName__(@var{file})\n \
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
      error ("__cfitsio_fileName__: couldnt read file name: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return octave_value (filename);
}
#if 0
%!test
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! assert(__cfitsio_fileName__(fd), testfile)
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_fileName__(1);
%!error __cfitsio_fileName__([]);
#endif

// PKG_ADD: autoload ("__cfitsio_closeFile__", "__fits__.oct");
DEFUN_DLD(__cfitsio_closeFile__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_closeFile__(@var{file})\n \
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
%! fd = __cfitsio_openFile__(testfile);
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_closeFile__();
%!error __cfitsio_closeFile__(1);
%!error __cfitsio_closeFile__([]);
#endif


// PKG_ADD: autoload ("__cfitsio_deleteFile__", "__fits__.oct");
DEFUN_DLD(__cfitsio_deleteFile__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_deleteFile__(@var{file})\n \
Force a close and delete of a fits file.\n \
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
%! fd = __cfitsio_openFile__(tmp);
%! __cfitsio_deleteFile__(fd);
%! assert(exist(tmp, "file"), 0);

%!error __cfitsio_deleteFile__();
%!error __cfitsio_deleteFile__(1);
%!error __cfitsio_deleteFile__("");
%!error __cfitsio_deleteFile__([]);
#endif


// PKG_ADD: autoload ("__cfitsio_getHDUnum__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getHDUnum__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{num}]} = __cfitsio_getHDUnum__(@var{file})\n \
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
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! assert(__cfitsio_getHDUnum__(fd), 1);
%! __cfitsio_movAbsHDU__(fd, 1);
%! assert(__cfitsio_getHDUnum__(fd), 1);
%! __cfitsio_movAbsHDU__(fd, 2);
%! assert(__cfitsio_getHDUnum__(fd), 2);
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_getHDUnum__(1);
%!error __cfitsio_getHDUnum__([]);
#endif


// PKG_ADD: autoload ("__cfitsio_getHDUtype__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getHDUtype__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{type}]} = __cfitsio_getHDUtype__(@var{file})\n \
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
      error ("__cfitsio_getHDUtype__: couldnt get hdu type : %s", get_fits_error(status).c_str());
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
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! assert(__cfitsio_getHDUtype__(fd), "IMAGE_HDU");
%! type = __cfitsio_movAbsHDU__(fd, 2);
%! assert(__cfitsio_getHDUtype__(fd), type);
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_getHDUtype__(1);
%!error __cfitsio_getHDUtype__([]);
#endif


// PKG_ADD: autoload ("__cfitsio_getNumHDUs__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getNumHDUs__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{num}]} = __cfitsio_getNumHDUs__(@var{file})\n \
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
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! assert(__cfitsio_getNumHDUs__(fd), 5);
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_getNumHDUs__(1);
%!error __cfitsio_getNumHDUs__([]);
#endif

// PKG_ADD: autoload ("__cfitsio_movAbsHDU__", "__fits__.oct");
DEFUN_DLD(__cfitsio_movAbsHDU__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{type}]} = __cfitsio_movAbsHDU__(@var{file}, @var{hdunum})\n \
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
      error ("__cfitsio_movAbsHDU__: expected hdu number");
      return octave_value ();  
    }

  int hdu = args(1).int_value();

  int status = 0, hdutype;

  if(fits_movabs_hdu(fp, hdu, &hdutype,&status) > 0)
    {
      error ("__cfitsio_movAbsHDU__: couldnt move hdus: %s", get_fits_error(status).c_str());
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
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! type = __cfitsio_movAbsHDU__(fd, 1);
%! assert(__cfitsio_getHDUtype__(fd), type);
%! assert(__cfitsio_getHDUnum__(fd), 1);
%! type = __cfitsio_movAbsHDU__(fd, 2);
%! assert(__cfitsio_getHDUtype__(fd), type);
%! assert(__cfitsio_getHDUnum__(fd), 2);
%! type = __cfitsio_movAbsHDU__(fd, 3);
%! assert(__cfitsio_getHDUtype__(fd), type);
%! assert(__cfitsio_getHDUnum__(fd), 3);
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_movAbsHDU__(1);
%!error __cfitsio_movAbsHDU__([]);
#endif


// PKG_ADD: autoload ("__cfitsio_movRelHDU__", "__fits__.oct");
DEFUN_DLD(__cfitsio_movRelHDU__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{type}]} = __cfitsio_movRelHDU__(@var{file}, @var{hdunum})\n \
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
      error ("__cfitsio_movRelHDU__: expected hdu number");
      return octave_value ();  
    }

  int hdu = args(1).int_value();

  int status = 0, hdutype;

  if(fits_movrel_hdu(fp, hdu, &hdutype,&status) > 0)
    {
      error ("__cfitsio_movRelHDU__: couldnt move hdus: %s", get_fits_error(status).c_str());
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
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! type = __cfitsio_movAbsHDU__(fd, 1);
%! assert(__cfitsio_getHDUnum__(fd), 1);
%! type = __cfitsio_movRelHDU__(fd, 1);
%! assert(__cfitsio_getHDUtype__(fd), type);
%! assert(__cfitsio_getHDUnum__(fd), 2);
%! type = __cfitsio_movRelHDU__(fd, -1);
%! assert(__cfitsio_getHDUtype__(fd), type);
%! assert(__cfitsio_getHDUnum__(fd), 1);
%! fail ("__cfitsio_movRelHDU__(fd, [])");
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_movRelHDU__(1);
%!error __cfitsio_movRelHDU__([]);
#endif


// PKG_ADD: autoload ("__cfitsio_movNamHDU__", "__fits__.oct");
DEFUN_DLD(__cfitsio_movNamHDU__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} __cfitsio_movNamHDU__(@var{file}, @var{hdutype}, @var{extname}, @var{extver})\n \
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
      error ("__cfitsio_movNamHDU__: expected hdu type string");
      return octave_value ();  
    }
  if (! args (2).is_string ())
    {
      error ("__cfitsio_movNamHDU__: expected extname string");
      return octave_value ();  
    }

  if (! args (3).isnumeric () || args (3).isempty())
    {
      error ("__cfitsio_movNamHDU__: expected extver number");
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
      error ("__cfitsio_movNamHDU__: couldnt move hdus: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return octave_value ();
}
#if 0
%!test
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! __cfitsio_movNamHDU__(fd, 'IMAGE_HDU', 'quality', 1);
%! assert(__cfitsio_getHDUnum__(fd), 4);
%! assert(__cfitsio_getHDUtype__(fd), 'IMAGE_HDU');
%! __cfitsio_movNamHDU__(fd, 'BINARY_TBL', 'BinTest', 0);
%! assert(__cfitsio_getHDUnum__(fd), 2);
%! assert(__cfitsio_getHDUtype__(fd), 'BINARY_TBL');
%! __cfitsio_movNamHDU__(fd, 'ANY_HDU', 'Unknown', 1);
%! assert(__cfitsio_getHDUnum__(fd), 3);
%! fail ("__cfitsio_movNamHDU__(fd, 'INVALID_HDU', '', 0);");
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_movNamHDU__(1);
%!error __cfitsio_movNamHDU__([]);
#endif


// PKG_ADD: autoload ("__cfitsio_deleteHDU__", "__fits__.oct");
DEFUN_DLD(__cfitsio_deleteHDU__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{type}]} = __cfitsio_deleteHDU__(@var{file})\n \
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
      error ("__cfitsio_deleteHDU__: couldnt delete hdu: %s", get_fits_error(status).c_str());
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

// PKG_ADD: autoload ("__cfitsio_copyHDU__", "__fits__.oct");
DEFUN_DLD(__cfitsio_copyHDU__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_copyHDU__(@var{infile}, @var{outfile})\n \
Copy current HDU from one infile to another.\n \
\n \
This is the equivalent of the cfitsio fits_copy_hdu function.\n \
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

  fitsfile * fp1 = get_fits_file (args(0).uint64_value());

  if(!fp1)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (!args (1).isinteger()  || !args(1).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp2 = get_fits_file (args(1).uint64_value());

  if(!fp2)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int status = 0;

  if(fits_copy_hdu(fp1, fp2, 0, &status) > 0)
    {
      error ("__cfitsio_copyHDU__: couldnt copy hdu: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename1 = tempname();
%! filename2 = tempname();
%! fd1 = __cfitsio_createFile__(filename1);
%! __cfitsio_createImg__(fd1,'int16',[256 512]);
%! __cfitsio_closeFile__(fd1);
%!
%! fd1 = __cfitsio_openFile__(filename1);
%!
%! fd2 = __cfitsio_createFile__(filename2);
%! __cfitsio_copyHDU__(fd1,fd2);
%! __cfitsio_closeFile__(fd1);
%! __cfitsio_closeFile__(fd2);
%!
%! delete (filename1);
%! delete (filename2);
#endif

// PKG_ADD: autoload ("__cfitsio_writeChecksum__", "__fits__.oct");
DEFUN_DLD(__cfitsio_writeChecksum__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_writeChecksum__(@var{file})\n \
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
      error ("__cfitsio_writeChecksum__: couldnt write checksum: %s", get_fits_error(status).c_str());
      return octave_value ();
   }

  return octave_value ();
}

// PKG_ADD: autoload ("__cfitsio_getHdrSpace__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getHdrSpace__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{numkeys}, @var{freekeys}] = } __cfitsio_getHdrSpace__(@var{file})\n \
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
      error ("__cfitsio_getHdrSpace__: couldnt write checksum: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  retval(0) = octave_value(nexist);
  retval(1) = octave_value(nmore);

  return retval;
}
#if 0
%!test
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! [numkeys, freekeys] = __cfitsio_getHdrSpace__(fd);
%! assert(numkeys, 23);
%! assert(freekeys, 12);
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_getHdrSpace__(1);
%!error __cfitsio_getHdrSpace__([]);
#endif


// PKG_ADD: autoload ("__cfitsio_readRecord__", "__fits__.oct");
DEFUN_DLD(__cfitsio_readRecord__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{rec} = } __cfitsio_readRecord__(@var{file}, @var{recidx})\n \
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
      error ("__cfitsio_readRecord__: idx should be a value");
      return octave_value ();  
    }
  int idx = args (1).int_value();

  int status = 0;
  char buffer[FLEN_CARD];

  if (fits_read_record(fp, idx, buffer, &status) > 0)
    {
      error ("__cfitsio_readRecord__: couldnt read record: %s", get_fits_error(status).c_str());
      return octave_value ();
   }

  return octave_value(buffer);
}
#if 0
%!test
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! rec = __cfitsio_readRecord__(fd, 1);
%! assert(length(rec), 51);
%! rec = __cfitsio_readRecord__(fd, 2);
%! assert(length(rec), 54);
%! fail ("__cfitsio_readRecord__(fd);");
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_readRecord__(1);
%!error __cfitsio_readRecord__([]);
%!error __cfitsio_readRecord__("");
#endif

// PKG_ADD: autoload ("__cfitsio_deleteRecord__", "__fits__.oct");
DEFUN_DLD(__cfitsio_deleteRecord__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_deleteRecord__(@var{file}, @var{keynum})\n \
Delete a key in the fits file.\n \
\n \
This is the equivalent of the cfitsio fits_delete_record function.\n \
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

  if (!args (0).isinteger()  || !args(0).is_real_scalar())
    {
      error ("__cfitsio_deleteRecord__: keynum should be a integer");
      return octave_value ();  
    }

  int keynum = args (1).int_value ();

  int status = 0;
  if (fits_delete_record(fp, keynum, &status) > 0)
    {
      error ("__cfitsio_deleteRecord__: couldnt delete key: %s", get_fits_error(status).c_str());
      return octave_value ();
    }
  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! assert(!isempty(fd));
%! __cfitsio_createImg__(fd,'int16',[10 20]);
%! __cfitsio_writeDate__(fd);
%! __cfitsio_closeFile__(fd);
%!
%! fd = __cfitsio_openFile__(filename, 'readwrite');
%! # date record
%! card = __cfitsio_readRecord__(fd,9);
%! __cfitsio_deleteRecord__(fd,9);
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_readCard__", "__fits__.oct");
DEFUN_DLD(__cfitsio_readCard__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{card} = } __cfitsio_readCard__(@var{file}, @var{recname})\n \
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
      error ("__cfitsio_readCard__: key should be a string");
      return octave_value ();  
    }

  int status = 0;
  char buffer[FLEN_CARD+1];
  std::string key = args (1).string_value ();

  if (fits_read_card(fp, key.c_str(), buffer, &status) > 0)
    {
      error ("__cfitsio_readCard__: couldnt read card: %s", get_fits_error(status).c_str());
      return octave_value ();
   }

  return octave_value(buffer);
}
#if 0
%!test
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! rec = __cfitsio_readCard__(fd, 'NAXIS');
%! assert(length(rec), 54);
%! fail ("__cfitsio_readCard__(fd);");
%! fail ("__cfitsio_readCard__(fd, 1);");
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_readCard__(1);
%!error __cfitsio_readCard__(1, "NAXIS");
%!error __cfitsio_readCard__([]);
%!error __cfitsio_readCard__("");
#endif

// PKG_ADD: autoload ("__cfitsio_readKey__", "__fits__.oct");
DEFUN_DLD(__cfitsio_readKey__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{keyvalue}, @var{keycomment}] = } __cfitsio_readKey__(@var{file}, @var{recname})\n \
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
      error ("__cfitsio_readKey__: key should be a string");
      return octave_value ();  
    }

  int status = 0;
  char vbuffer[FLEN_VALUE];
  char cbuffer[FLEN_VALUE];
  std::string key = args (1).string_value ();

  if (fits_read_key_str(fp, key.c_str(), vbuffer, cbuffer, &status) > 0)
    {
      error ("__cfitsio_readKey__: couldnt read key: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  ret(0) = octave_value(vbuffer);
  ret(1) = octave_value(cbuffer);
  return ret;
}
#if 0
%!test
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! [val, com] = __cfitsio_readKey__(fd, 'NAXIS');
%! assert(val, "2");
%! assert(!isempty(com));
%! fail ("__cfitsio_readKey__(fd);");
%! fail ("__cfitsio_readKey__(fd, 1);");
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_readKey__(1);
%!error __cfitsio_readKey__(1, "NAXIS");
%!error __cfitsio_readKey__([]);
%!error __cfitsio_readKey__("");
#endif


// PKG_ADD: autoload ("__cfitsio_readKeyUnit__", "__fits__.oct");
DEFUN_DLD(__cfitsio_readKeyUnit__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{keyunit} = } __cfitsio_readKeyUnit__(@var{file}, @var{recname})\n \
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
      error ("__cfitsio_readKeyUnit__: key should be a string");
      return octave_value ();  
    }

  int status = 0;
  char buffer[FLEN_VALUE];
  std::string key = args (1).string_value ();

  if (fits_read_key_unit(fp, key.c_str(), buffer, &status) > 0)
    {
      error ("__cfitsio_readKeyUnit__: couldnt read key units: %s", get_fits_error(status).c_str());
      return octave_value ();
    }
  else
    {
	  buffer[0] = '\0';
    }

  return octave_value (buffer);
}

// PKG_ADD: autoload ("__cfitsio_readKeyDbl__", "__fits__.oct");
DEFUN_DLD(__cfitsio_readKeyDbl__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{value}, @var{comment}] = } __cfitsio_readKeyDbl__(@var{file}, @var{recname})\n \
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
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! [val, com] = __cfitsio_readKeyDbl__(fd, 'NAXIS');
%! assert(val, 2);
%! assert(!isempty(com));
%! assert(class(val), 'double');
%! fail ("__cfitsio_readKeyDbl__(fd);");
%! fail ("__cfitsio_readKeyDbl__(fd, 1);");
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_readKeyDbl__(1);
%!error __cfitsio_readKeyDbl__(1, "NAXIS");
%!error __cfitsio_readKeyDbl__([]);
%!error __cfitsio_readKeyDbl__("");
#endif

// PKG_ADD: autoload ("__cfitsio_readKeyCmplx__", "__fits__.oct");
DEFUN_DLD(__cfitsio_readKeyCmplx__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{value}, @var{comment}] = } __cfitsio_readKeyCmplx__(@var{file}, @var{recname})\n \
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
      error ("__cfitsio_readKeyCmplx__: couldnt read key value: %s", get_fits_error(status).c_str());
      return octave_value ();
   }

  ret(0) = octave_value(Complex(val[0], val[1]));
  ret(1) = octave_value(cbuffer);

  return ret;
}

// PKG_ADD: autoload ("__cfitsio_readKeyLongLong__", "__fits__.oct");
DEFUN_DLD(__cfitsio_readKeyLongLong__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{value}, @var{comment}] = } __cfitsio_readKeyLongLong__(@var{file}, @var{recname})\n \
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
      error ("__cfitsio_readKeyLongLong__: key should be a string");
      return octave_value ();  
    }

  int status = 0;
  char cbuffer[FLEN_VALUE];
  LONGLONG val;
  std::string key = args (1).string_value ();

  if (fits_read_key_lnglng(fp, key.c_str(), &val, cbuffer, &status) > 0)
    {
      error ("__cfitsio_readKeyLongLong__: couldnt read key value: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  ret(0) = octave_value(octave_int64(val));
  ret(1) = octave_value(cbuffer);

  return ret;
}
#if 0
%!test
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! [val, com] = __cfitsio_readKeyLongLong__(fd, 'NAXIS');
%! assert(class(val), 'int64');
%! assert(val, int64(2));
%! assert(!isempty(com));
%! fail ("__cfitsio_readKeyLongLong__(fd);");
%! fail ("__cfitsio_readKeyLongLong__(fd, 1);");
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_readKeyLongLong__(1);
%!error __cfitsio_readKeyLongLong__(1, "NAXIS");
%!error __cfitsio_readKeyLongLong__([]);
%!error __cfitsio_readKeyLongLong__("");
#endif


// PKG_ADD: autoload ("__cfitsio_readKeyLongStr__", "__fits__.oct");
DEFUN_DLD(__cfitsio_readKeyLongStr__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{value}, @var{comment}] = } __cfitsio_readKeyLongStr__(@var{file}, @var{recname})\n \
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
      error ("__cfitsio_readKeyLongStr__: key should be a string");
      return octave_value ();  
    }

  int status = 0;
  char cbuffer[FLEN_VALUE];
  char * val;
  std::string key = args (1).string_value ();

  if (fits_read_key_longstr(fp, key.c_str(), &val, cbuffer, &status) > 0)
    {
      error ("__cfitsio_readKeyLongStr__: couldnt read key: %s", get_fits_error(status).c_str());
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
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! [val, com] = __cfitsio_readKeyLongStr__(fd, 'NAXIS');
%! assert(class(val), 'char');
%! assert(val, '2');
%! assert(!isempty(com));
%! fail ("__cfitsio_readKeyLongStr__(fd);");
%! fail ("__cfitsio_readKeyLongStr__(fd, 1);");
%! fail ("__cfitsio_readKeyLongStr__(fd, 'NOTKEY');");
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_readKeyLongStr__(1);
%!error __cfitsio_readKeyLongStr__(1, "NAXIS");
%!error __cfitsio_readKeyLongStr__([]);
%!error __cfitsio_readKeyLongStr__("");
#endif

// PKG_ADD: autoload ("__cfitsio_writeDate__", "__fits__.oct");
DEFUN_DLD(__cfitsio_writeDate__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_writeDate__(@var{file})\n \
Write the date keyword.\n \
\n \
This is the equivalent of the cfitsio fits_write_date function.\n \
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
  if (fits_write_date(fp, &status) > 0)
    {
      error ("__cfitsio_writeDate__: couldnt write date: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! assert(!isempty(fd));
%! __cfitsio_createImg__(fd,'int16',[10 20]);
%! __cfitsio_writeDate__(fd);
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_writeComment__", "__fits__.oct");
DEFUN_DLD(__cfitsio_writeComment__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_writeComment__(@var{file}, @var{comment})\n \
Append a comment to to the fits file.\n \
\n \
This is the equivalent of the cfitsio fits_write_comment function.\n \
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
      error ("__cfitsio_writeComment__: comment should be a string");
      return octave_value ();  
    }

  int status = 0;
  std::string comment = args (1).string_value ();

  if (fits_write_comment(fp, comment.c_str(), &status) > 0)
    {
      error ("__cfitsio_writeComment__: couldnt write comment: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! assert(!isempty(fd));
%! __cfitsio_createImg__(fd,'int16',[10 20]);
%! __cfitsio_writeComment__(fd, 'A comment');
%! __cfitsio_closeFile__(fd);
%! delete (filename);

%!error __cfitsio_writeComment__(1);
%!error __cfitsio_writeComment__(1, "comment");
%!error __cfitsio_writeComment__([]);
%!error __cfitsio_writeComment__("");
#endif

// PKG_ADD: autoload ("__cfitsio_writeHistory__", "__fits__.oct");
DEFUN_DLD(__cfitsio_writeHistory__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_writeHistory__(@var{file}, @var{history})\n \
Append a history to to the fits file.\n \
\n \
This is the equivalent of the cfitsio fits_write_history function.\n \
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
      error ("__cfitsio_writeHistory__: history should be a string");
      return octave_value ();  
    }

  int status = 0;
  std::string history = args (1).string_value ();

  if (fits_write_history(fp, history.c_str(), &status) > 0)
    {
      error ("__cfitsio_writeHistory__: couldnt write history: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! assert(!isempty(fd));
%! __cfitsio_createImg__(fd,'int16',[10 20]);
%! __cfitsio_writeHistory__(fd, 'history');
%! __cfitsio_closeFile__(fd);
%! delete (filename);

%!error __cfitsio_writeHistory__(1);
%!error __cfitsio_writeHistory__(1, "history");
%!error __cfitsio_writeHistory__([]);
%!error __cfitsio_writeHistory__("");
#endif

// PKG_ADD: autoload ("__cfitsio_writeKeyUnit__", "__fits__.oct");
DEFUN_DLD(__cfitsio_writeKeyUnit__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_writeKeyUnit__(@var{file}, @var{key}, @var{unit})\n \
Write a key unit to the fits file.\n \
\n \
This is the equivalent of the cfitsio fits_write_key_unit function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() != 3)
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
      error ("__cfitsio_writeKeyUnit__: key should be a string");
      return octave_value ();  
    }

  if (! args (2).is_string ())
    {
      error ("__cfitsio_writeKeyUnit__: unit should be a string");
      return octave_value ();  
    }

  int status = 0;
  std::string key = args (1).string_value ();
  std::string unit = args (2).string_value ();

  if (fits_write_key_unit(fp, key.c_str(), unit.c_str(), &status) > 0)
    {
      error ("__cfitsio_writeKeyUnit__: couldnt write key units: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! assert(!isempty(fd));
%! __cfitsio_createImg__(fd,'int16',[10 20]);
%! __cfitsio_writeKey__(fd, 'VELOCITY', 10.0, "Speed");
%! __cfitsio_writeKeyUnit__(fd, 'VELOCITY', "m/s");
%! __cfitsio_closeFile__(fd);
%! delete (filename);

%!error __cfitsio_writeKeyUnit__(1);
%!error __cfitsio_writeKeyUnit__(1, "VELOCITY");
%!error __cfitsio_writeKeyUnit__(1, "VELOCITY", "m/s");
#endif

// PKG_ADD: autoload ("__cfitsio_writeKey__", "__fits__.oct");
DEFUN_DLD(__cfitsio_writeKey__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_writeKey__(@var{file}, @var{key}, @var{value})\n \
@deftypefnx {Function File} {} __cfitsio_writeKey__(@var{file}, @var{key}, @var{value}, @var{comment})\n \
@deftypefnx {Function File} {} __cfitsio_writeKey__(@var{file}, @var{key}, @var{value}, @var{comment}, @var{decimals})\n \
Append or replace a key in the fits file.\n \
\n \
This is the equivalent of the cfitsio fits_write_key and fits_update_key function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() < 3)
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
      error ("__cfitsio_writeKey__: key should be a string");
      return octave_value ();  
    }

  std::string key = args (1).string_value ();

  octave_value value = args(2);

  std::string comment = "";
  const char *commentp = 0;
  if (args.length () >= 4)
    {
      if (! args (3).is_string ())
        {
          error ("__cfitsio_writeKey__: comment should be a string");
          return octave_value ();  
        }
      comment = args (3).string_value ();
      commentp = comment.c_str();
    }

  int status = 0;


  if (value.is_string())
    {
      std::string svalue = value.string_value ();
      char buffer[FLEN_CARD+1];
      strncpy(buffer, svalue.c_str(), FLEN_CARD);
      buffer[FLEN_CARD] = '\0';
      if (fits_update_key(fp, TSTRING, key.c_str(), &buffer, commentp, &status) > 0)
        {
          error ("__cfitsio_writeKey__: couldnt write key: %s", get_fits_error(status).c_str());
          return octave_value ();
        }
    }
  else if (value.islogical())
    {
      int svalue = value.int_value ();
      if (fits_update_key(fp, TLOGICAL, key.c_str(), &svalue, commentp, &status) > 0)
        {
          error ("__cfitsio_writeKey__: couldnt write key: %s", get_fits_error(status).c_str());
          return octave_value ();
        }
    }
  else if (value.is_scalar_type() && value.is_uint8_type())
    {
      uint8_t svalue = value.uint_value ();
      if (fits_update_key(fp, TBYTE, key.c_str(), &svalue, commentp, &status) > 0)
        {
          error ("__cfitsio_writeKey__: couldnt write key: %s", get_fits_error(status).c_str());
          return octave_value ();
        }
    }
  else if (value.is_scalar_type() && value.is_uint16_type())
    {
      unsigned short svalue = value.ushort_value ();
      if (fits_update_key(fp, TUSHORT, key.c_str(), &svalue, commentp, &status) > 0)
        {
          error ("__cfitsio_writeKey__: couldnt write key: %s", get_fits_error(status).c_str());
          return octave_value ();
        }
    }
  else if (value.is_scalar_type() && value.is_int16_type())
    {
      short svalue = value.short_value ();
      if (fits_update_key(fp, TSHORT, key.c_str(), &svalue, commentp, &status) > 0)
        {
          error ("__cfitsio_writeKey__: couldnt write key: %s", get_fits_error(status).c_str());
          return octave_value ();
        }
    }
  else if (value.is_scalar_type() && value.is_uint32_type())
    {
      unsigned long svalue = value.long_value ();
      if (fits_update_key(fp, TULONG, key.c_str(), &svalue, commentp, &status) > 0)
        {
          error ("__cfitsio_writeKey__: couldnt write key: %s", get_fits_error(status).c_str());
          return octave_value ();
        }
    }
  else if (value.is_scalar_type() && value.is_int32_type())
    {
      long svalue = value.long_value ();
      if (fits_update_key(fp, TLONG, key.c_str(), &svalue, commentp, &status) > 0)
        {
          error ("__cfitsio_writeKey__: couldnt write key: %s", get_fits_error(status).c_str());
          return octave_value ();
        }
    }
  else if (value.is_scalar_type() && value.is_int64_type())
    {
      int64_t svalue = value.int64_value ();
      if (fits_update_key(fp, TLONGLONG, key.c_str(), &svalue, commentp, &status) > 0)
        {
          error ("__cfitsio_writeKey__: couldnt write key: %s", get_fits_error(status).c_str());
          return octave_value ();
        }
    }
  else if (value.is_scalar_type() && value.isinteger())
    {
      int svalue = value.int_value ();
      if (fits_update_key(fp, TINT, key.c_str(), &svalue, commentp, &status) > 0)
        {
          error ("__cfitsio_writeKey__: couldnt write key: %s", get_fits_error(status).c_str());
          return octave_value ();
        }
    }
  else if (value.is_scalar_type() && value.is_double_type())
    {
      double svalue = value.double_value ();
      if (fits_update_key(fp, TDOUBLE, key.c_str(), &svalue, commentp, &status) > 0)
        {
          error ("__cfitsio_writeKey__: couldnt write key: %s", get_fits_error(status).c_str());
          return octave_value ();
        }
    }
  else if (value.is_scalar_type() && value.is_single_type())
    {
      float svalue = value.float_value ();
      if (fits_update_key(fp, TFLOAT, key.c_str(), &svalue, commentp, &status) > 0)
        {
          error ("__cfitsio_writeKey__: couldnt write key: %s", get_fits_error(status).c_str());
          return octave_value ();
        }
    }
  else
    {
       error ("__cfitsio_writeKey__: couldnt convert this data type");
       return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! assert(!isempty(fd));
%! __cfitsio_createImg__(fd,'int16',[10 20]);
%! __cfitsio_writeKey__(fd, 'VELOCITY', 10.0, "Speed");
%! __cfitsio_writeKey__(fd, 'VELOCITY', 10.1, "Speed1");
%! __cfitsio_writeKey__(fd, 'VELOCITY', 11.0);
%! __cfitsio_writeKey__(fd, 'AUTHOR', "me");
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_deleteKey__", "__fits__.oct");
DEFUN_DLD(__cfitsio_deleteKey__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_deleteKey__(@var{file}, @var{key})\n \
Delete a key in the fits file.\n \
\n \
This is the equivalent of the cfitsio fits_delete_key function.\n \
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
      error ("__cfitsio_deleteKey__: key should be a string");
      return octave_value ();  
    }

  std::string key = args (1).string_value ();

  int status = 0;
  if (fits_delete_key(fp, key.c_str(), &status) > 0)
    {
      error ("__cfitsio_deleteKey__: couldnt delete key: %s", get_fits_error(status).c_str());
      return octave_value ();
    }
  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! assert(!isempty(fd));
%! __cfitsio_createImg__(fd,'int16',[10 20]);
%! __cfitsio_writeDate__(fd);
%! __cfitsio_closeFile__(fd);
%!
%! fd = __cfitsio_openFile__(filename, 'readwrite');
%! # date record
%! d = __cfitsio_readKey__(fd,"DATE");
%! __cfitsio_deleteKey__(fd,"DATE");
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_getConstantValue__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getConstantValue__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{value}]} = __cfitsio_getConstantValue__(@var{name})\n \
Return the value of a known fits constant.\n \
@seealso {__cfitsio_getConstantNames__}\n \
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
      error ("__cfitsio_getConstantValue__: Couldnt find constant '%s'", name.c_str());
    }
  return value;
}
#if 0
%!test
%! assert(__cfitsio_getVersion__(), __cfitsio_getConstantValue__("CFITSIO_VERSION"), 1e-07);
%! assert(__cfitsio_getConstantValue__("IMAGE_HDU"), 0);
%! assert(__cfitsio_getConstantValue__("ASCII_TBL"), 1);
%! assert(__cfitsio_getConstantValue__("BINARY_TBL"), 2);
%! assert(__cfitsio_getConstantValue__("ANY_HDU"), -1);

%!error <Couldnt find constant> __cfitsio_getConstantValue__("UnkownVarName");
%!error <expected constant name> __cfitsio_getConstantValue__();
%!error <constant name should be a string> __cfitsio_getConstantValue__(1);
#endif

// PKG_ADD: autoload ("__cfitsio_getConstantNames__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getConstantNames__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{namelist}]} = __cfitsio_getConstantNames__()\n \
Return the names of all known fits constants\n \
@seealso {__cfitsio_getConstantValue__}\n \
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
%! names = __cfitsio_getConstantNames__();
%! assert(length(names) > 20);
#endif


// PKG_ADD: autoload ("__cfitsio_getVersion__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getVersion__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{ver}} = __cfitsio_getVersion__()\n \
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
%! assert(__cfitsio_getVersion__(), __cfitsio_getConstantValue__("CFITSIO_VERSION"), 1e-5);
#endif


// PKG_ADD: autoload ("__cfitsio_getHDUoff__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getHDUoff__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{headtstart}, @var{datastart}, @var{dataend}]} = __cfitsio_getHDUoff__(@var{file})\n \
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
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! assert(__cfitsio_getHDUoff__(fd), 0);
%! __cfitsio_movAbsHDU__(fd,1);
%! assert(__cfitsio_getHDUoff__(fd), 0);
%! __cfitsio_movAbsHDU__(fd,2);
%! assert(__cfitsio_getHDUoff__(fd), 48960);
%! __cfitsio_movAbsHDU__(fd,4);
%! assert(__cfitsio_getHDUoff__(fd), 72000);
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_getHDUoff__(1);
%!error __cfitsio_getHDUoff__([]);
%!error __cfitsio_getHDUoff__("");
#endif

// PKG_ADD: autoload ("__cfitsio_getImgSize__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getImgSize__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{size}} = __cfitsio_getImgSize__(@var{file})\n \
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
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! type = __cfitsio_movAbsHDU__(fd, 4);
%! assert(type, 'IMAGE_HDU');
%! assert (__cfitsio_getImgSize__(fd), [31 73 5]);
%! assert(__cfitsio_movAbsHDU__(fd, 3), "IMAGE_HDU");
%! assert (__cfitsio_getImgSize__(fd), [41 17 1 1 1 1 1 1 1 1 1 1 2]);
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_getImgSize__();
%!error __cfitsio_getImgSize__(1);
%!error __cfitsio_getImgSize__("");
%!error __cfitsio_getImgSize__([]);
#endif


// PKG_ADD: autoload ("__cfitsio_getImgType__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getImgType__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{type}} = __cfitsio_getImgType__(@var{file})\n \
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
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! assert(__cfitsio_movAbsHDU__(fd, 4), "IMAGE_HDU");
%! assert (__cfitsio_getImgType__(fd), "SHORT_IMG");
%! assert(__cfitsio_movAbsHDU__(fd, 3), "IMAGE_HDU");
%! assert (__cfitsio_getImgType__(fd), "BYTE_IMG");
%! __cfitsio_closeFile__(fd);

%!error __cfitsio_getImgType__();
%!error __cfitsio_getImgType__(1);
%!error __cfitsio_getImgType__("");
%!error __cfitsio_getImgType__([]);
#endif

// PKG_ADD: autoload ("__cfitsio_readImg__", "__fits__.oct");
DEFUN_DLD(__cfitsio_readImg__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{data}} = __cfitsio_readImg__(@var{file})\n \
@deftypefnx {Function File} {@var{data}} = __cfitsio_readImg__(@var{file}, @var{fisrtpix}, @var{lastpix})\n \
@deftypefnx {Function File} {@var{data}} = __cfitsio_readImg__(@var{file}, @var{fisrtpix}, @var{lastpix}, @var{inc})\n \
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
  int bpp;
  long axis[100];
  if( fits_get_img_param( fp, 100, &bpp, &num_axis, axis, &status) > 0 )
  {
      fits_report_error( stderr, status );
      error ("fits_readImage: could not get image parameters: %s", get_fits_error(status).c_str());
      return octave_value();
  }

  dim_vector dv(1, 1);
  dv.resize( num_axis );
  for(int i=0; i<num_axis;i++)
    {
      dv(i) = axis[i];
    }

  // TODO: convert to stored type 
  MArray<double> arr(dv); // a octave double-type array

  int datatype = TDOUBLE;
  std::vector<long> fpixel(num_axis,1);
  std::vector<long> inc(num_axis,1);
  std::vector<long> lpixel(num_axis,1);
  double nulval = 0;

  // read all image
  for(int i=0;i<num_axis;i++)
    lpixel[i] = axis[i];

  int  anynul;
  if(fits_read_subset(fp, datatype, fpixel.data(), lpixel.data(), inc.data(), NULL, arr.fortran_vec(), &anynul, &status) > 0)
    {
      error ("couldnt get data: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  if (num_axis >=2 )
    {
      // need swap first 2 dimensions, to match what matlab would return
      Array<int> dims(dim_vector(num_axis,1));;
      for (int i = 0; i < num_axis; i++)
        {
          if(i == 0) dims(i) = 1;
          else if(i == 1) dims(i) = 0;
          else dims(i) = i;
        }
      arr = arr.permute(dims);
    }

  return octave_value(arr);
}
#if 0
%!test
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! assert(__cfitsio_movAbsHDU__(fd, 4), "IMAGE_HDU");
%! data = __cfitsio_readImg__(fd);
%! assert (size(data), [31 73 5]);
%! __cfitsio_closeFile__(fd);
#endif

// PKG_ADD: autoload ("__cfitsio_createImg__", "__fits__.oct");
DEFUN_DLD(__cfitsio_createImg__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_createImg__(@var{file}, @var{bitpix}, @var{naxis})\n \
create a new primary image or image extension\n \
\n \
This is the equivalent of the cfitsio fits_create_imgll function.\n \
@end deftypefn")
{
  if ( args.length() < 3)
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

  int bpp;
  if (!args (1).is_string())
    {
      error("Expected bitpix as a string");
      return octave_value ();
    }
  std::string bitpix = args (1).string_value ();

  // The first two elements of naxes correspond to the NAXIS2 and NAXIS1 keywords
  
  if (bitpix == "byte_img" || bitpix == "uint8")
    bpp = BYTE_IMG;
  if (bitpix == "sbyte_img" || bitpix == "int8")
    bpp = SBYTE_IMG;
  else if (bitpix == "short_img" || bitpix == "int16")
    bpp = SHORT_IMG;
  else if (bitpix == "ushort_img" || bitpix == "uint16")
    bpp = USHORT_IMG;
  else if (bitpix == "long_img" || bitpix == "int32")
    bpp = LONG_IMG;
  else if (bitpix == "longlong_img" || bitpix == "int64")
    bpp = LONGLONG_IMG;
  else if (bitpix == "ulonglong_img" || bitpix == "uint64")
    bpp = ULONGLONG_IMG;
  else if (bitpix == "float_img" || bitpix == "single")
    bpp = FLOAT_IMG;
  else if (bitpix == "double_img" || bitpix == "double")
    bpp = DOUBLE_IMG;
  else
    {
      error("Unknown bitpix '%s'", bitpix.c_str());
      return octave_value ();
    }

  if (!args (2).is_matrix_type())
    {
      error("Expected nelem as a dimension vector");
      return octave_value ();
    }

  LONGLONG axis[100];
  Array<double> dv = args (2).vector_value ();
  int num_axis = dv.numel();
  for (octave_idx_type i=0;i<num_axis;i++)
    axis[i] = (int)dv(i);
  // need swap 1st to dimensions to match matlab
  if (num_axis >= 2)
    {
      LONGLONG tmp = axis[0];
      axis[0] = axis[1];
      axis[1] = tmp;
    }

  int status = 0;
  if( fits_create_imgll( fp, bpp, num_axis, axis, &status) > 0 )
    {
      error ("couldnt create image: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return octave_value();
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! assert(!isempty(fd));
%! __cfitsio_createImg__(fd,'int16',[10 20]);
%! __cfitsio_createImg__(fd,'int16',[10 20 3]);
%! __cfitsio_closeFile__(fd);
%! delete (filename);

%!error __cfitsio_createImg__(1);
%!error __cfitsio_createImg__(1, 'int16', []);
%!error __cfitsio_createImg__([]);
%!error __cfitsio_createImg__("");
#endif

// PKG_ADD: autoload ("__cfitsio_insertImg__", "__fits__.oct");
DEFUN_DLD(__cfitsio_insertImg__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_insertImg__(@var{file}, @var{bitpix}, @var{naxis})\n \
insert a new primary image or image extension at current HDU position\n \
\n \
This is the equivalent of the cfitsio fits_insert_imgll function.\n \
@end deftypefn")
{
  if ( args.length() < 3)
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

  int bpp;
  if (!args (1).is_string())
    {
      error("Expected bitpix as a string");
      return octave_value ();
    }
  std::string bitpix = args (1).string_value ();

  // The first two elements of naxes correspond to the NAXIS2 and NAXIS1 keywords
  
  if (bitpix == "byte_img" || bitpix == "uint8")
    bpp = BYTE_IMG;
  if (bitpix == "sbyte_img" || bitpix == "int8")
    bpp = SBYTE_IMG;
  else if (bitpix == "short_img" || bitpix == "int16")
    bpp = SHORT_IMG;
  else if (bitpix == "ushort_img" || bitpix == "uint16")
    bpp = USHORT_IMG;
  else if (bitpix == "long_img" || bitpix == "int32")
    bpp = LONG_IMG;
  else if (bitpix == "longlong_img" || bitpix == "int64")
    bpp = LONGLONG_IMG;
  else if (bitpix == "ulonglong_img" || bitpix == "uint64")
    bpp = ULONGLONG_IMG;
  else if (bitpix == "float_img" || bitpix == "single")
    bpp = FLOAT_IMG;
  else if (bitpix == "double_img" || bitpix == "double")
    bpp = DOUBLE_IMG;
  else
    {
      error("Unknown bitpix '%s'", bitpix.c_str());
      return octave_value ();
    }

  if (!args (2).is_matrix_type())
    {
      error("Expected nelem as a dimension vector");
      return octave_value ();
    }

  LONGLONG axis[100];
  Array<double> dv = args (2).vector_value ();
  int num_axis = dv.numel();
  for (octave_idx_type i=0;i<num_axis;i++)
    axis[i] = (int)dv(i);
  // need swap 1st to dimensions to match matlab
  if (num_axis >= 2)
    {
      LONGLONG tmp = axis[0];
      axis[0] = axis[1];
      axis[1] = tmp;
    }

  int status = 0;
  if( fits_insert_imgll( fp, bpp, num_axis, axis, &status) > 0 )
    {
      error ("couldnt insert image: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return octave_value();
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! assert(!isempty(fd));
%! __cfitsio_createImg__(fd,'int16',[10 20]);
%! __cfitsio_insertImg__(fd,'int16',[10 20 3]);
%! __cfitsio_movAbsHDU__(fd,1);
%! __cfitsio_insertImg__(fd,'int16',[20 30]);
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_writeImg__", "__fits__.oct");
DEFUN_DLD(__cfitsio_writeImg__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_writeImg__(@var{file}, @var{data})\n \
@deftypefnx {Function File} {} __cfitsio_writeImg__(@var{file}, @var{data}, @var{fpixel})\n \
write imagedata to a FITS file. The rows and column size must match the size of NAXIS, NAXIS etc \
\n \
This is the equivalent of the cfitsio fits_write_subset function.\n \
@end deftypefn")
{
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

  if (! args (1).is_matrix_type())
    {
      error("Not a fits file");
      return octave_value ();
    }

  const NDArray arr = args(1).array_value();
  int num_axis = arr.dims().length();
  NDArray imagedata;

  if (num_axis >=2 )
    {
      // need swap first 2 dimensions, to match what matlab would save
      Array<int> pdims(dim_vector(num_axis,1));;
      for (int i = 0; i < num_axis; i++)
        {
          if(i == 0) pdims(i) = 1;
          else if(i == 1) pdims(i) = 0;
          else pdims(i) = i;
        }
      imagedata = arr.ipermute(pdims);
    }
  else
    imagedata = arr;

  std::vector<long> fpixel(num_axis,1);
  std::vector<long> inc(num_axis,1);
  std::vector<long> lpixel(num_axis,1);

  dim_vector dims = imagedata.dims();
  for( int i=0; i<num_axis; i++ )  
  {
    lpixel[i] = dims(i);
  }

  // TODO: use fpixel from func input if available

  // TODO: convert to class type will be using 
  int bitperpixel = DOUBLE_IMG;
  //bitsperpixel = octave_to_type(imagedata);
  double * datap = const_cast<double*>( imagedata.data() );

  int status = 0;
  if( fits_write_subset( fp, TDOUBLE, fpixel.data(), lpixel.data(), datap , &status ) > 0 )
    {
      error ("__cfitsio_writeImg__: couldnt write: %s", get_fits_error(status).c_str());
    }

  return octave_value();
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! data = int16(zeros(10,10));
%! assert(!isempty(fd));
%! __cfitsio_createImg__(fd,class(data), size(data));
%! __cfitsio_writeImg__(fd,data);
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_setBscale__", "__fits__.oct");
DEFUN_DLD(__cfitsio_setBscale__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_setBscale__(@var{file}, @var{bscale}, @var{bzero})\n \
Reset bscale and bzero to be used with reading and writing Images.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() != 3)
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

  if (! args (1).isnumeric () || !args (1).is_scalar_type())
    {
      error ("__cfitsio_setBscale__: bscale should be numeric");
      return octave_value ();  
    }

  if (! args (2).isnumeric () || !args (1).is_scalar_type())
    {
      error ("__cfitsio_setBscale__: bzero should be numeric");
      return octave_value ();  
    }

  double scale = args (1).double_value ();
  double zero = args (2).double_value ();

  int status = 0;

  if (fits_set_bscale(fp, scale, zero, &status) > 0)
    {
      error ("__cfitsio_setBscale__: couldnt set scale: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! data = uint16([1:3; 4:6; 7:9]);
%! __cfitsio_createImg__(fd,class(data), size(data));
%! __cfitsio_setBscale__(fd, 1.0, 0.0);
%! __cfitsio_writeImg__(fd,data);
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_setTscale__", "__fits__.oct");
DEFUN_DLD(__cfitsio_setTscale__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_setTscale__(@var{file}, @var{col}, @var{scale}, @var{zero})\n \
Reset scale and zero to be used with reading and writing table data.\n \
@end deftypefn")
{
  octave_value_list ret;

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

  if (! args (1).isnumeric () || !args (1).is_scalar_type())
    {
      error ("__cfitsio_setTscale__: column should be numeric");
      return octave_value ();  
    }

  if (! args (2).isnumeric () || !args (2).is_scalar_type())
    {
      error ("__cfitsio_setTscale__: scale should be numeric");
      return octave_value ();  
    }

  if (! args (3).isnumeric () || !args (3).is_scalar_type())
    {
      error ("__cfitsio_setTscale__: zero should be numeric");
      return octave_value ();  
    }

  int col = args (1).int_value ();
  double scale = args (2).double_value ();
  double zero = args (3).double_value ();

  int status = 0;

  if (fits_set_tscale(fp, col, scale, zero, &status) > 0)
    {
      error ("__cfitsio_setTscale__: couldnt set scale: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! ttype = {'Col1','Col2','Col3','Col4'};
%! tform = {'A9','A4','A3','A8'};
%! tunit = {'m','s','kg','km'};
%! __cfitsio_createTbl__(fd,'binary',0,ttype,tform,tunit,'table-name');
%! __cfitsio_setTscale__(fd, 1, 1.0, 0.0);
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_getAColParms__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getAColParms__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{ttype},@var{tbcol},@var{tunit},@var{tform},@var{scale},@var{zero},@var{nulstr},@var{tdisp}]} = __cfitsio_getAColParms__(@var{file}, @var{colnum})\n \
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
#if 0
%!test
%! fd = __cfitsio_openFile__(testfile, "readonly");
%! assert(!isempty(fd));
%! __cfitsio_movAbsHDU__(fd,2);
%! [ttype,tbcol,tunit,tform,scale,zero,nulstr,tdisp] = __cfitsio_getAColParms__(fd, 1);
%! assert (ttype, "IDENT");
%! assert (tbcol, 1);
%! assert (tform, "9A");
%! assert (scale, 1);
%! assert (zero, 0);
%! __cfitsio_closeFile__(fd);
#endif

// PKG_ADD: autoload ("__cfitsio_getBColParms__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getBColParms__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{ttype},@var{tunit},@var{typechar},@var{repeat},@var{scale},@var{zero},@var{nulval},@var{tdisp}]} = getBColParms(@var{file}, @var{colnum})\n \
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

// PKG_ADD: autoload ("__cfitsio_getColName__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getColName__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{colnum},@var{colname}]} = __cfitsio_getColName__(@var{file}, @var{template}, @var{casesens})\n \
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
#if 0
%!test
%! fd = __cfitsio_openFile__(testfile);
%! __cfitsio_movAbsHDU__(fd,2);
%! [colnum, colname] = __cfitsio_getColName__(fd,"C*");
%! __cfitsio_closeFile__(fd);
#endif

// PKG_ADD: autoload ("__cfitsio_getColType__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getColType__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{dtype},@var{repeat},@var{width}]} = __cfitsio_getColType__(@var{file}, @var{colnum})\n \
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
#if 0
%!test
%! fd = __cfitsio_openFile__(testfile);
%! __cfitsio_movAbsHDU__(fd,2);
%! [dtype,repeat,width] = __cfitsio_getColType__(fd,5);
%! __cfitsio_closeFile__(fd);
#endif

// PKG_ADD: autoload ("__cfitsio_getEqColType__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getEqColType__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{dtype},@var{repeat},@var{width}]} = __cfitsio_getEqColType__(@var{file}, @var{colnum})\n \
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

  // FIXME
  // TODO: should dtype be a string 
  ret(0) = octave_value(dtype);

  ret(1) = octave_value(repeat);
  ret(2) = octave_value(width);

  return ret;
}
#if 0
%!test
%! fd = __cfitsio_openFile__(testfile);
%! __cfitsio_movAbsHDU__(fd,2);
%! [dtype,repeat,width] = __cfitsio_getEqColType__(fd,5);
%! __cfitsio_closeFile__(fd);
#endif

// PKG_ADD: autoload ("__cfitsio_getNumCols__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getNumCols__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{ncols}} = __cfitsio_getNumCols__(@var{file})\n \
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

// PKG_ADD: autoload ("__cfitsio_getNumRows__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getNumRows__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{nrows}} = __cfitsio_getNumRows__(@var{file})\n \
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

// PKG_ADD: autoload ("__cfitsio_getRowSize__", "__fits__.oct");
DEFUN_DLD(__cfitsio_getRowSize__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{nrows}} = __cfitsio_getRowSize__(@var{file})\n \
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

// PKG_ADD: autoload ("__cfitsio_readATblHdr__", "__fits__.oct");
DEFUN_DLD(__cfitsio_readATblHdr__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{rowlen}, @var{nrows}, @var{ttype},@var{tbcol},@var{tform},@var{tunit},@var{extname}]} = __cfitsio_readATblHdr__(@var{file})\n \
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

// PKG_ADD: autoload ("__cfitsio_readBTblHdr__", "__fits__.oct");
DEFUN_DLD(__cfitsio_readBTblHdr__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{nrows}, @var{ttype},@var{tform},@var{tunit},@var{extname}, @var{pcount}]} = __cfitsio_readBTblHdr__(@var{file})\n \
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

// PKG_ADD: autoload ("__cfitsio_createTbl__", "__fits__.oct");
DEFUN_DLD(__cfitsio_createTbl__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_createTbl__(@var{file}, @var{tbltype}, @var{nrows}, @var{ttype}, @var{tform})\n \
@deftypefnx {Function File} {} __cfitsio_createTbl__(@var{file}, @var{tbltype}, @var{nrows}, @var{ttype}, @var{tform}, @var{tunit})\n \
@deftypefnx {Function File} {} __cfitsio_createTbl__(@var{file}, @var{tbltype}, @var{nrows}, @var{ttype}, @var{tform}, @var{tunit}, @var{extname})\n \
Create a new ASCII or bintable extension\n \
\n \
This is the equivalent of the cfitsio fits_create_tbl function.\n \
@end deftypefn")
{
  octave_value_list ret;

  // tunit and ext name is optional
  if ( args.length() < 5 || args.length() > 7)
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

  // tbltype
  int tbltype = 0;
  if (!args (1).is_string())
    {
      error ("Expected tbltype as a string");
      return octave_value ();  
    }
  else if (args(1).string_value () == "ascii")
    {
      tbltype = ASCII_TBL;
    }
  else if (args(1).string_value () == "binary")
    {
      tbltype = BINARY_TBL;
    }
  else
    {
      error ("Expected tbltype as a 'ascii' or 'binary'");
      return octave_value ();  
    }

  //nrows
  if (!args (2).isnumeric()  || !args(2).is_real_scalar())
    {
      error ("Expected nrows to be a numeric value");
      return octave_value ();  
    }
  long nrows = args(2).long_value();

  int ncols = 1;
  // ttype
  if (!args (3).iscellstr())
    {
      error ("Expected ttype to be a cell of strings");
      return octave_value ();  
    }
  Array<std::string> attype = args(3).cellstr_value();
  ncols = attype.numel();
  if (ncols < 1)
    {
      error ("Expected ttype to have at least 1 item");
      return octave_value ();  
    }

  // tform
  if (!args (4).iscellstr())
    {
      error ("Expected tform to be a cell of strings");
      return octave_value ();  
    }

  Array<std::string> atform = args(4).cellstr_value();
  if (atform.numel() != ncols)
    {
      error ("Expected tform to have %d items", ncols);
      return octave_value ();  
    }

  // tunit
  Array<std::string> atunit;
  if ( args.length() > 5)
    {
      if (!args (5).iscellstr())
        {
          error ("Expected tunit to be a cell of strings");
          return octave_value ();  
        }

      atunit = args(5).cellstr_value();
      if (atunit.numel() != ncols)
        {
          error ("Expected tunit to have %d items", ncols);
          return octave_value ();  
        }
    }

  // extname
  char extname[FLEN_CARD];
  if ( args.length() > 6)
    {
      if (!args (6).is_string())
        {
          error ("Expected extname as a string");
          return octave_value ();  
        }
      std::string name = args (6).string_value();
      strcpy(extname, name.c_str());
    }
  else
    extname[0] = 0;

  char ttypebuf[(ncols*FLEN_CARD)+1];
  char tformbuf[(ncols*FLEN_CARD)+1];
  char tunitbuf[(ncols*FLEN_CARD)+1];

  char * ttype[ncols];
  char * tform[ncols];
  char * tunit[ncols];

  for (int i=0; i< ncols; i++)
    {
      ttype[i] = &ttypebuf[FLEN_CARD*i];
      tform[i] = &tformbuf[FLEN_CARD*i];
      tunit[i] = &tunitbuf[FLEN_CARD*i];

      strncpy(ttype[i], attype(i).c_str(), FLEN_CARD-1);
      strncpy(tform[i], atform(i).c_str(), FLEN_CARD-1);
      if (i < atunit.numel())
        strncpy(tunit[i], atunit(i).c_str(), FLEN_CARD-1);
      else
        *tunit[i] = 0;
    }


  int status = 0;

  if(fits_create_tbl(fp, tbltype, nrows, ncols, ttype, tform, tunit, extname[0] != 0 ? extname : 0, &status) > 0)
    {
      error ("couldnt create table: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! ttype = {'Col1','Col2','Col3','Col4'};
%! tform = {'A9','A4','A3','A8'};
%! tunit = {'m','s','kg','km'};
%! __cfitsio_createTbl__(fd,'binary',0,ttype,tform,tunit,'table-name');
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_insertBTbl__", "__fits__.oct");
DEFUN_DLD(__cfitsio_insertBTbl__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_insertBTbl__(@var{file}, @var{nrows}, @var{ttype}, @var{tform}, @var{tunit}, @var{extname}, @var{pcount})\n \
Insert a new bintable extension\n \
\n \
This is the equivalent of the cfitsio fits_insert_btbl function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if (args.length() != 7)
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

  //nrows
  if (!args (1).isnumeric()  || !args(1).is_real_scalar())
    {
      error ("Expected nrows to be a numeric value");
      return octave_value ();  
    }
  long nrows = args(1).long_value();

  int ncols = 1;
  // ttype
  if (!args (2).iscellstr())
    {
      error ("Expected ttype to be a cell of strings");
      return octave_value ();  
    }
  Array<std::string> attype = args(2).cellstr_value();
  ncols = attype.numel();
  if (ncols < 1)
    {
      error ("Expected ttype to have at least 1 item");
      return octave_value ();  
    }

  // tform
  if (!args (3).iscellstr())
    {
      error ("Expected tform to be a cell of strings");
      return octave_value ();  
    }

  Array<std::string> atform = args(3).cellstr_value();
  if (atform.numel() != ncols)
    {
      error ("Expected tform to have %d items", ncols);
      return octave_value ();  
    }

  // tunit
  if (!args (4).iscellstr())
    {
      error ("Expected tunit to be a cell of strings");
      return octave_value ();  
    }

  Array<std::string> atunit = args(4).cellstr_value();
  if (atunit.numel() != ncols)
    {
      error ("Expected tunit to have %d items", ncols);
      return octave_value ();  
    }

  // extname
  char extname[FLEN_CARD];
  if ( args.length() > 6)
    {
      if (!args (5).is_string())
        {
          error ("Expected extname as a string");
          return octave_value ();  
        }
      std::string name = args (5).string_value();
      strcpy(extname, name.c_str());
    }
  else
    extname[0] = 0;

  // pcount
  if (!args (6).isnumeric()  || !args(6).is_real_scalar())
    {
      error ("Expected nrows to be a numeric value");
      return octave_value ();  
    }
  long pcount = args(6).long_value();

  char ttypebuf[(ncols*FLEN_CARD)+1];
  char tformbuf[(ncols*FLEN_CARD)+1];
  char tunitbuf[(ncols*FLEN_CARD)+1];

  char * ttype[ncols];
  char * tform[ncols];
  char * tunit[ncols];

  for (int i=0; i< ncols; i++)
    {
      ttype[i] = &ttypebuf[FLEN_CARD*i];
      tform[i] = &tformbuf[FLEN_CARD*i];
      tunit[i] = &tunitbuf[FLEN_CARD*i];

      strncpy(ttype[i], attype(i).c_str(), FLEN_CARD-1);
      strncpy(tform[i], atform(i).c_str(), FLEN_CARD-1);
      if (i < atunit.numel())
        strncpy(tunit[i], atunit(i).c_str(), FLEN_CARD-1);
      else
        *tunit[i] = 0;
    }


  int status = 0;

  if(fits_insert_btbl(fp, nrows, ncols, ttype, tform, tunit, extname[0] != 0 ? extname : 0, pcount, &status) > 0)
    {
      error ("couldnt insert btable: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! ttype = {'Col1','Col2','Col3','Col4'};
%! tform = {'A9','A4','A3','A8'};
%! tunit = {'m','s','kg','km'};
%! __cfitsio_insertBTbl__(fd,0,ttype,tform,tunit,'table-name', 0);
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_insertATbl__", "__fits__.oct");
DEFUN_DLD(__cfitsio_insertATbl__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_insertATbl__(@var{file}, @var{tbltype}, @var{nrows}, @var{ttype}, @var{tbcol}, @var{tform}, @var{tunit}, @var{extname})\n \
Insert a new ASCII table after current HDU\n \
\n \
This is the equivalent of the cfitsio fits_insert_atbl function.\n \
@end deftypefn")
{
  octave_value_list ret;

  // tunit and ext name is optional
  if ( args.length() < 6 || args.length() > 8)
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

  // rowlen
  LONGLONG rowlen = 0;
  if (!args (1).isnumeric()  || !args(1).is_real_scalar())
    {
      error ("Expected rowlen to be a numeric value");
      return octave_value ();  
    }
  rowlen = args(1).int64_value();

  //nrows
  if (!args (2).isnumeric()  || !args(2).is_real_scalar())
    {
      error ("Expected nrows to be a numeric value");
      return octave_value ();  
    }
  LONGLONG nrows = args(2).int64_value();

  int ncols = 1;
  // ttype
  if (!args (3).iscellstr())
    {
      error ("Expected ttype to be a cell of strings");
      return octave_value ();  
    }
  Array<std::string> attype = args(3).cellstr_value();
  ncols = attype.numel();
  if (ncols < 1)
    {
      error ("Expected ttype to have at least 1 item");
      return octave_value ();  
    }

  // tbcol
  if (!args (4).is_matrix_type())
    {
      error("Expected tbcol as a  vector");
      return octave_value ();
    }
  Array<long> atbcol = args (4).vector_value ();
  if (atbcol.numel() != ncols)
    {
      error ("Expected tbcol to have %d items", ncols);
      return octave_value ();  
    }

  // tform
  if (!args (5).iscellstr())
    {
      error ("Expected tform to be a cell of strings");
      return octave_value ();  
    }

  Array<std::string> atform = args(5).cellstr_value();
  if (atform.numel() != ncols)
    {
      error ("Expected tform to have %d items", ncols);
      return octave_value ();  
    }

  // tunit
  Array<std::string> atunit;
  if ( args.length() > 6)
    {
      if (!args (6).iscellstr())
        {
          error ("Expected tunit to be a cell of strings");
          return octave_value ();  
        }

      atunit = args(6).cellstr_value();
      if (atunit.numel() != ncols)
        {
          error ("Expected tunit to have %d items", ncols);
          return octave_value ();  
        }
    }

  // extname
  char extname[FLEN_CARD];
  if ( args.length() > 7)
    {
      if (!args (7).is_string())
        {
          error ("Expected extname as a string");
          return octave_value ();  
        }
      std::string name = args (7).string_value();
      strcpy(extname, name.c_str());
    }
  else
    extname[0] = 0;

  char ttypebuf[(ncols*FLEN_CARD)+1];
  char tformbuf[(ncols*FLEN_CARD)+1];
  char tunitbuf[(ncols*FLEN_CARD)+1];
  long tbcol[ncols];

  char * ttype[ncols];
  char * tform[ncols];
  char * tunit[ncols];

  for (int i=0; i< ncols; i++)
    {
      ttype[i] = &ttypebuf[FLEN_CARD*i];
      tform[i] = &tformbuf[FLEN_CARD*i];
      tunit[i] = &tunitbuf[FLEN_CARD*i];

      tbcol[i] = atbcol(i);

      strncpy(ttype[i], attype(i).c_str(), FLEN_CARD-1);
      strncpy(tform[i], atform(i).c_str(), FLEN_CARD-1);
      if (i < atunit.numel())
        strncpy(tunit[i], atunit(i).c_str(), FLEN_CARD-1);
      else
        *tunit[i] = 0;
    }


  int status = 0;

  if(fits_insert_atbl(fp, rowlen, nrows, ncols, ttype, tbcol, tform, tunit, extname[0] != 0 ? extname : 0, &status) > 0)
    {
      error ("couldnt create table: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! __cfitsio_createImg__(fd,'double',[20 30]);
%! __cfitsio_createImg__(fd,'double',[20 30]);
%! __cfitsio_movRelHDU__(fd,-1);
%! ttype = {'Col1','Col2','Col3','Col4'};
%! tbcol = [1 10 14 17 ];
%! tform = {'A9','A4','A3','A8'};
%! tunit = {'m','s','kg','km'};
%! __cfitsio_insertATbl__(fd, 0,0,ttype,tbcol,tform,tunit,'table-name');
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif


// PKG_ADD: autoload ("__cfitsio_insertCol__", "__fits__.oct");
DEFUN_DLD(__cfitsio_insertCol__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_insertCol__(@var{file}, @var{colnum}, @var{ttype}, @var{tform})\n \
Insert a column into a table\n \
\n \
This is the equivalent of the cfitsio fits_insert_col function.\n \
@end deftypefn")
{
  octave_value_list ret;

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

  // colnum
  if (!args (1).isnumeric()  || !args(1).is_real_scalar())
    {
      error ("Expected colnum to be a numeric value");
      return octave_value ();  
    }
  int colnum = args(1).int_value();

  // ttype
  if (!args (2).is_string())
    {
      error ("Expected ttype to be a string");
      return octave_value ();  
    }
  std::string ttype = args (2).string_value ();

  // tform
  if (!args (3).is_string())
    {
      error ("Expected tform to be a string");
      return octave_value ();  
    }
  std::string tform = args (3).string_value ();

  char ttypebuf[FLEN_CARD];
  char tformbuf[FLEN_CARD];
  strncpy(ttypebuf, ttype.c_str(), FLEN_CARD-1);
  strncpy(tformbuf, tform.c_str(), FLEN_CARD-1);

  int status = 0;

  if(fits_insert_col(fp, colnum, ttypebuf, tformbuf, &status) > 0)
    {
      error ("couldnt insert column: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! ttype = {'Col1','Col2','Col3','Col4'};
%! tform = {'A9','A4','A3','A8'};
%! tunit = {'m','s','kg','km'};
%! __cfitsio_createTbl__(fd,'binary',0,ttype,tform,tunit,'table-name');
%! __cfitsio_insertCol__(fd, 1,"ICol","9A");
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_deleteCol__", "__fits__.oct");
DEFUN_DLD(__cfitsio_deleteCol__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_deleteCol__(@var{file}, @var{colnum})\n \
Delete a column from a table\n \
\n \
This is the equivalent of the cfitsio fits_delete_col function.\n \
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

  // colnum
  if (!args (1).isnumeric()  || !args(1).is_real_scalar())
    {
      error ("Expected colnum to be a numeric value");
      return octave_value ();  
    }
  int colnum = args(1).int_value();

  int status = 0;

  if(fits_delete_col(fp, colnum, &status) > 0)
    {
      error ("couldnt delete column: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! ttype = {'Col1','Col2','Col3','Col4'};
%! tform = {'9A','4X','3B','1D'};
%! tunit = {'m','s','kg','km'};
%! __cfitsio_createTbl__(fd,'binary',0,ttype,tform,tunit,'table-name');
%! __cfitsio_deleteCol__(fd, 1);
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif


// PKG_ADD: autoload ("__cfitsio_insertRows__", "__fits__.oct");
DEFUN_DLD(__cfitsio_insertRows__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_insertRows__(@var{file}, @var{firstrow}, @var{numrows})\n \
Insert a rows into a table\n \
\n \
This is the equivalent of the cfitsio fits_insert_rows function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() != 3)
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

  // firstrow
  if (!args (1).isnumeric()  || !args(1).is_real_scalar())
    {
      error ("Expected colnum to be a numeric value");
      return octave_value ();  
    }
  long firstrow = args(1).long_value();

  // nrows
  if (!args (2).isnumeric()  || !args(2).is_real_scalar())
    {
      error ("Expected nrows to be a numeric value");
      return octave_value ();  
    }
  long nrows = args(2).long_value();
  if (nrows < 1)
    {
      error ("Expected nrows to be a positive value");
      return octave_value ();  
    }

  int status = 0;

  if(fits_insert_rows(fp, firstrow, nrows, &status) > 0)
    {
      error ("Couldnt insert rows: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! ttype = {'Col1','Col2','Col3','Col4'};
%! tform = {'A9','A4','A3','A8'};
%! tunit = {'m','s','kg','km'};
%! __cfitsio_createImg__(fd,'int16',[10 20]);
%! __cfitsio_createTbl__(fd,'binary',0,ttype,tform,tunit,'table-name');
%! __cfitsio_closeFile__(fd);
%! fd = __cfitsio_openFile__(filename, "READWRITE");
%! __cfitsio_movRelHDU__(fd,1);
%! __cfitsio_insertRows__(fd, 0, 5);
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_deleteRows__", "__fits__.oct");
DEFUN_DLD(__cfitsio_deleteRows__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_deleteRows__(@var{file}, @var{firstrow}, @var{numrows})\n \
Insert a rows into a table\n \
\n \
This is the equivalent of the cfitsio fits_delete_rows function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() != 3)
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

  // firstrow
  if (!args (1).isnumeric()  || !args(1).is_real_scalar())
    {
      error ("Expected colnum to be a numeric value");
      return octave_value ();  
    }
  long firstrow = args(1).long_value();

  // nrows
  if (!args (2).isnumeric()  || !args(2).is_real_scalar())
    {
      error ("Expected nrows to be a numeric value");
      return octave_value ();  
    }
  long nrows = args(2).long_value();
  if (nrows < 1)
    {
      error ("Expected nrows to be a positive value");
      return octave_value ();  
    }

  int status = 0;

  if(fits_delete_rows(fp, firstrow, nrows, &status) > 0)
    {
      error ("couldnt delete rows: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! ttype = {'Col1','Col2','Col3','Col4'};
%! tform = {'A9','A4','A3','A8'};
%! tunit = {'m','s','kg','km'};
%! __cfitsio_createImg__(fd,'int16',[10 20]);
%! __cfitsio_createTbl__(fd,'binary',10,ttype,tform,tunit,'table-name');
%! __cfitsio_closeFile__(fd);
%! fd = __cfitsio_openFile__(filename, 'READWRITE');
%! __cfitsio_movAbsHDU__(fd,2);
%! __cfitsio_deleteRows__(fd, 1, 5);
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_writeCol__", "__fits__.oct");
DEFUN_DLD(__cfitsio_writeCol__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_writeCol__(@var{file}, @var{colnum}, @var{firstrow}, @var{data})\n \
Write elements to a table.\n \
\n \
This is the equivalent of the cfitsio fits_write_col function.\n \
@end deftypefn")
{
  octave_value_list ret;

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

  // colnum
  if (!args (1).isnumeric()  || !args(1).is_real_scalar())
    {
      error ("Expected colnum to be a numeric value");
      return octave_value ();  
    }
  int colnum = args(1).int_value();

  // firstrow
  if (!args (2).isnumeric()  || !args(2).is_real_scalar())
    {
      error ("Expected colnum to be a numeric value");
      return octave_value ();  
    }
  long firstrow = args(2).long_value();

  int status = 0;
  int dtype;
  LONGLONG repeat, width;
  if(fits_get_eqcoltypell(fp, colnum, &dtype, &repeat, &width, &status) > 0)
    {
      error ("couldnt get col parms: %s", get_fits_error(status).c_str());
      return octave_value ();
    }
  if(dtype < 0) dtype = -dtype;

  if (args(3).iscell())
    {
      // TODO: 2nd dim shoud be 1 ? ie: somenumrows x 1
      Cell cell = args(3).cell_value();

      // handle each row separately ?
      for(octave_idx_type idx=0; idx < cell.size(0); idx++)
        {
          octave_value value = cell(idx, 0);
          if (dtype == TSTRING)
            write_text_row(fp, colnum, TSTRING, firstrow, value.cellstr_value());
          else if ((value.isnumeric() || value.islogical()))
            {
              // TODO: size of value should be 1 x somewidth
              if (dtype == TLOGICAL)
                write_numeric_row<boolNDArray,int8_t>(fp, colnum, TLOGICAL, firstrow+idx, value.bool_array_value());
              else if(dtype == TBIT)
                write_numeric_row<int8NDArray,int8_t>(fp, colnum, TBIT, firstrow+idx, value.int8_array_value());
              else if(dtype == TCOMPLEX)
                write_numeric_row<FloatComplexNDArray,FloatComplex>(fp, colnum, TCOMPLEX, firstrow+idx, value.float_complex_array_value());
              else if(dtype == TDBLCOMPLEX)
                write_numeric_row<ComplexNDArray,Complex>(fp, colnum, TDBLCOMPLEX, firstrow+idx, value.complex_array_value());
              else
                write_numeric_row<NDArray,double>(fp, colnum, TDOUBLE, firstrow+idx, value.array_value());
            }
        }

    }
  else if(dtype == TSTRING)
      write_text_row(fp, colnum, TSTRING, firstrow, args(3).cellstr_value());
  else if ((args(3).isnumeric() || args(3).islogical()))
    {
      if(dtype == TLOGICAL)
        write_numeric_row<boolNDArray,int8_t>(fp, colnum, TLOGICAL, firstrow, args(3).bool_array_value());
      else if(dtype == TBIT)
        write_numeric_row<int8NDArray,int8_t>(fp, colnum, TBIT, firstrow, args(3).int8_array_value());
      else if(dtype == TCOMPLEX)
        write_numeric_row<FloatComplexNDArray,FloatComplex>(fp, colnum, TCOMPLEX, firstrow, args(3).float_complex_array_value());
      else if(dtype == TDBLCOMPLEX)
        write_numeric_row<ComplexNDArray,Complex>(fp, colnum, TDBLCOMPLEX, firstrow, args(3).complex_array_value());
      else
        write_numeric_row<NDArray,double>(fp, colnum, TDOUBLE, firstrow, args(3).array_value());
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! assert(!isempty(fd));
%! __cfitsio_createImg__(fd,'int16',[10 20]);
%! __cfitsio_writeKey__(fd, 'VELOCITY', 10.0, "Speed");
%! __cfitsio_writeKeyUnit__(fd, 'VELOCITY', "m/s");
%! __cfitsio_closeFile__(fd);
%! delete (filename);

%!error __cfitsio_writeKeyUnit__(1);
%!error __cfitsio_writeKeyUnit__(1, "VELOCITY");
%!error __cfitsio_writeKeyUnit__(1, "VELOCITY", "m/s");
#endif

// PKG_ADD: autoload ("__cfitsio_readCol__", "__fits__.oct");
DEFUN_DLD(__cfitsio_readCol__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{coldata}, @var{nullval}]} = __cfitsio_readCol__(@var{file}, @var{colnum})\n \
@deftypefnx {Function File} {[@var{coldata}, @var{nullval}]} = __cfitsio_readCol__(@var{file}, @var{colnum}, @var{firstrow}, @var{numrows})\n \
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
  bool variable = false;
  if(fits_get_eqcoltypell(fp, col, &dtype, &repeat, &width, &status) > 0)
    {
      error ("couldnt get parms: %s", get_fits_error(status).c_str());
      return octave_value ();
    }
  if(dtype < 0) 
    {
      // for variable length types
      dtype = -dtype;
      variable = true;
    }
  //printf("read %d t=%d r=%d w=%d v=%d\n", col, dtype, (int)repeat, (int)width, (int)variable);

  if(dtype == TBYTE)
    {
      ret = read_numeric_row<uint8NDArray,uint8_t>(fp, col, dtype,firstrow, nrows, repeat, variable);
    }
  else if(dtype == TSBYTE)
    {
      ret = read_numeric_row<int8NDArray,int8_t>(fp, col, dtype,firstrow, nrows, repeat, variable);
    }
  else if(dtype == TSHORT)
    {
      ret = read_numeric_row<int16NDArray,int16_t>(fp, col, dtype,firstrow, nrows, repeat, variable);
    }
  else if(dtype == TUSHORT)
    {
      ret = read_numeric_row<uint16NDArray,uint16_t>(fp, col, dtype,firstrow, nrows, repeat, variable);
    }
  else if(dtype == TLONG)
    {
      ret = read_numeric_row<int32NDArray,int32_t>(fp, col, dtype,firstrow, nrows, repeat, variable);
    }
  else if(dtype == TULONG)
    {
      ret = read_numeric_row<uint32NDArray,uint32_t>(fp, col, dtype,firstrow, nrows, repeat, variable);
    }
  else if(dtype == TINT32BIT)
    {
      ret = read_numeric_row<int32NDArray,int32_t>(fp, col, dtype,firstrow, nrows, repeat, variable);
    }
  else if(dtype == TUINT)
    {
      ret = read_numeric_row<uint32NDArray,unsigned int>(fp, col, dtype,firstrow, nrows, repeat, variable);
    }
  else if(dtype == TINT)
    {
      ret = read_numeric_row<int32NDArray,int>(fp, col, dtype,firstrow, nrows, repeat, variable);
    }
  else if(dtype == TULONGLONG)
    {
      ret = read_numeric_row<uint64NDArray,uint64_t>(fp, col, dtype,firstrow, nrows, repeat, variable);
    }
  else if(dtype == TLONGLONG)
    {
      ret = read_numeric_row<int64NDArray,int64_t>(fp, col, dtype,firstrow, nrows, repeat, variable);
    }
  else if(dtype == TDOUBLE)
    {
      ret = read_numeric_row<NDArray,double>(fp, col, dtype,firstrow, nrows, repeat, variable);
    }
  else if(dtype == TFLOAT)
    {
      ret = read_numeric_row<FloatNDArray,float>(fp, col, dtype,firstrow, nrows, repeat, variable);
    }
  else if(dtype == TBIT)
    {
      //ret = read_numeric_row<int8NDArray,int8_t>(fp, col, dtype,firstrow, nrows, repeat);
      ret = read_numeric_row<int8NDArray,int8_t>(fp, col, dtype,firstrow, nrows, repeat, variable);
    }
  else if(dtype == TLOGICAL)
    {
      ret = read_numeric_row<boolNDArray,int8_t>(fp, col, dtype,firstrow, nrows, repeat, variable);
    }
  else if(dtype == TCOMPLEX)
    {
      ret = read_numeric_row<FloatComplexNDArray,FloatComplex>(fp, col, dtype,firstrow, nrows, repeat, variable);
      //ret = read_numeric_row<Array<FloatComplex>,complex>(fp, col, dtype,firstrow, nrows, repeat);
    }
  else if(dtype == TDBLCOMPLEX)
    {
      ret = read_numeric_row<ComplexNDArray,Complex>(fp, col, dtype,firstrow, nrows, repeat, variable);
    }
  else
    {
      // TODO: handle variable here ???
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
              error ("couldnt get %d data: %s", dtype, get_fits_error(status).c_str());
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
%! fd = __cfitsio_openFile__(testfile);
%! assert(!isempty(fd));
%! assert(__cfitsio_movAbsHDU__(fd, 2), "BINARY_TBL");
%! [d,n] = __cfitsio_readCol__(fd, 1);
%! assert(size(d), [11 9])
%! assert(size(n), [11 9])
%! [d,n] = __cfitsio_readCol__(fd, 1, 11);
%! assert(size(d), [1 9])
%! assert(size(n), [1 9])
%! [d,n] = __cfitsio_readCol__(fd, 1, 8, 2);
%! assert(size(d), [2 9])
%! assert(size(n), [2 9])
%!
%! [d,n] = __cfitsio_readCol__(fd, 2);
%! assert(size(d), [11 13])
%! assert(size(n), [11 13])
%!
%! assert(__cfitsio_movAbsHDU__(fd, 5), "ASCII_TBL");
%! [d,n] = __cfitsio_readCol__(fd, 1);
%! assert(size(d), [53 9])
%! assert(size(n), [1 53])
%! [d,n] = __cfitsio_readCol__(fd, 2);
%! assert(size(d), [53 1])
%! assert(size(n), [53 1])
%! __cfitsio_closeFile__(fd);
#endif

// PKG_ADD: autoload ("__cfitsio_setCompressionType__", "__fits__.oct");
DEFUN_DLD(__cfitsio_setCompressionType__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_setCompressionType__(@var{file}, @var{comptype})\n \
Set compression type for writing FITS images.\n \
\n \
Valid comptype values are: 'GZIP', 'GZIP2', 'RICE', 'PLIO', 'HCOMPRESS' or 'NOCOMPRESS'\n \
\n \
This is the equivalent of the cfitsio fits_set_compression_type function.\n \
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
      error ("__cfitsio_setCompressionType__: comptype should be a string");
      return octave_value ();  
    }

  int status = 0;
  std::string comptype = args (1).string_value ();
  std::transform (comptype.begin(), comptype.end(), comptype.begin(), ::toupper);
  int ctype = NOCOMPRESS;
  if (comptype == "RICE") ctype = RICE_1;
  else if (comptype == "GZIP") ctype = GZIP_1;
  else if (comptype == "GZIP2") ctype = GZIP_2;
  else if (comptype == "PLIO") ctype = PLIO_1;
  else if (comptype == "HCOMPRESS") ctype = HCOMPRESS_1;
  else if (comptype == "BZIP2") ctype = BZIP2_1;
  else if (comptype == "NOCOMPRESS") ctype = NOCOMPRESS;
  else
    {
      error ("__cfitsio_setCompressionType__: unknown compression type '%s'", comptype.c_str());
      return octave_value ();
    }

  if (fits_set_compression_type(fp, ctype, &status) > 0)
    {
      error ("__cfitsio_setCompressionType__ couldnt write type: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! assert(!isempty(fd));
%! __cfitsio_setCompressionType__(fd, "NOCOMPRESS");
%! __cfitsio_createImg__(fd,'int16',[10 20]);
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_setTileDim__", "__fits__.oct");
DEFUN_DLD(__cfitsio_setTileDim__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_setTileDim__(@var{file}, @var{tiledims})\n \
Set compression tile dims for writing FITS images.\n \
\n \
This is the equivalent of the cfitsio fits_set_tile_dim function.\n \
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

  if (!args (1).is_matrix_type())
    {
      error("Expected tiledims as a dimension vector");
      return octave_value ();
    }

  long axis[100];
  Array<double> dv = args (1).vector_value ();
  int num_axis = dv.numel();
  for (octave_idx_type i=0;i<num_axis;i++)
    axis[i] = (long)dv(i);

  // need swap 1st to dimensions to match matlab ?
  if (num_axis >= 2)
    {
      long tmp = axis[0];
      axis[0] = axis[1];
      axis[1] = tmp;
    }

  int status = 0;
  if (fits_set_tile_dim(fp, num_axis, axis, &status) > 0)
    {
      error ("__cfitsio_setTileDim__ couldnt write tile dims: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! assert(!isempty(fd));
%! #__cfitsio_setCompressionType__(fd, "RICE");
%! __cfitsio_setTileDim__(fd, [64 128]);
%! __cfitsio_createImg__(fd,'int16',[256 512]);
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_isCompressedImg__", "__fits__.oct");
DEFUN_DLD(__cfitsio_isCompressedImg__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{yes} = } __cfitsio_isCompressedImg__(@var{file})\n \
Return true if image is compressed.\n \
\n \
This is the equivalent of the cfitsio fits_is_compressed_image function.\n \
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

  int compressed = fits_is_compressed_image(fp, &status);
  if(status != 0)
    {
      error ("__cfitsio_isCompressedImg__: couldnt determine compression: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  ret(0) = (compressed == 1);

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! assert(!isempty(fd));
%! __cfitsio_setCompressionType__(fd, "RICE");
%! __cfitsio_createImg__(fd,'int16',[256 512]);
%! assert(__cfitsio_isCompressedImg__(fd), true);
%! __cfitsio_closeFile__(fd);
%!
%! fd = __cfitsio_createFile__(['!' filename]);
%! __cfitsio_createImg__(fd,'int16',[256 512]);
%! assert(__cfitsio_isCompressedImg__(fd), false);
%! __cfitsio_closeFile__(fd);
%!
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_imgCompress__", "__fits__.oct");
DEFUN_DLD(__cfitsio_imgCompress__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_imgCompress__(@var{infile}, @var{outfile})\n \
Copy HDU and image data from one infile to another, using the outfiles compression type\n \
\n \
This is the equivalent of the cfitsio fits_img_compress function.\n \
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

  fitsfile * fp1 = get_fits_file (args(0).uint64_value());

  if(!fp1)
    {
      error("Not a fits file");
      return octave_value ();
    }

  if (!args (1).isinteger()  || !args(1).is_real_scalar())
    {
      error ("Not a fits file");
      return octave_value ();  
    }

  fitsfile * fp2 = get_fits_file (args(1).uint64_value());

  if(!fp2)
    {
      error("Not a fits file");
      return octave_value ();
    }

  int status = 0;

  if (fits_img_compress(fp1, fp2, &status) > 0)
    {
      error ("__cfitsio_imgCompress__: couldnt copy image: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename1 = tempname();
%! filename2 = tempname();
%! fd1 = __cfitsio_createFile__(filename1);
%! __cfitsio_createImg__(fd1,'int16',[256 512]);
%! __cfitsio_closeFile__(fd1);
%!
%! fd1 = __cfitsio_openFile__(filename1);
%!
%! fd2 = __cfitsio_createFile__(filename2);
%! __cfitsio_setCompressionType__(fd2, "RICE");
%! __cfitsio_imgCompress__(fd1,fd2);
%! __cfitsio_closeFile__(fd1);
%! __cfitsio_closeFile__(fd2);
%!
%! delete (filename1);
%! delete (filename2);
#endif

// PKG_ADD: autoload ("__cfitsio_setHCompScale__", "__fits__.oct");
DEFUN_DLD(__cfitsio_setHCompScale__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_setHCompScale__(@var{file}, @var{scale})\n \
Set scale to be used with HCOMPRESS compression.\n \
\n \
This is the equivalent of the cfitsio fits_set_hcomp_scale function.\n \
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

  if (! args (1).isnumeric () || !args (1).is_scalar_type())
    {
      error ("__cfitsio_setHCompScale__: scale should be numeric");
      return octave_value ();  
    }

  float scale = args (1).float_value ();

  int status = 0;

  if (fits_set_hcomp_scale(fp, scale, &status) > 0)
    {
      error ("__cfitsio_setHCompScale__: couldnt write scale: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! __cfitsio_setHCompScale__(fd, 1.0);
%! __cfitsio_createImg__(fd,'int16',[10 20]);
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

// PKG_ADD: autoload ("__cfitsio_setHCompSmooth__", "__fits__.oct");
DEFUN_DLD(__cfitsio_setHCompSmooth__, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} __cfitsio_setHCompSmooth__(@var{file}, @var{smooth})\n \
Set smooth value to be used with HCOMPRESS compression.\n \
\n \
This is the equivalent of the cfitsio fits_set_hcomp_smooth function.\n \
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

  if (! args (1).isnumeric () || !args (1).is_scalar_type())
    {
      error ("__cfitsio_setHCompSmooth__: scale should be numeric");
      return octave_value ();  
    }

  int smooth = args (1).int_value ();

  int status = 0;

  if (fits_set_hcomp_smooth(fp, smooth, &status) > 0)
    {
      error ("__cfitsio_setHCompSmooth__: couldnt write smooth: %s", get_fits_error(status).c_str());
      return octave_value ();
    }

  return ret;
}
#if 0
%!test
%! filename = tempname();
%! fd = __cfitsio_createFile__(filename);
%! __cfitsio_setHCompSmooth__(fd, 1);
%! __cfitsio_createImg__(fd,'int16',[10 20]);
%! __cfitsio_closeFile__(fd);
%! delete (filename);
#endif

