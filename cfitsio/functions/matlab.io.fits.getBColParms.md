---
layout: "default"
permalink: "/functions/27_matlabiofitsgetBColParms/"
pkg_name: "cfitsio"
pkg_version: "0.0.7"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.getBColParms"
category: "Low Level Binary and ASCII Tables"
func_name: "matlab.io.fits.getBColParms"
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
<dt class="deftypefn" id="index-_003d"><span class="category-def">: </span><span><code class="def-type">[<var class="var">ttype</var>,<var class="var">tunit</var>,<var class="var">typechar</var>,<var class="var">repeat</var>,<var class="var">scale</var>,<var class="var">zero</var>,<var class="var">nulval</var>,<var class="var">tdisp</var>]</code> <strong class="def-name">=</strong> <code class="def-code-arguments">getBColParms(<var class="var">file</var>, <var class="var">colnum</var>)</code><a class="copiable-link" href="#index-_003d"></a></span></dt>
<dd><p>Get binary table parameters.
</p>
<p>This is the equivalent of the cfitsio  fits_get_bcolparms function.
</p>
<h4 class="subsubheading" id="Inputs"><span>Inputs<a class="copiable-link" href="#Inputs"></a></span></h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">colnum</var> - Column to retrieve.
</p>
<h4 class="subsubheading" id="Outputs"><span>Outputs<a class="copiable-link" href="#Outputs"></a></span></h4>
<p><var class="var">ttype</var>,<var class="var">tunit</var>,<var class="var">typechar</var>,<var class="var">repeat</var>,<var class="var">scale</var>,<var class="var">zero</var>,<var class="var">nulval</var>,<var class="var">tdisp</var>
 column information in same format as provided by fits_get_bcolparms.
 </p></dd></dl>