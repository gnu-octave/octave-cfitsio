---
layout: "default"
permalink: "/functions/24_matlabiofitscreateTbl/"
pkg_name: "cfitsio"
pkg_version: "0.0.7"
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
- id: "25_HighLevelFileFunctions"
  name: "&nbsp;&nbsp;High Level File Functions"
  url: "/functions/#25_HighLevelFileFunctions"
- id: "24_LowLevelFileFunctions"
  name: "&nbsp;&nbsp;Low Level File Functions"
  url: "/functions/#24_LowLevelFileFunctions"
- id: "23_LowLevelHDUFunctions"
  name: "&nbsp;&nbsp;Low Level HDU Functions"
  url: "/functions/#23_LowLevelHDUFunctions"
- id: "27_LowLevelKeywordFunctions"
  name: "&nbsp;&nbsp;Low Level Keyword Functions"
  url: "/functions/#27_LowLevelKeywordFunctions"
- id: "28_LowLevelImageManipulation"
  name: "&nbsp;&nbsp;Low Level Image Manipulation"
  url: "/functions/#28_LowLevelImageManipulation"
- id: "27_LowLevelUtilityFunctions"
  name: "&nbsp;&nbsp;Low Level Utility Functions"
  url: "/functions/#27_LowLevelUtilityFunctions"
- id: "31_LowLevelCompressionFunctions"
  name: "&nbsp;&nbsp;Low Level Compression Functions"
  url: "/functions/#31_LowLevelCompressionFunctions"
- id: "33_LowLevelBinaryandASCIITables"
  name: "&nbsp;&nbsp;Low Level Binary and ASCII Tables"
  url: "/functions/#33_LowLevelBinaryandASCIITables"
- id: "16_Importfunctions"
  name: "&nbsp;&nbsp;Import functions"
  url: "/functions/#16_Importfunctions"
- id: "news"
  name: "News"
  url: "/news"
- id: "manual"
  name: "Manual"
  url: "/manual"
---
<dl class="first-deftypefn">
<dt class="deftypefn" id="index-createTbl_0028file_002c"><span class="category-def">: </span><span><strong class="def-name">createTbl(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">tbltype</var>, <var class="var">nrows</var>, <var class="var">ttype</var>, <var class="var">tform</var>)</code><a class="copiable-link" href="#index-createTbl_0028file_002c"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn" id="index-createTbl_0028file_002c-1"><span class="category-def">: </span><span><strong class="def-name">createTbl(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">tbltype</var>, <var class="var">nrows</var>, <var class="var">ttype</var>, <var class="var">tform</var>, <var class="var">tunit</var>)</code><a class="copiable-link" href="#index-createTbl_0028file_002c-1"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn" id="index-createTbl_0028file_002c-2"><span class="category-def">: </span><span><strong class="def-name">createTbl(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">tbltype</var>, <var class="var">nrows</var>, <var class="var">ttype</var>, <var class="var">tform</var>, <var class="var">tunit</var>, <var class="var">extname</var>)</code><a class="copiable-link" href="#index-createTbl_0028file_002c-2"></a></span></dt>
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