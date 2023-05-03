---
layout: "default"
permalink: "/functions/24_matlabiofitsmovRelHDU/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.movRelHDU"
category: "Low Level HDU Functions"
func_name: "matlab.io.fits.movRelHDU"
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
<dt id="index-_003d"><span class="category">: </span><span><em><var>type</var></em> <strong>=</strong> <em>movRelHDU(<var>file</var>, <var>hdunum</var>)</em><a href='#index-_003d' class='copiable-anchor'></a></span></dt>
<dd><p>Go to relative HDU index <var>hdunum</var>.
</p>
<p>Returns the newly current HDU type as a string.
</p>
<p>This is the equivalent of the cfitsio fits_movrel_hdu function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>hdunum</var> - relative HDU number to move to.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>type</var> - hdu type of the now current HDU. 
 </p></dd></dl>