---
layout: "default"
permalink: "/functions/23_matlabiofitswriteImg/"
pkg_name: "cfitsio"
pkg_version: "0.0.6"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.writeImg"
category: "Low Level Image Manipulation"
func_name: "matlab.io.fits.writeImg"
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
<dt class="deftypefn" id="index-writeImg_0028file_002c"><span class="category-def">: </span><span><strong class="def-name">writeImg(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">imagedata</var>)</code><a class="copiable-link" href='#index-writeImg_0028file_002c'></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn" id="index-writeImg_0028file_002c-1"><span class="category-def">: </span><span><strong class="def-name">writeImg(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">imagedata</var>, <var class="var">fpixel</var>)</code><a class="copiable-link" href='#index-writeImg_0028file_002c-1'></a></span></dt>
<dd><p>write imagedata to a FITS file. The rows and column size must match the size of NAXIS, NAXIS etc
</p>
<p>This is the equivalent of the cfitsio fits_write_subset function.
</p>
<h4 class="subsubheading" id="Inputs">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">imagedata</var> - Image data.
</p>
<p><var class="var">fpixel</var> - start pixel to write from.
</p>
<h4 class="subsubheading" id="Outputs">Outputs</h4>
<p>None
</p>
<h4 class="subsubheading" id="Examples">Examples</h4>
<p>Create a fits file and write a 10x10 image in the primary and image ext:
 </p><div class="example">
<pre class="example-preformatted"> import_fits;
 fd = fits.createFile(&quot;myfitsfile.fits&quot;);
 data = int16(zeros(10,10));
 # primary
 fits.createImg(fd,class(data), size(data));
 fits.writeImg(fd,data);
 # image ext
 fits.createImg(fd,class(data), size(data));
 fits.writeImg(fd,data);
 # close file
 fits.closeFile(fd);
 </pre></div>
</dd></dl>