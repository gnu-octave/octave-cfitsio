---
layout: "default"
permalink: "/functions/23_matlabiofitswriteKey/"
pkg_name: "cfitsio"
pkg_version: "0.0.7"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.writeKey"
category: "Low Level Functions"
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
<dt class="deftypefn def-line" id="index-writeKey_0028file_002c"><span class="category-def">: </span><span><strong class="def-name">writeKey(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">key</var>, <var class="var">value</var>)</code><a class="copiable-link" href="#index-writeKey_0028file_002c"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-writeKey_0028file_002c-1"><span class="category-def">: </span><span><strong class="def-name">writeKey(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">key</var>, <var class="var">value</var>, <var class="var">comment</var>)</code><a class="copiable-link" href="#index-writeKey_0028file_002c-1"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-writeKey_0028file_002c-2"><span class="category-def">: </span><span><strong class="def-name">writeKey(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">key</var>, <var class="var">value</var>, <var class="var">comment</var>, <var class="var">decimals</var>)</code><a class="copiable-link" href="#index-writeKey_0028file_002c-2"></a></span></dt>
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