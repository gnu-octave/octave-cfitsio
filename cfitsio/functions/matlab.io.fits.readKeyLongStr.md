---
layout: "default"
permalink: "/functions/29_matlabiofitsreadKeyLongStr/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.readKeyLongStr"
category: "Low Level Keyword Functions"
func_name: "matlab.io.fits.readKeyLongStr"
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
<dt id="index-readKeyLongStr_0028file_002c"><span class="category">: </span><span><em>[<var>value</var>, <var>comment</var>] =</em> <strong>readKeyLongStr(<var>file</var>,</strong> <em><var>recname</var>)</em><a href='#index-readKeyLongStr_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Read the key value <var>recname</var> as a string.
</p>
<p>This is the equivalent of the cfitsio fits_read_key_longstr function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>recname</var> - keyword name.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>value</var> - string value of record.
</p>
<p><var>comment</var> - comment string
 </p></dd></dl>