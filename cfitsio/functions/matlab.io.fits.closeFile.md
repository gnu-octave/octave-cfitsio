---
layout: "default"
permalink: "/functions/24_matlabiofitscloseFile/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.closeFile"
category: "Low Level File Functions"
func_name: "matlab.io.fits.closeFile"
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
<dt id="index-closeFile_0028file_0029"><span class="category">: </span><span><em></em> <strong>closeFile(<var>file</var>)</strong><a href='#index-closeFile_0028file_0029' class='copiable-anchor'></a></span></dt>
<dd><p>Close the opened fits file
</p> 
<p>This is the equivalent of the fits_close_file function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened file returned from openFile or createFile.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p>None
</p>
<span id="Examples"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;
 filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;)

 fd = fits.openFile(filename);
 fits.closeFile(fd);
 </pre></div>

</dd></dl>