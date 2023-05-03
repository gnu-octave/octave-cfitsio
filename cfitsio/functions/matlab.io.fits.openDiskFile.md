---
layout: "default"
permalink: "/functions/27_matlabiofitsopenDiskFile/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
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
- id: "news"
  name: "News"
  url: "/news"
- id: "manual"
  name: "Manual"
  url: "/manual"
---
<dl class="def">
<dt id="index-_003d"><span class="category">: </span><span><em><var>file</var></em> <strong>=</strong> <em>openDiskFile(<var>filename</var>)</em><a href='#index-_003d' class='copiable-anchor'></a></span></dt>
<dt id="index-_003d-1"><span class="category">: </span><span><em><var>file</var></em> <strong>=</strong> <em>openDiskFile(<var>filename</var>, <var>mode</var>)</em><a href='#index-_003d-1' class='copiable-anchor'></a></span></dt>
<dd><p>Attempt to open a file of the given input name, ignoring any special processing of the filename.
</p>
<p>This is the equivalent of the cfitsio fits_open_diskfile function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>filename</var> - filename to open.
</p>
<p><var>mode</var> - If the option mode string &rsquo;READONLY&rsquo; (default) or &rsquo;READWRITE&rsquo; is provided,
 open the file using that mode.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>file</var> - opened file identifier.
</p>
<span id="Examples"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;
 filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;)

 fd = fits.openDiskFile(filename, 'READONLY');
 fits.closeFile(fd);
 </pre></div>

</dd></dl>