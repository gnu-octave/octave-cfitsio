---
layout: "default"
permalink: "/functions/25_matlabiofitsgetNumCols/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.getNumCols"
category: "Low Level Binary and ASCII Tables"
func_name: "matlab.io.fits.getNumCols"
navigation:
- id: "overview"
  name: "Overview"
  url: "/index"
- id: "Functions"
  name: "Function Reference"
  url: "/functions"
- id: "news"
  name: "News"
  url: "/news"
- id: "manual"
  name: "Manual"
  url: "/manual"
---
<dl class="def">
<dt id="index-_003d"><span class="category">: </span><span><em><var>ncols</var></em> <strong>=</strong> <em>getNumCols(<var>file</var>)</em><a href='#index-_003d' class='copiable-anchor'></a></span></dt>
<dd><p>Get number of columns.
</p>
<p>This is the equivalent of the cfitsio  fits_get_num_cols function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>ncols</var> - the number of columns in the table.
 </p></dd></dl>