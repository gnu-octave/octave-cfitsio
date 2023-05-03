---
layout: "default"
permalink: "/functions/25_matlabiofitsinsertBTbl/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.insertBTbl"
category: "Low Level Binary and ASCII Tables"
func_name: "matlab.io.fits.insertBTbl"
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
<dt id="index-insertBTbl_0028file_002c"><span class="category">: </span><span><em></em> <strong>insertBTbl(<var>file</var>,</strong> <em><var>nrows</var>, <var>ttype</var>, <var>tform</var>, <var>tunit</var>, <var>extname</var>, <var>pcount</var>)</em><a href='#index-insertBTbl_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Insert a new bintable extension.
</p>
<p>This is the equivalent of the cfitsio fits_insert_btbl function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>nrows</var> - initial number of rows (normally 0)
</p>
<p><var>ttype</var> - cell array of column type
</p>
<p><var>tform</var> - cell array of column format
</p>
<p><var>tunit</var> - cell array of column units
</p>
<p><var>extname</var> - optional extension name
</p>
<p><var>pcount</var> - heap size.
</p>
<p><var>ttype</var>, <var>tform</var>, <var>tunit</var> are expected to be the same size.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>