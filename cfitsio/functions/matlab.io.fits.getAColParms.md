---
layout: "default"
permalink: "/functions/27_matlabiofitsgetAColParms/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.getAColParms"
category: "Low Level Binary and ASCII Tables"
func_name: "matlab.io.fits.getAColParms"
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
<dt id="index-_003d"><span class="category">: </span><span><em>[<var>ttype</var>,<var>tbcol</var>,<var>tunit</var>,<var>tform</var>,<var>scale</var>,<var>zero</var>,<var>nulstr</var>,<var>tdisp</var>]</em> <strong>=</strong> <em>getAColParms(<var>file</var>, <var>colnum</var>)</em><a href='#index-_003d' class='copiable-anchor'></a></span></dt>
<dd><p>Get ASCII table parameters.
</p>
<p>This is the equivalent of the cfitsio fits_get_acolparms function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>colnum</var> - Column to retrieve.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>ttype</var>,<var>tbcol</var>,<var>tunit</var>,<var>tform</var>,<var>scale</var>,<var>zero</var>,<var>nulstr</var>,<var>tdisp</var>
 column information in same format as provided by fits_get_acolparms.
 </p></dd></dl>