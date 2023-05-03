---
layout: "default"
permalink: "/functions/26_matlabiofitsimgCompress/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.imgCompress"
category: "Low Level Compression Functions"
func_name: "matlab.io.fits.imgCompress"
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
<dt id="index-imgCompress_0028infile_002c"><span class="category">: </span><span><em></em> <strong>imgCompress(<var>infile</var>,</strong> <em><var>outfile</var>)</em><a href='#index-imgCompress_0028infile_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Copy HDU and image data from one infile to another, using the outfiles compression type.
</p>
<p>This is the equivalent of the cfitsio fits_img_compress function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>infile</var> - opened input fits file.
</p>
<p><var>outfile</var> - opened writable output fits file.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>