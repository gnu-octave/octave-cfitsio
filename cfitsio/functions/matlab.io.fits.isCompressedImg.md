---
layout: "default"
permalink: "/functions/30_matlabiofitsisCompressedImg/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.isCompressedImg"
category: "Low Level Compression Functions"
func_name: "matlab.io.fits.isCompressedImg"
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
<dt id="index-isCompressedImg_0028file_0029"><span class="category">: </span><span><em><var>comp</var> =</em> <strong>isCompressedImg(<var>file</var>)</strong><a href='#index-isCompressedImg_0028file_0029' class='copiable-anchor'></a></span></dt>
<dd><p>Return true if image is compressed.
</p>
<p>This is the equivalent of the cfitsio fits_is_compressed_image function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>comp</var> - boolean for whether image is compressed or not. 
 </p></dd></dl>