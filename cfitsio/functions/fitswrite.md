---
layout: "default"
permalink: "/functions/9_fitswrite/"
pkg_name: "cfitsio"
pkg_version: "0.0.7"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - fitswrite"
category: "High Level File Functions"
func_name: "fitswrite"
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
<dt class="deftypefn" id="index-fitswrite_0028data_002c"><span class="category-def">: </span><span><strong class="def-name">fitswrite(<var class="var">data</var>,</strong> <code class="def-code-arguments"><var class="var">filename</var>)</code><a class="copiable-link" href="#index-fitswrite_0028data_002c"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn" id="index-fitswrite_0028data_002c-1"><span class="category-def">: </span><span><strong class="def-name">fitswrite(<var class="var">data</var>,</strong> <code class="def-code-arguments"><var class="var">filename</var>, <var class="var">propertyname</var>, <var class="var">propertyvalue</var>)</code><a class="copiable-link" href="#index-fitswrite_0028data_002c-1"></a></span></dt>
<dd><p>Write image data <var class="var">data</var>  to FITS file <var class="var">filename</var>. If the fie already exists, overwrite it.
</p>
<h4 class="subsubheading" id="Inputs"><span>Inputs<a class="copiable-link" href="#Inputs"></a></span></h4>
<p><var class="var">data</var> - imagedata to write to a file.
</p>
<p><var class="var">filename</var> - filename to write to.
</p>
<p><var class="var">propertyname</var>, <var class="var">propertyvalue</var> - property name/value pairs
</p>
<p>Additional properties can be set as <var class="var">propertyname</var>, <var class="var">propertyvalue</var> pairs.
 Known property names are:
 </p><dl class="table">
<dt>WriteMode</dt>
<dd><p>Set mode for writing to image as &rsquo;overwrite&rsquo; (default) or &rsquo;append&rsquo; to append images.
 </p></dd>
<dt>Compression</dt>
<dd><p>Set compression type to use for image as
 &rsquo;none&rsquo; (default), &rsquo;gzip&rsquo;, &rsquo;rice&rsquo;, &rsquo;hcompress&rsquo; or &rsquo;plio&rsquo;.
 </p></dd>
</dl>

<h4 class="subsubheading" id="Outputs"><span>Outputs<a class="copiable-link" href="#Outputs"></a></span></h4>
<p>None
</p>
<h4 class="subsubheading" id="Examples"><span>Examples<a class="copiable-link" href="#Examples"></a></span></h4>
<div class="example">
<pre class="example-preformatted"> filename = tempname();
 X =  double([1:3;4:6]);
 fitswrite(X, filename);
 </pre></div>
</dd></dl>