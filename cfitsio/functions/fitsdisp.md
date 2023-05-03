---
layout: "default"
permalink: "/functions/8_fitsdisp/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
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
- id: "news"
  name: "News"
  url: "/news"
- id: "manual"
  name: "Manual"
  url: "/manual"
---
<dl class="def">
<dt id="index-_003d"><span class="category">: </span><span><em><var>info</var></em> <strong>=</strong> <em>fitsdisp(<var>filename</var>)</em><a href='#index-_003d' class='copiable-anchor'></a></span></dt>
<dt id="index-_003d-1"><span class="category">: </span><span><em><var>info</var></em> <strong>=</strong> <em>fitsdisp(<var>filename</var>, <var>propertyname</var>, <var>propertyvalue</var>)</em><a href='#index-_003d-1' class='copiable-anchor'></a></span></dt>
<dd><p>Display metadata about fits format file
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>filename</var> - filename to open.
</p>
<p><var>propertyname</var>, <var>propertyvalue</var> - property name/value pairs
</p>
<p>Known property names are:
 </p><dl compact="compact">
<dt><span>&rsquo;Index&rsquo;</span></dt>
<dd><p>Value is a scalar or vector of hdu numbers to display
 </p></dd>
<dt><span>&rsquo;Mode&rsquo;</span></dt>
<dd><p>display mode of &rsquo;standard&rsquo; (default), &rsquo;min&rsquo; or &rsquo;full&rsquo;
 </p></dd>
</dl>

<p>&rsquo;standard&rsquo; display mode shows the standard keywords for the selected HDUs.<br>
 &rsquo;min&rsquo; display mode shows only the type and size of the selected HDUs.<br>
 &rsquo;full&rsquo; display shows all keywords for the selected HDU.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>info</var> - the metadata of the file. If no output variable is provided, it displays
 to the screen.
</p>
<span id="Examples"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;);

 fitsdisp(filename);
 </pre></div>
</dd></dl>