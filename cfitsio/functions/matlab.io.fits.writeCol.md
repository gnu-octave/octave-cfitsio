---
layout: "default"
permalink: "/functions/23_matlabiofitswriteCol/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.writeCol"
category: "Low Level Binary and ASCII Tables"
func_name: "matlab.io.fits.writeCol"
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
<dt id="index-writeCol_0028file_002c"><span class="category">: </span><span><em></em> <strong>writeCol(<var>file</var>,</strong> <em><var>colnum</var>, <var>firstrow</var>, <var>data</var>)</em><a href='#index-writeCol_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Write elements to a table.
</p>
<p>This is the equivalent of the cfitsio fits_write_col function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>colnum</var> - column number.
</p>
<p><var>firstrow</var> - first row number.
</p>
<p><var>data</var> - data to write to column
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>