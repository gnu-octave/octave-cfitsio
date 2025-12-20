---
layout: "default"
permalink: "/functions/8_fitsread/"
pkg_name: "cfitsio"
pkg_version: "0.0.7"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - fitsread"
category: "Low Level Functions"
func_name: "fitsread"
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
<dt class="deftypefn def-line" id="index-_003d"><span class="category-def">: </span><span><code class="def-type"><var class="var">data</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fitsread(<var class="var">filename</var>)</code><a class="copiable-link" href="#index-_003d"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-_003d-1"><span class="category-def">: </span><span><code class="def-type"><var class="var">data</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fitsread(<var class="var">filename</var>, 'raw')</code><a class="copiable-link" href="#index-_003d-1"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-_003d-2"><span class="category-def">: </span><span><code class="def-type"><var class="var">data</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fitsread(<var class="var">filename</var>, <var class="var">extname</var>)</code><a class="copiable-link" href="#index-_003d-2"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-_003d-3"><span class="category-def">: </span><span><code class="def-type"><var class="var">data</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fitsread(<var class="var">filename</var>, <var class="var">extname</var>, <var class="var">index</var>)</code><a class="copiable-link" href="#index-_003d-3"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-_003d-4"><span class="category-def">: </span><span><code class="def-type"><var class="var">data</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fitsread(<var class="var">filename</var>, ____, <var class="var">propertyname</var>, <var class="var">propertyvalue</var>)</code><a class="copiable-link" href="#index-_003d-4"></a></span></dt>
<dd><p>Read the primary data, or specified extension data. It scales the data and applied Nan to any undefined values.
</p>
<h4 class="subsubheading" id="Inputs"><span>Inputs<a class="copiable-link" href="#Inputs"></a></span></h4>
<p><var class="var">filename</var> - filename to open.
</p>
<p><var class="var">exttype</var> - can be  &rsquo;primary&rsquo;, &rsquo;asciitable&rsquo;, &rsquo;binarytable&rsquo;, &rsquo;image&rsquo;, &rsquo;unknown&rsquo;.
</p>
<p><var class="var">index</var> - can be used to specify which table when more than one of a given type exists.
</p>
<p>&rsquo;raw&rsquo;-  If the &rsquo;raw&rsquo; keyword is used, the raw data from the file will be used without replacing
 undefined values with Nan
</p>
<p>Known property names are:
 </p><dl class="table">
<dt>Info</dt>
<dd><p>input info from fitsinfo call.
 </p></dd>
<dt>PixelRegion</dt>
<dd><p>pixel region to extract data for in an image. It expects a cell array of same size as 
 the number of axis in the image. Each cell should be in vector format of: start, [start stop] 
 or [start, increment, stop].
 </p></dd>
<dt>TableColumns</dt>
<dd><p>A list of columns to extract from a ascii or binary table.
 </p></dd>
<dt>TableRows</dt>
<dd><p>A list of rows to extract from an ascii or binary table.
 </p></dd>
</dl>

<h4 class="subsubheading" id="Outputs"><span>Outputs<a class="copiable-link" href="#Outputs"></a></span></h4>
<p><var class="var">data</var> - The read data from the table or image.
</p>
<h4 class="subsubheading" id="Examples"><span>Examples<a class="copiable-link" href="#Examples"></a></span></h4>
<div class="example">
<pre class="example-preformatted"> filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;);

 # read the primary image data
 imagedata = fitsread(filename);

 # read the 1st non primary image
 imagedata = fitsread(filename, &quot;image&quot;);

 # read the first binary table, selected columns
 tbldata = fitsread(filename, &quot;binarytable&quot;, &quot;TableColumns&quot;, [1 2 11]);

 # read the first ascii table
 atbldata = fitsread(filename, &quot;asciitable&quot;);
 </pre></div>
</dd></dl>