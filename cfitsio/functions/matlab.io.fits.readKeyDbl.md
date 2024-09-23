---
layout: "default"
permalink: "/functions/25_matlabiofitsreadKeyDbl/"
pkg_name: "cfitsio"
pkg_version: "0.0.7"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.readKeyDbl"
category: "Low Level Keyword Functions"
func_name: "matlab.io.fits.readKeyDbl"
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
<dt class="deftypefn" id="index-readKeyDbl_0028file_002c"><span class="category-def">Function File: </span><span><code class="def-type">[<var class="var">value</var>, <var class="var">comment</var>] =</code> <strong class="def-name">readKeyDbl(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">recname</var>)</code><a class="copiable-link" href="#index-readKeyDbl_0028file_002c"></a></span></dt>
<dd><p>Read the key value <var class="var">recname</var> as a double.
</p>
<p>This is the equivalent of the cfitsio fits_read_key_dbl function.\n \
</p>
<h4 class="subsubheading" id="Inputs"><span>Inputs<a class="copiable-link" href="#Inputs"></a></span></h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">recname</var> - keyword name.
</p>
<h4 class="subsubheading" id="Outputs"><span>Outputs<a class="copiable-link" href="#Outputs"></a></span></h4>
<p><var class="var">value</var> - double value of record.
</p>
<p><var class="var">comment</var> - comment string
 </p></dd></dl>