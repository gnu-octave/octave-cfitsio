---
layout: "default"
permalink: "/functions/24_matlabiofitscreateTbl/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.createTbl"
category: "Low Level Binary and ASCII Tables"
func_name: "matlab.io.fits.createTbl"
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
<dt id="index-createTbl_0028file_002c"><span class="category">: </span><span><em></em> <strong>createTbl(<var>file</var>,</strong> <em><var>tbltype</var>, <var>nrows</var>, <var>ttype</var>, <var>tform</var>)</em><a href='#index-createTbl_0028file_002c' class='copiable-anchor'></a></span></dt>
<dt id="index-createTbl_0028file_002c-1"><span class="category">: </span><span><em></em> <strong>createTbl(<var>file</var>,</strong> <em><var>tbltype</var>, <var>nrows</var>, <var>ttype</var>, <var>tform</var>, <var>tunit</var>)</em><a href='#index-createTbl_0028file_002c-1' class='copiable-anchor'></a></span></dt>
<dt id="index-createTbl_0028file_002c-2"><span class="category">: </span><span><em></em> <strong>createTbl(<var>file</var>,</strong> <em><var>tbltype</var>, <var>nrows</var>, <var>ttype</var>, <var>tform</var>, <var>tunit</var>, <var>extname</var>)</em><a href='#index-createTbl_0028file_002c-2' class='copiable-anchor'></a></span></dt>
<dd><p>Create a new ASCII or bintable extension.
</p>
<p>This is the equivalent of the cfitsio fits_create_tbl function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>tbltype</var> - table type &rsquo;binary&rsquo; or &rsquo;ascii&rsquo;.
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
<p><var>ttype</var>, <var>tform</var>, <var>tunit</var> are expected to be the same size.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
</p>
<span id="Examples"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;
 fd = fits.createFile(&quot;test.fits&quot;);
 ttype = {'Col1','Col2','Col3','Col4'};
 tform = {'A9','A4','A3','A8'};
 tunit = {'m','s','kg','km'};
 fits.createTbl(fd,'binary',0,ttype,tform,tunit,'table-name');
 fits.closeFile(fd);
 </pre></div>
</dd></dl>