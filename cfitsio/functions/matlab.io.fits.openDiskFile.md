---
layout: "default"
permalink: "/functions/27_matlabiofitsopenDiskFile/"
pkg_name: "cfitsio"
pkg_version: "0.0.6"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.openDiskFile"
category: "Low Level File Functions"
func_name: "matlab.io.fits.openDiskFile"
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
<dt class="deftypefn" id="index-_003d"><span class="category-def">: </span><span><code class="def-type"><var class="var">file</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">openDiskFile(<var class="var">filename</var>)</code><a class="copiable-link" href='#index-_003d'></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn" id="index-_003d-1"><span class="category-def">: </span><span><code class="def-type"><var class="var">file</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">openDiskFile(<var class="var">filename</var>, <var class="var">mode</var>)</code><a class="copiable-link" href='#index-_003d-1'></a></span></dt>
<dd><p>Attempt to open a file of the given input name, ignoring any special processing of the filename.
</p>
<p>This is the equivalent of the cfitsio fits_open_diskfile function.
</p>
<h4 class="subsubheading" id="Inputs">Inputs</h4>
<p><var class="var">filename</var> - filename to open.
</p>
<p><var class="var">mode</var> - If the option mode string &rsquo;READONLY&rsquo; (default) or &rsquo;READWRITE&rsquo; is provided,
 open the file using that mode.
</p>
<h4 class="subsubheading" id="Outputs">Outputs</h4>
<p><var class="var">file</var> - opened file identifier.
</p>
<h4 class="subsubheading" id="Examples">Examples</h4>
<div class="example">
<pre class="example-preformatted"> import_fits;
 filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;)

 fd = fits.openDiskFile(filename, 'READONLY');
 fits.closeFile(fd);
 </pre></div>

</dd></dl>