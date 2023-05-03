---
layout: "default"
permalink: "/functions/25_matlabiofitssetTileDim/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.setTileDim"
category: "Low Level Compression Functions"
func_name: "matlab.io.fits.setTileDim"
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
<dt id="index-setTileDim_0028file_002c"><span class="category">: </span><span><em></em> <strong>setTileDim(<var>file</var>,</strong> <em><var>tiledims</var>)</em><a href='#index-setTileDim_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Set compression tile dims for writing FITS images.
</p>
<p>This is the equivalent of the cfitsio fits_set_tile_dim function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>tiledims</var> - tile dimensions
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>