#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
#
### Copyright (C) 2019-2024 John Donoghue <john.donoghue@ieee.org>
###
### This program is free software; you can redistribute it and/or
### modify it under the terms of the GNU General Public License as
### published by the Free Software Foundation; either version 3 of the
### License, or (at your option) any later version.
###
### This program is distributed in the hope that it will be useful,
### but WITHOUT ANY WARRANTY; without even the implied warranty of
### MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
### General Public License for more details.
###
### You should have received a copy of the GNU General Public License
### along with this program; if not, see
### <http://www.gnu.org/licenses/>.

AC_PREREQ([2.67])
AC_INIT([cfitsio], [0.0.7])
AC_CONFIG_HEADERS([config.h])

# Avoid warnings for redefining AH-generated preprocessor symbols of
# Octave.
AH_TOP([#include "undef-ah-octave.h"])

AC_CONFIG_MACRO_DIRS([m4])

AC_CANONICAL_HOST
AC_CANONICAL_TARGET

# Checks for programs.
AC_PROG_CXX
AC_PROG_CXXCPP
AC_LANG(C++)

# check can access std c files
AC_CHECK_HEADERS([string.h])

AC_CHECK_PROG(PKG_CONFIG, pkg-config, pkg-config)
AC_PROG_GREP
AC_PROG_SED

AC_CHECK_TOOL([MKOCTFILE], [mkoctfile], [none])
if [ test "$MKOCTFILE" = "none" ]; then
  AC_MSG_ERROR([mkoctfile required to install $PACKAGE_NAME])
fi

AC_CHECK_TOOL([OCTAVE_CONFIG], [octave-config], [none])
if [ test "$OCTAVE_CONFIG" = "none" ]; then
  AC_MSG_ERROR([octave-config required to install $PACKAGE_NAME])
fi

# try get around possible spaces in the path
if test "X${IGNORE_MINGW_PATH_MODIFICATION}" == "X"; then
case $host_os in
  mingw*)
    # try demangle spaces in escaped input strings
    MKOCTFILE=`echo $MKOCTFILE | $SED "s,\\\\\ ,?,g"`
    OCTAVE_CONFIG=`echo $OCTAVE_CONFIG | $SED "s,\\\\\ ,?,g"`
    ;;
  *)
    ;;
esac
fi

# Check for Windows
AC_MSG_CHECKING([for windows])
have_windows=no
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
   #include <windows.h>
   #ifndef __WIN32__
     #error "Not windows!"
   #endif
  ]], [])],
 [AC_MSG_RESULT([yes])
  have_windows=yes],
 [AC_MSG_RESULT([no])])

# checks for libcfitsio
if test  "x$PKG_CONFIG" != "x" ; then
  FITSIO_CXXFLAGS=`$PKG_CONFIG --cflags cfitsio`
  if test $have_windows = yes; then
    # in windows we need to know and link in dependant libs as well, so use static
    FITSIO_LIBS=`$PKG_CONFIG --static --libs cfitsio`
  else
    FITSIO_LIBS=`$PKG_CONFIG --libs cfitsio`
  fi
  FITSIO_INCPATH=`$PKG_CONFIG --variable=includedir cfitsio`
fi

save_CPPFLAGS="$CPPFLAGS"
save_LDFLAGS=$LDFLAGS
# spaces in paths can mess stuff up
# so if cant find the header, do a manual find
if test "$FITSIO_CXXFLAGS$FITSIO_LIBS" != "" ; then
  CPPFLAGS="$FITSIO_CXXFLAGS $save_CPPFLAGS"
  AC_CHECK_HEADERS([fitsio.h], ,
     [FITSIO_CXXFLAGS=""; FITSIO_LIBS=""],
   )
fi

if test "$FITSIO_CXXFLAGS$FITSIO_LIBS" == "" ; then
  AC_MSG_NOTICE([Trying fallback FITSIO detection])

  # find headers first
  AC_MSG_CHECKING([for fitsio headers path])
  found_header=
  for p in [ /usr/include /usr/local/include /opt/include /mingw32/include /mingw64/include ]; do
    for v in [ '' cfitsio ]; do
      file_name="$p/$v/fitsio.h"
      if test -f $file_name; then 
        CPPFLAGS="-I$p/$v $save_CPPFLAGS"
        AC_COMPILE_IFELSE(
          [AC_LANG_PROGRAM([
           #include <fitsio.h>
          ],
          [
            int i=0;
          ])],
        [found_header="$p/$v"],
        [])
      fi
    done
  done

  if test "$found_header" == "" ; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Unable to find CFITSIO headers]),
  else
    AC_MSG_RESULT([$found_header])
    FITSIO_CXXFLAGS="-I$found_header"
    FITSIO_INCPATH="$found_header"
    FITSIO_LIBS=-lcfitsio
    if test $have_windows = yes; then
      FITSIO_LIBS="$FITSIO_LIBS -lz"
    fi
  fi
fi

CPPFLAGS=$save_CPPFLAGS
LDFLAGS=$save_LDFLAGS

AC_SUBST([FITSIO_LIBS])
AC_SUBST([FITSIO_INCPATH])
AC_SUBST([FITSIO_CXXFLAGS])

# Checks for octave depreciated symbols
## Simple symbol alternatives of different Octave versions.
save_altsyms_CXX="$CXX"
save_altsyms_CXXFLAGS="$CXXFLAGS"
save_altsyms_LDFLAGS="$LDFLAGS"
save_altsyms_LIBS="$LIBS"
OCTINCLUDEDIR="${OCTINCLUDEDIR:-`$MKOCTFILE -p OCTINCLUDEDIR`}/.."
OCTLIBDIR=${OCTLIBDIR:-`$MKOCTFILE -p OCTLIBDIR`}

if test "X${IGNORE_MINGW_PATH_MODIFICATION}" == "X"; then
  MSYSTEM="${MSYSTEM}"
else
  MSYSTEM="none"
fi

case X$MSYSTEM in
  XMINGW64*)
    OCTAVE_HOME=`${MKOCTFILE} -p OCTAVE_HOME | $SED 's,\\\\,/,g'`
    # change \ to / and replace octave home part with mingw part
    OCTINCLUDEDIR=`echo $OCTINCLUDEDIR | $SED -e 's,\\\\,/,g' -e "s,${OCTAVE_HOME},/mingw64,g"`
    OCTLIBDIR=`echo $OCTLIBDIR | $SED -e 's,\\\\,/,g' -e "s,${OCTAVE_HOME},/mingw64,g"`
    ;;
  XMINGW32*)
    OCTAVE_HOME=`${MKOCTFILE} -p OCTAVE_HOME | $SED 's,\\\\,/,g'`
    # change \ to / and replace octave home part with mingw part
    OCTINCLUDEDIR=`echo $OCTINCLUDEDIR | $SED -e 's,\\\\,/,g' -e "s,${OCTAVE_HOME},/mingw32,g"`
    OCTLIBDIR=`echo $OCTLIBDIR | $SED -e 's,\\\\,/,g -e "s,${OCTAVE_HOME},/mingw32,g"'`
    ;;
  *)
    ;;
esac

CXX=`${MKOCTFILE} -p CXX`
CXXFLAGS="-I$OCTINCLUDEDIR $CXXFLAGS"
LDFLAGS="-L$OCTLIBDIR $LDFLAGS"
LIBS="-loctinterp $LIBS"

# includes
AC_CHECK_HEADERS([octave/interpreter.h],
  [],
  [],
  [#include <octave/oct.h>]
)

OF_OCTAVE_LIST_ALT_SYMS([

[dnl
  [is_cellstr],
  [iscellstr],
  [[octave_value ().iscellstr ();]],
  [OV_ISCELLSTR],
  [],
  []
],

[dnl
  [is_cell],
  [iscell],
  [[octave_value ().iscell ();]],
  [OV_ISCELL],
  [],
  []
],

[dnl
  [is_integer_type],
  [isinteger],
  [[octave_value ().isinteger ();]],
  [OV_ISINTEGER],
  [],
  []
],

[dnl
  [is_numeric_type],
  [isnumeric],
  [[octave_value ().isnumeric ();]],
  [OV_ISNUMERIC],
  [],
  []
],

[dnl
  [is_bool_type],
  [islogical],
  [[octave_value ().islogical ();]],
  [OV_ISLOGICAL],
  [],
  []
],

[dnl
  [is_empty],
  [isempty],
  [[octave_value ().isempty ();]],
  [OV_ISEMPTY],
  [],
  []
]

],[oct-alt-includes.h])

CXX=$save_altsyms_CXX
CXXFLAGS=$save_altsyms_CXXFLAGS
LDFLAGS=$save_altsyms_LDFLAGS
LIBS=$save_altsyms_LIBS


AC_CONFIG_FILES([Makefile])
AC_OUTPUT

AC_MSG_NOTICE([

$PACKAGE_NAME is configured with:
  LIBS:     $LIBS $FITSIO_LIBS
  CXXFLAGS: $CXXFLAGS $FITSIO_CXXFLAGS $DEFS
])

