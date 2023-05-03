---
layout: "default"
permalink: "/functions/28_matlabiofitswriteChecksum/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.writeChecksum"
category: "Low Level HDU Functions"
func_name: "matlab.io.fits.writeChecksum"
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
<dt id="index-writeChecksum_0028file_0029"><span class="category">: </span><span><em></em> <strong>writeChecksum(<var>file</var>)</strong><a href='#index-writeChecksum_0028file_0029' class='copiable-anchor'></a></span></dt>
<dd><p>Recalculate the HDU checksum and if required, write the new value.
</p>
<p>This is the equivalent of the cfitsio fits_write_chksum function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>