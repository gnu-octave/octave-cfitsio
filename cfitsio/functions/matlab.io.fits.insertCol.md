---
layout: "default"
permalink: "/functions/24_matlabiofitsinsertCol/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.insertCol"
category: "Low Level Binary and ASCII Tables"
func_name: "matlab.io.fits.insertCol"
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
<dt id="index-insertCol_0028file_002c"><span class="category">: </span><span><em></em> <strong>insertCol(<var>file</var>,</strong> <em><var>colnum</var>, <var>ttype</var>, <var>tform</var>)</em><a href='#index-insertCol_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Insert a column into a table.
</p>
<p>This is the equivalent of the cfitsio fits_insert_col function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>colnum</var> - Column to delete from current table.
</p>
<p><var>ttype</var>, <var>tform</var> - column type to insert
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>