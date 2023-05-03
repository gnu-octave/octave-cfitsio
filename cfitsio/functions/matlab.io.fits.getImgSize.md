---
layout: "default"
permalink: "/functions/25_matlabiofitsgetImgSize/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.getImgSize"
category: "Low Level Image Manipulation"
func_name: "matlab.io.fits.getImgSize"
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
<dt id="index-_003d"><span class="category">: </span><span><em><var>size</var></em> <strong>=</strong> <em>getImgSize(<var>file</var>)</em><a href='#index-_003d' class='copiable-anchor'></a></span></dt>
<dd><p>Return size of a Image HDU.
</p>
<p>This is the equivalent of the cfitsio fits_get_img_size function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>size</var> - vector containing the image dimensions.
 </p></dd></dl>