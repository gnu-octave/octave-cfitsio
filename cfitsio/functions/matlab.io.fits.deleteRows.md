---
layout: "default"
permalink: "/functions/25_matlabiofitsdeleteRows/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.deleteRows"
category: "Low Level Binary and ASCII Tables"
func_name: "matlab.io.fits.deleteRows"
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
<dt id="index-deleteRows_0028file_002c"><span class="category">: </span><span><em></em> <strong>deleteRows(<var>file</var>,</strong> <em><var>firstrow</var>, <var>numrows</var>)</em><a href='#index-deleteRows_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Insert a rows into a table.
</p>
<p>This is the equivalent of the cfitsio fits_delete_rows function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>firstrow</var> - Start row to delete.
</p>
<p><var>numrows</var> - Number of rows to delete.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>