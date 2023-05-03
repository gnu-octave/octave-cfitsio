---
layout: "default"
permalink: "/functions/33_matlabiofitssetCompressionType/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.setCompressionType"
category: "Low Level Compression Functions"
func_name: "matlab.io.fits.setCompressionType"
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
<dt id="index-setCompressionType_0028file_002c"><span class="category">: </span><span><em></em> <strong>setCompressionType(<var>file</var>,</strong> <em><var>comptype</var>)</em><a href='#index-setCompressionType_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Set compression type for writing FITS images.
</p>
<p>This is the equivalent of the cfitsio fits_set_compression_type function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>comptype</var> - compression type.
 Valid comptype values are: &rsquo;GZIP&rsquo;, &rsquo;GZIP2&rsquo;, &rsquo;RICE&rsquo;, &rsquo;PLIO&rsquo;, &rsquo;HCOMPRESS&rsquo; or &rsquo;NOCOMPRESS&rsquo;.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>