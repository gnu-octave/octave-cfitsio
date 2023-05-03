---
layout: "default"
permalink: "/functions/27_matlabiofitsdeleteRecord/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.deleteRecord"
category: "Low Level Keyword Functions"
func_name: "matlab.io.fits.deleteRecord"
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
<dt id="index-deleteRecord_0028file_002c"><span class="category">: </span><span><em></em> <strong>deleteRecord(<var>file</var>,</strong> <em><var>keynum</var>)</em><a href='#index-deleteRecord_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Delete a key in the fits file.
</p>
<p>This is the equivalent of the cfitsio fits_delete_record function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>keynum</var> - Record number to remove.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>