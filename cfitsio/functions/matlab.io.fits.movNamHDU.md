---
layout: "default"
permalink: "/functions/24_matlabiofitsmovNamHDU/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.movNamHDU"
category: "Low Level HDU Functions"
func_name: "matlab.io.fits.movNamHDU"
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
<dl class="def">
<dt id="index-movNamHDU_0028file_002c"><span class="category">Function File: </span><span><em><var>hdutype</var> =</em> <strong>movNamHDU(<var>file</var>,</strong> <em><var>hdutype</var>, <var>extname</var>, <var>extver</var>)</em><a href='#index-movNamHDU_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Go to HDU matching <var>hdutype</var>, <var>extname</var>, <var>extver</var>.
</p>

<p>This is the equivalent of the cfitsio fits_movnam_hdu function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>hdutype</var> - HDU number to move to.
 Valid hdutype values are &rsquo;IMAGE_HDU&rsquo;, &rsquo;ASCII_TBL&rsquo;, &rsquo;BINARY_TBL&rsquo;, &rsquo;ANY_HDU&rsquo;.
</p>
<p><var>extname</var>, <var>extver</var> - EXTNAME and EXTVER keywords to match.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>hdutype</var> - hdu type of the now current HDU. 
 </p></dd></dl>