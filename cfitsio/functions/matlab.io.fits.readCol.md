---
layout: "default"
permalink: "/functions/22_matlabiofitsreadCol/"
pkg_name: "cfitsio"
pkg_version: "0.0.5"
pkg_description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
title: "Cfitsio Toolkit - matlab.io.fits.readCol"
category: "Low Level Binary and ASCII Tables"
func_name: "matlab.io.fits.readCol"
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
<dl class="def">
<dt id="index-_003d"><span class="category">: </span><span><em>[<var>coldata</var>, <var>nullval</var>]</em> <strong>=</strong> <em>readCol(<var>file</var>, <var>colnum</var>)</em><a href='#index-_003d' class='copiable-anchor'></a></span></dt>
<dt id="index-_003d-1"><span class="category">: </span><span><em>[<var>coldata</var>, <var>nullval</var>]</em> <strong>=</strong> <em>readCol(<var>file</var>, <var>colnum</var>, <var>firstrow</var>, <var>numrows</var>)</em><a href='#index-_003d-1' class='copiable-anchor'></a></span></dt>
<dd><p>Get table row data.
</p>
<p>This is the equivalent of the cfitsio  fits_read_col function.
</p>
<span id="Inputs"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>firstrow</var> - Start row
</p>
<p><var>numrows</var> - Number of rows to read
</p>
<span id="Outputs"></span><h4 class="subsubheading">Outputs</h4>
<p><var>coldata</var> - the column data rows
</p>
<p><var>nulldata</var> - the null value flags
 </p><span id="Examples"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;

 # open file
 filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;);
 fd = fits.openFile(filename);

 # move to binary table and get column for flux
 fits.movAbsHDU(fd, 2);
 colnum = fits.getColName(fd, 'flux');

 # read all rows in column
 fluxdata = fits.readCol(fd, colnum);
 # read data starting at 2nd value
 fluxdata = fits.readCol(fd, colnum, 2);
 # read rows 3 rows starting at row 2
 fluxdata = fits.readCol(fd, colnum, 2, 3);
 fits.closeFile(fd);
 </pre></div>
</dd></dl>