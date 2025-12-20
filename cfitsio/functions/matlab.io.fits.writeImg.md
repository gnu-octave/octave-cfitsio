---
layout: "default"
permalink: "/functions/23_matlabiofitswriteImg/"
pkg_name: "cfitsio"
pkg_version: "0.0.7"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.writeImg"
category: "Low Level Functions"
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
<dt class="deftypefn def-line" id="index-writeImg_0028file_002c"><span class="category-def">: </span><span><strong class="def-name">writeImg(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">imagedata</var>)</code><a class="copiable-link" href="#index-writeImg_0028file_002c"></a></span></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-writeImg_0028file_002c-1"><span class="category-def">: </span><span><strong class="def-name">writeImg(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">imagedata</var>, <var class="var">fpixel</var>)</code><a class="copiable-link" href="#index-writeImg_0028file_002c-1"></a></span></dt>
<dd><p>write imagedata to a FITS file. The rows and column size must match the size of NAXIS, NAXIS etc
</p>
<p>This is the equivalent of the cfitsio fits_write_subset function.
</p>
<h4 class="subsubheading" id="Inputs"><span>Inputs<a class="copiable-link" href="#Inputs"></a></span></h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">imagedata</var> - Image data.
</p>
<p><var class="var">fpixel</var> - start pixel to write from.
</p>
<h4 class="subsubheading" id="Outputs"><span>Outputs<a class="copiable-link" href="#Outputs"></a></span></h4>
<p>None
</p>
<h4 class="subsubheading" id="Examples"><span>Examples<a class="copiable-link" href="#Examples"></a></span></h4>
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