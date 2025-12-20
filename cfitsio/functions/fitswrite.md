---
layout: "default"
permalink: "/functions/9_fitswrite/"
pkg_name: "cfitsio"
pkg_version: "0.0.7"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - fitswrite"
category: "Low Level Functions"
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
<dt class="deftypefn def-line" id="index-fitswrite_0028data_002c"><span class="category-def">: </span><span><strong class="def-name">fitswrite(<var class="var">data</var>,</strong> <code class="def-code-arguments"><var class="var">filename</var>)</code><a class="copiable-link" href="#index-fitswrite_0028data_002c"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-fitswrite_0028data_002c-1"><span class="category-def">: </span><span><strong class="def-name">fitswrite(<var class="var">data</var>,</strong> <code class="def-code-arguments"><var class="var">filename</var>, <var class="var">propertyname</var>, <var class="var">propertyvalue</var>)</code><a class="copiable-link" href="#index-fitswrite_0028data_002c-1"></a></span></dt>
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