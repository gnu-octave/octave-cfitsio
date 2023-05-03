---
layout: "default"
permalink: "/functions/25_matlabiofitsgetColName/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.getColName"
category: "Low Level Binary and ASCII Tables"
func_name: "matlab.io.fits.getColName"
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
<dt id="index-_003d"><span class="category">: </span><span><em>[<var>colnum</var>,<var>colname</var>]</em> <strong>=</strong> <em>getColName(<var>file</var>, <var>template</var>)</em><a href='#index-_003d' class='copiable-anchor'></a></span></dt>
<dt id="index-_003d-1"><span class="category">: </span><span><em>[<var>colnum</var>,<var>colname</var>]</em> <strong>=</strong> <em>getColName(<var>file</var>, <var>template</var>, <var>casesens</var>)</em><a href='#index-_003d-1' class='copiable-anchor'></a></span></dt>
<dd><p>Get column name.
</p>
<p>This is the equivalent of the cfitsio fits_get_colname function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>template</var> - template string for matching column name.
</p>
<p><var>casesens</var> - boolean whether to be case sensitive in match.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>colnum</var> - column number of match.
</p>
<p><var>colname</var> - column name of match.
</p>
<span id="Examples"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;
 filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;);
 fd = fits.openFile(filename);
 fits.movAbsHDU(fd,2);
 [colnum, colname] = fits.getColName(fd,&quot;C*&quot;);
 # returned 3, &quot;COUNTS&quot;
 fits.closeFile(fd);
 </pre></div>
</dd></dl>