# octave-cfitsio

Introduction
============

This toolkit provides GNU Octave with I/O routines to read and write
FITS (Flexible Image Transport System) files.

It provides both high and low level functions similar to the Matlab FITS
functions.

Requirements
============

* cfitsio library and dev files

* Octave >= 4.0.0

Installing
==========

To install, run the octave package manager:

1. If running Windows, the package may already be installed:
   type pkg list, to view the installed packages.

2. To install from internet:
   pkg install pkg install https://sourceforge.net/projects/octave-cfitsio/files/vXXXXXX/raspi-XXXXXX.tar.gz/download

3. To install from a local tarball.
   pkg install octave-cfitsio-XXXXXXX.tar.gz

Where XXXXXXX is the version of the package.

Usage:
======

1. Load the package.
   pkg load cfitsio
   (Required each time Octave is started)

2. Use the high-level function calls fitsread, fitswrite, fitsinfo to read and write FITS files.
   or use the low-level functions for custom file manipulation.

Documentation of functions are availible in octave after install and loading.

Known limitations and bugs
==========================

None provided
