---
layout: "default"
permalink: "/functions/25_matlabiofitsinsertATbl/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.insertATbl"
category: "Low Level Binary and ASCII Tables"
func_name: "matlab.io.fits.insertATbl"
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
<dt id="index-insertATbl_0028file_002c"><span class="category">: </span><span><em></em> <strong>insertATbl(<var>file</var>,</strong> <em><var>rowlen</var>, <var>nrows</var>, <var>ttype</var>, <var>tbcol</var>, <var>tform</var>)</em><a href='#index-insertATbl_0028file_002c' class='copiable-anchor'></a></span></dt>
<dt id="index-insertATbl_0028file_002c-1"><span class="category">: </span><span><em></em> <strong>insertATbl(<var>file</var>,</strong> <em><var>rowlen</var>, <var>nrows</var>, <var>ttype</var>, <var>tbcol</var>, <var>tform</var>, <var>tunit</var>)</em><a href='#index-insertATbl_0028file_002c-1' class='copiable-anchor'></a></span></dt>
<dt id="index-insertATbl_0028file_002c-2"><span class="category">: </span><span><em></em> <strong>insertATbl(<var>file</var>,</strong> <em><var>tbltype</var>, <var>nrows</var>, <var>ttype</var>, <var>tbcol</var>, <var>tform</var>, <var>tunit</var>, <var>extname</var>)</em><a href='#index-insertATbl_0028file_002c-2' class='copiable-anchor'></a></span></dt>
<dd><p>Insert a new ASCII table after current HDU.
</p>
<p>This is the equivalent of the cfitsio fits_insert_atbl function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>rowlen</var> - row length. If set to 0, the function will calculate size based on 
 tbcol and ttype.
</p>
<p><var>nrows</var> - initial number of rows (normally 0)
</p>
<p><var>ttype</var> - cell array of column type
</p>
<p><var>tbcol</var> - array containing the start indices for each column.
</p>
<p><var>tform</var> - cell array of column format
</p>
<p><var>tunit</var> - cell array of column units
</p>
<p><var>extname</var> - optional extension name
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
</p>
</dd></dl>