---
layout: "default"
permalink: "/manual/"
title: "Cfitsio Toolkit - Manual"
pkg_name: "cfitsio"
version: "0.0.4"
description: "octave-fitsio provides I/O routines to read and  write FITS (Flexible Image Transport System) files."
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
- id: "Installing-and-loading-1"
  name: "&nbsp;&nbsp; Installing and loading"
  url: "/manual/#Installing-and-loading-1"
- id: "Basic-Usage-Overview-1"
  name: "&nbsp;&nbsp; Basic Usage Overview"
  url: "/manual/#Basic-Usage-Overview-1"
- id: "Function-Reference-1"
  name: "&nbsp;&nbsp; Function Reference"
  url: "/manual/#Function-Reference-1"
---
<h1 class="settitle" align="center">Octave CFITSIO - FITS File I/O Toolkit for GNU octave</h1>
<div class="top" id="Top">
<div class="header">
<p>
Next: <a href="#Installing-and-loading" accesskey="n" rel="next">Installing and loading</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<span id="Introduction"></span><h1 class="top">Introduction</h1>
<p>The <acronym>GNU</acronym> Octave CFITSIO toolkit is a set of functions for manipulating FITS files for GNU Octave
</p>
<div class="Contents_element" id="SEC_Contents">
<h2 class="contents-heading">Table of Contents</h2>
<div class="contents">
<ul class="no-bullet">
  <li><a id="toc-Installing-and-loading-1" href="#Installing-and-loading">1 Installing and loading</a>
  <ul class="no-bullet">
    <li><a id="toc-Windows-install" href="#Windows-install">1.1 Windows install</a></li>
    <li><a id="toc-Online-Direct-install" href="#Online-Direct-install">1.2 Online Direct install</a></li>
    <li><a id="toc-Off_002dline-install" href="#Off_002dline-install">1.3 Off-line install</a></li>
    <li><a id="toc-Loading" href="#Loading">1.4 Loading</a></li>
  </ul></li>
  <li><a id="toc-Basic-Usage-Overview-1" href="#Basic-Usage-Overview">2 Basic Usage Overview</a>
  <ul class="no-bullet">
    <li><a id="toc-Overview" href="#Overview">2.1 Overview</a></li>
    <li><a id="toc-Using-the-toolkit" href="#Using-the-toolkit">2.2 Using the toolkit</a>
    <ul class="no-bullet">
      <li><a id="toc-Reading-Data" href="#Reading-Data">2.2.1 Reading Data</a></li>
      <li><a id="toc-Reading-Information" href="#Reading-Information">2.2.2 Reading Information</a></li>
      <li><a id="toc-Low-level-functionality" href="#Low-level-functionality">2.2.3 Low level functionality</a></li>
    </ul></li>
  </ul></li>
  <li><a id="toc-Function-Reference-1" href="#Function-Reference">3 Function Reference</a>
  <ul class="no-bullet">
    <li><a id="toc-High-Level-File-Functions-1" href="#High-Level-File-Functions">3.1 High Level File Functions</a>
    <ul class="no-bullet">
      <li><a id="toc-fitsdisp" href="#fitsdisp">3.1.1 fitsdisp</a></li>
      <li><a id="toc-fitsinfo" href="#fitsinfo">3.1.2 fitsinfo</a></li>
      <li><a id="toc-fitsread" href="#fitsread">3.1.3 fitsread</a></li>
      <li><a id="toc-fitswrite" href="#fitswrite">3.1.4 fitswrite</a></li>
    </ul></li>
    <li><a id="toc-Low-Level-File-Functions-1" href="#Low-Level-File-Functions">3.2 Low Level File Functions</a>
    <ul class="no-bullet">
      <li><a id="toc-matlab_002eio_002efits_002ecloseFile" href="#matlab_002eio_002efits_002ecloseFile">3.2.1 matlab.io.fits.closeFile</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ecreateFile" href="#matlab_002eio_002efits_002ecreateFile">3.2.2 matlab.io.fits.createFile</a></li>
      <li><a id="toc-matlab_002eio_002efits_002edeleteFile" href="#matlab_002eio_002efits_002edeleteFile">3.2.3 matlab.io.fits.deleteFile</a></li>
      <li><a id="toc-matlab_002eio_002efits_002efileMode" href="#matlab_002eio_002efits_002efileMode">3.2.4 matlab.io.fits.fileMode</a></li>
      <li><a id="toc-matlab_002eio_002efits_002efileName" href="#matlab_002eio_002efits_002efileName">3.2.5 matlab.io.fits.fileName</a></li>
      <li><a id="toc-matlab_002eio_002efits_002eopenDiskFile" href="#matlab_002eio_002efits_002eopenDiskFile">3.2.6 matlab.io.fits.openDiskFile</a></li>
      <li><a id="toc-matlab_002eio_002efits_002eopenFile" href="#matlab_002eio_002efits_002eopenFile">3.2.7 matlab.io.fits.openFile</a></li>
    </ul></li>
    <li><a id="toc-Low-Level-HDU-Functions-1" href="#Low-Level-HDU-Functions">3.3 Low Level HDU Functions</a>
    <ul class="no-bullet">
      <li><a id="toc-matlab_002eio_002efits_002ecopyHDU" href="#matlab_002eio_002efits_002ecopyHDU">3.3.1 matlab.io.fits.copyHDU</a></li>
      <li><a id="toc-matlab_002eio_002efits_002edeleteHDU" href="#matlab_002eio_002efits_002edeleteHDU">3.3.2 matlab.io.fits.deleteHDU</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetHDUnum" href="#matlab_002eio_002efits_002egetHDUnum">3.3.3 matlab.io.fits.getHDUnum</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetHDUoff" href="#matlab_002eio_002efits_002egetHDUoff">3.3.4 matlab.io.fits.getHDUoff</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetHDUtype" href="#matlab_002eio_002efits_002egetHDUtype">3.3.5 matlab.io.fits.getHDUtype</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetNumHDUs" href="#matlab_002eio_002efits_002egetNumHDUs">3.3.6 matlab.io.fits.getNumHDUs</a></li>
      <li><a id="toc-matlab_002eio_002efits_002emovAbsHDU" href="#matlab_002eio_002efits_002emovAbsHDU">3.3.7 matlab.io.fits.movAbsHDU</a></li>
      <li><a id="toc-matlab_002eio_002efits_002emovNamHDU" href="#matlab_002eio_002efits_002emovNamHDU">3.3.8 matlab.io.fits.movNamHDU</a></li>
      <li><a id="toc-matlab_002eio_002efits_002emovRelHDU" href="#matlab_002eio_002efits_002emovRelHDU">3.3.9 matlab.io.fits.movRelHDU</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ewriteChecksum" href="#matlab_002eio_002efits_002ewriteChecksum">3.3.10 matlab.io.fits.writeChecksum</a></li>
    </ul></li>
    <li><a id="toc-Low-Level-Keyword-Functions-1" href="#Low-Level-Keyword-Functions">3.4 Low Level Keyword Functions</a>
    <ul class="no-bullet">
      <li><a id="toc-matlab_002eio_002efits_002edeleteKey" href="#matlab_002eio_002efits_002edeleteKey">3.4.1 matlab.io.fits.deleteKey</a></li>
      <li><a id="toc-matlab_002eio_002efits_002edeleteRecord" href="#matlab_002eio_002efits_002edeleteRecord">3.4.2 matlab.io.fits.deleteRecord</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetHdrSpace" href="#matlab_002eio_002efits_002egetHdrSpace">3.4.3 matlab.io.fits.getHdrSpace</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ereadCard" href="#matlab_002eio_002efits_002ereadCard">3.4.4 matlab.io.fits.readCard</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ereadKey" href="#matlab_002eio_002efits_002ereadKey">3.4.5 matlab.io.fits.readKey</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ereadKeyCmplx" href="#matlab_002eio_002efits_002ereadKeyCmplx">3.4.6 matlab.io.fits.readKeyCmplx</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ereadKeyDbl" href="#matlab_002eio_002efits_002ereadKeyDbl">3.4.7 matlab.io.fits.readKeyDbl</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ereadKeyLongLong" href="#matlab_002eio_002efits_002ereadKeyLongLong">3.4.8 matlab.io.fits.readKeyLongLong</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ereadKeyLongStr" href="#matlab_002eio_002efits_002ereadKeyLongStr">3.4.9 matlab.io.fits.readKeyLongStr</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ereadKeyUnit" href="#matlab_002eio_002efits_002ereadKeyUnit">3.4.10 matlab.io.fits.readKeyUnit</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ereadRecord" href="#matlab_002eio_002efits_002ereadRecord">3.4.11 matlab.io.fits.readRecord</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ewriteComment" href="#matlab_002eio_002efits_002ewriteComment">3.4.12 matlab.io.fits.writeComment</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ewriteDate" href="#matlab_002eio_002efits_002ewriteDate">3.4.13 matlab.io.fits.writeDate</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ewriteHistory" href="#matlab_002eio_002efits_002ewriteHistory">3.4.14 matlab.io.fits.writeHistory</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ewriteKey" href="#matlab_002eio_002efits_002ewriteKey">3.4.15 matlab.io.fits.writeKey</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ewriteKeyUnit" href="#matlab_002eio_002efits_002ewriteKeyUnit">3.4.16 matlab.io.fits.writeKeyUnit</a></li>
    </ul></li>
    <li><a id="toc-Low-Level-Image-Manipulation-1" href="#Low-Level-Image-Manipulation">3.5 Low Level Image Manipulation</a>
    <ul class="no-bullet">
      <li><a id="toc-matlab_002eio_002efits_002ecreateImg" href="#matlab_002eio_002efits_002ecreateImg">3.5.1 matlab.io.fits.createImg</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetImgSize" href="#matlab_002eio_002efits_002egetImgSize">3.5.2 matlab.io.fits.getImgSize</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetImgType" href="#matlab_002eio_002efits_002egetImgType">3.5.3 matlab.io.fits.getImgType</a></li>
      <li><a id="toc-matlab_002eio_002efits_002einsertImg" href="#matlab_002eio_002efits_002einsertImg">3.5.4 matlab.io.fits.insertImg</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ereadImg" href="#matlab_002eio_002efits_002ereadImg">3.5.5 matlab.io.fits.readImg</a></li>
      <li><a id="toc-matlab_002eio_002efits_002esetBscale" href="#matlab_002eio_002efits_002esetBscale">3.5.6 matlab.io.fits.setBscale</a></li>
      <li><a id="toc-matlab_002eio_002efits_002esetTscale" href="#matlab_002eio_002efits_002esetTscale">3.5.7 matlab.io.fits.setTscale</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ewriteImg" href="#matlab_002eio_002efits_002ewriteImg">3.5.8 matlab.io.fits.writeImg</a></li>
    </ul></li>
    <li><a id="toc-Low-Level-Utility-Functions-1" href="#Low-Level-Utility-Functions">3.6 Low Level Utility Functions</a>
    <ul class="no-bullet">
      <li><a id="toc-matlab_002eio_002efits_002egetConstantNames" href="#matlab_002eio_002efits_002egetConstantNames">3.6.1 matlab.io.fits.getConstantNames</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetConstantValue" href="#matlab_002eio_002efits_002egetConstantValue">3.6.2 matlab.io.fits.getConstantValue</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetOpenFiles" href="#matlab_002eio_002efits_002egetOpenFiles">3.6.3 matlab.io.fits.getOpenFiles</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetVersion" href="#matlab_002eio_002efits_002egetVersion">3.6.4 matlab.io.fits.getVersion</a></li>
    </ul></li>
    <li><a id="toc-Low-Level-Compression-Functions-1" href="#Low-Level-Compression-Functions">3.7 Low Level Compression Functions</a>
    <ul class="no-bullet">
      <li><a id="toc-matlab_002eio_002efits_002eimgCompress" href="#matlab_002eio_002efits_002eimgCompress">3.7.1 matlab.io.fits.imgCompress</a></li>
      <li><a id="toc-matlab_002eio_002efits_002eisCompressedImg" href="#matlab_002eio_002efits_002eisCompressedImg">3.7.2 matlab.io.fits.isCompressedImg</a></li>
      <li><a id="toc-matlab_002eio_002efits_002esetCompressionType" href="#matlab_002eio_002efits_002esetCompressionType">3.7.3 matlab.io.fits.setCompressionType</a></li>
      <li><a id="toc-matlab_002eio_002efits_002esetHCompScale" href="#matlab_002eio_002efits_002esetHCompScale">3.7.4 matlab.io.fits.setHCompScale</a></li>
      <li><a id="toc-matlab_002eio_002efits_002esetHCompSmooth" href="#matlab_002eio_002efits_002esetHCompSmooth">3.7.5 matlab.io.fits.setHCompSmooth</a></li>
      <li><a id="toc-matlab_002eio_002efits_002esetTileDim" href="#matlab_002eio_002efits_002esetTileDim">3.7.6 matlab.io.fits.setTileDim</a></li>
    </ul></li>
    <li><a id="toc-Low-Level-Binary-and-ASCII-Tables-1" href="#Low-Level-Binary-and-ASCII-Tables">3.8 Low Level Binary and ASCII Tables</a>
    <ul class="no-bullet">
      <li><a id="toc-matlab_002eio_002efits_002ecreateTbl" href="#matlab_002eio_002efits_002ecreateTbl">3.8.1 matlab.io.fits.createTbl</a></li>
      <li><a id="toc-matlab_002eio_002efits_002edeleteCol" href="#matlab_002eio_002efits_002edeleteCol">3.8.2 matlab.io.fits.deleteCol</a></li>
      <li><a id="toc-matlab_002eio_002efits_002edeleteRows" href="#matlab_002eio_002efits_002edeleteRows">3.8.3 matlab.io.fits.deleteRows</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetAColParms" href="#matlab_002eio_002efits_002egetAColParms">3.8.4 matlab.io.fits.getAColParms</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetBColParms" href="#matlab_002eio_002efits_002egetBColParms">3.8.5 matlab.io.fits.getBColParms</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetColName" href="#matlab_002eio_002efits_002egetColName">3.8.6 matlab.io.fits.getColName</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetColType" href="#matlab_002eio_002efits_002egetColType">3.8.7 matlab.io.fits.getColType</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetEqColType" href="#matlab_002eio_002efits_002egetEqColType">3.8.8 matlab.io.fits.getEqColType</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetNumCols" href="#matlab_002eio_002efits_002egetNumCols">3.8.9 matlab.io.fits.getNumCols</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetNumRows" href="#matlab_002eio_002efits_002egetNumRows">3.8.10 matlab.io.fits.getNumRows</a></li>
      <li><a id="toc-matlab_002eio_002efits_002egetRowSize" href="#matlab_002eio_002efits_002egetRowSize">3.8.11 matlab.io.fits.getRowSize</a></li>
      <li><a id="toc-matlab_002eio_002efits_002einsertATbl" href="#matlab_002eio_002efits_002einsertATbl">3.8.12 matlab.io.fits.insertATbl</a></li>
      <li><a id="toc-matlab_002eio_002efits_002einsertBTbl" href="#matlab_002eio_002efits_002einsertBTbl">3.8.13 matlab.io.fits.insertBTbl</a></li>
      <li><a id="toc-matlab_002eio_002efits_002einsertCol" href="#matlab_002eio_002efits_002einsertCol">3.8.14 matlab.io.fits.insertCol</a></li>
      <li><a id="toc-matlab_002eio_002efits_002einsertRows" href="#matlab_002eio_002efits_002einsertRows">3.8.15 matlab.io.fits.insertRows</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ereadATblHdr" href="#matlab_002eio_002efits_002ereadATblHdr">3.8.16 matlab.io.fits.readATblHdr</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ereadBTblHdr" href="#matlab_002eio_002efits_002ereadBTblHdr">3.8.17 matlab.io.fits.readBTblHdr</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ereadCol" href="#matlab_002eio_002efits_002ereadCol">3.8.18 matlab.io.fits.readCol</a></li>
      <li><a id="toc-matlab_002eio_002efits_002ewriteCol" href="#matlab_002eio_002efits_002ewriteCol">3.8.19 matlab.io.fits.writeCol</a></li>
    </ul></li>
    <li><a id="toc-Import-functions-1" href="#Import-functions">3.9 Import functions</a>
    <ul class="no-bullet">
      <li><a id="toc-import_005ffits" href="#import_005ffits">3.9.1 import_fits</a></li>
    </ul></li>
  </ul></li>
  <li><a id="toc-GNU-General-Public-License" href="#Copying">Appendix A GNU General Public License</a></li>
  <li><a id="toc-Index-1" href="#Index" rel="index">Index</a></li>
</ul>
</div>
</div>
<hr>
<div class="chapter" id="Installing-and-loading">
<div class="header">
<p>
Next: <a href="#Basic-Usage-Overview" accesskey="n" rel="next">Basic Usage Overview</a>, Previous: <a href="#Top" accesskey="p" rel="prev">Introduction</a>, Up: <a href="#Top" accesskey="u" rel="up">Introduction</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<span id="Installing-and-loading-1"></span><h2 class="chapter">1 Installing and loading</h2>
<span id="index-Installing-and-loading"></span>
<p>The <acronym>GNU</acronym> Octave CFITSIO toolkit must be installed and then loaded to be used.
</p>
<p>It can be installed in <acronym>GNU</acronym> Octave directly from octave-cfitsio,
or can be installed in an off-line mode via a downloaded tarball.
</p>
<p>The toolkit has a dependency on the cfitsio library (<a href="https://heasarc.gsfc.nasa.gov/fitsio/">https://heasarc.gsfc.nasa.gov/fitsio/</a>), so it must be installed in order
to successfully install the <acronym>GNU</acronym> Octave toolkit.
</p>
<p>For Fedora: <code>yum install cfitsio-devel</code> 
</p>
<p>The toolkit must be then be loaded once per each <acronym>GNU</acronym> Octave session in order to use its functionality.
</p>
<ul class="section-toc">
<li><a href="#Windows-install" accesskey="1">Windows install</a></li>
<li><a href="#Online-Direct-install" accesskey="2">Online Direct install</a></li>
<li><a href="#Off_002dline-install" accesskey="3">Off-line install</a></li>
<li><a href="#Loading" accesskey="4">Loading</a></li>
</ul>
<div class="section" id="Windows-install">
<h3 class="section">1.1 Windows install</h3>
<span id="index-Windows-install"></span>
<p>If running in Windows, the package may already be installed, to check run:
</p>
<div class="example">
<pre class="example">pkg list cfitsio
</pre></div>
<p>Otherwise it can be installed by installing the requirements and then using the online or offline install method.
</p>
</div>
<div class="section" id="Online-Direct-install">
<h3 class="section">1.2 Online Direct install</h3>
<span id="index-Online-install"></span>
<p>With an internet connection available, the package can be installed from
octave-cfitsio using the following command within <acronym>GNU</acronym> Octave:
</p>
<div class="example">
<pre class="example">pkg install https://sourceforge.net/projects/octave-cfitsio/files/v0.0.4/octave-cfitsio-0.0.4.tar.gz/download
</pre></div>
<p>The latest released version of the toolkit will be downloaded and installed.
</p>
</div>
<div class="section" id="Off_002dline-install">
<h3 class="section">1.3 Off-line install</h3>
<span id="index-Off_002dline-install"></span>
<p>With the toolkit package already downloaded, and in the current directory when running
<acronym>GNU</acronym> Octave, the package can be installed using the following command within <acronym>GNU</acronym> Octave:
</p>
<div class="example">
<pre class="example">pkg install octave-cfitsio-0.0.4.tar.gz
</pre></div>
</div>
<div class="section" id="Loading">
<h3 class="section">1.4 Loading</h3>
<span id="index-Loading"></span>
<p>Regardless of the method of installing the toolkit, in order to use its functions,
the toolkit must be loaded using the pkg load command:
</p>
<div class="example">
<pre class="example">pkg load cfitsio
</pre></div>
<p>The toolkit must be loaded on each <acronym>GNU</acronym> Octave session.
</p>
<hr>
</div>
</div>
<div class="chapter" id="Basic-Usage-Overview">
<div class="header">
<p>
Next: <a href="#Function-Reference" accesskey="n" rel="next">Function Reference</a>, Previous: <a href="#Installing-and-loading" accesskey="p" rel="prev">Installing and loading</a>, Up: <a href="#Top" accesskey="u" rel="up">Introduction</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<span id="Basic-Usage-Overview-1"></span><h2 class="chapter">2 Basic Usage Overview</h2>
<span id="index-Basic-Usage-Overview"></span>
<ul class="section-toc">
<li><a href="#Overview" accesskey="1">Overview</a></li>
<li><a href="#Using-the-toolkit" accesskey="2">Using the toolkit</a></li>
</ul>
<div class="section" id="Overview">
<h3 class="section">2.1 Overview</h3>
<span id="index-Overview"></span>
<p>The octave-cfitsio toolkit provides high and level functionality for reading and
writing FITS format files.
</p>
<p>The high level functions provide base read and write of data to octave.
</p>
<p>The low level functions almost direct access to the cfitsio API and 
are provided under the matlab.io.fits namespace.
</p>
<p>Since <acronym>GNU</acronym> Octave does not support the matlab import command, a import_fits function
is provided.
</p>
<p>Running the statement:
</p><div class="example">
<pre class="example">import_fits
</pre></div>
<p>Is the equivalent of running in matlab:
</p><div class="example">
<pre class="example">import matlab.io.fits;
</pre></div>
</div>
<div class="section" id="Using-the-toolkit">
<h3 class="section">2.2 Using the toolkit</h3>
<span id="index-Using-the-toolkit"></span>
<p>The package must be loaded each time a <acronym>GNU</acronym> Octave session is started:
</p><div class="example">
<pre class="example">pkg load cfitsio
</pre></div>
<p>After loading the toolkit, the toolkit functions are available.
</p>
<ul class="section-toc">
<li><a href="#Reading-Data" accesskey="1">Reading Data</a></li>
<li><a href="#Reading-Information" accesskey="2">Reading Information</a></li>
<li><a href="#Low-level-functionality" accesskey="3">Low level functionality</a></li>
</ul>
<div class="subsection" id="Reading-Data">
<h4 class="subsection">2.2.1 Reading Data</h4>
<span id="index-Reading-Data"></span>
<p>To read the primary image data of a fits file, use the fitsread function:
</p>
<div class="example">
<pre class="example">  imagedata = fitsread(&quot;thefitsfile.fits&quot;);
</pre></div>
</div>
<div class="subsection" id="Reading-Information">
<h4 class="subsection">2.2.2 Reading Information</h4>
<span id="index-Reading-Information"></span>
<p>To read information about the content in a fits file, use the fitsinfo functions.
</p>
<div class="example">
<pre class="example">  info = fitsinfo(&quot;thefitsfile.fits&quot;);
</pre></div>
</div>
<div class="subsection" id="Low-level-functionality">
<h4 class="subsection">2.2.3 Low level functionality</h4>
<span id="index-Low-level-functionality"></span>
<p>Where functionality is required that is not met be the high level functions, 
most of the cfitsio functions are available in the matlab.io.fits namespace.
</p>
<div class="example">
<pre class="example">  # import the fits functions so don't have to use the full namespace each time
  import_fits;
  # open the file
  fd = fits.openFile('tst0012.fits');
  # get number of hdus in the file
  n = fits.getNumHDUs (fd);
  # for each hdu, go to it, print out the type
  for j = 1:n
    hdutype = fits.movAbsHDU (fd, j);
    printf ('HDU %d:  &quot;%s&quot;\n', j, hdutype);
  endif
  # close the file
  fits.closeFile (fd);
</pre></div>
<hr>
</div>
</div>
</div>
<div class="chapter" id="Function-Reference">
<div class="header">
<p>
Next: <a href="#Copying" accesskey="n" rel="next">GNU General Public License</a>, Previous: <a href="#Basic-Usage-Overview" accesskey="p" rel="prev">Basic Usage Overview</a>, Up: <a href="#Top" accesskey="u" rel="up">Introduction</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<span id="Function-Reference-1"></span><h2 class="chapter">3 Function Reference</h2>
<span id="index-Function-Reference"></span>
<p>The functions currently available in the toolkit are described below:
</p>
<ul class="section-toc">
<li><a href="#High-Level-File-Functions" accesskey="1">High Level File Functions</a></li>
<li><a href="#Low-Level-File-Functions" accesskey="2">Low Level File Functions</a></li>
<li><a href="#Low-Level-HDU-Functions" accesskey="3">Low Level HDU Functions</a></li>
<li><a href="#Low-Level-Keyword-Functions" accesskey="4">Low Level Keyword Functions</a></li>
<li><a href="#Low-Level-Image-Manipulation" accesskey="5">Low Level Image Manipulation</a></li>
<li><a href="#Low-Level-Utility-Functions" accesskey="6">Low Level Utility Functions</a></li>
<li><a href="#Low-Level-Compression-Functions" accesskey="7">Low Level Compression Functions</a></li>
<li><a href="#Low-Level-Binary-and-ASCII-Tables" accesskey="8">Low Level Binary and ASCII Tables</a></li>
<li><a href="#Import-functions" accesskey="9">Import functions</a></li>
</ul>
<hr>
<div class="section" id="High-Level-File-Functions">
<div class="header">
<p>
Next: <a href="#Low-Level-File-Functions" accesskey="n" rel="next">Low Level File Functions</a>, Up: <a href="#Function-Reference" accesskey="u" rel="up">Function Reference</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<span id="High-Level-File-Functions-1"></span><h3 class="section">3.1 High Level File Functions</h3>
<span id="index-High-Level-File-Functions"></span>
<ul class="section-toc">
<li><a href="#fitsdisp" accesskey="1">fitsdisp</a></li>
<li><a href="#fitsinfo" accesskey="2">fitsinfo</a></li>
<li><a href="#fitsread" accesskey="3">fitsread</a></li>
<li><a href="#fitswrite" accesskey="4">fitswrite</a></li>
</ul>
<div class="subsection" id="fitsdisp">
<h4 class="subsection">3.1.1 fitsdisp</h4>
<span id="index-fitsdisp"></span>
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
</div>
<div class="subsection" id="fitsinfo">
<h4 class="subsection">3.1.2 fitsinfo</h4>
<span id="index-fitsinfo"></span>
<dl class="def">
<dt id="index-_003d-2"><span class="category">: </span><span><em><var>info</var></em> <strong>=</strong> <em>fitsinfo(<var>filename</var>)</em><a href='#index-_003d-2' class='copiable-anchor'></a></span></dt>
<dd><p>Read information about fits format file
 </p><span id="Inputs-1"></span><h4 class="subsubheading">Inputs</h4>
<p><var>filename</var> - filename to open.
</p>
<span id="Outputs-1"></span><h4 class="subsubheading">Outputs</h4>
<p><var>info</var> - a struct containing the structure and information about
 the fits file.
</p>
<span id="Examples-1"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;);
 info = fitsinfo(filename);
 </pre></div>
</dd></dl>
</div>
<div class="subsection" id="fitsread">
<h4 class="subsection">3.1.3 fitsread</h4>
<span id="index-fitsread"></span>
<dl class="def">
<dt id="index-_003d-3"><span class="category">: </span><span><em><var>data</var></em> <strong>=</strong> <em>fitsread(<var>filename</var>)</em><a href='#index-_003d-3' class='copiable-anchor'></a></span></dt>
<dt id="index-_003d-4"><span class="category">: </span><span><em><var>data</var></em> <strong>=</strong> <em>fitsread(<var>filename</var>, 'raw')</em><a href='#index-_003d-4' class='copiable-anchor'></a></span></dt>
<dt id="index-_003d-5"><span class="category">: </span><span><em><var>data</var></em> <strong>=</strong> <em>fitsread(<var>filename</var>, <var>extname</var>)</em><a href='#index-_003d-5' class='copiable-anchor'></a></span></dt>
<dt id="index-_003d-6"><span class="category">: </span><span><em><var>data</var></em> <strong>=</strong> <em>fitsread(<var>filename</var>, <var>extname</var>, <var>index</var>)</em><a href='#index-_003d-6' class='copiable-anchor'></a></span></dt>
<dt id="index-_003d-7"><span class="category">: </span><span><em><var>data</var></em> <strong>=</strong> <em>fitsread(<var>filename</var>, ____, <var>propertyname</var>, <var>propertyvalue</var>)</em><a href='#index-_003d-7' class='copiable-anchor'></a></span></dt>
<dd><p>Read the primary data, or specified extension data. It scales the data and applied Nan to any undefined values.
</p>
<span id="Inputs-2"></span><h4 class="subsubheading">Inputs</h4>
<p><var>filename</var> - filename to open.
</p>
<p><var>exttype</var> - can be  &rsquo;primary&rsquo;, &rsquo;asciitable&rsquo;, &rsquo;binarytable&rsquo;, &rsquo;image&rsquo;, &rsquo;unknown&rsquo;.
</p>
<p><var>index</var> - can be used to specify which table when more than one of a given type exists.
</p>
<p>&rsquo;raw&rsquo;-  If the &rsquo;raw&rsquo; keyword is used, the raw data from the file will be used without replacing
 undefined values with Nan
</p>
<p>Known property names are:
 </p><dl compact="compact">
<dt><span>Info</span></dt>
<dd><p>input info from fitsinfo call.
 </p></dd>
<dt><span>PixelRegion</span></dt>
<dd><p>pixel region to extract data for in an image. It expects a cell array of same size as
 the number of axis in the image. Each cell should be in vector format of: start, [start stop]
 or [start, increment, stop].
 </p></dd>
<dt><span>TableColumns</span></dt>
<dd><p>A list of columns to extract from a ascii or binary table.
 </p></dd>
<dt><span>TableRows</span></dt>
<dd><p>A list of rows to extract from an ascii or binary table.
 </p></dd>
</dl>
<span id="Outputs-2"></span><h4 class="subsubheading">Outputs</h4>
<p><var>data</var> - The read data from the table or image.
</p>
<span id="Examples-2"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;);
 # read the primary image data
 imagedata = fitsread(filename);
 # read the 1st non primary image
 imagedata = fitsread(filename, &quot;image&quot;);
 # read the first binary table, selected columns
 tbldata = fitsread(filename, &quot;binarytable&quot;, &quot;TableColumns&quot;, [1 2 11]);
 # read the first ascii table
 atbldata = fitsread(filename, &quot;asciitable&quot;);
 </pre></div>
</dd></dl>
</div>
<div class="subsection" id="fitswrite">
<h4 class="subsection">3.1.4 fitswrite</h4>
<span id="index-fitswrite"></span>
<dl class="def">
<dt id="index-fitswrite_0028data_002c"><span class="category">: </span><span><em></em> <strong>fitswrite(<var>data</var>,</strong> <em><var>filename</var>)</em><a href='#index-fitswrite_0028data_002c' class='copiable-anchor'></a></span></dt>
<dt id="index-fitswrite_0028data_002c-1"><span class="category">: </span><span><em></em> <strong>fitswrite(<var>data</var>,</strong> <em><var>filename</var>, <var>propertyname</var>, <var>propertyvalue</var>)</em><a href='#index-fitswrite_0028data_002c-1' class='copiable-anchor'></a></span></dt>
<dd><p>Write image data <var>data</var>  to FITS file <var>filename</var>. If the fie already exists, overwrite it.
</p>
<span id="Inputs-3"></span><h4 class="subsubheading">Inputs</h4>
<p><var>data</var> - imagedata to write to a file.
</p>
<p><var>filename</var> - filename to write to.
</p>
<p><var>propertyname</var>, <var>propertyvalue</var> - property name/value pairs
</p>
<p>Additional properties can be set as <var>propertyname</var>, <var>propertyvalue</var> pairs.
 Known property names are:
 </p><dl compact="compact">
<dt><span>WriteMode</span></dt>
<dd><p>Set mode for writing to image as &rsquo;overwrite&rsquo; (default) or &rsquo;append&rsquo; to append images.
 </p></dd>
<dt><span>Compression</span></dt>
<dd><p>Set compression type to use for image as
 &rsquo;none&rsquo; (default), &rsquo;gzip&rsquo;, &rsquo;rice&rsquo;, &rsquo;hcompress&rsquo; or &rsquo;plio&rsquo;.
 </p></dd>
</dl>
<span id="Outputs-3"></span><h4 class="subsubheading">Outputs</h4>
<p>None
</p>
<span id="Examples-3"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> filename = tempname();
 X =  double([1:3;4:6]);
 fitswrite(X, filename);
 </pre></div>
</dd></dl>
<hr>
</div>
</div>
<div class="section" id="Low-Level-File-Functions">
<div class="header">
<p>
Next: <a href="#Low-Level-HDU-Functions" accesskey="n" rel="next">Low Level HDU Functions</a>, Previous: <a href="#High-Level-File-Functions" accesskey="p" rel="prev">High Level File Functions</a>, Up: <a href="#Function-Reference" accesskey="u" rel="up">Function Reference</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<span id="Low-Level-File-Functions-1"></span><h3 class="section">3.2 Low Level File Functions</h3>
<span id="index-Low-Level-File-Functions"></span>
<ul class="section-toc">
<li><a href="#matlab_002eio_002efits_002ecloseFile" accesskey="1">matlab.io.fits.closeFile</a></li>
<li><a href="#matlab_002eio_002efits_002ecreateFile" accesskey="2">matlab.io.fits.createFile</a></li>
<li><a href="#matlab_002eio_002efits_002edeleteFile" accesskey="3">matlab.io.fits.deleteFile</a></li>
<li><a href="#matlab_002eio_002efits_002efileMode" accesskey="4">matlab.io.fits.fileMode</a></li>
<li><a href="#matlab_002eio_002efits_002efileName" accesskey="5">matlab.io.fits.fileName</a></li>
<li><a href="#matlab_002eio_002efits_002eopenDiskFile" accesskey="6">matlab.io.fits.openDiskFile</a></li>
<li><a href="#matlab_002eio_002efits_002eopenFile" accesskey="7">matlab.io.fits.openFile</a></li>
</ul>
<div class="subsection" id="matlab_002eio_002efits_002ecloseFile">
<h4 class="subsection">3.2.1 matlab.io.fits.closeFile</h4>
<span id="index-closeFile"></span>
<dl class="def">
<dt id="index-closeFile_0028file_0029"><span class="category">: </span><span><em></em> <strong>closeFile(<var>file</var>)</strong><a href='#index-closeFile_0028file_0029' class='copiable-anchor'></a></span></dt>
<dd><p>Close the opened fits file
</p>
<p>This is the equivalent of the fits_close_file function.
</p>
<span id="Inputs-4"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened file returned from openFile or createFile.
</p>
<span id="Outputs-4"></span><h4 class="subsubheading">Outputs</h4>
<p>None
</p>
<span id="Examples-4"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;
 filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;)
 fd = fits.openFile(filename);
 fits.closeFile(fd);
 </pre></div>
<p><strong>See also:</strong> matlab.io.fits.createFile, matlab.io.fits.openFile.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ecreateFile">
<h4 class="subsection">3.2.2 matlab.io.fits.createFile</h4>
<span id="index-createFile"></span>
<dl class="def">
<dt id="index-_003d-8"><span class="category">: </span><span><em><var>file</var></em> <strong>=</strong> <em>createFile(<var>filename</var>)</em><a href='#index-_003d-8' class='copiable-anchor'></a></span></dt>
<dd><p>Attempt to create  a file of the given input name.
</p>
<p>If the filename starts with ! and the file exists, it will create a new file, otherwise, if the
 file exists, the create will fail.
</p>
<p>This is the equivalent of the cfitsio fits_create_file function.
</p>
<span id="Inputs-5"></span><h4 class="subsubheading">Inputs</h4>
<p><var>filename</var> - filename to open.
</p>
<span id="Outputs-5"></span><h4 class="subsubheading">Outputs</h4>
<p><var>file</var> - opened file identifier.
</p>
<span id="Examples-5"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;
 fd = fits.createFile(&quot;myfitsfile.fits&quot;);
 fits.createImg(fd, 'uint16', [100 100]);
 fits.closeFile(fd);
 </pre></div>
<p><strong>See also:</strong> matlab.io.fits.openFile.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002edeleteFile">
<h4 class="subsection">3.2.3 matlab.io.fits.deleteFile</h4>
<span id="index-deleteFile"></span>
<dl class="def">
<dt id="index-deleteFile_0028file_0029"><span class="category">: </span><span><em></em> <strong>deleteFile(<var>file</var>)</strong><a href='#index-deleteFile_0028file_0029' class='copiable-anchor'></a></span></dt>
<dd><p>Force a close and delete of a fits file.
</p>
<p>The is the equivalent of the fits_delete_file function.
</p>
<span id="Inputs-6"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-6"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002efileMode">
<h4 class="subsection">3.2.4 matlab.io.fits.fileMode</h4>
<span id="index-fileMode"></span>
<dl class="def">
<dt id="index-_003d-9"><span class="category">: </span><span><em><var>mode</var></em> <strong>=</strong> <em>fileMode(<var>file</var>)</em><a href='#index-_003d-9' class='copiable-anchor'></a></span></dt>
<dd><p>Return the file mode of the opened fits file.
</p>
<p>The is the equivalent of the fits_file_mode function.
</p>
<span id="Inputs-7"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-7"></span><h4 class="subsubheading">Outputs</h4>
<p><var>mode</var> - The mode will return as a string &rsquo;READWRITE&rsquo; or &rsquo;READONLY&rsquo;
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002efileName">
<h4 class="subsection">3.2.5 matlab.io.fits.fileName</h4>
<span id="index-fileName"></span>
<dl class="def">
<dt id="index-_003d-10"><span class="category">: </span><span><em><var>filename</var></em> <strong>=</strong> <em>fileName(<var>file</var>)</em><a href='#index-_003d-10' class='copiable-anchor'></a></span></dt>
<dd><p>Return the file name of the opened fits file.
</p>
<p>The is the equivalent of the fits_file_name function.
</p>
<span id="Inputs-8"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-8"></span><h4 class="subsubheading">Outputs</h4>
<p><var>filename</var> - name of the fits file.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002eopenDiskFile">
<h4 class="subsection">3.2.6 matlab.io.fits.openDiskFile</h4>
<span id="index-openDiskFile"></span>
<dl class="def">
<dt id="index-_003d-11"><span class="category">: </span><span><em><var>file</var></em> <strong>=</strong> <em>openDiskFile(<var>filename</var>)</em><a href='#index-_003d-11' class='copiable-anchor'></a></span></dt>
<dt id="index-_003d-12"><span class="category">: </span><span><em><var>file</var></em> <strong>=</strong> <em>openDiskFile(<var>filename</var>, <var>mode</var>)</em><a href='#index-_003d-12' class='copiable-anchor'></a></span></dt>
<dd><p>Attempt to open a file of the given input name, ignoring any special processing of the filename.
</p>
<p>This is the equivalent of the cfitsio fits_open_diskfile function.
</p>
<span id="Inputs-9"></span><h4 class="subsubheading">Inputs</h4>
<p><var>filename</var> - filename to open.
</p>
<p><var>mode</var> - If the option mode string &rsquo;READONLY&rsquo; (default) or &rsquo;READWRITE&rsquo; is provided,
 open the file using that mode.
</p>
<span id="Outputs-9"></span><h4 class="subsubheading">Outputs</h4>
<p><var>file</var> - opened file identifier.
</p>
<span id="Examples-6"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;
 filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;)
 fd = fits.openDiskFile(filename, 'READONLY');
 fits.closeFile(fd);
 </pre></div>
<p><strong>See also:</strong> openFile, createFile.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002eopenFile">
<h4 class="subsection">3.2.7 matlab.io.fits.openFile</h4>
<span id="index-openFile"></span>
<dl class="def">
<dt id="index-_003d-13"><span class="category">: </span><span><em><var>file</var></em> <strong>=</strong> <em>openFile(<var>filename</var>)</em><a href='#index-_003d-13' class='copiable-anchor'></a></span></dt>
<dt id="index-_003d-14"><span class="category">: </span><span><em><var>file</var></em> <strong>=</strong> <em>openFile(<var>filename</var>, <var>mode</var>)</em><a href='#index-_003d-14' class='copiable-anchor'></a></span></dt>
<dd><p>Attempt to open a file of the given input name.
</p>
<p>This is the equivalent of the cfitsio fits_open_file function.
</p>
<span id="Inputs-10"></span><h4 class="subsubheading">Inputs</h4>
<p><var>filename</var> - filename to open.
</p>
<p><var>mode</var> - If the option mode string &rsquo;READONLY&rsquo; (default) or &rsquo;READWRITE&rsquo; is provided,
 open the file using that mode.
</p>
<span id="Outputs-10"></span><h4 class="subsubheading">Outputs</h4>
<p><var>file</var> - opened file identifier.
</p>
<span id="Examples-7"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;
 filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;)
 fd = fits.openFile(filename, 'READONLY');
 fits.closeFile(fd);
 </pre></div>
<p><strong>See also:</strong> matlab.io.fits.openDiskFile, matlab.io.fits.createFile.
 </p></dd></dl>
<hr>
</div>
</div>
<div class="section" id="Low-Level-HDU-Functions">
<div class="header">
<p>
Next: <a href="#Low-Level-Keyword-Functions" accesskey="n" rel="next">Low Level Keyword Functions</a>, Previous: <a href="#Low-Level-File-Functions" accesskey="p" rel="prev">Low Level File Functions</a>, Up: <a href="#Function-Reference" accesskey="u" rel="up">Function Reference</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<span id="Low-Level-HDU-Functions-1"></span><h3 class="section">3.3 Low Level HDU Functions</h3>
<span id="index-Low-Level-HDU-Functions"></span>
<ul class="section-toc">
<li><a href="#matlab_002eio_002efits_002ecopyHDU" accesskey="1">matlab.io.fits.copyHDU</a></li>
<li><a href="#matlab_002eio_002efits_002edeleteHDU" accesskey="2">matlab.io.fits.deleteHDU</a></li>
<li><a href="#matlab_002eio_002efits_002egetHDUnum" accesskey="3">matlab.io.fits.getHDUnum</a></li>
<li><a href="#matlab_002eio_002efits_002egetHDUoff" accesskey="4">matlab.io.fits.getHDUoff</a></li>
<li><a href="#matlab_002eio_002efits_002egetHDUtype" accesskey="5">matlab.io.fits.getHDUtype</a></li>
<li><a href="#matlab_002eio_002efits_002egetNumHDUs" accesskey="6">matlab.io.fits.getNumHDUs</a></li>
<li><a href="#matlab_002eio_002efits_002emovAbsHDU" accesskey="7">matlab.io.fits.movAbsHDU</a></li>
<li><a href="#matlab_002eio_002efits_002emovNamHDU" accesskey="8">matlab.io.fits.movNamHDU</a></li>
<li><a href="#matlab_002eio_002efits_002emovRelHDU" accesskey="9">matlab.io.fits.movRelHDU</a></li>
<li><a href="#matlab_002eio_002efits_002ewriteChecksum">matlab.io.fits.writeChecksum</a></li>
</ul>
<div class="subsection" id="matlab_002eio_002efits_002ecopyHDU">
<h4 class="subsection">3.3.1 matlab.io.fits.copyHDU</h4>
<span id="index-copyHDU"></span>
<dl class="def">
<dt id="index-copyHDU_0028infile_002c"><span class="category">: </span><span><em></em> <strong>copyHDU(<var>infile</var>,</strong> <em><var>outfile</var>)</em><a href='#index-copyHDU_0028infile_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Copy current HDU from one infile to another.
</p>
<p>This is the equivalent of the cfitsio fits_copy_hdu function.
</p>
<span id="Inputs-11"></span><h4 class="subsubheading">Inputs</h4>
<p><var>filename</var> - filename to open.
</p>
<span id="Outputs-11"></span><h4 class="subsubheading">Outputs</h4>
<p><var>infile</var> - opened input file identifier.
</p>
<p><var>outfile</var> - opened output file identifier.
</p>
<span id="Examples-8"></span><h4 class="subsubheading">Examples</h4>
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
</div>
<div class="subsection" id="matlab_002eio_002efits_002edeleteHDU">
<h4 class="subsection">3.3.2 matlab.io.fits.deleteHDU</h4>
<span id="index-deleteHDU"></span>
<dl class="def">
<dt id="index-_003d-15"><span class="category">: </span><span><em><var>type</var></em> <strong>=</strong> <em>deleteHDU(<var>file</var>)</em><a href='#index-_003d-15' class='copiable-anchor'></a></span></dt>
<dd><p>Delete the current HDU and go to next HDU.
</p>
<p>Returns the newly current HDU type as a string.
</p>
<p>This is the equivalent of the cfitsio fits_delete_hdu function.
</p>
<span id="Inputs-12"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-12"></span><h4 class="subsubheading">Outputs</h4>
<p><var>type</var> - string value for type of the next HDU.
</p>
</dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetHDUnum">
<h4 class="subsection">3.3.3 matlab.io.fits.getHDUnum</h4>
<span id="index-getHDUnum"></span>
<dl class="def">
<dt id="index-_003d-16"><span class="category">: </span><span><em><var>num</var></em> <strong>=</strong> <em>getHDUnum(<var>file</var>)</em><a href='#index-_003d-16' class='copiable-anchor'></a></span></dt>
<dd><p>Return the index of the current HDU.
</p>
<p>This is the equivalent of the cfitsio fits_get_hdu_num function.
 </p><span id="Inputs-13"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-13"></span><h4 class="subsubheading">Outputs</h4>
<p><var>num</var> - current hdu number.
</p>
</dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetHDUoff">
<h4 class="subsection">3.3.4 matlab.io.fits.getHDUoff</h4>
<span id="index-getHDUoff"></span>
<dl class="def">
<dt id="index-_003d-17"><span class="category">: </span><span><em>[<var>headtstart</var>, <var>datastart</var>, <var>dataend</var>]</em> <strong>=</strong> <em>getHDUoff(<var>file</var>)</em><a href='#index-_003d-17' class='copiable-anchor'></a></span></dt>
<dd><p>Return offsets of the current HDU.
</p>
<p>This is the equivalent of the cfitsio fits_get_hduoff function.
</p>
<span id="Inputs-14"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-14"></span><h4 class="subsubheading">Outputs</h4>
<p><var>headtstart</var>, <var>datastart</var>, <var>dataend</var> - offset information for the current HDU.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetHDUtype">
<h4 class="subsection">3.3.5 matlab.io.fits.getHDUtype</h4>
<span id="index-getHDUtype"></span>
<dl class="def">
<dt id="index-_003d-18"><span class="category">: </span><span><em><var>type</var></em> <strong>=</strong> <em>getHDUtype(<var>file</var>)</em><a href='#index-_003d-18' class='copiable-anchor'></a></span></dt>
<dd><p>Return the current HDUs type as a string.
</p>
<p>This is the equivalent of the cfitsio fits_get_hdu_type function.
</p>
<span id="Inputs-15"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-15"></span><h4 class="subsubheading">Outputs</h4>
<p><var>type</var> - current hdu type
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetNumHDUs">
<h4 class="subsection">3.3.6 matlab.io.fits.getNumHDUs</h4>
<span id="index-getNumHDUs"></span>
<dl class="def">
<dt id="index-_003d-19"><span class="category">: </span><span><em><var>num</var></em> <strong>=</strong> <em>getNumHDUs(<var>file</var>)</em><a href='#index-_003d-19' class='copiable-anchor'></a></span></dt>
<dd><p>Return the count of HDUs in the file.
</p>
<p>This is the equivalent of the cfitsio fits_get_num_hdus function.
</p>
<span id="Inputs-16"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-16"></span><h4 class="subsubheading">Outputs</h4>
<p><var>num</var> - return the number of HDUs in the file.
 </p><span id="Examples-9"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;
 testname = file_in_loadpath(&quot;demos/tst0012.fits&quot;);
 fd = fits.openFile(testname);
 hducount = getNumHDUs(fd), 5);
 fits.closeFile(fd);
 </pre></div>
</dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002emovAbsHDU">
<h4 class="subsection">3.3.7 matlab.io.fits.movAbsHDU</h4>
<span id="index-movAbsHDU"></span>
<dl class="def">
<dt id="index-movAbsHDU_0028file_002c"><span class="category">: </span><span><em><var>type</var> =</em> <strong>movAbsHDU(<var>file</var>,</strong> <em><var>hdunum</var>)</em><a href='#index-movAbsHDU_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Go to absolute HDU index <var>hdunum</var>
</p>
<p>Returns the newly current HDU type as a string.
</p>
<p>This is the equivalent of the cfitsio fits_movabs_hdu function.
</p>
<span id="Inputs-17"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>hdunum</var> - HDU number to move to.
</p>
<span id="Outputs-17"></span><h4 class="subsubheading">Outputs</h4>
<p><var>type</var> - hdu type of the now current HDU.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002emovNamHDU">
<h4 class="subsection">3.3.8 matlab.io.fits.movNamHDU</h4>
<span id="index-movNamHDU"></span>
<dl class="def">
<dt id="index-movNamHDU_0028file_002c"><span class="category">Function File: </span><span><em><var>hdutype</var> =</em> <strong>movNamHDU(<var>file</var>,</strong> <em><var>hdutype</var>, <var>extname</var>, <var>extver</var>)</em><a href='#index-movNamHDU_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Go to HDU matching <var>hdutype</var>, <var>extname</var>, <var>extver</var>.
</p>
<p>This is the equivalent of the cfitsio fits_movnam_hdu function.
</p>
<span id="Inputs-18"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>hdutype</var> - HDU number to move to.
 Valid hdutype values are &rsquo;IMAGE_HDU&rsquo;, &rsquo;ASCII_TBL&rsquo;, &rsquo;BINARY_TBL&rsquo;, &rsquo;ANY_HDU&rsquo;.
</p>
<p><var>extname</var>, <var>extver</var> - EXTNAME and EXTVER keywords to match.
</p>
<span id="Outputs-18"></span><h4 class="subsubheading">Outputs</h4>
<p><var>hdutype</var> - hdu type of the now current HDU.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002emovRelHDU">
<h4 class="subsection">3.3.9 matlab.io.fits.movRelHDU</h4>
<span id="index-movRelHDU"></span>
<dl class="def">
<dt id="index-_003d-20"><span class="category">: </span><span><em><var>type</var></em> <strong>=</strong> <em>movRelHDU(<var>file</var>, <var>hdunum</var>)</em><a href='#index-_003d-20' class='copiable-anchor'></a></span></dt>
<dd><p>Go to relative HDU index <var>hdunum</var>.
</p>
<p>Returns the newly current HDU type as a string.
</p>
<p>This is the equivalent of the cfitsio fits_movrel_hdu function.
</p>
<span id="Inputs-19"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>hdunum</var> - relative HDU number to move to.
</p>
<span id="Outputs-19"></span><h4 class="subsubheading">Outputs</h4>
<p><var>type</var> - hdu type of the now current HDU.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ewriteChecksum">
<h4 class="subsection">3.3.10 matlab.io.fits.writeChecksum</h4>
<span id="index-writeChecksum"></span>
<dl class="def">
<dt id="index-writeChecksum_0028file_0029"><span class="category">: </span><span><em></em> <strong>writeChecksum(<var>file</var>)</strong><a href='#index-writeChecksum_0028file_0029' class='copiable-anchor'></a></span></dt>
<dd><p>Recalculate the HDU checksum and if required, write the new value.
</p>
<p>This is the equivalent of the cfitsio fits_write_chksum function.
</p>
<span id="Inputs-20"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-20"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
<hr>
</div>
</div>
<div class="section" id="Low-Level-Keyword-Functions">
<div class="header">
<p>
Next: <a href="#Low-Level-Image-Manipulation" accesskey="n" rel="next">Low Level Image Manipulation</a>, Previous: <a href="#Low-Level-HDU-Functions" accesskey="p" rel="prev">Low Level HDU Functions</a>, Up: <a href="#Function-Reference" accesskey="u" rel="up">Function Reference</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<span id="Low-Level-Keyword-Functions-1"></span><h3 class="section">3.4 Low Level Keyword Functions</h3>
<span id="index-Low-Level-Keyword-Functions"></span>
<ul class="section-toc">
<li><a href="#matlab_002eio_002efits_002edeleteKey" accesskey="1">matlab.io.fits.deleteKey</a></li>
<li><a href="#matlab_002eio_002efits_002edeleteRecord" accesskey="2">matlab.io.fits.deleteRecord</a></li>
<li><a href="#matlab_002eio_002efits_002egetHdrSpace" accesskey="3">matlab.io.fits.getHdrSpace</a></li>
<li><a href="#matlab_002eio_002efits_002ereadCard" accesskey="4">matlab.io.fits.readCard</a></li>
<li><a href="#matlab_002eio_002efits_002ereadKey" accesskey="5">matlab.io.fits.readKey</a></li>
<li><a href="#matlab_002eio_002efits_002ereadKeyCmplx" accesskey="6">matlab.io.fits.readKeyCmplx</a></li>
<li><a href="#matlab_002eio_002efits_002ereadKeyDbl" accesskey="7">matlab.io.fits.readKeyDbl</a></li>
<li><a href="#matlab_002eio_002efits_002ereadKeyLongLong" accesskey="8">matlab.io.fits.readKeyLongLong</a></li>
<li><a href="#matlab_002eio_002efits_002ereadKeyLongStr" accesskey="9">matlab.io.fits.readKeyLongStr</a></li>
<li><a href="#matlab_002eio_002efits_002ereadKeyUnit">matlab.io.fits.readKeyUnit</a></li>
<li><a href="#matlab_002eio_002efits_002ereadRecord">matlab.io.fits.readRecord</a></li>
<li><a href="#matlab_002eio_002efits_002ewriteComment">matlab.io.fits.writeComment</a></li>
<li><a href="#matlab_002eio_002efits_002ewriteDate">matlab.io.fits.writeDate</a></li>
<li><a href="#matlab_002eio_002efits_002ewriteHistory">matlab.io.fits.writeHistory</a></li>
<li><a href="#matlab_002eio_002efits_002ewriteKey">matlab.io.fits.writeKey</a></li>
<li><a href="#matlab_002eio_002efits_002ewriteKeyUnit">matlab.io.fits.writeKeyUnit</a></li>
</ul>
<div class="subsection" id="matlab_002eio_002efits_002edeleteKey">
<h4 class="subsection">3.4.1 matlab.io.fits.deleteKey</h4>
<span id="index-deleteKey"></span>
<dl class="def">
<dt id="index-deleteKey_0028file_002c"><span class="category">: </span><span><em></em> <strong>deleteKey(<var>file</var>,</strong> <em><var>key</var>)</em><a href='#index-deleteKey_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Delete a key in the fits file.
</p>
<p>This is the equivalent of the cfitsio fits_delete_key function.
</p>
<span id="Inputs-21"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>key</var> - Key name to remove.
</p>
<span id="Outputs-21"></span><h4 class="subsubheading">Outputs</h4>
<p>None
</p>
</dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002edeleteRecord">
<h4 class="subsection">3.4.2 matlab.io.fits.deleteRecord</h4>
<span id="index-deleteRecord"></span>
<dl class="def">
<dt id="index-deleteRecord_0028file_002c"><span class="category">: </span><span><em></em> <strong>deleteRecord(<var>file</var>,</strong> <em><var>keynum</var>)</em><a href='#index-deleteRecord_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Delete a key in the fits file.
</p>
<p>This is the equivalent of the cfitsio fits_delete_record function.
</p>
<span id="Inputs-22"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>keynum</var> - Record number to remove.
</p>
<span id="Outputs-22"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetHdrSpace">
<h4 class="subsection">3.4.3 matlab.io.fits.getHdrSpace</h4>
<span id="index-getHdrSpace"></span>
<dl class="def">
<dt id="index-getHdrSpace_0028file_0029"><span class="category">: </span><span><em>[<var>numkeys</var>, <var>freekeys</var>] =</em> <strong>getHdrSpace(<var>file</var>)</strong><a href='#index-getHdrSpace_0028file_0029' class='copiable-anchor'></a></span></dt>
<dd><p>Get the number of keyword records used and available.
</p>
<p>This is the equivalent of the cfitsio fits_get_hdrspace function.
</p>
<span id="Inputs-23"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-23"></span><h4 class="subsubheading">Outputs</h4>
<p><var>numkeys</var> - number of existing keys.
</p>
<p><var>freekeys</var> - number of free key space.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ereadCard">
<h4 class="subsection">3.4.4 matlab.io.fits.readCard</h4>
<span id="index-readCard"></span>
<dl class="def">
<dt id="index-readCard_0028file_002c"><span class="category">: </span><span><em><var>card</var> =</em> <strong>readCard(<var>file</var>,</strong> <em><var>recname</var>)</em><a href='#index-readCard_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Read the keyword card for name <var>recname</var>
</p>
<p>This is the equivalent of the cfitsio fits_read_card function.
</p>
<span id="Inputs-24"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>recname</var> - record name to read
</p>
<span id="Outputs-24"></span><h4 class="subsubheading">Outputs</h4>
<p><var>card</var> - unparsed record value string
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ereadKey">
<h4 class="subsection">3.4.5 matlab.io.fits.readKey</h4>
<span id="index-readKey"></span>
<dl class="def">
<dt id="index-readKey_0028file_002c"><span class="category">: </span><span><em>[<var>keyvalue</var>, <var>keycomment</var>] =</em> <strong>readKey(<var>file</var>,</strong> <em><var>recname</var>)</em><a href='#index-readKey_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Read the keyword value and comment for name <var>recname</var>.
</p>
<p>This is the equivalent of the cfitsio fits_read_key_str function.
</p>
<span id="Inputs-25"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>recname</var> - keyword name.
</p>
<span id="Outputs-25"></span><h4 class="subsubheading">Outputs</h4>
<p><var>keyvalue</var> - string value of record.
</p>
<p><var>keycomment</var> - comment string
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ereadKeyCmplx">
<h4 class="subsection">3.4.6 matlab.io.fits.readKeyCmplx</h4>
<span id="index-readKeyCmplx"></span>
<dl class="def">
<dt id="index-readKeyCmplx_0028file_002c"><span class="category">: </span><span><em>[<var>value</var>, <var>comment</var>] =</em> <strong>readKeyCmplx(<var>file</var>,</strong> <em><var>recname</var>)</em><a href='#index-readKeyCmplx_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Read the key value <var>recname</var> as a complex double.
</p>
<p>This is the equivalent of the cfitsio fits_read_key_dblcmp function.
</p>
<span id="Inputs-26"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>recname</var> - keyword name.
</p>
<span id="Outputs-26"></span><h4 class="subsubheading">Outputs</h4>
<p><var>value</var> - complex value of record.
</p>
<p><var>comment</var> - comment string
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ereadKeyDbl">
<h4 class="subsection">3.4.7 matlab.io.fits.readKeyDbl</h4>
<span id="index-readKeyDbl"></span>
<dl class="def">
<dt id="index-readKeyDbl_0028file_002c"><span class="category">Function File: </span><span><em>[<var>value</var>, <var>comment</var>] =</em> <strong>readKeyDbl(<var>file</var>,</strong> <em><var>recname</var>)</em><a href='#index-readKeyDbl_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Read the key value <var>recname</var> as a double.
</p>
<p>This is the equivalent of the cfitsio fits_read_key_dbl function.\n \
</p>
<span id="Inputs-27"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>recname</var> - keyword name.
</p>
<span id="Outputs-27"></span><h4 class="subsubheading">Outputs</h4>
<p><var>value</var> - double value of record.
</p>
<p><var>comment</var> - comment string
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ereadKeyLongLong">
<h4 class="subsection">3.4.8 matlab.io.fits.readKeyLongLong</h4>
<span id="index-readKeyLongLong"></span>
<dl class="def">
<dt id="index-readKeyLongLong_0028file_002c"><span class="category">: </span><span><em>[<var>value</var>, <var>comment</var>] =</em> <strong>readKeyLongLong(<var>file</var>,</strong> <em><var>recname</var>)</em><a href='#index-readKeyLongLong_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Read the key value <var>recname</var> as a long long.
</p>
<p>This is the equivalent of the cfitsio fits_read_key_lnglng function.
</p>
<span id="Inputs-28"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>recname</var> - keyword name.
</p>
<span id="Outputs-28"></span><h4 class="subsubheading">Outputs</h4>
<p><var>value</var> - int64 value of record.
</p>
<p><var>comment</var> - comment string
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ereadKeyLongStr">
<h4 class="subsection">3.4.9 matlab.io.fits.readKeyLongStr</h4>
<span id="index-readKeyLongStr"></span>
<dl class="def">
<dt id="index-readKeyLongStr_0028file_002c"><span class="category">: </span><span><em>[<var>value</var>, <var>comment</var>] =</em> <strong>readKeyLongStr(<var>file</var>,</strong> <em><var>recname</var>)</em><a href='#index-readKeyLongStr_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Read the key value <var>recname</var> as a string.
</p>
<p>This is the equivalent of the cfitsio fits_read_key_longstr function.
</p>
<span id="Inputs-29"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>recname</var> - keyword name.
</p>
<span id="Outputs-29"></span><h4 class="subsubheading">Outputs</h4>
<p><var>value</var> - string value of record.
</p>
<p><var>comment</var> - comment string
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ereadKeyUnit">
<h4 class="subsection">3.4.10 matlab.io.fits.readKeyUnit</h4>
<span id="index-readKeyUnit"></span>
<dl class="def">
<dt id="index-readKeyUnit_0028file_002c"><span class="category">: </span><span><em><var>keyunit</var> =</em> <strong>readKeyUnit(<var>file</var>,</strong> <em><var>recname</var>)</em><a href='#index-readKeyUnit_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Read the physical key units value <var>recname</var>.
</p>
<p>This is the equivalent of the cfitsio fits_read_key_unit function.
</p>
<span id="Inputs-30"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>recname</var> - keyword name.
</p>
<span id="Outputs-30"></span><h4 class="subsubheading">Outputs</h4>
<p><var>keyunit</var> - units value of record.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ereadRecord">
<h4 class="subsection">3.4.11 matlab.io.fits.readRecord</h4>
<span id="index-readRecord"></span>
<dl class="def">
<dt id="index-readRecord_0028file_002c"><span class="category">: </span><span><em><var>rec</var> =</em> <strong>readRecord(<var>file</var>,</strong> <em><var>recidx</var>)</em><a href='#index-readRecord_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Read the keyword record at <var>recidx</var>.
</p>
<p>This is the equivalent of the cfitsio fits_read_record function.
</p>
<span id="Inputs-31"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>recidx</var> - record number.
</p>
<span id="Outputs-31"></span><h4 class="subsubheading">Outputs</h4>
<p><var>rec</var> - full keyword record
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ewriteComment">
<h4 class="subsection">3.4.12 matlab.io.fits.writeComment</h4>
<span id="index-writeComment"></span>
<dl class="def">
<dt id="index-writeComment_0028file_002c"><span class="category">: </span><span><em></em> <strong>writeComment(<var>file</var>,</strong> <em><var>comment</var>)</em><a href='#index-writeComment_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Append a comment to to the fits file.
</p>
<p>This is the equivalent of the cfitsio fits_write_comment function.
</p>
<span id="Inputs-32"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>comment</var> - comment to append
</p>
<span id="Outputs-32"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ewriteDate">
<h4 class="subsection">3.4.13 matlab.io.fits.writeDate</h4>
<span id="index-writeDate"></span>
<dl class="def">
<dt id="index-writeDate_0028file_0029"><span class="category">: </span><span><em></em> <strong>writeDate(<var>file</var>)</strong><a href='#index-writeDate_0028file_0029' class='copiable-anchor'></a></span></dt>
<dd><p>Write the date keyword.
</p>
<p>This is the equivalent of the cfitsio fits_write_date function.
</p>
<span id="Inputs-33"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-33"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ewriteHistory">
<h4 class="subsection">3.4.14 matlab.io.fits.writeHistory</h4>
<span id="index-writeHistory"></span>
<dl class="def">
<dt id="index-writeHistory_0028file_002c"><span class="category">: </span><span><em></em> <strong>writeHistory(<var>file</var>,</strong> <em><var>history</var>)</em><a href='#index-writeHistory_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Append a history to to the fits file.
</p>
<p>This is the equivalent of the cfitsio fits_write_history function.
 </p><span id="Inputs-34"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>history</var> - history string.
</p>
<span id="Outputs-34"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ewriteKey">
<h4 class="subsection">3.4.15 matlab.io.fits.writeKey</h4>
<span id="index-writeKey"></span>
<dl class="def">
<dt id="index-writeKey_0028file_002c"><span class="category">: </span><span><em></em> <strong>writeKey(<var>file</var>,</strong> <em><var>key</var>, <var>value</var>)</em><a href='#index-writeKey_0028file_002c' class='copiable-anchor'></a></span></dt>
<dt id="index-writeKey_0028file_002c-1"><span class="category">: </span><span><em></em> <strong>writeKey(<var>file</var>,</strong> <em><var>key</var>, <var>value</var>, <var>comment</var>)</em><a href='#index-writeKey_0028file_002c-1' class='copiable-anchor'></a></span></dt>
<dt id="index-writeKey_0028file_002c-2"><span class="category">: </span><span><em></em> <strong>writeKey(<var>file</var>,</strong> <em><var>key</var>, <var>value</var>, <var>comment</var>, <var>decimals</var>)</em><a href='#index-writeKey_0028file_002c-2' class='copiable-anchor'></a></span></dt>
<dd><p>Append or replace a key in the fits file.
</p>
<p>This is the equivalent of the cfitsio fits_write_key and fits_update_key function.
 </p><span id="Inputs-35"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>key</var> - keyword name.
</p>
<p><var>value</var> - keyword value.
</p>
<p><var>comment</var> - keyword comment.
</p>
<p><var>decimals</var> - number of decimals.
</p>
<span id="Outputs-35"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ewriteKeyUnit">
<h4 class="subsection">3.4.16 matlab.io.fits.writeKeyUnit</h4>
<span id="index-writeKeyUnit"></span>
<dl class="def">
<dt id="index-writeKeyUnit_0028file_002c"><span class="category">: </span><span><em></em> <strong>writeKeyUnit(<var>file</var>,</strong> <em><var>key</var>, <var>unit</var>)</em><a href='#index-writeKeyUnit_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Write a key unit to the fits file.
</p>
<p>This is the equivalent of the cfitsio fits_write_key_unit function.
 </p><span id="Inputs-36"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>key</var> - keyword name.
</p>
<p><var>unit</var> - keyword units as string.
</p>
<span id="Outputs-36"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
<hr>
</div>
</div>
<div class="section" id="Low-Level-Image-Manipulation">
<div class="header">
<p>
Next: <a href="#Low-Level-Utility-Functions" accesskey="n" rel="next">Low Level Utility Functions</a>, Previous: <a href="#Low-Level-Keyword-Functions" accesskey="p" rel="prev">Low Level Keyword Functions</a>, Up: <a href="#Function-Reference" accesskey="u" rel="up">Function Reference</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<span id="Low-Level-Image-Manipulation-1"></span><h3 class="section">3.5 Low Level Image Manipulation</h3>
<span id="index-Low-Level-Image-Manipulation"></span>
<ul class="section-toc">
<li><a href="#matlab_002eio_002efits_002ecreateImg" accesskey="1">matlab.io.fits.createImg</a></li>
<li><a href="#matlab_002eio_002efits_002egetImgSize" accesskey="2">matlab.io.fits.getImgSize</a></li>
<li><a href="#matlab_002eio_002efits_002egetImgType" accesskey="3">matlab.io.fits.getImgType</a></li>
<li><a href="#matlab_002eio_002efits_002einsertImg" accesskey="4">matlab.io.fits.insertImg</a></li>
<li><a href="#matlab_002eio_002efits_002ereadImg" accesskey="5">matlab.io.fits.readImg</a></li>
<li><a href="#matlab_002eio_002efits_002esetBscale" accesskey="6">matlab.io.fits.setBscale</a></li>
<li><a href="#matlab_002eio_002efits_002esetTscale" accesskey="7">matlab.io.fits.setTscale</a></li>
<li><a href="#matlab_002eio_002efits_002ewriteImg" accesskey="8">matlab.io.fits.writeImg</a></li>
</ul>
<div class="subsection" id="matlab_002eio_002efits_002ecreateImg">
<h4 class="subsection">3.5.1 matlab.io.fits.createImg</h4>
<span id="index-createImg"></span>
<dl class="def">
<dt id="index-createImg_0028file_002c"><span class="category">: </span><span><em></em> <strong>createImg(<var>file</var>,</strong> <em><var>bitpix</var>, <var>naxis</var>)</em><a href='#index-createImg_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>create a new primary image or image extension.
</p>
<p>This is the equivalent of the cfitsio fits_create_imgll function.
</p>
<span id="Inputs-37"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - file previously opened with openFile, openDiskFile
 or createFile.
</p>
<p><var>bitpix</var> - type for the data as a string in either matlab or cfitsio naming.
</p>
<p><var>naxis</var> - axis values for the image.
</p>
<span id="Outputs-37"></span><h4 class="subsubheading">Outputs</h4>
<p>None
</p>
<span id="Examples-10"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;
 fd = fits.createFile(&quot;test.fits&quot;);
 fits.createImg(fd,'int16',[10 20]);
 fits.close(fd);
 </pre></div>
</dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetImgSize">
<h4 class="subsection">3.5.2 matlab.io.fits.getImgSize</h4>
<span id="index-getImgSize"></span>
<dl class="def">
<dt id="index-_003d-21"><span class="category">: </span><span><em><var>size</var></em> <strong>=</strong> <em>getImgSize(<var>file</var>)</em><a href='#index-_003d-21' class='copiable-anchor'></a></span></dt>
<dd><p>Return size of a Image HDU.
</p>
<p>This is the equivalent of the cfitsio fits_get_img_size function.
</p>
<span id="Inputs-38"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-38"></span><h4 class="subsubheading">Outputs</h4>
<p><var>size</var> - vector containing the image dimensions.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetImgType">
<h4 class="subsection">3.5.3 matlab.io.fits.getImgType</h4>
<span id="index-getImgType"></span>
<dl class="def">
<dt id="index-_003d-22"><span class="category">: </span><span><em><var>type</var></em> <strong>=</strong> <em>getImgType(<var>file</var>)</em><a href='#index-_003d-22' class='copiable-anchor'></a></span></dt>
<dd><p>Return datatype of a Image HDU
</p>
<p>This is the equivalent of the cfitsio fits_get_img_type function.
</p>
<span id="Inputs-39"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-39"></span><h4 class="subsubheading">Outputs</h4>
<p><var>type</var> - datatype as a string for the image type.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002einsertImg">
<h4 class="subsection">3.5.4 matlab.io.fits.insertImg</h4>
<span id="index-insertImg"></span>
<dl class="def">
<dt id="index-insertImg_0028file_002c"><span class="category">: </span><span><em></em> <strong>insertImg(<var>file</var>,</strong> <em><var>bitpix</var>, <var>naxis</var>)</em><a href='#index-insertImg_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Insert a new primary image or image extension at current HDU position.
</p>
<p>This is the equivalent of the cfitsio fits_insert_imgll function.
</p>
<span id="Inputs-40"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - file previously opened with openFile, openDiskFile
 or createFile.
</p>
<p><var>bitpix</var> - type for the data as a string in either matlab or cfitsio naming.
</p>
<p><var>naxis</var> - axis values for the image.
</p>
<span id="Outputs-40"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ereadImg">
<h4 class="subsection">3.5.5 matlab.io.fits.readImg</h4>
<span id="index-readImg"></span>
<dl class="def">
<dt id="index-_003d-23"><span class="category">: </span><span><em><var>data</var></em> <strong>=</strong> <em>readImg(<var>file</var>)</em><a href='#index-_003d-23' class='copiable-anchor'></a></span></dt>
<dt id="index-_003d-24"><span class="category">: </span><span><em><var>data</var></em> <strong>=</strong> <em>readImg(<var>file</var>, <var>firstpix</var>, <var>lastpix</var>)</em><a href='#index-_003d-24' class='copiable-anchor'></a></span></dt>
<dt id="index-_003d-25"><span class="category">: </span><span><em><var>data</var></em> <strong>=</strong> <em>readImg(<var>file</var>, <var>firstpix</var>, <var>lastpix</var>, <var>inc</var>)</em><a href='#index-_003d-25' class='copiable-anchor'></a></span></dt>
<dd><p>Read Image data.
</p>
<p>This is the equivalent of the cfitsio fits_read_subset function.
</p>
<span id="Inputs-41"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>firstpix</var> - first pile coordinate
</p>
<p><var>lastpix</var> - last pixel coordinate
</p>
<p><var>inc</var> -  pixel increment
</p>
<span id="Outputs-41"></span><h4 class="subsubheading">Outputs</h4>
<p><var>data</var> - image data read
 </p><span id="Examples-11"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;
 filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;);
 fd = fits.openFile(filename);
 # read the image
 imagedata = fits.readImg(fd);
 # read a 70x80 part of the image
 imagedata = fits.readImg(fd, [11 11],[80 90]);
 fits.closeFile(fd);
 </pre></div>
</dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002esetBscale">
<h4 class="subsection">3.5.6 matlab.io.fits.setBscale</h4>
<span id="index-setBscale"></span>
<dl class="def">
<dt id="index-setBscale_0028file_002c"><span class="category">: </span><span><em></em> <strong>setBscale(<var>file</var>,</strong> <em><var>bscale</var>, <var>bzero</var>)</em><a href='#index-setBscale_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Reset bscale and bzero to be used with reading and writing Images.
</p>
<p>This is the equivalent of the cfitsio fits_set_bscale function.
</p>
<span id="Inputs-42"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>bscale</var> - bscale value
</p>
<p><var>bzero</var> - bzero value
</p>
<span id="Outputs-42"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002esetTscale">
<h4 class="subsection">3.5.7 matlab.io.fits.setTscale</h4>
<span id="index-setTscale"></span>
<dl class="def">
<dt id="index-setTscale_0028file_002c"><span class="category">: </span><span><em></em> <strong>setTscale(<var>file</var>,</strong> <em><var>col</var>, <var>scale</var>, <var>zero</var>)</em><a href='#index-setTscale_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Reset scale and zero to be used with reading and writing table data.
</p>
<p>This is the equivalent of the cfitsio fits_set_tscale function.
</p>
<span id="Inputs-43"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>col</var> - column number
</p>
<p><var>scale</var> - scale value
</p>
<p><var>zero</var> - zero value
</p>
<span id="Outputs-43"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ewriteImg">
<h4 class="subsection">3.5.8 matlab.io.fits.writeImg</h4>
<span id="index-writeImg"></span>
<dl class="def">
<dt id="index-writeImg_0028file_002c"><span class="category">: </span><span><em></em> <strong>writeImg(<var>file</var>,</strong> <em><var>imagedata</var>)</em><a href='#index-writeImg_0028file_002c' class='copiable-anchor'></a></span></dt>
<dt id="index-writeImg_0028file_002c-1"><span class="category">: </span><span><em></em> <strong>writeImg(<var>file</var>,</strong> <em><var>imagedata</var>, <var>fpixel</var>)</em><a href='#index-writeImg_0028file_002c-1' class='copiable-anchor'></a></span></dt>
<dd><p>write imagedata to a FITS file. The rows and column size must match the size of NAXIS, NAXIS etc
</p>
<p>This is the equivalent of the cfitsio fits_write_subset function.
</p>
<span id="Inputs-44"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>imagedata</var> - Image data.
</p>
<p><var>fpixel</var> - start pixel to write from.
</p>
<span id="Outputs-44"></span><h4 class="subsubheading">Outputs</h4>
<p>None
</p>
<span id="Examples-12"></span><h4 class="subsubheading">Examples</h4>
<p>Create a fits file and write a 10x10 image in the primary and image ext:
 </p><div class="example">
<pre class="example"> import_fits;
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
<hr>
</div>
</div>
<div class="section" id="Low-Level-Utility-Functions">
<div class="header">
<p>
Next: <a href="#Low-Level-Compression-Functions" accesskey="n" rel="next">Low Level Compression Functions</a>, Previous: <a href="#Low-Level-Image-Manipulation" accesskey="p" rel="prev">Low Level Image Manipulation</a>, Up: <a href="#Function-Reference" accesskey="u" rel="up">Function Reference</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<span id="Low-Level-Utility-Functions-1"></span><h3 class="section">3.6 Low Level Utility Functions</h3>
<span id="index-Low-Level-Utility-Functions"></span>
<ul class="section-toc">
<li><a href="#matlab_002eio_002efits_002egetConstantNames" accesskey="1">matlab.io.fits.getConstantNames</a></li>
<li><a href="#matlab_002eio_002efits_002egetConstantValue" accesskey="2">matlab.io.fits.getConstantValue</a></li>
<li><a href="#matlab_002eio_002efits_002egetOpenFiles" accesskey="3">matlab.io.fits.getOpenFiles</a></li>
<li><a href="#matlab_002eio_002efits_002egetVersion" accesskey="4">matlab.io.fits.getVersion</a></li>
</ul>
<div class="subsection" id="matlab_002eio_002efits_002egetConstantNames">
<h4 class="subsection">3.6.1 matlab.io.fits.getConstantNames</h4>
<span id="index-getConstantNames"></span>
<dl class="def">
<dt id="index-_003d-26"><span class="category">: </span><span><em><var>namelist</var></em> <strong>=</strong> <em>getConstantNames()</em><a href='#index-_003d-26' class='copiable-anchor'></a></span></dt>
<dd><p>Return the names of all known fits constants.
</p>
<span id="Inputs-45"></span><h4 class="subsubheading">Inputs</h4>
<p>None
</p>
<span id="Outputs-45"></span><h4 class="subsubheading">Outputs</h4>
<p><var>namelist</var> - cell array of all known fits constant names
</p>
<p><strong>See also:</strong> getConstantValue.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetConstantValue">
<h4 class="subsection">3.6.2 matlab.io.fits.getConstantValue</h4>
<span id="index-getConstantValue"></span>
<dl class="def">
<dt id="index-_003d-27"><span class="category">: </span><span><em><var>value</var></em> <strong>=</strong> <em>getConstantValue(<var>name</var>)</em><a href='#index-_003d-27' class='copiable-anchor'></a></span></dt>
<dd><p>Return the value of a known fits constant.
</p>
<span id="Inputs-46"></span><h4 class="subsubheading">Inputs</h4>
<p><var>name</var> - name of the constant to retrieve value of.
</p>
<span id="Outputs-46"></span><h4 class="subsubheading">Outputs</h4>
<p><var>value</var> - value of the constant
</p>
<p><strong>See also:</strong> getConstantNames.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetOpenFiles">
<h4 class="subsection">3.6.3 matlab.io.fits.getOpenFiles</h4>
<span id="index-getOpenFiles"></span>
<dl class="def">
<dt id="index-_003d-28"><span class="category">: </span><span><em><var>files</var></em> <strong>=</strong> <em>getOpenFiles()</em><a href='#index-_003d-28' class='copiable-anchor'></a></span></dt>
<dd><p>Get the file handles of all open fits files.
</p>
<span id="Inputs-47"></span><h4 class="subsubheading">Inputs</h4>
<p>None
</p>
<span id="Outputs-47"></span><h4 class="subsubheading">Outputs</h4>
<p><var>files</var> list of opened fits file handles.
 </p>
<p><strong>See also:</strong> openFile.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetVersion">
<h4 class="subsection">3.6.4 matlab.io.fits.getVersion</h4>
<span id="index-getVersion"></span>
<dl class="def">
<dt id="index-_003d-29"><span class="category">: </span><span><em><var>ver</var></em> <strong>=</strong> <em>getVersion()</em><a href='#index-_003d-29' class='copiable-anchor'></a></span></dt>
<dd><p>Return the version number of the cfitsio library used.
</p>
<p>This is the equivalent of the cfitsio fits_get_version function.
</p>
<span id="Inputs-48"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-48"></span><h4 class="subsubheading">Outputs</h4>
<p><var>ver</var> - version
 </p></dd></dl>
<hr>
</div>
</div>
<div class="section" id="Low-Level-Compression-Functions">
<div class="header">
<p>
Next: <a href="#Low-Level-Binary-and-ASCII-Tables" accesskey="n" rel="next">Low Level Binary and ASCII Tables</a>, Previous: <a href="#Low-Level-Utility-Functions" accesskey="p" rel="prev">Low Level Utility Functions</a>, Up: <a href="#Function-Reference" accesskey="u" rel="up">Function Reference</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<span id="Low-Level-Compression-Functions-1"></span><h3 class="section">3.7 Low Level Compression Functions</h3>
<span id="index-Low-Level-Compression-Functions"></span>
<ul class="section-toc">
<li><a href="#matlab_002eio_002efits_002eimgCompress" accesskey="1">matlab.io.fits.imgCompress</a></li>
<li><a href="#matlab_002eio_002efits_002eisCompressedImg" accesskey="2">matlab.io.fits.isCompressedImg</a></li>
<li><a href="#matlab_002eio_002efits_002esetCompressionType" accesskey="3">matlab.io.fits.setCompressionType</a></li>
<li><a href="#matlab_002eio_002efits_002esetHCompScale" accesskey="4">matlab.io.fits.setHCompScale</a></li>
<li><a href="#matlab_002eio_002efits_002esetHCompSmooth" accesskey="5">matlab.io.fits.setHCompSmooth</a></li>
<li><a href="#matlab_002eio_002efits_002esetTileDim" accesskey="6">matlab.io.fits.setTileDim</a></li>
</ul>
<div class="subsection" id="matlab_002eio_002efits_002eimgCompress">
<h4 class="subsection">3.7.1 matlab.io.fits.imgCompress</h4>
<span id="index-imgCompress"></span>
<dl class="def">
<dt id="index-imgCompress_0028infile_002c"><span class="category">: </span><span><em></em> <strong>imgCompress(<var>infile</var>,</strong> <em><var>outfile</var>)</em><a href='#index-imgCompress_0028infile_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Copy HDU and image data from one infile to another, using the outfiles compression type.
</p>
<p>This is the equivalent of the cfitsio fits_img_compress function.
</p>
<span id="Inputs-49"></span><h4 class="subsubheading">Inputs</h4>
<p><var>infile</var> - opened input fits file.
</p>
<p><var>outfile</var> - opened writable output fits file.
</p>
<span id="Outputs-49"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002eisCompressedImg">
<h4 class="subsection">3.7.2 matlab.io.fits.isCompressedImg</h4>
<span id="index-isCompressedImg"></span>
<dl class="def">
<dt id="index-isCompressedImg_0028file_0029"><span class="category">: </span><span><em><var>comp</var> =</em> <strong>isCompressedImg(<var>file</var>)</strong><a href='#index-isCompressedImg_0028file_0029' class='copiable-anchor'></a></span></dt>
<dd><p>Return true if image is compressed.
</p>
<p>This is the equivalent of the cfitsio fits_is_compressed_image function.
</p>
<span id="Inputs-50"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-50"></span><h4 class="subsubheading">Outputs</h4>
<p><var>comp</var> - boolean for whether image is compressed or not.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002esetCompressionType">
<h4 class="subsection">3.7.3 matlab.io.fits.setCompressionType</h4>
<span id="index-setCompressionType"></span>
<dl class="def">
<dt id="index-setCompressionType_0028file_002c"><span class="category">: </span><span><em></em> <strong>setCompressionType(<var>file</var>,</strong> <em><var>comptype</var>)</em><a href='#index-setCompressionType_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Set compression type for writing FITS images.
</p>
<p>This is the equivalent of the cfitsio fits_set_compression_type function.
</p>
<span id="Inputs-51"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>comptype</var> - compression type.
 Valid comptype values are: &rsquo;GZIP&rsquo;, &rsquo;GZIP2&rsquo;, &rsquo;RICE&rsquo;, &rsquo;PLIO&rsquo;, &rsquo;HCOMPRESS&rsquo; or &rsquo;NOCOMPRESS&rsquo;.
</p>
<span id="Outputs-51"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002esetHCompScale">
<h4 class="subsection">3.7.4 matlab.io.fits.setHCompScale</h4>
<span id="index-setHCompScale"></span>
<dl class="def">
<dt id="index-setHCompScale_0028file_002c"><span class="category">: </span><span><em></em> <strong>setHCompScale(<var>file</var>,</strong> <em><var>scale</var>)</em><a href='#index-setHCompScale_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Set scale to be used with HCOMPRESS compression.
</p>
<p>This is the equivalent of the cfitsio fits_set_hcomp_scale function.
</p>
<span id="Inputs-52"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>scale</var> - scale value
 </p><span id="Outputs-52"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002esetHCompSmooth">
<h4 class="subsection">3.7.5 matlab.io.fits.setHCompSmooth</h4>
<span id="index-setHCompSmooth"></span>
<dl class="def">
<dt id="index-setHCompSmooth_0028file_002c"><span class="category">: </span><span><em></em> <strong>setHCompSmooth(<var>file</var>,</strong> <em><var>smooth</var>)</em><a href='#index-setHCompSmooth_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Set smooth value to be used with HCOMPRESS compression.
</p>
<p>This is the equivalent of the cfitsio fits_set_hcomp_smooth function.
</p>
<span id="Inputs-53"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>smooth</var> - smooth value
</p>
<span id="Outputs-53"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002esetTileDim">
<h4 class="subsection">3.7.6 matlab.io.fits.setTileDim</h4>
<span id="index-setTileDim"></span>
<dl class="def">
<dt id="index-setTileDim_0028file_002c"><span class="category">: </span><span><em></em> <strong>setTileDim(<var>file</var>,</strong> <em><var>tiledims</var>)</em><a href='#index-setTileDim_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Set compression tile dims for writing FITS images.
</p>
<p>This is the equivalent of the cfitsio fits_set_tile_dim function.
</p>
<span id="Inputs-54"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>tiledims</var> - tile dimensions
</p>
<span id="Outputs-54"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
<hr>
</div>
</div>
<div class="section" id="Low-Level-Binary-and-ASCII-Tables">
<div class="header">
<p>
Next: <a href="#Import-functions" accesskey="n" rel="next">Import functions</a>, Previous: <a href="#Low-Level-Compression-Functions" accesskey="p" rel="prev">Low Level Compression Functions</a>, Up: <a href="#Function-Reference" accesskey="u" rel="up">Function Reference</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<span id="Low-Level-Binary-and-ASCII-Tables-1"></span><h3 class="section">3.8 Low Level Binary and ASCII Tables</h3>
<span id="index-Low-Level-Binary-and-ASCII-Tables"></span>
<ul class="section-toc">
<li><a href="#matlab_002eio_002efits_002ecreateTbl" accesskey="1">matlab.io.fits.createTbl</a></li>
<li><a href="#matlab_002eio_002efits_002edeleteCol" accesskey="2">matlab.io.fits.deleteCol</a></li>
<li><a href="#matlab_002eio_002efits_002edeleteRows" accesskey="3">matlab.io.fits.deleteRows</a></li>
<li><a href="#matlab_002eio_002efits_002egetAColParms" accesskey="4">matlab.io.fits.getAColParms</a></li>
<li><a href="#matlab_002eio_002efits_002egetBColParms" accesskey="5">matlab.io.fits.getBColParms</a></li>
<li><a href="#matlab_002eio_002efits_002egetColName" accesskey="6">matlab.io.fits.getColName</a></li>
<li><a href="#matlab_002eio_002efits_002egetColType" accesskey="7">matlab.io.fits.getColType</a></li>
<li><a href="#matlab_002eio_002efits_002egetEqColType" accesskey="8">matlab.io.fits.getEqColType</a></li>
<li><a href="#matlab_002eio_002efits_002egetNumCols" accesskey="9">matlab.io.fits.getNumCols</a></li>
<li><a href="#matlab_002eio_002efits_002egetNumRows">matlab.io.fits.getNumRows</a></li>
<li><a href="#matlab_002eio_002efits_002egetRowSize">matlab.io.fits.getRowSize</a></li>
<li><a href="#matlab_002eio_002efits_002einsertATbl">matlab.io.fits.insertATbl</a></li>
<li><a href="#matlab_002eio_002efits_002einsertBTbl">matlab.io.fits.insertBTbl</a></li>
<li><a href="#matlab_002eio_002efits_002einsertCol">matlab.io.fits.insertCol</a></li>
<li><a href="#matlab_002eio_002efits_002einsertRows">matlab.io.fits.insertRows</a></li>
<li><a href="#matlab_002eio_002efits_002ereadATblHdr">matlab.io.fits.readATblHdr</a></li>
<li><a href="#matlab_002eio_002efits_002ereadBTblHdr">matlab.io.fits.readBTblHdr</a></li>
<li><a href="#matlab_002eio_002efits_002ereadCol">matlab.io.fits.readCol</a></li>
<li><a href="#matlab_002eio_002efits_002ewriteCol">matlab.io.fits.writeCol</a></li>
</ul>
<div class="subsection" id="matlab_002eio_002efits_002ecreateTbl">
<h4 class="subsection">3.8.1 matlab.io.fits.createTbl</h4>
<span id="index-createTbl"></span>
<dl class="def">
<dt id="index-createTbl_0028file_002c"><span class="category">: </span><span><em></em> <strong>createTbl(<var>file</var>,</strong> <em><var>tbltype</var>, <var>nrows</var>, <var>ttype</var>, <var>tform</var>)</em><a href='#index-createTbl_0028file_002c' class='copiable-anchor'></a></span></dt>
<dt id="index-createTbl_0028file_002c-1"><span class="category">: </span><span><em></em> <strong>createTbl(<var>file</var>,</strong> <em><var>tbltype</var>, <var>nrows</var>, <var>ttype</var>, <var>tform</var>, <var>tunit</var>)</em><a href='#index-createTbl_0028file_002c-1' class='copiable-anchor'></a></span></dt>
<dt id="index-createTbl_0028file_002c-2"><span class="category">: </span><span><em></em> <strong>createTbl(<var>file</var>,</strong> <em><var>tbltype</var>, <var>nrows</var>, <var>ttype</var>, <var>tform</var>, <var>tunit</var>, <var>extname</var>)</em><a href='#index-createTbl_0028file_002c-2' class='copiable-anchor'></a></span></dt>
<dd><p>Create a new ASCII or bintable extension.
</p>
<p>This is the equivalent of the cfitsio fits_create_tbl function.
</p>
<span id="Inputs-55"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>tbltype</var> - table type &rsquo;binary&rsquo; or &rsquo;ascii&rsquo;.
</p>
<p><var>nrows</var> - initial number of rows (normally 0)
</p>
<p><var>ttype</var> - cell array of column type
</p>
<p><var>tform</var> - cell array of column format
</p>
<p><var>tunit</var> - cell array of column units
</p>
<p><var>extname</var> - optional extension name
</p>
<p><var>ttype</var>, <var>tform</var>, <var>tunit</var> are expected to be the same size.
</p>
<span id="Outputs-55"></span><h4 class="subsubheading">Outputs</h4>
<p>None
</p>
<span id="Examples-13"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;
 fd = fits.createFile(&quot;test.fits&quot;);
 ttype = {'Col1','Col2','Col3','Col4'};
 tform = {'A9','A4','A3','A8'};
 tunit = {'m','s','kg','km'};
 fits.createTbl(fd,'binary',0,ttype,tform,tunit,'table-name');
 fits.closeFile(fd);
 </pre></div>
</dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002edeleteCol">
<h4 class="subsection">3.8.2 matlab.io.fits.deleteCol</h4>
<span id="index-deleteCol"></span>
<dl class="def">
<dt id="index-deleteCol_0028file_002c"><span class="category">: </span><span><em></em> <strong>deleteCol(<var>file</var>,</strong> <em><var>colnum</var>)</em><a href='#index-deleteCol_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Delete a column from a table.
</p>
<p>This is the equivalent of the cfitsio fits_delete_col function.
</p>
<span id="Inputs-56"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>colnum</var> - Column to delete from current table.
</p>
<span id="Outputs-56"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002edeleteRows">
<h4 class="subsection">3.8.3 matlab.io.fits.deleteRows</h4>
<span id="index-deleteRows"></span>
<dl class="def">
<dt id="index-deleteRows_0028file_002c"><span class="category">: </span><span><em></em> <strong>deleteRows(<var>file</var>,</strong> <em><var>firstrow</var>, <var>numrows</var>)</em><a href='#index-deleteRows_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Insert a rows into a table.
</p>
<p>This is the equivalent of the cfitsio fits_delete_rows function.
</p>
<span id="Inputs-57"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>firstrow</var> - Start row to delete.
</p>
<p><var>numrows</var> - Number of rows to delete.
</p>
<span id="Outputs-57"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetAColParms">
<h4 class="subsection">3.8.4 matlab.io.fits.getAColParms</h4>
<span id="index-getAColParms"></span>
<dl class="def">
<dt id="index-_003d-30"><span class="category">: </span><span><em>[<var>ttype</var>,<var>tbcol</var>,<var>tunit</var>,<var>tform</var>,<var>scale</var>,<var>zero</var>,<var>nulstr</var>,<var>tdisp</var>]</em> <strong>=</strong> <em>getAColParms(<var>file</var>, <var>colnum</var>)</em><a href='#index-_003d-30' class='copiable-anchor'></a></span></dt>
<dd><p>Get ASCII table parameters.
</p>
<p>This is the equivalent of the cfitsio fits_get_acolparms function.
</p>
<span id="Inputs-58"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>colnum</var> - Column to retrieve.
</p>
<span id="Outputs-58"></span><h4 class="subsubheading">Outputs</h4>
<p><var>ttype</var>,<var>tbcol</var>,<var>tunit</var>,<var>tform</var>,<var>scale</var>,<var>zero</var>,<var>nulstr</var>,<var>tdisp</var>
 column information in same format as provided by fits_get_acolparms.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetBColParms">
<h4 class="subsection">3.8.5 matlab.io.fits.getBColParms</h4>
<span id="index-getBColParms"></span>
<dl class="def">
<dt id="index-_003d-31"><span class="category">: </span><span><em>[<var>ttype</var>,<var>tunit</var>,<var>typechar</var>,<var>repeat</var>,<var>scale</var>,<var>zero</var>,<var>nulval</var>,<var>tdisp</var>]</em> <strong>=</strong> <em>getBColParms(<var>file</var>, <var>colnum</var>)</em><a href='#index-_003d-31' class='copiable-anchor'></a></span></dt>
<dd><p>Get binary table parameters.
</p>
<p>This is the equivalent of the cfitsio  fits_get_bcolparms function.
</p>
<span id="Inputs-59"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>colnum</var> - Column to retrieve.
</p>
<span id="Outputs-59"></span><h4 class="subsubheading">Outputs</h4>
<p><var>ttype</var>,<var>tunit</var>,<var>typechar</var>,<var>repeat</var>,<var>scale</var>,<var>zero</var>,<var>nulval</var>,<var>tdisp</var>
 column information in same format as provided by fits_get_bcolparms.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetColName">
<h4 class="subsection">3.8.6 matlab.io.fits.getColName</h4>
<span id="index-getColName"></span>
<dl class="def">
<dt id="index-_003d-32"><span class="category">: </span><span><em>[<var>colnum</var>,<var>colname</var>]</em> <strong>=</strong> <em>getColName(<var>file</var>, <var>template</var>)</em><a href='#index-_003d-32' class='copiable-anchor'></a></span></dt>
<dt id="index-_003d-33"><span class="category">: </span><span><em>[<var>colnum</var>,<var>colname</var>]</em> <strong>=</strong> <em>getColName(<var>file</var>, <var>template</var>, <var>casesens</var>)</em><a href='#index-_003d-33' class='copiable-anchor'></a></span></dt>
<dd><p>Get column name.
</p>
<p>This is the equivalent of the cfitsio fits_get_colname function.
</p>
<span id="Inputs-60"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>template</var> - template string for matching column name.
</p>
<p><var>casesens</var> - boolean whether to be case sensitive in match.
</p>
<span id="Outputs-60"></span><h4 class="subsubheading">Outputs</h4>
<p><var>colnum</var> - column number of match.
</p>
<p><var>colname</var> - column name of match.
</p>
<span id="Examples-14"></span><h4 class="subsubheading">Examples</h4>
<div class="example">
<pre class="example"> import_fits;
 filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;);
 fd = fits.openFile(filename);
 fits.movAbsHDU(fd,2);
 [colnum, colname] = fits.getColName(fd,&quot;C*&quot;);
 # returned 3, &quot;COUNTS&quot;
 fits.closeFile(fd);
 </pre></div>
</dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetColType">
<h4 class="subsection">3.8.7 matlab.io.fits.getColType</h4>
<span id="index-getColType"></span>
<dl class="def">
<dt id="index-_003d-34"><span class="category">: </span><span><em>[<var>dtype</var>,<var>repeat</var>,<var>width</var>]</em> <strong>=</strong> <em>getColType(<var>file</var>, <var>colnum</var>)</em><a href='#index-_003d-34' class='copiable-anchor'></a></span></dt>
<dd><p>Get column type.
</p>
<p>This is the equivalent of the cfitsio  fits_get_coltypell function.
</p>
<span id="Inputs-61"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>colnum</var> - Column to delete from current table.
</p>
<span id="Outputs-61"></span><h4 class="subsubheading">Outputs</h4>
<p><var>dtype</var>,<var>repeat</var>,<var>width</var> - column information.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetEqColType">
<h4 class="subsection">3.8.8 matlab.io.fits.getEqColType</h4>
<span id="index-getEqColType"></span>
<dl class="def">
<dt id="index-_003d-35"><span class="category">: </span><span><em>[<var>dtype</var>,<var>repeat</var>,<var>width</var>]</em> <strong>=</strong> <em>getEqColType(<var>file</var>, <var>colnum</var>)</em><a href='#index-_003d-35' class='copiable-anchor'></a></span></dt>
<dd><p>Get column type.
</p>
<p>This is the equivalent of the cfitsio  fits_get_eqcoltypell function.
</p>
<span id="Inputs-62"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>colnum</var> - Column number.
</p>
<span id="Outputs-62"></span><h4 class="subsubheading">Outputs</h4>
<p><var>dtype</var>,<var>repeat</var>,<var>width</var> - column type
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetNumCols">
<h4 class="subsection">3.8.9 matlab.io.fits.getNumCols</h4>
<span id="index-getNumCols"></span>
<dl class="def">
<dt id="index-_003d-36"><span class="category">: </span><span><em><var>ncols</var></em> <strong>=</strong> <em>getNumCols(<var>file</var>)</em><a href='#index-_003d-36' class='copiable-anchor'></a></span></dt>
<dd><p>Get number of columns.
</p>
<p>This is the equivalent of the cfitsio  fits_get_num_cols function.
</p>
<span id="Inputs-63"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-63"></span><h4 class="subsubheading">Outputs</h4>
<p><var>ncols</var> - the number of columns in the table.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetNumRows">
<h4 class="subsection">3.8.10 matlab.io.fits.getNumRows</h4>
<span id="index-getNumRows"></span>
<dl class="def">
<dt id="index-_003d-37"><span class="category">: </span><span><em><var>nrows</var></em> <strong>=</strong> <em>getNumRows(<var>file</var>)</em><a href='#index-_003d-37' class='copiable-anchor'></a></span></dt>
<dd><p>Get number of rows.
</p>
<p>This is the equivalent of the cfitsio fits_get_numrowsll function.
</p>
<span id="Inputs-64"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-64"></span><h4 class="subsubheading">Outputs</h4>
<p><var>nrows</var> - the number of rows in in the current table.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002egetRowSize">
<h4 class="subsection">3.8.11 matlab.io.fits.getRowSize</h4>
<span id="index-getRowSize"></span>
<dl class="def">
<dt id="index-_003d-38"><span class="category">: </span><span><em><var>nrows</var></em> <strong>=</strong> <em>getRowSize(<var>file</var>)</em><a href='#index-_003d-38' class='copiable-anchor'></a></span></dt>
<dd><p>Get optimum number of rows to read/write at one time.
</p>
<p>This is the equivalent of the cfitsio  fits_get_rowsize function.
</p>
<span id="Inputs-65"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-65"></span><h4 class="subsubheading">Outputs</h4>
<p><var>nrows</var> - number of rows.
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002einsertATbl">
<h4 class="subsection">3.8.12 matlab.io.fits.insertATbl</h4>
<span id="index-insertATbl"></span>
<dl class="def">
<dt id="index-insertATbl_0028file_002c"><span class="category">: </span><span><em></em> <strong>insertATbl(<var>file</var>,</strong> <em><var>rowlen</var>, <var>nrows</var>, <var>ttype</var>, <var>tbcol</var>, <var>tform</var>)</em><a href='#index-insertATbl_0028file_002c' class='copiable-anchor'></a></span></dt>
<dt id="index-insertATbl_0028file_002c-1"><span class="category">: </span><span><em></em> <strong>insertATbl(<var>file</var>,</strong> <em><var>rowlen</var>, <var>nrows</var>, <var>ttype</var>, <var>tbcol</var>, <var>tform</var>, <var>tunit</var>)</em><a href='#index-insertATbl_0028file_002c-1' class='copiable-anchor'></a></span></dt>
<dt id="index-insertATbl_0028file_002c-2"><span class="category">: </span><span><em></em> <strong>insertATbl(<var>file</var>,</strong> <em><var>tbltype</var>, <var>nrows</var>, <var>ttype</var>, <var>tbcol</var>, <var>tform</var>, <var>tunit</var>, <var>extname</var>)</em><a href='#index-insertATbl_0028file_002c-2' class='copiable-anchor'></a></span></dt>
<dd><p>Insert a new ASCII table after current HDU.
</p>
<p>This is the equivalent of the cfitsio fits_insert_atbl function.
</p>
<span id="Inputs-66"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>rowlen</var> - row length. If set to 0, the function will calculate size based on
 tbcol and ttype.
</p>
<p><var>nrows</var> - initial number of rows (normally 0)
</p>
<p><var>ttype</var> - cell array of column type
</p>
<p><var>tbcol</var> - array containing the start indices for each column.
</p>
<p><var>tform</var> - cell array of column format
</p>
<p><var>tunit</var> - cell array of column units
</p>
<p><var>extname</var> - optional extension name
</p>
<span id="Outputs-66"></span><h4 class="subsubheading">Outputs</h4>
<p>None
</p>
</dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002einsertBTbl">
<h4 class="subsection">3.8.13 matlab.io.fits.insertBTbl</h4>
<span id="index-insertBTbl"></span>
<dl class="def">
<dt id="index-insertBTbl_0028file_002c"><span class="category">: </span><span><em></em> <strong>insertBTbl(<var>file</var>,</strong> <em><var>nrows</var>, <var>ttype</var>, <var>tform</var>, <var>tunit</var>, <var>extname</var>, <var>pcount</var>)</em><a href='#index-insertBTbl_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Insert a new bintable extension.
</p>
<p>This is the equivalent of the cfitsio fits_insert_btbl function.
</p>
<span id="Inputs-67"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>nrows</var> - initial number of rows (normally 0)
</p>
<p><var>ttype</var> - cell array of column type
</p>
<p><var>tform</var> - cell array of column format
</p>
<p><var>tunit</var> - cell array of column units
</p>
<p><var>extname</var> - optional extension name
</p>
<p><var>pcount</var> - heap size.
</p>
<p><var>ttype</var>, <var>tform</var>, <var>tunit</var> are expected to be the same size.
</p>
<span id="Outputs-67"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002einsertCol">
<h4 class="subsection">3.8.14 matlab.io.fits.insertCol</h4>
<span id="index-insertCol"></span>
<dl class="def">
<dt id="index-insertCol_0028file_002c"><span class="category">: </span><span><em></em> <strong>insertCol(<var>file</var>,</strong> <em><var>colnum</var>, <var>ttype</var>, <var>tform</var>)</em><a href='#index-insertCol_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Insert a column into a table.
</p>
<p>This is the equivalent of the cfitsio fits_insert_col function.
</p>
<span id="Inputs-68"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>colnum</var> - Column to delete from current table.
</p>
<p><var>ttype</var>, <var>tform</var> - column type to insert
</p>
<span id="Outputs-68"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002einsertRows">
<h4 class="subsection">3.8.15 matlab.io.fits.insertRows</h4>
<span id="index-insertRows"></span>
<dl class="def">
<dt id="index-insertRows_0028file_002c"><span class="category">: </span><span><em></em> <strong>insertRows(<var>file</var>,</strong> <em><var>firstrow</var>, <var>numrows</var>)</em><a href='#index-insertRows_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Insert rows into a table.
</p>
<p>This is the equivalent of the cfitsio fits_insert_rows function.
</p>
<span id="Inputs-69"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>firstrow</var> - Start row to insert from.
</p>
<p><var>numrows</var> - Number of rows to add.
</p>
<span id="Outputs-69"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ereadATblHdr">
<h4 class="subsection">3.8.16 matlab.io.fits.readATblHdr</h4>
<span id="index-readATblHdr"></span>
<dl class="def">
<dt id="index-_003d-39"><span class="category">: </span><span><em>[<var>rowlen</var>,<var>nrows</var>,<var>ttype</var>,<var>tbcol</var>,<var>tform</var>,<var>tunit</var>,<var>extname</var>]</em> <strong>=</strong> <em>readATblHdr(<var>file</var>)</em><a href='#index-_003d-39' class='copiable-anchor'></a></span></dt>
<dd><p>Get ASCII table parameters.
</p>
<p>This is the equivalent of the cfitsio  fits_read_atablhdrll function.
</p>
<span id="Inputs-70"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-70"></span><h4 class="subsubheading">Outputs</h4>
<p><var>rowlen</var>,<var>nrows</var>,<var>ttype</var>,<var>tbcol</var>,<var>tform</var>,<var>tunit</var>,<var>extname</var> - table properties
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ereadBTblHdr">
<h4 class="subsection">3.8.17 matlab.io.fits.readBTblHdr</h4>
<span id="index-readBTblHdr"></span>
<dl class="def">
<dt id="index-_003d-40"><span class="category">: </span><span><em>[<var>nrows</var>,<var>ttype</var>,<var>tform</var>,<var>tunit</var>,<var>extname</var>,<var>pcount</var>]</em> <strong>=</strong> <em>readBTblHdr(<var>file</var>)</em><a href='#index-_003d-40' class='copiable-anchor'></a></span></dt>
<dd><p>Get Binary table parameters.
</p>
<p>This is the equivalent of the cfitsio  fits_read_btablhdrll function.
</p>
<span id="Inputs-71"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<span id="Outputs-71"></span><h4 class="subsubheading">Outputs</h4>
<p><var>nrows</var>,<var>ttype</var>,<var>tform</var>,<var>tunit</var>,<var>extname</var>,<var>pcount</var>] - table properties
 </p></dd></dl>
</div>
<div class="subsection" id="matlab_002eio_002efits_002ereadCol">
<h4 class="subsection">3.8.18 matlab.io.fits.readCol</h4>
<span id="index-readCol"></span>
<dl class="def">
<dt id="index-_003d-41"><span class="category">: </span><span><em>[<var>coldata</var>, <var>nullval</var>]</em> <strong>=</strong> <em>readCol(<var>file</var>, <var>colnum</var>)</em><a href='#index-_003d-41' class='copiable-anchor'></a></span></dt>
<dt id="index-_003d-42"><span class="category">: </span><span><em>[<var>coldata</var>, <var>nullval</var>]</em> <strong>=</strong> <em>readCol(<var>file</var>, <var>colnum</var>, <var>firstrow</var>, <var>numrows</var>)</em><a href='#index-_003d-42' class='copiable-anchor'></a></span></dt>
<dd><p>Get table row data.
</p>
<p>This is the equivalent of the cfitsio  fits_read_col function.
</p>
<span id="Inputs-72"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>firstrow</var> - Start row
</p>
<p><var>numrows</var> - Number of rows to read
</p>
<span id="Outputs-72"></span><h4 class="subsubheading">Outputs</h4>
<p><var>coldata</var> - the column data rows
</p>
<p><var>nulldata</var> - the null value flags
 </p><span id="Examples-15"></span><h4 class="subsubheading">Examples</h4>
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
</div>
<div class="subsection" id="matlab_002eio_002efits_002ewriteCol">
<h4 class="subsection">3.8.19 matlab.io.fits.writeCol</h4>
<span id="index-writeCol"></span>
<dl class="def">
<dt id="index-writeCol_0028file_002c"><span class="category">: </span><span><em></em> <strong>writeCol(<var>file</var>,</strong> <em><var>colnum</var>, <var>firstrow</var>, <var>data</var>)</em><a href='#index-writeCol_0028file_002c' class='copiable-anchor'></a></span></dt>
<dd><p>Write elements to a table.
</p>
<p>This is the equivalent of the cfitsio fits_write_col function.
</p>
<span id="Inputs-73"></span><h4 class="subsubheading">Inputs</h4>
<p><var>file</var> - opened fits file.
</p>
<p><var>colnum</var> - column number.
</p>
<p><var>firstrow</var> - first row number.
</p>
<p><var>data</var> - data to write to column
</p>
<span id="Outputs-73"></span><h4 class="subsubheading">Outputs</h4>
<p>None
 </p></dd></dl>
<hr>
</div>
</div>
<div class="section" id="Import-functions">
<div class="header">
<p>
Previous: <a href="#Low-Level-Binary-and-ASCII-Tables" accesskey="p" rel="prev">Low Level Binary and ASCII Tables</a>, Up: <a href="#Function-Reference" accesskey="u" rel="up">Function Reference</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<span id="Import-functions-1"></span><h3 class="section">3.9 Import functions</h3>
<span id="index-Import-functions"></span>
<ul class="section-toc">
<li><a href="#import_005ffits" accesskey="1">import_fits</a></li>
</ul>
<div class="subsection" id="import_005ffits">
<h4 class="subsection">3.9.1 import_fits</h4>
<span id="index-import_005ffits"></span>
<dl class="def">
<dt id="index-import_005ffits-1"><span class="category">: </span><span><em></em> <strong>import_fits</strong><a href='#index-import_005ffits-1' class='copiable-anchor'></a></span></dt>
<dd><p>Import the fits functions into a fits.xxxxx variable, to emulate importing the fits namespace.
 </p></dd></dl>
<hr>
</div>
</div>
</div>
<div class="appendix" id="Copying">
<div class="header">
<p>
Next: <a href="#Index" accesskey="n" rel="next">Index</a>, Previous: <a href="#Function-Reference" accesskey="p" rel="prev">Function Reference</a>, Up: <a href="#Top" accesskey="u" rel="up">Introduction</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<span id="GNU-General-Public-License"></span><h2 class="appendix">Appendix A GNU General Public License</h2>
<span id="index-warranty"></span>
<span id="index-copyright"></span>
<div align="center">Version 3, 29 June 2007
</div>
<div class="display">
<pre class="display">Copyright &copy; 2007 Free Software Foundation, Inc. <a href="http://fsf.org/">http://fsf.org/</a>
Everyone is permitted to copy and distribute verbatim copies of this
license document, but changing it is not allowed.
</pre></div>
<span id="Preamble"></span><h3 class="heading">Preamble</h3>
<p>The GNU General Public License is a free, copyleft license for
software and other kinds of works.
</p>
<p>The licenses for most software and other practical works are designed
to take away your freedom to share and change the works.  By contrast,
the GNU General Public License is intended to guarantee your freedom
to share and change all versions of a program&mdash;to make sure it remains
free software for all its users.  We, the Free Software Foundation,
use the GNU General Public License for most of our software; it
applies also to any other work released this way by its authors.  You
can apply it to your programs, too.
</p>
<p>When we speak of free software, we are referring to freedom, not
price.  Our General Public Licenses are designed to make sure that you
have the freedom to distribute copies of free software (and charge for
them if you wish), that you receive source code or can get it if you
want it, that you can change the software or use pieces of it in new
free programs, and that you know you can do these things.
</p>
<p>To protect your rights, we need to prevent others from denying you
these rights or asking you to surrender the rights.  Therefore, you
have certain responsibilities if you distribute copies of the
software, or if you modify it: responsibilities to respect the freedom
of others.
</p>
<p>For example, if you distribute copies of such a program, whether
gratis or for a fee, you must pass on to the recipients the same
freedoms that you received.  You must make sure that they, too,
receive or can get the source code.  And you must show them these
terms so they know their rights.
</p>
<p>Developers that use the GNU GPL protect your rights with two steps:
(1) assert copyright on the software, and (2) offer you this License
giving you legal permission to copy, distribute and/or modify it.
</p>
<p>For the developers&rsquo; and authors&rsquo; protection, the GPL clearly explains
that there is no warranty for this free software.  For both users&rsquo; and
authors&rsquo; sake, the GPL requires that modified versions be marked as
changed, so that their problems will not be attributed erroneously to
authors of previous versions.
</p>
<p>Some devices are designed to deny users access to install or run
modified versions of the software inside them, although the
manufacturer can do so.  This is fundamentally incompatible with the
aim of protecting users&rsquo; freedom to change the software.  The
systematic pattern of such abuse occurs in the area of products for
individuals to use, which is precisely where it is most unacceptable.
Therefore, we have designed this version of the GPL to prohibit the
practice for those products.  If such problems arise substantially in
other domains, we stand ready to extend this provision to those
domains in future versions of the GPL, as needed to protect the
freedom of users.
</p>
<p>Finally, every program is threatened constantly by software patents.
States should not allow patents to restrict development and use of
software on general-purpose computers, but in those that do, we wish
to avoid the special danger that patents applied to a free program
could make it effectively proprietary.  To prevent this, the GPL
assures that patents cannot be used to render the program non-free.
</p>
<p>The precise terms and conditions for copying, distribution and
modification follow.
</p>
<span id="TERMS-AND-CONDITIONS"></span><h3 class="heading">TERMS AND CONDITIONS</h3>
<ol start="0">
<li> Definitions.
<p>&ldquo;This License&rdquo; refers to version 3 of the GNU General Public License.
</p>
<p>&ldquo;Copyright&rdquo; also means copyright-like laws that apply to other kinds
of works, such as semiconductor masks.
</p>
<p>&ldquo;The Program&rdquo; refers to any copyrightable work licensed under this
License.  Each licensee is addressed as &ldquo;you&rdquo;.  &ldquo;Licensees&rdquo; and
&ldquo;recipients&rdquo; may be individuals or organizations.
</p>
<p>To &ldquo;modify&rdquo; a work means to copy from or adapt all or part of the work
in a fashion requiring copyright permission, other than the making of
an exact copy.  The resulting work is called a &ldquo;modified version&rdquo; of
the earlier work or a work &ldquo;based on&rdquo; the earlier work.
</p>
<p>A &ldquo;covered work&rdquo; means either the unmodified Program or a work based
on the Program.
</p>
<p>To &ldquo;propagate&rdquo; a work means to do anything with it that, without
permission, would make you directly or secondarily liable for
infringement under applicable copyright law, except executing it on a
computer or modifying a private copy.  Propagation includes copying,
distribution (with or without modification), making available to the
public, and in some countries other activities as well.
</p>
<p>To &ldquo;convey&rdquo; a work means any kind of propagation that enables other
parties to make or receive copies.  Mere interaction with a user
through a computer network, with no transfer of a copy, is not
conveying.
</p>
<p>An interactive user interface displays &ldquo;Appropriate Legal Notices&rdquo; to
the extent that it includes a convenient and prominently visible
feature that (1) displays an appropriate copyright notice, and (2)
tells the user that there is no warranty for the work (except to the
extent that warranties are provided), that licensees may convey the
work under this License, and how to view a copy of this License.  If
the interface presents a list of user commands or options, such as a
menu, a prominent item in the list meets this criterion.
</p>
</li><li> Source Code.
<p>The &ldquo;source code&rdquo; for a work means the preferred form of the work for
making modifications to it.  &ldquo;Object code&rdquo; means any non-source form
of a work.
</p>
<p>A &ldquo;Standard Interface&rdquo; means an interface that either is an official
standard defined by a recognized standards body, or, in the case of
interfaces specified for a particular programming language, one that
is widely used among developers working in that language.
</p>
<p>The &ldquo;System Libraries&rdquo; of an executable work include anything, other
than the work as a whole, that (a) is included in the normal form of
packaging a Major Component, but which is not part of that Major
Component, and (b) serves only to enable use of the work with that
Major Component, or to implement a Standard Interface for which an
implementation is available to the public in source code form.  A
&ldquo;Major Component&rdquo;, in this context, means a major essential component
(kernel, window system, and so on) of the specific operating system
(if any) on which the executable work runs, or a compiler used to
produce the work, or an object code interpreter used to run it.
</p>
<p>The &ldquo;Corresponding Source&rdquo; for a work in object code form means all
the source code needed to generate, install, and (for an executable
work) run the object code and to modify the work, including scripts to
control those activities.  However, it does not include the work&rsquo;s
System Libraries, or general-purpose tools or generally available free
programs which are used unmodified in performing those activities but
which are not part of the work.  For example, Corresponding Source
includes interface definition files associated with source files for
the work, and the source code for shared libraries and dynamically
linked subprograms that the work is specifically designed to require,
such as by intimate data communication or control flow between those
subprograms and other parts of the work.
</p>
<p>The Corresponding Source need not include anything that users can
regenerate automatically from other parts of the Corresponding Source.
</p>
<p>The Corresponding Source for a work in source code form is that same
work.
</p>
</li><li> Basic Permissions.
<p>All rights granted under this License are granted for the term of
copyright on the Program, and are irrevocable provided the stated
conditions are met.  This License explicitly affirms your unlimited
permission to run the unmodified Program.  The output from running a
covered work is covered by this License only if the output, given its
content, constitutes a covered work.  This License acknowledges your
rights of fair use or other equivalent, as provided by copyright law.
</p>
<p>You may make, run and propagate covered works that you do not convey,
without conditions so long as your license otherwise remains in force.
You may convey covered works to others for the sole purpose of having
them make modifications exclusively for you, or provide you with
facilities for running those works, provided that you comply with the
terms of this License in conveying all material for which you do not
control copyright.  Those thus making or running the covered works for
you must do so exclusively on your behalf, under your direction and
control, on terms that prohibit them from making any copies of your
copyrighted material outside their relationship with you.
</p>
<p>Conveying under any other circumstances is permitted solely under the
conditions stated below.  Sublicensing is not allowed; section 10
makes it unnecessary.
</p>
</li><li> Protecting Users&rsquo; Legal Rights From Anti-Circumvention Law.
<p>No covered work shall be deemed part of an effective technological
measure under any applicable law fulfilling obligations under article
11 of the WIPO copyright treaty adopted on 20 December 1996, or
similar laws prohibiting or restricting circumvention of such
measures.
</p>
<p>When you convey a covered work, you waive any legal power to forbid
circumvention of technological measures to the extent such
circumvention is effected by exercising rights under this License with
respect to the covered work, and you disclaim any intention to limit
operation or modification of the work as a means of enforcing, against
the work&rsquo;s users, your or third parties&rsquo; legal rights to forbid
circumvention of technological measures.
</p>
</li><li> Conveying Verbatim Copies.
<p>You may convey verbatim copies of the Program&rsquo;s source code as you
receive it, in any medium, provided that you conspicuously and
appropriately publish on each copy an appropriate copyright notice;
keep intact all notices stating that this License and any
non-permissive terms added in accord with section 7 apply to the code;
keep intact all notices of the absence of any warranty; and give all
recipients a copy of this License along with the Program.
</p>
<p>You may charge any price or no price for each copy that you convey,
and you may offer support or warranty protection for a fee.
</p>
</li><li> Conveying Modified Source Versions.
<p>You may convey a work based on the Program, or the modifications to
produce it from the Program, in the form of source code under the
terms of section 4, provided that you also meet all of these
conditions:
</p>
<ol type="a" start="1">
<li> The work must carry prominent notices stating that you modified it,
and giving a relevant date.
</li><li> The work must carry prominent notices stating that it is released
under this License and any conditions added under section 7.  This
requirement modifies the requirement in section 4 to &ldquo;keep intact all
notices&rdquo;.
</li><li> You must license the entire work, as a whole, under this License to
anyone who comes into possession of a copy.  This License will
therefore apply, along with any applicable section 7 additional terms,
to the whole of the work, and all its parts, regardless of how they
are packaged.  This License gives no permission to license the work in
any other way, but it does not invalidate such permission if you have
separately received it.
</li><li> If the work has interactive user interfaces, each must display
Appropriate Legal Notices; however, if the Program has interactive
interfaces that do not display Appropriate Legal Notices, your work
need not make them do so.
</li></ol>
<p>A compilation of a covered work with other separate and independent
works, which are not by their nature extensions of the covered work,
and which are not combined with it such as to form a larger program,
in or on a volume of a storage or distribution medium, is called an
&ldquo;aggregate&rdquo; if the compilation and its resulting copyright are not
used to limit the access or legal rights of the compilation&rsquo;s users
beyond what the individual works permit.  Inclusion of a covered work
in an aggregate does not cause this License to apply to the other
parts of the aggregate.
</p>
</li><li> Conveying Non-Source Forms.
<p>You may convey a covered work in object code form under the terms of
sections 4 and 5, provided that you also convey the machine-readable
Corresponding Source under the terms of this License, in one of these
ways:
</p>
<ol type="a" start="1">
<li> Convey the object code in, or embodied in, a physical product
(including a physical distribution medium), accompanied by the
Corresponding Source fixed on a durable physical medium customarily
used for software interchange.
</li><li> Convey the object code in, or embodied in, a physical product
(including a physical distribution medium), accompanied by a written
offer, valid for at least three years and valid for as long as you
offer spare parts or customer support for that product model, to give
anyone who possesses the object code either (1) a copy of the
Corresponding Source for all the software in the product that is
covered by this License, on a durable physical medium customarily used
for software interchange, for a price no more than your reasonable
cost of physically performing this conveying of source, or (2) access
to copy the Corresponding Source from a network server at no charge.
</li><li> Convey individual copies of the object code with a copy of the written
offer to provide the Corresponding Source.  This alternative is
allowed only occasionally and noncommercially, and only if you
received the object code with such an offer, in accord with subsection
6b.
</li><li> Convey the object code by offering access from a designated place
(gratis or for a charge), and offer equivalent access to the
Corresponding Source in the same way through the same place at no
further charge.  You need not require recipients to copy the
Corresponding Source along with the object code.  If the place to copy
the object code is a network server, the Corresponding Source may be
on a different server (operated by you or a third party) that supports
equivalent copying facilities, provided you maintain clear directions
next to the object code saying where to find the Corresponding Source.
Regardless of what server hosts the Corresponding Source, you remain
obligated to ensure that it is available for as long as needed to
satisfy these requirements.
</li><li> Convey the object code using peer-to-peer transmission, provided you
inform other peers where the object code and Corresponding Source of
the work are being offered to the general public at no charge under
subsection 6d.
</li></ol>
<p>A separable portion of the object code, whose source code is excluded
from the Corresponding Source as a System Library, need not be
included in conveying the object code work.
</p>
<p>A &ldquo;User Product&rdquo; is either (1) a &ldquo;consumer product&rdquo;, which means any
tangible personal property which is normally used for personal,
family, or household purposes, or (2) anything designed or sold for
incorporation into a dwelling.  In determining whether a product is a
consumer product, doubtful cases shall be resolved in favor of
coverage.  For a particular product received by a particular user,
&ldquo;normally used&rdquo; refers to a typical or common use of that class of
product, regardless of the status of the particular user or of the way
in which the particular user actually uses, or expects or is expected
to use, the product.  A product is a consumer product regardless of
whether the product has substantial commercial, industrial or
non-consumer uses, unless such uses represent the only significant
mode of use of the product.
</p>
<p>&ldquo;Installation Information&rdquo; for a User Product means any methods,
procedures, authorization keys, or other information required to
install and execute modified versions of a covered work in that User
Product from a modified version of its Corresponding Source.  The
information must suffice to ensure that the continued functioning of
the modified object code is in no case prevented or interfered with
solely because modification has been made.
</p>
<p>If you convey an object code work under this section in, or with, or
specifically for use in, a User Product, and the conveying occurs as
part of a transaction in which the right of possession and use of the
User Product is transferred to the recipient in perpetuity or for a
fixed term (regardless of how the transaction is characterized), the
Corresponding Source conveyed under this section must be accompanied
by the Installation Information.  But this requirement does not apply
if neither you nor any third party retains the ability to install
modified object code on the User Product (for example, the work has
been installed in ROM).
</p>
<p>The requirement to provide Installation Information does not include a
requirement to continue to provide support service, warranty, or
updates for a work that has been modified or installed by the
recipient, or for the User Product in which it has been modified or
installed.  Access to a network may be denied when the modification
itself materially and adversely affects the operation of the network
or violates the rules and protocols for communication across the
network.
</p>
<p>Corresponding Source conveyed, and Installation Information provided,
in accord with this section must be in a format that is publicly
documented (and with an implementation available to the public in
source code form), and must require no special password or key for
unpacking, reading or copying.
</p>
</li><li> Additional Terms.
<p>&ldquo;Additional permissions&rdquo; are terms that supplement the terms of this
License by making exceptions from one or more of its conditions.
Additional permissions that are applicable to the entire Program shall
be treated as though they were included in this License, to the extent
that they are valid under applicable law.  If additional permissions
apply only to part of the Program, that part may be used separately
under those permissions, but the entire Program remains governed by
this License without regard to the additional permissions.
</p>
<p>When you convey a copy of a covered work, you may at your option
remove any additional permissions from that copy, or from any part of
it.  (Additional permissions may be written to require their own
removal in certain cases when you modify the work.)  You may place
additional permissions on material, added by you to a covered work,
for which you have or can give appropriate copyright permission.
</p>
<p>Notwithstanding any other provision of this License, for material you
add to a covered work, you may (if authorized by the copyright holders
of that material) supplement the terms of this License with terms:
</p>
<ol type="a" start="1">
<li> Disclaiming warranty or limiting liability differently from the terms
of sections 15 and 16 of this License; or
</li><li> Requiring preservation of specified reasonable legal notices or author
attributions in that material or in the Appropriate Legal Notices
displayed by works containing it; or
</li><li> Prohibiting misrepresentation of the origin of that material, or
requiring that modified versions of such material be marked in
reasonable ways as different from the original version; or
</li><li> Limiting the use for publicity purposes of names of licensors or
authors of the material; or
</li><li> Declining to grant rights under trademark law for use of some trade
names, trademarks, or service marks; or
</li><li> Requiring indemnification of licensors and authors of that material by
anyone who conveys the material (or modified versions of it) with
contractual assumptions of liability to the recipient, for any
liability that these contractual assumptions directly impose on those
licensors and authors.
</li></ol>
<p>All other non-permissive additional terms are considered &ldquo;further
restrictions&rdquo; within the meaning of section 10.  If the Program as you
received it, or any part of it, contains a notice stating that it is
governed by this License along with a term that is a further
restriction, you may remove that term.  If a license document contains
a further restriction but permits relicensing or conveying under this
License, you may add to a covered work material governed by the terms
of that license document, provided that the further restriction does
not survive such relicensing or conveying.
</p>
<p>If you add terms to a covered work in accord with this section, you
must place, in the relevant source files, a statement of the
additional terms that apply to those files, or a notice indicating
where to find the applicable terms.
</p>
<p>Additional terms, permissive or non-permissive, may be stated in the
form of a separately written license, or stated as exceptions; the
above requirements apply either way.
</p>
</li><li> Termination.
<p>You may not propagate or modify a covered work except as expressly
provided under this License.  Any attempt otherwise to propagate or
modify it is void, and will automatically terminate your rights under
this License (including any patent licenses granted under the third
paragraph of section 11).
</p>
<p>However, if you cease all violation of this License, then your license
from a particular copyright holder is reinstated (a) provisionally,
unless and until the copyright holder explicitly and finally
terminates your license, and (b) permanently, if the copyright holder
fails to notify you of the violation by some reasonable means prior to
60 days after the cessation.
</p>
<p>Moreover, your license from a particular copyright holder is
reinstated permanently if the copyright holder notifies you of the
violation by some reasonable means, this is the first time you have
received notice of violation of this License (for any work) from that
copyright holder, and you cure the violation prior to 30 days after
your receipt of the notice.
</p>
<p>Termination of your rights under this section does not terminate the
licenses of parties who have received copies or rights from you under
this License.  If your rights have been terminated and not permanently
reinstated, you do not qualify to receive new licenses for the same
material under section 10.
</p>
</li><li> Acceptance Not Required for Having Copies.
<p>You are not required to accept this License in order to receive or run
a copy of the Program.  Ancillary propagation of a covered work
occurring solely as a consequence of using peer-to-peer transmission
to receive a copy likewise does not require acceptance.  However,
nothing other than this License grants you permission to propagate or
modify any covered work.  These actions infringe copyright if you do
not accept this License.  Therefore, by modifying or propagating a
covered work, you indicate your acceptance of this License to do so.
</p>
</li><li> Automatic Licensing of Downstream Recipients.
<p>Each time you convey a covered work, the recipient automatically
receives a license from the original licensors, to run, modify and
propagate that work, subject to this License.  You are not responsible
for enforcing compliance by third parties with this License.
</p>
<p>An &ldquo;entity transaction&rdquo; is a transaction transferring control of an
organization, or substantially all assets of one, or subdividing an
organization, or merging organizations.  If propagation of a covered
work results from an entity transaction, each party to that
transaction who receives a copy of the work also receives whatever
licenses to the work the party&rsquo;s predecessor in interest had or could
give under the previous paragraph, plus a right to possession of the
Corresponding Source of the work from the predecessor in interest, if
the predecessor has it or can get it with reasonable efforts.
</p>
<p>You may not impose any further restrictions on the exercise of the
rights granted or affirmed under this License.  For example, you may
not impose a license fee, royalty, or other charge for exercise of
rights granted under this License, and you may not initiate litigation
(including a cross-claim or counterclaim in a lawsuit) alleging that
any patent claim is infringed by making, using, selling, offering for
sale, or importing the Program or any portion of it.
</p>
</li><li> Patents.
<p>A &ldquo;contributor&rdquo; is a copyright holder who authorizes use under this
License of the Program or a work on which the Program is based.  The
work thus licensed is called the contributor&rsquo;s &ldquo;contributor version&rdquo;.
</p>
<p>A contributor&rsquo;s &ldquo;essential patent claims&rdquo; are all patent claims owned
or controlled by the contributor, whether already acquired or
hereafter acquired, that would be infringed by some manner, permitted
by this License, of making, using, or selling its contributor version,
but do not include claims that would be infringed only as a
consequence of further modification of the contributor version.  For
purposes of this definition, &ldquo;control&rdquo; includes the right to grant
patent sublicenses in a manner consistent with the requirements of
this License.
</p>
<p>Each contributor grants you a non-exclusive, worldwide, royalty-free
patent license under the contributor&rsquo;s essential patent claims, to
make, use, sell, offer for sale, import and otherwise run, modify and
propagate the contents of its contributor version.
</p>
<p>In the following three paragraphs, a &ldquo;patent license&rdquo; is any express
agreement or commitment, however denominated, not to enforce a patent
(such as an express permission to practice a patent or covenant not to
sue for patent infringement).  To &ldquo;grant&rdquo; such a patent license to a
party means to make such an agreement or commitment not to enforce a
patent against the party.
</p>
<p>If you convey a covered work, knowingly relying on a patent license,
and the Corresponding Source of the work is not available for anyone
to copy, free of charge and under the terms of this License, through a
publicly available network server or other readily accessible means,
then you must either (1) cause the Corresponding Source to be so
available, or (2) arrange to deprive yourself of the benefit of the
patent license for this particular work, or (3) arrange, in a manner
consistent with the requirements of this License, to extend the patent
license to downstream recipients.  &ldquo;Knowingly relying&rdquo; means you have
actual knowledge that, but for the patent license, your conveying the
covered work in a country, or your recipient&rsquo;s use of the covered work
in a country, would infringe one or more identifiable patents in that
country that you have reason to believe are valid.
</p>
<p>If, pursuant to or in connection with a single transaction or
arrangement, you convey, or propagate by procuring conveyance of, a
covered work, and grant a patent license to some of the parties
receiving the covered work authorizing them to use, propagate, modify
or convey a specific copy of the covered work, then the patent license
you grant is automatically extended to all recipients of the covered
work and works based on it.
</p>
<p>A patent license is &ldquo;discriminatory&rdquo; if it does not include within the
scope of its coverage, prohibits the exercise of, or is conditioned on
the non-exercise of one or more of the rights that are specifically
granted under this License.  You may not convey a covered work if you
are a party to an arrangement with a third party that is in the
business of distributing software, under which you make payment to the
third party based on the extent of your activity of conveying the
work, and under which the third party grants, to any of the parties
who would receive the covered work from you, a discriminatory patent
license (a) in connection with copies of the covered work conveyed by
you (or copies made from those copies), or (b) primarily for and in
connection with specific products or compilations that contain the
covered work, unless you entered into that arrangement, or that patent
license was granted, prior to 28 March 2007.
</p>
<p>Nothing in this License shall be construed as excluding or limiting
any implied license or other defenses to infringement that may
otherwise be available to you under applicable patent law.
</p>
</li><li> No Surrender of Others&rsquo; Freedom.
<p>If conditions are imposed on you (whether by court order, agreement or
otherwise) that contradict the conditions of this License, they do not
excuse you from the conditions of this License.  If you cannot convey
a covered work so as to satisfy simultaneously your obligations under
this License and any other pertinent obligations, then as a
consequence you may not convey it at all.  For example, if you agree
to terms that obligate you to collect a royalty for further conveying
from those to whom you convey the Program, the only way you could
satisfy both those terms and this License would be to refrain entirely
from conveying the Program.
</p>
</li><li> Use with the GNU Affero General Public License.
<p>Notwithstanding any other provision of this License, you have
permission to link or combine any covered work with a work licensed
under version 3 of the GNU Affero General Public License into a single
combined work, and to convey the resulting work.  The terms of this
License will continue to apply to the part which is the covered work,
but the special requirements of the GNU Affero General Public License,
section 13, concerning interaction through a network will apply to the
combination as such.
</p>
</li><li> Revised Versions of this License.
<p>The Free Software Foundation may publish revised and/or new versions
of the GNU General Public License from time to time.  Such new
versions will be similar in spirit to the present version, but may
differ in detail to address new problems or concerns.
</p>
<p>Each version is given a distinguishing version number.  If the Program
specifies that a certain numbered version of the GNU General Public
License &ldquo;or any later version&rdquo; applies to it, you have the option of
following the terms and conditions either of that numbered version or
of any later version published by the Free Software Foundation.  If
the Program does not specify a version number of the GNU General
Public License, you may choose any version ever published by the Free
Software Foundation.
</p>
<p>If the Program specifies that a proxy can decide which future versions
of the GNU General Public License can be used, that proxy&rsquo;s public
statement of acceptance of a version permanently authorizes you to
choose that version for the Program.
</p>
<p>Later license versions may give you additional or different
permissions.  However, no additional obligations are imposed on any
author or copyright holder as a result of your choosing to follow a
later version.
</p>
</li><li> Disclaimer of Warranty.
<p>THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY
APPLICABLE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT
HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM &ldquo;AS IS&rdquo; WITHOUT
WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND
PERFORMANCE OF THE PROGRAM IS WITH YOU.  SHOULD THE PROGRAM PROVE
DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR
CORRECTION.
</p>
</li><li> Limitation of Liability.
<p>IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING
WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MODIFIES AND/OR
CONVEYS THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES,
INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES
ARISING OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT
NOT LIMITED TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR
LOSSES SUSTAINED BY YOU OR THIRD PARTIES OR A FAILURE OF THE PROGRAM
TO OPERATE WITH ANY OTHER PROGRAMS), EVEN IF SUCH HOLDER OR OTHER
PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
</p>
</li><li> Interpretation of Sections 15 and 16.
<p>If the disclaimer of warranty and limitation of liability provided
above cannot be given local legal effect according to their terms,
reviewing courts shall apply local law that most closely approximates
an absolute waiver of all civil liability in connection with the
Program, unless a warranty or assumption of liability accompanies a
copy of the Program in return for a fee.
</p>
</li></ol>
<span id="END-OF-TERMS-AND-CONDITIONS"></span><h3 class="heading">END OF TERMS AND CONDITIONS</h3>
<span id="How-to-Apply-These-Terms-to-Your-New-Programs"></span><h3 class="heading">How to Apply These Terms to Your New Programs</h3>
<p>If you develop a new program, and you want it to be of the greatest
possible use to the public, the best way to achieve this is to make it
free software which everyone can redistribute and change under these
terms.
</p>
<p>To do so, attach the following notices to the program.  It is safest
to attach them to the start of each source file to most effectively
state the exclusion of warranty; and each file should have at least
the &ldquo;copyright&rdquo; line and a pointer to where the full notice is found.
</p>
<div class="example">
<pre class="example"><var>one line to give the program's name and a brief idea of what it does.</var>  
Copyright (C) <var>year</var> <var>name of author</var>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <a href="http://www.gnu.org/licenses/">http://www.gnu.org/licenses/</a>.
</pre></div>
<p>Also add information on how to contact you by electronic and paper mail.
</p>
<p>If the program does terminal interaction, make it output a short
notice like this when it starts in an interactive mode:
</p>
<div class="example">
<pre class="example"><var>program</var> Copyright (C) <var>year</var> <var>name of author</var> 
This program comes with ABSOLUTELY NO WARRANTY; for details type &lsquo;<samp>show w</samp>&rsquo;.
This is free software, and you are welcome to redistribute it
under certain conditions; type &lsquo;<samp>show c</samp>&rsquo; for details.
</pre></div>
<p>The hypothetical commands &lsquo;<samp>show w</samp>&rsquo; and &lsquo;<samp>show c</samp>&rsquo; should show
the appropriate parts of the General Public License.  Of course, your
program&rsquo;s commands might be different; for a GUI interface, you would
use an &ldquo;about box&rdquo;.
</p>
<p>You should also get your employer (if you work as a programmer) or school,
if any, to sign a &ldquo;copyright disclaimer&rdquo; for the program, if necessary.
For more information on this, and how to apply and follow the GNU GPL, see
<a href="http://www.gnu.org/licenses/">http://www.gnu.org/licenses/</a>.
</p>
<p>The GNU General Public License does not permit incorporating your
program into proprietary programs.  If your program is a subroutine
library, you may consider it more useful to permit linking proprietary
applications with the library.  If this is what you want to do, use
the GNU Lesser General Public License instead of this License.  But
first, please read <a href="http://www.gnu.org/philosophy/why-not-lgpl.html">http://www.gnu.org/philosophy/why-not-lgpl.html</a>.
</p>
<hr>
</div>
<div class="unnumbered" id="Index">
<div class="header">
<p>
Previous: <a href="#Copying" accesskey="p" rel="prev">GNU General Public License</a>, Up: <a href="#Top" accesskey="u" rel="up">Introduction</a> &nbsp; [<a href="#SEC_Contents" title="Table of contents" rel="contents">Contents</a>][<a href="#Index" title="Index" rel="index">Index</a>]</p>
</div>
<span id="Index-1"></span><h2 class="unnumbered">Index</h2>
 
<table><tr><th valign="top">Jump to: &nbsp; </th><td><a class="summary-letter" href="#Index_cp_letter-B"><b>B</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-C"><b>C</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-D"><b>D</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-F"><b>F</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-G"><b>G</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-H"><b>H</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-I"><b>I</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-L"><b>L</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-M"><b>M</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-O"><b>O</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-R"><b>R</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-S"><b>S</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-U"><b>U</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-W"><b>W</b></a>
 &nbsp; 
</td></tr></table>
<table class="index-cp" border="0">
<tr><td></td><th align="left">Index Entry</th><td>&nbsp;</td><th align="left"> Section</th></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-B">B</th><td></td><td></td></tr>
<tr><td></td><td valign="top"><a href="#index-Basic-Usage-Overview">Basic Usage Overview</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-C">C</th><td></td><td></td></tr>
<tr><td></td><td valign="top"><a href="#index-closeFile">closeFile</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-File-Functions">Low Level File Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-copyHDU">copyHDU</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-HDU-Functions">Low Level HDU Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-copyright">copyright</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Copying">Copying</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-createFile">createFile</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-File-Functions">Low Level File Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-createImg">createImg</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Image-Manipulation">Low Level Image Manipulation</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-createTbl">createTbl</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-D">D</th><td></td><td></td></tr>
<tr><td></td><td valign="top"><a href="#index-deleteCol">deleteCol</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-deleteFile">deleteFile</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-File-Functions">Low Level File Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-deleteHDU">deleteHDU</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-HDU-Functions">Low Level HDU Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-deleteKey">deleteKey</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-deleteRecord">deleteRecord</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-deleteRows">deleteRows</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-F">F</th><td></td><td></td></tr>
<tr><td></td><td valign="top"><a href="#index-fileMode">fileMode</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-File-Functions">Low Level File Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-fileName">fileName</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-File-Functions">Low Level File Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-fitsdisp">fitsdisp</a>:</td><td>&nbsp;</td><td valign="top"><a href="#High-Level-File-Functions">High Level File Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-fitsinfo">fitsinfo</a>:</td><td>&nbsp;</td><td valign="top"><a href="#High-Level-File-Functions">High Level File Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-fitsread">fitsread</a>:</td><td>&nbsp;</td><td valign="top"><a href="#High-Level-File-Functions">High Level File Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-fitswrite">fitswrite</a>:</td><td>&nbsp;</td><td valign="top"><a href="#High-Level-File-Functions">High Level File Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-Function-Reference">Function Reference</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Function-Reference">Function Reference</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-G">G</th><td></td><td></td></tr>
<tr><td></td><td valign="top"><a href="#index-getAColParms">getAColParms</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getBColParms">getBColParms</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getColName">getColName</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getColType">getColType</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getConstantNames">getConstantNames</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Utility-Functions">Low Level Utility Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getConstantValue">getConstantValue</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Utility-Functions">Low Level Utility Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getEqColType">getEqColType</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getHdrSpace">getHdrSpace</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getHDUnum">getHDUnum</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-HDU-Functions">Low Level HDU Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getHDUoff">getHDUoff</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-HDU-Functions">Low Level HDU Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getHDUtype">getHDUtype</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-HDU-Functions">Low Level HDU Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getImgSize">getImgSize</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Image-Manipulation">Low Level Image Manipulation</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getImgType">getImgType</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Image-Manipulation">Low Level Image Manipulation</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getNumCols">getNumCols</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getNumHDUs">getNumHDUs</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-HDU-Functions">Low Level HDU Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getNumRows">getNumRows</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getOpenFiles">getOpenFiles</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Utility-Functions">Low Level Utility Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getRowSize">getRowSize</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-getVersion">getVersion</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Utility-Functions">Low Level Utility Functions</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-H">H</th><td></td><td></td></tr>
<tr><td></td><td valign="top"><a href="#index-High-Level-File-Functions">High Level File Functions</a>:</td><td>&nbsp;</td><td valign="top"><a href="#High-Level-File-Functions">High Level File Functions</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-I">I</th><td></td><td></td></tr>
<tr><td></td><td valign="top"><a href="#index-imgCompress">imgCompress</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Compression-Functions">Low Level Compression Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-Import-functions">Import functions</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Import-functions">Import functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-import_005ffits">import_fits</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Import-functions">Import functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-insertATbl">insertATbl</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-insertBTbl">insertBTbl</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-insertCol">insertCol</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-insertImg">insertImg</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Image-Manipulation">Low Level Image Manipulation</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-insertRows">insertRows</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-Installing-and-loading">Installing and loading</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Installing-and-loading">Installing and loading</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-isCompressedImg">isCompressedImg</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Compression-Functions">Low Level Compression Functions</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-L">L</th><td></td><td></td></tr>
<tr><td></td><td valign="top"><a href="#index-Loading">Loading</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Installing-and-loading">Installing and loading</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-Low-Level-Compression-Functions">Low Level Compression Functions</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Compression-Functions">Low Level Compression Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-Low-Level-File-Functions">Low Level File Functions</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-File-Functions">Low Level File Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-Low-level-functionality">Low level functionality</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-Low-Level-HDU-Functions">Low Level HDU Functions</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-HDU-Functions">Low Level HDU Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-Low-Level-Image-Manipulation">Low Level Image Manipulation</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Image-Manipulation">Low Level Image Manipulation</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-Low-Level-Keyword-Functions">Low Level Keyword Functions</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-Low-Level-Utility-Functions">Low Level Utility Functions</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Utility-Functions">Low Level Utility Functions</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-M">M</th><td></td><td></td></tr>
<tr><td></td><td valign="top"><a href="#index-movAbsHDU">movAbsHDU</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-HDU-Functions">Low Level HDU Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-movNamHDU">movNamHDU</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-HDU-Functions">Low Level HDU Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-movRelHDU">movRelHDU</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-HDU-Functions">Low Level HDU Functions</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-O">O</th><td></td><td></td></tr>
<tr><td></td><td valign="top"><a href="#index-Off_002dline-install">Off-line install</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Installing-and-loading">Installing and loading</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-Online-install">Online install</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Installing-and-loading">Installing and loading</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-openDiskFile">openDiskFile</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-File-Functions">Low Level File Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-openFile">openFile</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-File-Functions">Low Level File Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-Overview">Overview</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-R">R</th><td></td><td></td></tr>
<tr><td></td><td valign="top"><a href="#index-readATblHdr">readATblHdr</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-readBTblHdr">readBTblHdr</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-readCard">readCard</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-readCol">readCol</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-readImg">readImg</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Image-Manipulation">Low Level Image Manipulation</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-Reading-Data">Reading Data</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-Reading-Information">Reading Information</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-readKey">readKey</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-readKeyCmplx">readKeyCmplx</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-readKeyDbl">readKeyDbl</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-readKeyLongLong">readKeyLongLong</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-readKeyLongStr">readKeyLongStr</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-readKeyUnit">readKeyUnit</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-readRecord">readRecord</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-S">S</th><td></td><td></td></tr>
<tr><td></td><td valign="top"><a href="#index-setBscale">setBscale</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Image-Manipulation">Low Level Image Manipulation</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-setCompressionType">setCompressionType</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Compression-Functions">Low Level Compression Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-setHCompScale">setHCompScale</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Compression-Functions">Low Level Compression Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-setHCompSmooth">setHCompSmooth</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Compression-Functions">Low Level Compression Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-setTileDim">setTileDim</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Compression-Functions">Low Level Compression Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-setTscale">setTscale</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Image-Manipulation">Low Level Image Manipulation</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-U">U</th><td></td><td></td></tr>
<tr><td></td><td valign="top"><a href="#index-Using-the-toolkit">Using the toolkit</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
<tr><th id="Index_cp_letter-W">W</th><td></td><td></td></tr>
<tr><td></td><td valign="top"><a href="#index-warranty">warranty</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Copying">Copying</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-Windows-install">Windows install</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Installing-and-loading">Installing and loading</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-writeChecksum">writeChecksum</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-HDU-Functions">Low Level HDU Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-writeCol">writeCol</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Binary-and-ASCII-Tables">Low Level Binary and ASCII Tables</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-writeComment">writeComment</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-writeDate">writeDate</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-writeHistory">writeHistory</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-writeImg">writeImg</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Image-Manipulation">Low Level Image Manipulation</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-writeKey">writeKey</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td></td><td valign="top"><a href="#index-writeKeyUnit">writeKeyUnit</a>:</td><td>&nbsp;</td><td valign="top"><a href="#Low-Level-Keyword-Functions">Low Level Keyword Functions</a></td></tr>
<tr><td colspan="4"> <hr></td></tr>
</table>
<table><tr><th valign="top">Jump to: &nbsp; </th><td><a class="summary-letter" href="#Index_cp_letter-B"><b>B</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-C"><b>C</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-D"><b>D</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-F"><b>F</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-G"><b>G</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-H"><b>H</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-I"><b>I</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-L"><b>L</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-M"><b>M</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-O"><b>O</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-R"><b>R</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-S"><b>S</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-U"><b>U</b></a>
 &nbsp; 
<a class="summary-letter" href="#Index_cp_letter-W"><b>W</b></a>
 &nbsp; 
</td></tr></table>
 
</div>
</div>
