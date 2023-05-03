---
layout: "default"
permalink: "/functions/25_matlabiofitsinsertRows/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.insertRows"
category: "Low Level Binary and ASCII Tables"
func_name: "matlab.io.fits.insertRows"
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
<dt id="index-insertRows_0028file_002c"><span class="category">: </span><span><em></em> <strong>insertRows(<var>file</var>,</strong> <em><var>firstrow</var>, <var>numrows</var>)</em><a href='#index-insertRows_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Insert rows into a table.
</p>
<p>This is the equivalent of the cfitsio fits_insert_rows function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>firstrow</var> - Start row to insert from.
</p>
<p><var>numrows</var> - Number of rows to add.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>