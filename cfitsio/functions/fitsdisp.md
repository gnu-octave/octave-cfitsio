---
layout: "default"
permalink: "/functions/8_fitsdisp/"
pkg_name: "cfitsio"
pkg_version: "0.0.6"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - fitsdisp"
category: "High Level File Functions"
func_name: "fitsdisp"
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
<dt class="deftypefn" id="index-_003d"><span class="category-def">: </span><span><code class="def-type"><var class="var">info</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fitsdisp(<var class="var">filename</var>)</code><a class="copiable-link" href='#index-_003d'></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn" id="index-_003d-1"><span class="category-def">: </span><span><code class="def-type"><var class="var">info</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fitsdisp(<var class="var">filename</var>, <var class="var">propertyname</var>, <var class="var">propertyvalue</var>)</code><a class="copiable-link" href='#index-_003d-1'></a></span></dt>
<dd><p>Display metadata about fits format file
</p>
<h4 class="subsubheading" id="Inputs">Inputs</h4>
<p><var class="var">filename</var> - filename to open.
</p>
<p><var class="var">propertyname</var>, <var class="var">propertyvalue</var> - property name/value pairs
</p>
<p>Known property names are:
 </p><dl class="table">
<dt>&rsquo;Index&rsquo;</dt>
<dd><p>Value is a scalar or vector of hdu numbers to display
 </p></dd>
<dt>&rsquo;Mode&rsquo;</dt>
<dd><p>display mode of &rsquo;standard&rsquo; (default), &rsquo;min&rsquo; or &rsquo;full&rsquo;
 </p></dd>
</dl>

<p>&rsquo;standard&rsquo; display mode shows the standard keywords for the selected HDUs.<br>
 &rsquo;min&rsquo; display mode shows only the type and size of the selected HDUs.<br>
 &rsquo;full&rsquo; display shows all keywords for the selected HDU.
</p>
<h4 class="subsubheading" id="Outputs">Outputs</h4>
<p><var class="var">info</var> - the metadata of the file. If no output variable is provided, it displays
 to the screen.
</p>
<h4 class="subsubheading" id="Examples">Examples</h4>
<div class="example">
<pre class="example-preformatted"> filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;);

 fitsdisp(filename);
 </pre></div>
</dd></dl>