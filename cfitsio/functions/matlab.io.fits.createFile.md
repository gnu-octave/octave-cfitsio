---
layout: "default"
permalink: "/functions/25_matlabiofitscreateFile/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.createFile"
category: "Low Level File Functions"
func_name: "matlab.io.fits.createFile"
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
<dt id="index-_003d"><span class="category">: </span><span><em><var>file</var></em> <strong>=</strong> <em>createFile(<var>filename</var>)</em><a href='#index-_003d' class='copiable-anchor'></a></span></dt>
<dd><p>Attempt to create  a file of the given input name.
</p>
<p>If the filename starts with ! and the file exists, it will create a new file, otherwise, if the
 file exists, the create will fail.
</p>
<p>This is the equivalent of the cfitsio fits_create_file function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>filename</var> - filename to open.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>file</var> - opened file identifier.
</p>
<span id="Examples"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;

 fd = fits.createFile(&quot;myfitsfile.fits&quot;);
 fits.createImg(fd, 'uint16', [100 100]);
 fits.closeFile(fd);
 </pre></div>

</dd></dl>