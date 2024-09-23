---
layout: "default"
permalink: "/functions/25_matlabiofitsgetColName/"
pkg_name: "cfitsio"
pkg_version: "0.0.7"
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
<dt class="deftypefn" id="index-_003d"><span class="category-def">: </span><span><code class="def-type">[<var class="var">colnum</var>,<var class="var">colname</var>]</code> <strong class="def-name">=</strong> <code class="def-code-arguments">getColName(<var class="var">file</var>, <var class="var">template</var>)</code><a class="copiable-link" href="#index-_003d"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn" id="index-_003d-1"><span class="category-def">: </span><span><code class="def-type">[<var class="var">colnum</var>,<var class="var">colname</var>]</code> <strong class="def-name">=</strong> <code class="def-code-arguments">getColName(<var class="var">file</var>, <var class="var">template</var>, <var class="var">casesens</var>)</code><a class="copiable-link" href="#index-_003d-1"></a></span></dt>
<dd><p>Get column name.
</p>
<p>This is the equivalent of the cfitsio fits_get_colname function.
</p>
<h4 class="subsubheading" id="Inputs"><span>Inputs<a class="copiable-link" href="#Inputs"></a></span></h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">template</var> - template string for matching column name.
</p>
<p><var class="var">casesens</var> - boolean whether to be case sensitive in match.
</p>
<h4 class="subsubheading" id="Outputs"><span>Outputs<a class="copiable-link" href="#Outputs"></a></span></h4>
<p><var class="var">colnum</var> - column number of match.
</p>
<p><var class="var">colname</var> - column name of match.
</p>
<h4 class="subsubheading" id="Examples"><span>Examples<a class="copiable-link" href="#Examples"></a></span></h4>
<div class="example">
<pre class="example-preformatted"> import_fits;
 filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;);
 fd = fits.openFile(filename);
 fits.movAbsHDU(fd,2);
 [colnum, colname] = fits.getColName(fd,&quot;C*&quot;);
 # returned 3, &quot;COUNTS&quot;
 fits.closeFile(fd);
 </pre></div>
</dd></dl>