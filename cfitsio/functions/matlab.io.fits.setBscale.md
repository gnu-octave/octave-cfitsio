---
layout: "default"
permalink: "/functions/24_matlabiofitssetBscale/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.setBscale"
category: "Low Level Image Manipulation"
func_name: "matlab.io.fits.setBscale"
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
<dt id="index-setBscale_0028file_002c"><span class="category">: </span><span><em></em> <strong>setBscale(<var>file</var>,</strong> <em><var>bscale</var>, <var>bzero</var>)</em><a href='#index-setBscale_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Reset bscale and bzero to be used with reading and writing Images.
</p>
<p>This is the equivalent of the cfitsio fits_set_bscale function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>bscale</var> - bscale value
</p>
<p><var>bzero</var> - bzero value
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>