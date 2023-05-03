---
layout: "default"
permalink: "/functions/22_matlabiofitscopyHDU/"
pkg_name: "cfitsio"
pkg_version: "0.0.4"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.copyHDU"
category: "Low Level HDU Functions"
func_name: "matlab.io.fits.copyHDU"
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
<dt id="index-copyHDU_0028infile_002c"><span class="category">: </span><span><em></em> <strong>copyHDU(<var>infile</var>,</strong> <em><var>outfile</var>)</em><a href='#index-copyHDU_0028infile_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Copy current HDU from one infile to another.
</p>
<p>This is the equivalent of the cfitsio fits_copy_hdu function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>filename</var> - filename to open.
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>infile</var> - opened input file identifier.
</p>
<p><var>outfile</var> - opened output file identifier.
</p>
<span id="Examples"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;
 
 # open input and output files
 infilename = file_in_loadpath(&quot;demos/tst0012.fits&quot;);
 infile = fits.openFile(infilename);

 outfile = fits.createFile(&quot;myfitsfile.fits&quot;);
 # copy first hdu
 fits.copyHDU(infile, outfile);
 # move to and then copy 2nd hdu
 fits.movAbsHDU(infile,2);
 fits.copyHDU(infile, outfile);

 # close files
 fits.closeFile(infile);
 fits.closeFile(outfile);
 </pre></div>
</dd></dl>