---
layout: "default"
permalink: "/functions/9_fitswrite/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
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
- id: "news"
  name: "News"
  url: "/news"
- id: "manual"
  name: "Manual"
  url: "/manual"
---
<dl class="def">
<dt id="index-fitswrite_0028data_002c"><span class="category">: </span><span><em></em> <strong>fitswrite(<var>data</var>,</strong> <em><var>filename</var>)</em><a href='#index-fitswrite_0028data_002c' class='copiable-anchor'></a></span></dt>
<dt id="index-fitswrite_0028data_002c-1"><span class="category">: </span><span><em></em> <strong>fitswrite(<var>data</var>,</strong> <em><var>filename</var>, <var>propertyname</var>, <var>propertyvalue</var>)</em><a href='#index-fitswrite_0028data_002c-1' class='copiable-anchor'></a></span></dt>
<dd><p>Write image data <var>data</var>  to FITS file <var>filename</var>. If the fie already exists, overwrite it.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>data</var> - imagedata to write to a file.
</p>
<p><var>filename</var> - filename to write to.
</p>
<p><var>propertyname</var>, <var>propertyvalue</var> - property name/value pairs
</p>
<p>Additional properties can be set as <var>propertyname</var>, <var>propertyvalue</var> pairs.
 Known property names are:
 </p><dl compact="compact">
<dt><span>WriteMode</span></dt>
<dd><p>Set mode for writing to image as &rsquo;overwrite&rsquo; (default) or &rsquo;append&rsquo; to append images.
 </p></dd>
<dt><span>Compression</span></dt>
<dd><p>Set compression type to use for image as
 &rsquo;none&rsquo; (default), &rsquo;gzip&rsquo;, &rsquo;rice&rsquo;, &rsquo;hcompress&rsquo; or &rsquo;plio&rsquo;.
 </p></dd>
</dl>

<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
</p>
<span id="Examples"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> filename = tempname();
 X =  double([1:3;4:6]);
 fitswrite(X, filename);
 </pre></div>
</dd></dl>