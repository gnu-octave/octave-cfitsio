---
layout: "default"
permalink: "/functions/25_matlabiofitsgetNumHDUs/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.getNumHDUs"
category: "Low Level HDU Functions"
func_name: "matlab.io.fits.getNumHDUs"
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
<dt id="index-_003d"><span class="category">: </span><span><em><var>num</var></em> <strong>=</strong> <em>getNumHDUs(<var>file</var>)</em><a href='#index-_003d' class='copiable-anchor'></a></span></dt>
<dd><p>Return the count of HDUs in the file.
</p>
<p>This is the equivalent of the cfitsio fits_get_num_hdus function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>num</var> - return the number of HDUs in the file.
 </p><span id="Examples"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;
 testname = file_in_loadpath(&quot;demos/tst0012.fits&quot;);
 fd = fits.openFile(testname);
 hducount = getNumHDUs(fd), 5);
 fits.closeFile(fd);
 </pre></div>
</dd></dl>