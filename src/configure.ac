#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
#
### Copyright (C) 2019 John Donoghue <john.donoghue@ieee.org>
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
AC_INIT([fits], [1.0.7])
AC_CONFIG_HEADERS([config.h])

# Avoid warnings for redefining AH-generated preprocessor symbols of
# Octave.
AH_TOP([#include "undef-ah-octave.h"])

AC_CONFIG_MACRO_DIRS([m4])

# Checks for programs.
AC_PROG_CXX
AC_LANG(C++)
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



# checks for cfitsio
FITSIO_CXXFLAGS=`$PKG_CONFIG --cflags cfitsio`
FITSIO_LIBS=`$PKG_CONFIG --libs cfitsio`
FITSIO_INCPATH=`$PKG_CONFIG --variable=includedir cfitsio`
save_CPPFLAGS="$CPPFLAGS"
CPPFLAGS="$FITSIO_CXXFLAGS $CPPFLAGS"
AC_CHECK_HEADERS([fitsio.h],[],[
  AC_MSG_ERROR([Cant find cfitsio,h])
])
CPPFLAGS=$save_CPPFLAGS
AC_SUBST([FITSIO_LIBS])
AC_SUBST([FITSIO_INCPATH])
AC_SUBST([FITSIO_CXXFLAGS])

# Checks for octave depreciated symbols
## Simple symbol alternatives of different Octave versions.
save_altsyms_CXX="$CXX"
save_altsyms_CXXFLAGS="$CXXFLAGS"
save_altsyms_LDFLAGS="$LDFLAGS"
save_altsyms_LIBS="$LIBS"
OCTINCLUDEDIR=${OCTINCLUDEDIR:-`$MKOCTFILE -p INCFLAGS`}
OCTLIBDIR=${OCTLIBDIR:-`$MKOCTFILE -p OCTLIBDIR`}
CXX=`${MKOCTFILE} -p CXX`
CXXFLAGS="$OCTINCLUDEDIR $CXXFLAGS"
LDFLAGS="-L$OCTLIBDIR $LDFLAGS"
LIBS="-loctinterp $LIBS"

OF_OCTAVE_LIST_ALT_SYMS([
[dnl
  [D_NINT],
  [octave::math::x_nint],
  [[octave::math::x_nint (1);]],
  [OCTAVE__D_NINT],
  [[]],
  [[]]
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

