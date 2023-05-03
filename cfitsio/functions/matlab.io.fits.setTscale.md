---
layout: "default"
permalink: "/functions/24_matlabiofitssetTscale/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.setTscale"
category: "Low Level Image Manipulation"
func_name: "matlab.io.fits.setTscale"
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
<dt id="index-setTscale_0028file_002c"><span class="category">: </span><span><em></em> <strong>setTscale(<var>file</var>,</strong> <em><var>col</var>, <var>scale</var>, <var>zero</var>)</em><a href='#index-setTscale_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Reset scale and zero to be used with reading and writing table data.
</p>
<p>This is the equivalent of the cfitsio fits_set_tscale function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>col</var> - column number
</p>
<p><var>scale</var> - scale value
</p>
<p><var>zero</var> - zero value
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>