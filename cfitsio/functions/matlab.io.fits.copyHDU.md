---
layout: "default"
permalink: "/functions/22_matlabiofitscopyHDU/"
pkg_name: "cfitsio"
pkg_version: "0.0.7"
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
<dt class="deftypefn" id="index-copyHDU_0028infile_002c"><span class="category-def">: </span><span><strong class="def-name">copyHDU(<var class="var">infile</var>,</strong> <code class="def-code-arguments"><var class="var">outfile</var>)</code><a class="copiable-link" href="#index-copyHDU_0028infile_002c"></a></span></dt>
<dd><p>Copy current HDU from one infile to another.
</p>
<p>This is the equivalent of the cfitsio fits_copy_hdu function.
</p>
<h4 class="subsubheading" id="Inputs"><span>Inputs<a class="copiable-link" href="#Inputs"></a></span></h4>
<p><var class="var">filename</var> - filename to open.
</p>
<h4 class="subsubheading" id="Outputs"><span>Outputs<a class="copiable-link" href="#Outputs"></a></span></h4>
<p><var class="var">infile</var> - opened input file identifier.
</p>
<p><var class="var">outfile</var> - opened output file identifier.
</p>
<h4 class="subsubheading" id="Examples"><span>Examples<a class="copiable-link" href="#Examples"></a></span></h4>
<div class="example">
<pre class="example-preformatted"> import_fits;
 
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