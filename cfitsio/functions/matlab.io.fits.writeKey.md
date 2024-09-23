---
layout: "default"
permalink: "/functions/23_matlabiofitswriteKey/"
pkg_name: "cfitsio"
pkg_version: "0.0.7"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.writeKey"
category: "Low Level Keyword Functions"
func_name: "matlab.io.fits.writeKey"
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
<dt class="deftypefn" id="index-writeKey_0028file_002c"><span class="category-def">: </span><span><strong class="def-name">writeKey(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">key</var>, <var class="var">value</var>)</code><a class="copiable-link" href="#index-writeKey_0028file_002c"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn" id="index-writeKey_0028file_002c-1"><span class="category-def">: </span><span><strong class="def-name">writeKey(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">key</var>, <var class="var">value</var>, <var class="var">comment</var>)</code><a class="copiable-link" href="#index-writeKey_0028file_002c-1"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn" id="index-writeKey_0028file_002c-2"><span class="category-def">: </span><span><strong class="def-name">writeKey(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">key</var>, <var class="var">value</var>, <var class="var">comment</var>, <var class="var">decimals</var>)</code><a class="copiable-link" href="#index-writeKey_0028file_002c-2"></a></span></dt>
<dd><p>Append or replace a key in the fits file.
</p>
<p>This is the equivalent of the cfitsio fits_write_key and fits_update_key function.
 </p><h4 class="subsubheading" id="Inputs"><span>Inputs<a class="copiable-link" href="#Inputs"></a></span></h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">key</var> - keyword name.
</p>
<p><var class="var">value</var> - keyword value.
</p>
<p><var class="var">comment</var> - keyword comment.
</p>
<p><var class="var">decimals</var> - number of decimals.
</p>
<h4 class="subsubheading" id="Outputs"><span>Outputs<a class="copiable-link" href="#Outputs"></a></span></h4>
<p>None
 </p></dd></dl>