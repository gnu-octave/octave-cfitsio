---
layout: "default"
permalink: "/functions/26_matlabiofitsgetHdrSpace/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.getHdrSpace"
category: "Low Level Keyword Functions"
func_name: "matlab.io.fits.getHdrSpace"
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
<dt id="index-getHdrSpace_0028file_0029"><span class="category">: </span><span><em>[<var>numkeys</var>, <var>freekeys</var>] =</em> <strong>getHdrSpace(<var>file</var>)</strong><a href='#index-getHdrSpace_0028file_0029' class='copiable-anchor'></a></span></dt>
<dd><p>Get the number of keyword records used and available.
</p>
<p>This is the equivalent of the cfitsio fits_get_hdrspace function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>numkeys</var> - number of existing keys.
</p>
<p><var>freekeys</var> - number of free key space.
 </p></dd></dl>