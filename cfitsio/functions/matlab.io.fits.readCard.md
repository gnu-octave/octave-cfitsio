---
layout: "default"
permalink: "/functions/23_matlabiofitsreadCard/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.readCard"
category: "Low Level Keyword Functions"
func_name: "matlab.io.fits.readCard"
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
<dt id="index-readCard_0028file_002c"><span class="category">: </span><span><em><var>card</var> =</em> <strong>readCard(<var>file</var>,</strong> <em><var>recname</var>)</em><a href='#index-readCard_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Read the keyword card for name <var>recname</var>
</p> 
<p>This is the equivalent of the cfitsio fits_read_card function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>recname</var> - record name to read
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>card</var> - unparsed record value string
 </p></dd></dl>