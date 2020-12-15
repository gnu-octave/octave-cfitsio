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

extern "C"
{
#include <fitsio.h>
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

// class type to hold the file const
class
octave_fits_file : public octave_base_value
{
public:

  octave_fits_file ()
    : fp (0) { }

  ~octave_fits_file (void)
  {
    if(fp != NULL)
      this->close();
  }

  // Octave internal stuff
  bool is_constant (void) const { return true; }
  bool is_defined (void) const { return true; }

  octave_base_value * clone (void) const { return new octave_fits_file(*this); };
  octave_base_value * empty_clone (void) const { return new octave_fits_file(); }
  octave_base_value * unique_clone (void) { return this; }


  void print_raw (std::ostream& os, bool pr_as_read_syntax = false) const
  {
    indent (os);
    os << "<fits_file>";
    newline (os);
  }

  void print (std::ostream& os, bool pr_as_read_syntax = false) const
  {
    print_raw (os);
  }

  void print (std::ostream& os, bool pr_as_read_syntax = false)
  {
    print_raw (os);
  }

  // internal functions
  bool open (const std::string &name, int mode); 
  bool open_diskfile (const std::string &name, int mode); 
  bool create (const std::string &name);

  void deletefile (void);
  void close (void);

  // get the fits file ptr
  fitsfile * get_fp() { return fp; };
private:
  fitsfile *fp;

  // needed by Octave for register_type()
  octave_fits_file (const octave_fits_file &f);

  DECLARE_OV_TYPEID_FUNCTIONS_AND_DATA
};

DEFINE_OV_TYPEID_FUNCTIONS_AND_DATA (octave_fits_file, "fits_file", "fits_file")


/*
 * get the fits file
 */
octave_fits_file::octave_fits_file(const octave_fits_file &file)
: fp(NULL)
{
  fprintf(stderr, "Called fits_file copy\n");
}

/*
 * attempt to open file
 */
bool
octave_fits_file::open (const std::string &name, int mode)
{
  int status = 0;
  fitsfile *fp;

  if ( fits_open_file( &fp, name.c_str(), mode, &status) > 0 )
    {
      fits_report_error( stderr, status );
      return false;
    }

  this->fp = fp;
  
  return true;
}

/*
 * open disk file
 */
bool
octave_fits_file::open_diskfile (const std::string &name, int mode)
{
  int status = 0;
  fitsfile *fp;

  if ( fits_open_diskfile( &fp, name.c_str(), mode, &status) > 0 )
    {
      fits_report_error( stderr, status );
      return false;
    }

  this->fp = fp;
  
  return true;
}

/*
 * create a file
 */
bool
octave_fits_file::create (const std::string &name)
{
  int status = 0;
  fitsfile *fp;

  if ( fits_create_file( &fp, name.c_str(), &status) > 0 )
    {
      fits_report_error( stderr, status );
      return false;
    }

  this->fp = fp;
  
  return true;
}

/*
 * close fits file
 */
void
octave_fits_file::close (void)
{
  int status = 0;

  if (! this->fp)
  {
    error ("fits file not open");
    return;
  }

  if ( fits_close_file(this->fp, &status ) > 0 )
    {
      fits_report_error( stderr, status );
    }

  this->fp = 0;
}

/*
 * close and delete file 
 */
void
octave_fits_file::deletefile (void)
{
  int status=0;

  if (! this->fp)
  {
    error ("fits file not open");
    return;
  }

  if ( fits_delete_file(this->fp, &status ) > 0 )
    {
      fits_report_error( stderr, status );
    }

  this->fp = 0;
}

/*
 * register the fitfile class 
 */
void init_types ()
{
  static bool type_registered = false;

  if (! type_registered)
    {
      type_registered = true;

      octave_fits_file::register_type ();
    }
}

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

  init_types ();

  octave_fits_file *fitsfile = new octave_fits_file ();
  if (! fitsfile->create (infile))
    {
      error ("fits_createFile: Cant create fits file '%s'", infile.c_str ());
      delete fitsfile;
      return octave_value ();
    }
  return octave_value (fitsfile);
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

  init_types ();

  octave_fits_file *fitsfile = new octave_fits_file ();
  
  if (! fitsfile->open (infile, mode))
    {
      error ("fits_openFile: error opening fits file '%s'", infile.c_str());
      delete fitsfile;
      return octave_value ();
    }

  return octave_value (fitsfile);
}

// PKG_ADD: autoload ("fits_openDiskFile", "__fits__.oct");
DEFUN_DLD(fits_openDiskFile, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{file}]} = fits_openDiskFile(@var{filename})\n \
@deftypefnx {Function File} {[@var{file}]} = fits_openDiskFile(@var{filename}, @var{mode})\n \
Attempt to open a a file of the given input name, ignoring and special processing of the filename.\n \
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

  init_types ();

  octave_fits_file *fitsfile = new octave_fits_file ();
  if (! fitsfile->open_diskfile (infile, mode))
    {
      error ("fits_openDiskFile: error opening fits diskfile '%s'", infile.c_str());
      delete fitsfile;
      return octave_value ();
    }
  return octave_value (fitsfile);
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

  init_types ();

  if (args.length () != 1 
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error("fits_fileMode: file not open");
    return octave_value ();
    }

  int mode, status = 0;

  if (fits_file_mode(fp, &mode, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("fits_fileMode: couldnt read file mode");
      return octave_value ();
    }

  std::string modestr = "READONLY";
  if(mode == READWRITE)
    modestr = "READWRITE";

  return octave_value (modestr);
}

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

  init_types ();

  if (args.length () != 1 
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error("fits_fileName: file not open");
      return octave_value ();
    }

  int status = 0;
  char filename[FLEN_FILENAME];

  if( fits_file_name(fp, filename, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("fits_fileName: couldnt read file name");
      return octave_value ();
    }

  return octave_value (filename);
}

// PKG_ADD: autoload ("fits_closeFile", "__fits__.oct");
DEFUN_DLD(fits_closeFile, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {} fits_closeFile(@var{file})\n \
Close the opened fits file\n \
\n \
The is the eqivalent of the fits_close_file function.\n \
@end deftypefn")
{
  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () != 1 
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  file->close ();

  return octave_value();
}

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

  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () != 1 
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  file->deletefile ();

  return octave_value();
}

// PKG_ADD: autoload ("fits_getHDUnum", "__fits__.oct");
DEFUN_DLD(fits_getHDUnum, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{num}]} = fits_getHDUnum(@var{file})\n \
Return the index of the current HDU\n \
\n \
This is the equivalent of the cfitsio fits_get_hdu_num function.\n \
@end deftypefn")
{

  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () != 1 
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error("fits_getHDUnum: file not open");
      return octave_value ();
    }

  int hdunum, status = 0;

  fits_get_hdu_num(fp, &hdunum);

  return octave_value (hdunum);
}

// PKG_ADD: autoload ("fits_getHDUtype", "__fits__.oct");
DEFUN_DLD(fits_getHDUtype, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{type}]} = fits_getHDUtype(@var{file})\n \
Return the current HDUs type as a string\n \
\n \
This is the equivalent of the cfitsio fits_get_hdu_type function.\n \
@end deftypefn")
{

  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () != 1 
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error("fits_getHDUtype: file not open");
      return octave_value ();
    }

  int hdutype, status = 0;

  if(fits_get_hdu_type(fp, &hdutype, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("fits_getHDUtype: couldnt get hdu type");
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

// PKG_ADD: autoload ("fits_getNumHDUs", "__fits__.oct");
DEFUN_DLD(fits_getNumHDUs, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{num}]} = fits_getNumHDUts(@var{file})\n \
Return the count of HDUs in the file\n \
\n \
This is the equivalent of the cfitsio fits_get_num_hdus function.\n \
@end deftypefn")
{

  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () != 1 
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_getNumHDUs: file not open");
      return octave_value ();
    }

  int cnt, status = 0;

  if(fits_get_num_hdus(fp, &cnt, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("couldnt get num hdus");
      return octave_value ();
    }

  return octave_value(cnt);
}

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

  init_types ();

  if ( args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  if (! args (1).isnumeric ())
    {
      error ("fits_movAbsHDU: expected hdu number");
      return octave_value ();  
    }

  int hdu = args(1).int_value();

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error("fits_movAbsHDU: file not open");
      return octave_value ();
    }
  int status = 0, hdutype;

  if(fits_movabs_hdu(fp, hdu, &hdutype,&status) > 0)
    {
      fits_report_error( stderr, status );
      error ("fits_movAbsHDU: couldnt move hdus");
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

// PKG_ADD: autoload ("fits_movRelHDU", "__fits__.oct");
DEFUN_DLD(fits_movRelHDU, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{num}]} = fits_movRelHDU(@var{file}, @var{hdunum})\n \
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

  init_types ();

  if ( args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }
  if (! args (1).isnumeric ())
    {
      error ("fits_moveRelHDU: expected hdu number");
      return octave_value ();  
    }

  int hdu = args(1).int_value();

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_moveRelHDU: file not open");
      return octave_value ();
    }

  int status = 0, hdutype;

  if(fits_movrel_hdu(fp, hdu, &hdutype,&status) > 0)
    {
      fits_report_error( stderr, status );
      error ("fits_moveRelHDU: couldnt move hdus");
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

  init_types ();

  if ( args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
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

  if (! args (3).isnumeric ())
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

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error("fits_movAbsHDU: file not open");
      return octave_value ();
    }
  int status = 0;

  if(fits_movnam_hdu(fp, hdu, extname_c, extver, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("fits_movNamHDU: couldnt move hdus");
      return octave_value ();
    }

  return octave_value ();
}

// PKG_ADD: autoload ("fits_deleteHDU", "__fits__.oct");
DEFUN_DLD(fits_deleteHDU, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{type}]} = fits_deleteHDU(@var{file})\n \
Delete the currenlt HDU and go to enxt HDU\n \
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

  init_types ();

  if ( args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error("fits_deleteHDU: file not open");
      return octave_value ();
    }

  int status = 0, hdutype;

  if(fits_delete_hdu(fp, &hdutype,&status) > 0)
    {
      fits_report_error ( stderr, status );
      error ("fits_deleteHDU: couldnt delete hdu");
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

  init_types ();

  if ( args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_writeChecksum: file not open");
      return octave_value ();
    }

  int status = 0;

  if (fits_write_chksum(fp, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("fits_writeChecksum: couldnt write checksum");
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

  init_types ();

  if ( args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error("fits_getHdrSpace: file not open");
      return octave_value ();
    }

  int status = 0;
  int nexist, nmore;

  if (fits_get_hdrspace(fp, &nexist, &nmore, &status) > 0)
    {
      fits_report_error ( stderr, status );
      error ("fits_getHdrSpace: couldnt write checksum");
      return octave_value ();
    }

  retval(0) = octave_value(nexist);
  retval(1) = octave_value(nmore);

  return retval;
}

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

  init_types ();

  if ( args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  if (! args (1).isnumeric ())
    {
      error ("fits_readRecord: idx should be a value");
      return octave_value ();  
    }
  int idx = args (1).int_value();

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_readRecord: file not open");
      return octave_value ();
    }

  int status = 0;
  char buffer[FLEN_CARD];

  if (fits_read_record(fp, idx, buffer, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("fits_readRecord: couldnt read record");
      return octave_value ();
   }

  return octave_value(buffer);
}

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

  init_types ();

  if ( args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }
  if (! args (1).is_string ())
    {
      error ("fits_readCard: key should be a string");
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if (!fp)
    {
      error ("fits_readCard: file not open");
      return octave_value ();
    }

  int status = 0;
  char buffer[FLEN_CARD+1];
  std::string key = args (1).string_value ();

  if (fits_read_card(fp, key.c_str(), buffer, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("fits_readCard: couldnt read card");
      return octave_value ();
   }

  return octave_value(buffer);
}

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

  init_types ();

  if ( args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }
  if (! args (1).is_string ())
    {
      error ("fits_readKey: key should be a string");
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if (!fp)
    {
      error ("fits_readKey: file not open");
      return octave_value ();
    }

  int status = 0;
  char vbuffer[FLEN_VALUE];
  char cbuffer[FLEN_VALUE];
  std::string key = args (1).string_value ();

  if (fits_read_key_str(fp, key.c_str(), vbuffer, cbuffer, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("fits_readKey: couldnt read key");
      return octave_value ();
    }

  ret(0) = octave_value(vbuffer);
  ret(1) = octave_value(cbuffer);
  return ret;
}

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

  init_types ();

  if ( args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }
  if (! args (1).is_string ())
    {
      error ("fits_readKeyUnit: key should be a string");
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if (!fp)
    {
      error ("fits_readKeyUnit: file not open");
      return octave_value ();
    }

  int status = 0;
  char buffer[FLEN_VALUE];
  std::string key = args (1).string_value ();

  if (fits_read_key_unit(fp, key.c_str(), buffer, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("fits_readKeyUnit: couldnt read key units");
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

  init_types ();

  if ( args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  if (! args (1).is_string ())
    {
      error ("key should be a string");
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
  {
    error("file not open");
    return octave_value ();
  }
  int status = 0;

  char cbuffer[FLEN_VALUE];
  double val;

  std::string key = args (1).string_value ();

  if(fits_read_key_dbl(fp, key.c_str(), &val, cbuffer, &status) > 0)
  {
      fits_report_error( stderr, status );
      error ("couldnt read key units");
      return octave_value ();
  }
  ret(0) = octave_value(val);
  ret(1) = octave_value(cbuffer);

  return ret;
}

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

  init_types ();

  if ( args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }
  if (! args (1).is_string ())
    {
      error ("key should be a string");
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if (!fp)
    {
      error ("fits_readKeyDblCpmlx: file not open");
      return octave_value ();
    }

  int status = 0;
  char cbuffer[FLEN_VALUE];
  double val[2];
  std::string key = args (1).string_value ();

  if (fits_read_key_dblcmp(fp, key.c_str(), val, cbuffer, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("fits_readKeyDblCpmlx: couldnt read key units");
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

  init_types ();

  if ( args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }
  if (! args (1).is_string ())
    {
      error ("fits_readKeyLongLong: key should be a string");
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if (!fp)
    {
      error ("fits_readKeyLongLong: file not open");
      return octave_value ();
    }

  int status = 0;
  char cbuffer[FLEN_VALUE];
  LONGLONG val;
  std::string key = args (1).string_value ();

  if (fits_read_key_lnglng(fp, key.c_str(), &val, cbuffer, &status) > 0)
    {
      fits_report_error (stderr, status);
      error ("fits_readKeyLongLong: couldnt read key units");
      return octave_value ();
    }

  ret(0) = octave_value(val);
  ret(1) = octave_value(cbuffer);

  return ret;
}

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

  init_types ();

  if ( args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }
  if (! args (1).is_string ())
    {
      error ("fits_readKeyLongLong: key should be a string");
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if (!fp)
    {
      error ("fits_readKeyLongLong: file not open");
      return octave_value ();
    }

  int status = 0;
  char cbuffer[FLEN_VALUE];
  char * val;
  std::string key = args (1).string_value ();

  if (fits_read_key_longstr(fp, key.c_str(), &val, cbuffer, &status) > 0)
    {
      fits_report_error (stderr, status);
      error ("fits_readKeyLongStr: couldnt read key units");
      return octave_value ();
    }

  ret(0) = octave_value(val);
  ret(1) = octave_value(cbuffer);

  // free the key mem
  fits_free_memory(val, &status);

  return ret;
}

// PKG_ADD: autoload ("fits_getConstantValue", "__fits__.oct");
DEFUN_DLD(fits_getConstantValue, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {[@var{value}]} = fits_getConstantValue(@var{name})\n \
Return the value of a known fits constant.\n \
@seealso {fits_getConstantNames}\n \
@end deftypefn")
{
  if ( args.length() == 0)
    {
      print_usage ();
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

  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () != 1 
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_getHDUoff: file not open");
      return octave_value ();
    }

  int status = 0;
  OFF_T headstart, datastart, dataend;

  if(fits_get_hduoff(fp, &headstart, &datastart, &dataend, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("couldnt get offsets");
      return octave_value ();
    }

  ret(0) = octave_value(headstart);
  ret(1) = octave_value(datastart);
  ret(2) = octave_value(dataend);

  return ret;
}

// PKG_ADD: autoload ("fits_getImgSize", "__fits__.oct");
DEFUN_DLD(fits_getImgSize, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{size}} = fits_getImgSize(@var{file})\n \
Return size of a Image HDU\n \
\n \
This is the equivalent of the cfitsio fits_get_img_size function.\n \
@end deftypefn")
{
  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () != 1 
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_getImgSize: file not open");
      return octave_value ();
    }

  int status = 0;
  long axis[100];
  int naxis;

  if (fits_get_img_dim(fp, &naxis, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("couldnt get dims");
      return octave_value ();
    }

  if (naxis > 100)
    naxis = 100;

  if(fits_get_img_size(fp, naxis, axis, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("couldnt get size");
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

// PKG_ADD: autoload ("fits_getImgType", "__fits__.oct");
DEFUN_DLD(fits_getImgType, args, nargout,
"-*- texinfo -*-\n \
@deftypefn {Function File} {@var{type}} = fits_getImgType(@var{file})\n \
Return size of a Image HDU\n \
\n \
This is the equivalent of the cfitsio fits_get_img_type function.\n \
@end deftypefn")
{
  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () != 1 
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_getImgType: file not open");
      return octave_value ();
    }

  int status = 0;
  int type;

  if(fits_get_img_type(fp, &type, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("couldnt get type");
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
  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () < 1
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_readImage: file not open");
      return octave_value ();
    }

  int status = 0;

  int num_axis;
  long axis[100];
  if( fits_get_img_param( fp, 100, 0, &num_axis, axis, &status) > 0 )
  {
      fits_report_error( stderr, status );
      error ("firs_readImage: could not get image paramters");
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
      fits_report_error( stderr, status );
      error ("couldnt get data");
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
  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () < 1
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_isCompressedImg: file not open");
      return octave_value ();
    }

  int status = 0;

  int c = fits_is_compressed_image(fp, &status);

  if(status)
    {
      fits_report_error( stderr, status );
      error ("couldnt get compression");
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

  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () < 1
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  if (args.length () < 2
    || !args (1).isnumeric())
    {
      error ("Expected numeric col number");
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_isCompressedImg: file not open");
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
      fits_report_error( stderr, status );
      error ("couldnt get parms");
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

  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () < 1
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  if (args.length () < 2
    || !args (1).isnumeric())
    {
      error ("Expected numeric col number");
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_isCompressedImg: file not open");
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
      fits_report_error( stderr, status );
      error ("couldnt get parms");
      return octave_value ();
    }

  ret(0) = octave_value(ttype);
  ret(1) = octave_value(tunit);
  ret(2) = octave_value(typechar);
  ret(3) = octave_value(repeat);
  ret(4) = octave_value(scale);
  ret(5) = octave_value(zero);
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

  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () < 1
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
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
  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_isCompressedImg: file not open");
      return octave_value ();
    }

  int status = 0;

  int colnum;
  char colname[FLEN_CARD];

  if(fits_get_colname(fp, casesense, templatestr, colname, &colnum, &status) > 0 && status != COL_NOT_UNIQUE)
    {
      fits_report_error( stderr, status );
      error ("couldnt get column match");
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

  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () < 1
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  if (args.length () < 2
    || !args (1).isnumeric())
    {
      error ("Expected numeric col number");
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_isCompressedImg: file not open");
      return octave_value ();
    }

  int status = 0;
  int colnum = args (1).int_value();
  LONGLONG repeat, width;
  int dtype;

  if(fits_get_coltypell(fp, colnum, &dtype, &repeat, &width, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("couldnt get parms");
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

  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () < 1
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  if (args.length () < 2
    || !args (1).isnumeric())
    {
      error ("Expected numeric col number");
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_isCompressedImg: file not open");
      return octave_value ();
    }

  int status = 0;
  int colnum = args (1).int_value();
  LONGLONG repeat, width;
  int dtype;

  if(fits_get_eqcoltypell(fp, colnum, &dtype, &repeat, &width, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("couldnt get parms");
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

  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () != 1
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_isCompressedImg: file not open");
      return octave_value ();
    }

  int status = 0;
  int ncols;

  if(fits_get_num_cols(fp, &ncols, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("couldnt get parms");
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

  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () != 1
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_isCompressedImg: file not open");
      return octave_value ();
    }

  int status = 0;
  LONGLONG nrows;

  if(fits_get_num_rowsll(fp, &nrows, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("couldnt get parms");
      return octave_value ();
    }

  return octave_value(nrows);
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

  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () != 1
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_getATblHdr: file not open");
      return octave_value ();
    }

  int status = 0;
  int ncols;
  if(fits_get_num_cols(fp, &ncols, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("couldnt get cols");
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
      fits_report_error( stderr, status );
      error ("couldnt get parms");
      return octave_value ();
    }

  Cell ttypev(1, tfields);
  Cell tformv(1, tfields);
  Cell tunitv(1, tfields);
//  string_vector ttypev;
//  string_vector tformv;
//  string_vector tunitv;
  NDArray tbcolv(dim_vector(tfields, 1));

  for (int i=0; i< tfields; i++)
  {
//	  printf("%d - %s\n", i, ttype[i]);
  //  ttypev.append(std::string(ttype[i]));
    //tformv.append(std::string(tform[i]));
  //  tunitv.append(std::string(tunit[i]));
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

  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () != 1
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_getATblHdr: file not open");
      return octave_value ();
    }

  int status = 0;
  int ncols;
  if(fits_get_num_cols(fp, &ncols, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("couldnt get cols");
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
      fits_report_error( stderr, status );
      error ("couldnt get parms");
      return octave_value ();
    }

  Cell ttypev(1, tfields);
  Cell tformv(1, tfields);
  Cell tunitv(1, tfields);
  //string_vector ttypev;
  //string_vector tformv;
  //string_vector tunitv;

  for (int i=0; i< tfields; i++)
  {
  //  ttypev.append(std::string(ttype[i]));
 //   tformv.append(std::string(tform[i]));
   // tunitv.append(std::string(tunit[i]));
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
@deftypefnx {Function File} {[@var{coldata}, @var{nullval}]} = fits_readCol(@var{file}, @var{colnum}i, @var{firstrow}, @var{numrows})\n \
Get table row data\n \
\n \
This is the equivalent of the cfitsio  fits_read_col function.\n \
@end deftypefn")
{
  octave_value_list ret;

  if ( args.length() == 0)
    {
      print_usage ();
      return octave_value();
    }

  init_types ();

  if (args.length () < 2
    || args (0).type_id () != octave_fits_file::static_type_id ())
    {
      print_usage ();
      return octave_value ();  
    }

  if (!args (1).isnumeric())
    {
      error ("expected numeric col value");
      return octave_value ();  
    }

  int col = args(1).int_value();

  octave_fits_file * file = NULL;

  const octave_base_value& rep = args (0).get_rep ();

  file = &((octave_fits_file &)rep);

  fitsfile *fp = file->get_fp();

  if(!fp)
    {
      error ("fits_readCol: file not open");
      return octave_value ();
    }

  // we need
  // // data type want to convert to
  // number of axis ? and sxiis to work out size ??? or do we not need ? as only getting one row ?
  // num rows we have
  // width of row for ascii

  int status;

  int hdutype;

  if(fits_get_hdu_type(fp, &hdutype, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("fits_getHDUtype: couldnt get hdu type");
      return octave_value ();
    }

  LONGLONG nrows;

  if(fits_get_num_rowsll(fp, &nrows, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("couldnt get parms");
      return octave_value ();
    }

/*
  std::string name = "";
  if(hdutype == IMAGE_HDU) 
    name = "IMAGE_HDU";
  else if(hdutype == ASCII_TBL)
    name = "ASCII_TBL";
  else if(hdutype == BINARY_TBL)
    name = "BINARY_TBL";
  else
    name = "UNKNOWN";
*/

  int dtype;
  LONGLONG repeat, width;
  // get data type to use
  if(fits_get_eqcoltypell(fp, col, &dtype, &repeat, &width, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("couldnt get parms");
      return octave_value ();
    }

  // if will read as string, get width
  int charwidth;
  if (fits_get_col_display_width (fp, col, &charwidth, &status) > 0)
  {
      fits_report_error( stderr, status );
      error ("couldnt get col width");
      return octave_value ();
  }


/*
 { "TBYTE", TBYTE },
 { "TSBYTE", TSBYTE },
 { "TLOGICAL", TLOGICAL },
 { "TSTRING", TSTRING },
 { "TUSHORT", TUSHORT },
 { "TSHORT", TSHORT },
 { "TUINT", TUINT },
 { "TINT", TINT },
 { "TULONG", TULONG },
 { "TLONG", TLONG },
 { "TINT32BIT", TINT32BIT },
 { "TFLOAT", TFLOAT },
 { "TULONGLONG", TULONGLONG },
 { "TLONGLONG", TLONGLONG },
 { "TDOUBLE", TDOUBLE },
 { "TCOMPLEX", TCOMPLEX },
 { "TDBLCOMPLEX", TDBLCOMPLEX },
    int fits_read_col / ffgcv
      (fitsfile *fptr, int datatype, int colnum, LONGLONG firstrow, LONGLONG firstelem,
       LONGLONG nelements, DTYPE *nulval, DTYPE *array, int *anynul, int *status)
*/
  
  LONGLONG firstrow = 1;
  LONGLONG firstel = 1;
  LONGLONG nels = nrows;

  char nulval[1] = { '\0' };
  char cdata[charwidth+1];
  char ndata[charwidth+1];

  string_vector strdata;
  string_vector nuldata;

  int anynul;
  // for strings lets just read line by line
  for(LONGLONG i = firstrow;i<nels;i++)
  {
    anynul = 0;
    if(fits_read_col(fp, TSTRING, col, i, firstel, 1, &nulval, cdata, &anynul, &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("couldnt get data");
      return octave_value ();
    }
    strdata.append(std::string(cdata));
    //nuldata.append(std::string(ndata));
    //TODO: if anynull - add this index val to null position list
  }
  ret(0) = strdata;
  ret(1) = nuldata;
/*
  if(fits_read_col(fp, datatype, col, firstrow, firstel, &nels, &nulval, data, &anynull , &status) > 0)
    {
      fits_report_error( stderr, status );
      error ("couldnt get data");
      return octave_value ();
    }

  string_vector ttypev;
  string_vector tformv;
  string_vector tunitv;

  for (int i=0; i< tfields; i++)
  {
    ttypev.append(std::string(ttype[i]));
    tformv.append(std::string(tform[i]));
    tunitv.append(std::string(tunit[i]));
  }

  ret(0) = octave_value(nrows);
  ret(1) = octave_value(ttypev);
  ret(2) = octave_value(tformv);
  ret(3) = octave_value(tunitv);
  ret(4) = octave_value(extname);
  ret(5) = octave_value(pcount);
 */

  return ret;
}




#if 0
%!shared testfile
%! testfile = urlwrite ( ...
%!   'https://fits.gsfc.nasa.gov/nrao_data/tests/pg93/tst0012.fits', ...
%!   tempname() );

%!test
%! assert(fits_getVersion(), fits_getConstantValue("CFITSIO_VERSION"), 1e8);
%! fd = fits_openFile(testfile);
%! assert(fits_getNumHDUs(fd), 5);
%! assert(fits_movAbsHDU(fd, 1), "IMAGE_HDU");
%1 assert(fits_readKeyDbl(fd, "NAXIS"), 2)
%! assert(fits_movRelHDU(fd, 1), "BINARY_TBL");
%1 assert(fits_getHdrSpace(fd), [31 0]);
%!
%! fits_closeFile(fd);

%!test
%! if exist (testfile, 'file')
%!   delete (testfile);
%! endif

#endif
