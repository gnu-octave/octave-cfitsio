---
layout: "default"
permalink: "/functions/25_matlabiofitsgetNumHDUs/"
pkg_name: "cfitsio"
pkg_version: "0.0.6"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.getNumHDUs"
category: "Low Level HDU Functions"
func_name: "matlab.io.fits.getNumHDUs"
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
<dt class="deftypefn" id="index-_003d"><span class="category-def">: </span><span><code class="def-type"><var class="var">num</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">getNumHDUs(<var class="var">file</var>)</code><a class="copiable-link" href='#index-_003d'></a></span></dt>
<dd><p>Return the count of HDUs in the file.
</p>
<p>This is the equivalent of the cfitsio fits_get_num_hdus function.
</p>
<h4 class="subsubheading" id="Inputs">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs">Outputs</h4>
<p><var class="var">num</var> - return the number of HDUs in the file.
 </p><h4 class="subsubheading" id="Examples">Examples</h4>
<div class="example">
<pre class="example-preformatted"> import_fits;
 testname = file_in_loadpath(&quot;demos/tst0012.fits&quot;);
 fd = fits.openFile(testname);
 hducount = getNumHDUs(fd), 5);
 fits.closeFile(fd);
 </pre></div>
</dd></dl>