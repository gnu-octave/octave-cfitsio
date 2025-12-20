---
layout: "default"
permalink: "/functions/24_matlabiofitscreateTbl/"
pkg_name: "cfitsio"
pkg_version: "0.0.7"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.createTbl"
category: "Low Level Functions"
func_name: "matlab.io.fits.createTbl"
navigation:
- id: "overview"
  name: "Overview"
  url: "/index"
- id: "Functions"
  name: "Function Reference"
  url: "/functions"
- id: "25_HighLevelFileFunctions"
  name: "&nbsp;&nbsp;High Level File Functions"
  url: "/functions/#25_HighLevelFileFunctions"
  subitems:
- id: "19_LowLevelFunctions"
  name: "&nbsp;&nbsp;Low Level Functions"
  url: "/functions/#19_LowLevelFunctions"
  subitems:
  - id: "34_LowLevelFunctions-FileFunctions"
    name: "&nbsp;&nbsp;&nbsp;&nbsp;File Functions"
    url: "/functions/#34_LowLevelFunctions-FileFunctions"
  - id: "33_LowLevelFunctions-HDUFunctions"
    name: "&nbsp;&nbsp;&nbsp;&nbsp;HDU Functions"
    url: "/functions/#33_LowLevelFunctions-HDUFunctions"
  - id: "37_LowLevelFunctions-KeywordFunctions"
    name: "&nbsp;&nbsp;&nbsp;&nbsp;Keyword Functions"
    url: "/functions/#37_LowLevelFunctions-KeywordFunctions"
  - id: "38_LowLevelFunctions-ImageManipulation"
    name: "&nbsp;&nbsp;&nbsp;&nbsp;Image Manipulation"
    url: "/functions/#38_LowLevelFunctions-ImageManipulation"
  - id: "37_LowLevelFunctions-UtilityFunctions"
    name: "&nbsp;&nbsp;&nbsp;&nbsp;Utility Functions"
    url: "/functions/#37_LowLevelFunctions-UtilityFunctions"
  - id: "41_LowLevelFunctions-CompressionFunctions"
    name: "&nbsp;&nbsp;&nbsp;&nbsp;Compression Functions"
    url: "/functions/#41_LowLevelFunctions-CompressionFunctions"
  - id: "43_LowLevelFunctions-BinaryandASCIITables"
    name: "&nbsp;&nbsp;&nbsp;&nbsp;Binary and ASCII Tables"
    url: "/functions/#43_LowLevelFunctions-BinaryandASCIITables"
  - id: "36_LowLevelFunctions-Importfunctions"
    name: "&nbsp;&nbsp;&nbsp;&nbsp;Import functions"
    url: "/functions/#36_LowLevelFunctions-Importfunctions"
- id: "news"
  name: "News"
  url: "/news"
- id: "manual"
  name: "Manual"
  url: "/manual"
---
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-createTbl_0028file_002c"><span class="category-def">: </span><span><strong class="def-name">createTbl(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">tbltype</var>, <var class="var">nrows</var>, <var class="var">ttype</var>, <var class="var">tform</var>)</code><a class="copiable-link" href="#index-createTbl_0028file_002c"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-createTbl_0028file_002c-1"><span class="category-def">: </span><span><strong class="def-name">createTbl(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">tbltype</var>, <var class="var">nrows</var>, <var class="var">ttype</var>, <var class="var">tform</var>, <var class="var">tunit</var>)</code><a class="copiable-link" href="#index-createTbl_0028file_002c-1"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-createTbl_0028file_002c-2"><span class="category-def">: </span><span><strong class="def-name">createTbl(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">tbltype</var>, <var class="var">nrows</var>, <var class="var">ttype</var>, <var class="var">tform</var>, <var class="var">tunit</var>, <var class="var">extname</var>)</code><a class="copiable-link" href="#index-createTbl_0028file_002c-2"></a></span></dt>
<dd><p>Create a new ASCII or bintable extension.
</p>
<p>This is the equivalent of the cfitsio fits_create_tbl function.
</p>
<h4 class="subsubheading" id="Inputs"><span>Inputs<a class="copiable-link" href="#Inputs"></a></span></h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">tbltype</var> - table type &rsquo;binary&rsquo; or &rsquo;ascii&rsquo;.
</p>
<p><var class="var">nrows</var> - initial number of rows (normally 0)
</p>
<p><var class="var">ttype</var> - cell array of column type
</p>
<p><var class="var">tform</var> - cell array of column format
</p>
<p><var class="var">tunit</var> - cell array of column units
</p>
<p><var class="var">extname</var> - optional extension name
</p>
<p><var class="var">ttype</var>, <var class="var">tform</var>, <var class="var">tunit</var> are expected to be the same size.
</p>
<h4 class="subsubheading" id="Outputs"><span>Outputs<a class="copiable-link" href="#Outputs"></a></span></h4>
<p>None
</p>
<h4 class="subsubheading" id="Examples"><span>Examples<a class="copiable-link" href="#Examples"></a></span></h4>
<div class="example">
<pre class="example-preformatted"> import_fits;
 fd = fits.createFile(&quot;test.fits&quot;);
 ttype = {'Col1','Col2','Col3','Col4'};
 tform = {'A9','A4','A3','A8'};
 tunit = {'m','s','kg','km'};
 fits.createTbl(fd,'binary',0,ttype,tform,tunit,'table-name');
 fits.closeFile(fd);
 </pre></div>
</dd></dl>