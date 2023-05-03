---
layout: "default"
permalink: "/functions/25_matlabiofitsreadRecord/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.readRecord"
category: "Low Level Keyword Functions"
func_name: "matlab.io.fits.readRecord"
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
<dt id="index-readRecord_0028file_002c"><span class="category">: </span><span><em><var>rec</var> =</em> <strong>readRecord(<var>file</var>,</strong> <em><var>recidx</var>)</em><a href='#index-readRecord_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Read the keyword record at <var>recidx</var>.
</p>
<p>This is the equivalent of the cfitsio fits_read_record function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>recidx</var> - record number.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>rec</var> - full keyword record
 </p></dd></dl>