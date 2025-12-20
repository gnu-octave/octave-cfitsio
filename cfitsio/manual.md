---
layout: "default"
permalink: "/manual/"
title: "Cfitsio Toolkit - Manual"
pkg_name: "cfitsio"
version: "0.0.7"
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
<div class="top-level-extent" id="Top">
<h1 class="top" id="Introduction">Introduction</h1>
<p>The <abbr class="acronym">GNU</abbr> Octave CFITSIO toolkit is a set of functions for manipulating Flexible Image Transport
System (FITS) files for GNU Octave.
</p>
<div class="region-contents" id="SEC_Contents">
<h2 class="contents-heading">Table of Contents</h2>
<div class="contents">
<ul class="toc-numbered-mark">
  <li><a id="toc-Installing-and-loading" href="#Installing-and-loading">1 Installing and loading</a>
  <ul class="toc-numbered-mark">
    <li><a id="toc-Windows-install" href="#Windows-install">1.1 Windows install</a></li>
    <li><a id="toc-Online-Direct-install" href="#Online-Direct-install">1.2 Online Direct install</a></li>
    <li><a id="toc-Off_002dline-install" href="#Off_002dline-install">1.3 Off-line install</a></li>
    <li><a id="toc-Loading" href="#Loading">1.4 Loading</a></li>
  </ul></li>
  <li><a id="toc-Basic-Usage-Overview" href="#Basic-Usage-Overview">2 Basic Usage Overview</a>
  <ul class="toc-numbered-mark">
    <li><a id="toc-Overview" href="#Overview">2.1 Overview</a></li>
    <li><a id="toc-Using-the-toolkit" href="#Using-the-toolkit">2.2 Using the toolkit</a>
    <ul class="toc-numbered-mark">
      <li><a id="toc-Reading-Data" href="#Reading-Data">2.2.1 Reading Data</a></li>
      <li><a id="toc-Reading-Information" href="#Reading-Information">2.2.2 Reading Information</a></li>
      <li><a id="toc-Low-level-functionality" href="#Low-level-functionality">2.2.3 Low level functionality</a></li>
    </ul></li>
  </ul></li>
  <li><a id="toc-Function-Reference" href="#Function-Reference">3 Function Reference</a>
  <ul class="toc-numbered-mark">
    <li><a id="toc-High-Level-File-Functions" href="#High-Level-File-Functions">3.1 High Level File Functions</a>
    <ul class="toc-numbered-mark">
      <li><a id="toc-fitsdisp" href="#fitsdisp">3.1.1 fitsdisp</a></li>
      <li><a id="toc-fitsinfo" href="#fitsinfo">3.1.2 fitsinfo</a></li>
      <li><a id="toc-fitsread" href="#fitsread">3.1.3 fitsread</a></li>
      <li><a id="toc-fitswrite" href="#fitswrite">3.1.4 fitswrite</a></li>
    </ul></li>
    <li><a id="toc-Low-Level-Functions" href="#Low-Level-Functions">3.2 Low Level Functions</a>
    <ul class="toc-numbered-mark">
      <li><a id="toc-File-Functions" href="#Low-Level-Functions-_002d-File-Functions">3.2.1 File Functions</a>
      <ul class="toc-numbered-mark">
        <li><a id="toc-matlab_002eio_002efits_002ecloseFile" href="#matlab_002eio_002efits_002ecloseFile">3.2.1.1 matlab.io.fits.closeFile</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ecreateFile" href="#matlab_002eio_002efits_002ecreateFile">3.2.1.2 matlab.io.fits.createFile</a></li>
        <li><a id="toc-matlab_002eio_002efits_002edeleteFile" href="#matlab_002eio_002efits_002edeleteFile">3.2.1.3 matlab.io.fits.deleteFile</a></li>
        <li><a id="toc-matlab_002eio_002efits_002efileMode" href="#matlab_002eio_002efits_002efileMode">3.2.1.4 matlab.io.fits.fileMode</a></li>
        <li><a id="toc-matlab_002eio_002efits_002efileName" href="#matlab_002eio_002efits_002efileName">3.2.1.5 matlab.io.fits.fileName</a></li>
        <li><a id="toc-matlab_002eio_002efits_002eopenDiskFile" href="#matlab_002eio_002efits_002eopenDiskFile">3.2.1.6 matlab.io.fits.openDiskFile</a></li>
        <li><a id="toc-matlab_002eio_002efits_002eopenFile" href="#matlab_002eio_002efits_002eopenFile">3.2.1.7 matlab.io.fits.openFile</a></li>
      </ul></li>
      <li><a id="toc-HDU-Functions" href="#Low-Level-Functions-_002d-HDU-Functions">3.2.2 HDU Functions</a>
      <ul class="toc-numbered-mark">
        <li><a id="toc-matlab_002eio_002efits_002ecopyHDU" href="#matlab_002eio_002efits_002ecopyHDU">3.2.2.1 matlab.io.fits.copyHDU</a></li>
        <li><a id="toc-matlab_002eio_002efits_002edeleteHDU" href="#matlab_002eio_002efits_002edeleteHDU">3.2.2.2 matlab.io.fits.deleteHDU</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetHDUnum" href="#matlab_002eio_002efits_002egetHDUnum">3.2.2.3 matlab.io.fits.getHDUnum</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetHDUoff" href="#matlab_002eio_002efits_002egetHDUoff">3.2.2.4 matlab.io.fits.getHDUoff</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetHDUtype" href="#matlab_002eio_002efits_002egetHDUtype">3.2.2.5 matlab.io.fits.getHDUtype</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetNumHDUs" href="#matlab_002eio_002efits_002egetNumHDUs">3.2.2.6 matlab.io.fits.getNumHDUs</a></li>
        <li><a id="toc-matlab_002eio_002efits_002emovAbsHDU" href="#matlab_002eio_002efits_002emovAbsHDU">3.2.2.7 matlab.io.fits.movAbsHDU</a></li>
        <li><a id="toc-matlab_002eio_002efits_002emovNamHDU" href="#matlab_002eio_002efits_002emovNamHDU">3.2.2.8 matlab.io.fits.movNamHDU</a></li>
        <li><a id="toc-matlab_002eio_002efits_002emovRelHDU" href="#matlab_002eio_002efits_002emovRelHDU">3.2.2.9 matlab.io.fits.movRelHDU</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ewriteChecksum" href="#matlab_002eio_002efits_002ewriteChecksum">3.2.2.10 matlab.io.fits.writeChecksum</a></li>
      </ul></li>
      <li><a id="toc-Keyword-Functions" href="#Low-Level-Functions-_002d-Keyword-Functions">3.2.3 Keyword Functions</a>
      <ul class="toc-numbered-mark">
        <li><a id="toc-matlab_002eio_002efits_002edeleteKey" href="#matlab_002eio_002efits_002edeleteKey">3.2.3.1 matlab.io.fits.deleteKey</a></li>
        <li><a id="toc-matlab_002eio_002efits_002edeleteRecord" href="#matlab_002eio_002efits_002edeleteRecord">3.2.3.2 matlab.io.fits.deleteRecord</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetHdrSpace" href="#matlab_002eio_002efits_002egetHdrSpace">3.2.3.3 matlab.io.fits.getHdrSpace</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ereadCard" href="#matlab_002eio_002efits_002ereadCard">3.2.3.4 matlab.io.fits.readCard</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ereadKey" href="#matlab_002eio_002efits_002ereadKey">3.2.3.5 matlab.io.fits.readKey</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ereadKeyCmplx" href="#matlab_002eio_002efits_002ereadKeyCmplx">3.2.3.6 matlab.io.fits.readKeyCmplx</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ereadKeyDbl" href="#matlab_002eio_002efits_002ereadKeyDbl">3.2.3.7 matlab.io.fits.readKeyDbl</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ereadKeyLongLong" href="#matlab_002eio_002efits_002ereadKeyLongLong">3.2.3.8 matlab.io.fits.readKeyLongLong</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ereadKeyLongStr" href="#matlab_002eio_002efits_002ereadKeyLongStr">3.2.3.9 matlab.io.fits.readKeyLongStr</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ereadKeyUnit" href="#matlab_002eio_002efits_002ereadKeyUnit">3.2.3.10 matlab.io.fits.readKeyUnit</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ereadRecord" href="#matlab_002eio_002efits_002ereadRecord">3.2.3.11 matlab.io.fits.readRecord</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ewriteComment" href="#matlab_002eio_002efits_002ewriteComment">3.2.3.12 matlab.io.fits.writeComment</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ewriteDate" href="#matlab_002eio_002efits_002ewriteDate">3.2.3.13 matlab.io.fits.writeDate</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ewriteHistory" href="#matlab_002eio_002efits_002ewriteHistory">3.2.3.14 matlab.io.fits.writeHistory</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ewriteKey" href="#matlab_002eio_002efits_002ewriteKey">3.2.3.15 matlab.io.fits.writeKey</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ewriteKeyUnit" href="#matlab_002eio_002efits_002ewriteKeyUnit">3.2.3.16 matlab.io.fits.writeKeyUnit</a></li>
      </ul></li>
      <li><a id="toc-Image-Manipulation" href="#Low-Level-Functions-_002d-Image-Manipulation">3.2.4 Image Manipulation</a>
      <ul class="toc-numbered-mark">
        <li><a id="toc-matlab_002eio_002efits_002ecreateImg" href="#matlab_002eio_002efits_002ecreateImg">3.2.4.1 matlab.io.fits.createImg</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetImgSize" href="#matlab_002eio_002efits_002egetImgSize">3.2.4.2 matlab.io.fits.getImgSize</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetImgType" href="#matlab_002eio_002efits_002egetImgType">3.2.4.3 matlab.io.fits.getImgType</a></li>
        <li><a id="toc-matlab_002eio_002efits_002einsertImg" href="#matlab_002eio_002efits_002einsertImg">3.2.4.4 matlab.io.fits.insertImg</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ereadImg" href="#matlab_002eio_002efits_002ereadImg">3.2.4.5 matlab.io.fits.readImg</a></li>
        <li><a id="toc-matlab_002eio_002efits_002esetBscale" href="#matlab_002eio_002efits_002esetBscale">3.2.4.6 matlab.io.fits.setBscale</a></li>
        <li><a id="toc-matlab_002eio_002efits_002esetTscale" href="#matlab_002eio_002efits_002esetTscale">3.2.4.7 matlab.io.fits.setTscale</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ewriteImg" href="#matlab_002eio_002efits_002ewriteImg">3.2.4.8 matlab.io.fits.writeImg</a></li>
      </ul></li>
      <li><a id="toc-Utility-Functions" href="#Low-Level-Functions-_002d-Utility-Functions">3.2.5 Utility Functions</a>
      <ul class="toc-numbered-mark">
        <li><a id="toc-matlab_002eio_002efits_002egetConstantNames" href="#matlab_002eio_002efits_002egetConstantNames">3.2.5.1 matlab.io.fits.getConstantNames</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetConstantValue" href="#matlab_002eio_002efits_002egetConstantValue">3.2.5.2 matlab.io.fits.getConstantValue</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetOpenFiles" href="#matlab_002eio_002efits_002egetOpenFiles">3.2.5.3 matlab.io.fits.getOpenFiles</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetVersion" href="#matlab_002eio_002efits_002egetVersion">3.2.5.4 matlab.io.fits.getVersion</a></li>
      </ul></li>
      <li><a id="toc-Compression-Functions" href="#Low-Level-Functions-_002d-Compression-Functions">3.2.6 Compression Functions</a>
      <ul class="toc-numbered-mark">
        <li><a id="toc-matlab_002eio_002efits_002eimgCompress" href="#matlab_002eio_002efits_002eimgCompress">3.2.6.1 matlab.io.fits.imgCompress</a></li>
        <li><a id="toc-matlab_002eio_002efits_002eisCompressedImg" href="#matlab_002eio_002efits_002eisCompressedImg">3.2.6.2 matlab.io.fits.isCompressedImg</a></li>
        <li><a id="toc-matlab_002eio_002efits_002esetCompressionType" href="#matlab_002eio_002efits_002esetCompressionType">3.2.6.3 matlab.io.fits.setCompressionType</a></li>
        <li><a id="toc-matlab_002eio_002efits_002esetHCompScale" href="#matlab_002eio_002efits_002esetHCompScale">3.2.6.4 matlab.io.fits.setHCompScale</a></li>
        <li><a id="toc-matlab_002eio_002efits_002esetHCompSmooth" href="#matlab_002eio_002efits_002esetHCompSmooth">3.2.6.5 matlab.io.fits.setHCompSmooth</a></li>
        <li><a id="toc-matlab_002eio_002efits_002esetTileDim" href="#matlab_002eio_002efits_002esetTileDim">3.2.6.6 matlab.io.fits.setTileDim</a></li>
      </ul></li>
      <li><a id="toc-Binary-and-ASCII-Tables" href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">3.2.7 Binary and ASCII Tables</a>
      <ul class="toc-numbered-mark">
        <li><a id="toc-matlab_002eio_002efits_002ecreateTbl" href="#matlab_002eio_002efits_002ecreateTbl">3.2.7.1 matlab.io.fits.createTbl</a></li>
        <li><a id="toc-matlab_002eio_002efits_002edeleteCol" href="#matlab_002eio_002efits_002edeleteCol">3.2.7.2 matlab.io.fits.deleteCol</a></li>
        <li><a id="toc-matlab_002eio_002efits_002edeleteRows" href="#matlab_002eio_002efits_002edeleteRows">3.2.7.3 matlab.io.fits.deleteRows</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetAColParms" href="#matlab_002eio_002efits_002egetAColParms">3.2.7.4 matlab.io.fits.getAColParms</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetBColParms" href="#matlab_002eio_002efits_002egetBColParms">3.2.7.5 matlab.io.fits.getBColParms</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetColName" href="#matlab_002eio_002efits_002egetColName">3.2.7.6 matlab.io.fits.getColName</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetColType" href="#matlab_002eio_002efits_002egetColType">3.2.7.7 matlab.io.fits.getColType</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetEqColType" href="#matlab_002eio_002efits_002egetEqColType">3.2.7.8 matlab.io.fits.getEqColType</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetNumCols" href="#matlab_002eio_002efits_002egetNumCols">3.2.7.9 matlab.io.fits.getNumCols</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetNumRows" href="#matlab_002eio_002efits_002egetNumRows">3.2.7.10 matlab.io.fits.getNumRows</a></li>
        <li><a id="toc-matlab_002eio_002efits_002egetRowSize" href="#matlab_002eio_002efits_002egetRowSize">3.2.7.11 matlab.io.fits.getRowSize</a></li>
        <li><a id="toc-matlab_002eio_002efits_002einsertATbl" href="#matlab_002eio_002efits_002einsertATbl">3.2.7.12 matlab.io.fits.insertATbl</a></li>
        <li><a id="toc-matlab_002eio_002efits_002einsertBTbl" href="#matlab_002eio_002efits_002einsertBTbl">3.2.7.13 matlab.io.fits.insertBTbl</a></li>
        <li><a id="toc-matlab_002eio_002efits_002einsertCol" href="#matlab_002eio_002efits_002einsertCol">3.2.7.14 matlab.io.fits.insertCol</a></li>
        <li><a id="toc-matlab_002eio_002efits_002einsertRows" href="#matlab_002eio_002efits_002einsertRows">3.2.7.15 matlab.io.fits.insertRows</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ereadATblHdr" href="#matlab_002eio_002efits_002ereadATblHdr">3.2.7.16 matlab.io.fits.readATblHdr</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ereadBTblHdr" href="#matlab_002eio_002efits_002ereadBTblHdr">3.2.7.17 matlab.io.fits.readBTblHdr</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ereadCol" href="#matlab_002eio_002efits_002ereadCol">3.2.7.18 matlab.io.fits.readCol</a></li>
        <li><a id="toc-matlab_002eio_002efits_002ewriteCol" href="#matlab_002eio_002efits_002ewriteCol">3.2.7.19 matlab.io.fits.writeCol</a></li>
      </ul></li>
      <li><a id="toc-Import-functions" href="#Low-Level-Functions-_002d-Import-functions">3.2.8 Import functions</a>
      <ul class="toc-numbered-mark">
        <li><a id="toc-import_005ffits" href="#import_005ffits">3.2.8.1 import_fits</a></li>
      </ul></li>
    </ul></li>
  </ul></li>
  <li><a id="toc-GNU-General-Public-License" href="#Copying">Appendix A GNU General Public License</a></li>
  <li><a id="toc-Index" href="#Index" rel="index">Index</a></li>
</ul>
</div>
</div>
<hr>
<div class="chapter-level-extent" id="Installing-and-loading">
<h2 class="chapter" id="Installing-and-loading-1">1 Installing and loading</h2>
<a class="index-entry-id" id="index-Installing-and-loading"></a>
<p>The <abbr class="acronym">GNU</abbr> Octave CFITSIO toolkit must be installed and then loaded to be used.
</p>
<p>It can be installed in <abbr class="acronym">GNU</abbr> Octave directly from octave-cfitsio,
or can be installed in an off-line mode via a downloaded tarball.
</p>
<p>The toolkit has a dependency on the cfitsio library (<a class="url" href="https://heasarc.gsfc.nasa.gov/fitsio/">https://heasarc.gsfc.nasa.gov/fitsio/</a>), so it must be installed in order
to successfully install the <abbr class="acronym">GNU</abbr> Octave toolkit.
</p>
<p>For Fedora: <code class="code">yum install cfitsio-devel</code> 
</p>
<p>The toolkit must be then be loaded once per each <abbr class="acronym">GNU</abbr> Octave session in order to use its functionality.
</p>
<div class="section-level-extent" id="Windows-install">
<h3 class="section">1.1 Windows install</h3>
<a class="index-entry-id" id="index-Windows-install"></a>
<p>If running in Windows, the package may already be installed, to check run:
</p>
<div class="example">
<pre class="example-preformatted">pkg list cfitsio
</pre></div>
<p>Otherwise it can be installed by installing the requirements and then using the online or offline install method.
</p>
</div>
<div class="section-level-extent" id="Online-Direct-install">
<h3 class="section">1.2 Online Direct install</h3>
<a class="index-entry-id" id="index-Online-install"></a>
<p>With an internet connection available, the package can be installed from
octave-cfitsio using the following command within <abbr class="acronym">GNU</abbr> Octave:
</p>
<div class="example">
<pre class="example-preformatted">pkg install &quot;https://github.com/gnu-octave/octave-/cfitsioreleases/download/v0.0.7/octave-cfitsio-0.0.7.tar.gz&quot;
</pre></div>
<p>On <abbr class="acronym">GNU</abbr> Octave 7 and higher, the package can be installed in the simpler form of:
</p>
<div class="example">
<pre class="example-preformatted">pkg install -forge cfitsio
</pre></div>
<p>The latest released version of the toolkit will be downloaded and installed.
</p>
</div>
<div class="section-level-extent" id="Off_002dline-install">
<h3 class="section">1.3 Off-line install</h3>
<a class="index-entry-id" id="index-Off_002dline-install"></a>
<p>With the toolkit package already downloaded, and in the current directory when running
<abbr class="acronym">GNU</abbr> Octave, the package can be installed using the following command within <abbr class="acronym">GNU</abbr> Octave:
</p>
<div class="example">
<pre class="example-preformatted">pkg install octave-cfitsio-0.0.7.tar.gz
</pre></div>
</div>
<div class="section-level-extent" id="Loading">
<h3 class="section">1.4 Loading</h3>
<a class="index-entry-id" id="index-Loading"></a>
<p>Regardless of the method of installing the toolkit, in order to use its functions
the toolkit must be loaded using the pkg load command:
</p>
<div class="example">
<pre class="example-preformatted">pkg load cfitsio
</pre></div>
<p>The toolkit must be loaded on each <abbr class="acronym">GNU</abbr> Octave session.
</p>
<hr>
</div>
</div>
<div class="chapter-level-extent" id="Basic-Usage-Overview">
<h2 class="chapter" id="Basic-Usage-Overview-1">2 Basic Usage Overview</h2>
<a class="index-entry-id" id="index-Basic-Usage-Overview"></a>
<div class="section-level-extent" id="Overview">
<h3 class="section">2.1 Overview</h3>
<a class="index-entry-id" id="index-Overview"></a>
<p>The octave-cfitsio toolkit provides high and low level functionality for reading and
writing FITS format files.
</p>
<p>The high level functions provide base read and write of data to octave using the functions
fitsdisp, fitsinfo, fitsread and fitswrite.  The low level functions provide direct access to the cfitsio API and 
are provided under the matlab.io.fits namespace. The low level functions provide access to the low level
API of the CFITSIO C library (<a class="url" href="https://heasarc.gsfc.nasa.gov/fitsio/">https://heasarc.gsfc.nasa.gov/fitsio/</a>).
</p>
<p>Since <abbr class="acronym">GNU</abbr> Octave does not support the matlab import command, an import_fits function
is provided.
</p>
<p>Running the statement:
</p><div class="example">
<pre class="example-preformatted">import_fits
</pre></div>
<p>Is the equivalent of running in matlab:
</p><div class="example">
<pre class="example-preformatted">import matlab.io.fits;
</pre></div>
</div>
<div class="section-level-extent" id="Using-the-toolkit">
<h3 class="section">2.2 Using the toolkit</h3>
<a class="index-entry-id" id="index-Using-the-toolkit"></a>
<p>The package must be loaded each time a <abbr class="acronym">GNU</abbr> Octave session is started:
</p><div class="example">
<pre class="example-preformatted">pkg load cfitsio
</pre></div>
<p>After loading the toolkit, the toolkit functions are available.
</p>
<div class="subsection-level-extent" id="Reading-Data">
<h4 class="subsection">2.2.1 Reading Data</h4>
<a class="index-entry-id" id="index-Reading-Data"></a>
<p>To read the primary image data of a fits file, use the fitsread function:
</p>
<div class="example">
<pre class="example-preformatted">  imagedata = fitsread(&quot;thefitsfile.fits&quot;);
</pre></div>
</div>
<div class="subsection-level-extent" id="Reading-Information">
<h4 class="subsection">2.2.2 Reading Information</h4>
<a class="index-entry-id" id="index-Reading-Information"></a>
<p>To read information about the content in a fits file, use the fitsinfo functions.
</p>
<div class="example">
<pre class="example-preformatted">  info = fitsinfo(&quot;thefitsfile.fits&quot;);
</pre></div>
</div>
<div class="subsection-level-extent" id="Low-level-functionality">
<h4 class="subsection">2.2.3 Low level functionality</h4>
<a class="index-entry-id" id="index-Low-level-functionality"></a>
<p>Where functionality is required that is not met by the high level functions, 
most of the cfitsio functions are available in the matlab.io.fits namespace.
</p>
<p>Knowledge of the CFITSIO c library is beneficial in using the low level functions.
</p>
<div class="example">
<pre class="example-preformatted">  # import the fits functions so don't have to use the full namespace each time
  import_fits;
  # open the file
  fd = fits.openFile('tst0012.fits');
  # get number of hdus in the file
  n = fits.getNumHDUs (fd);
  # for each hdu, go to it, print out the type
  for j = 1:n
    hdutype = fits.movAbsHDU (fd, j);
    printf ('HDU %d:  &quot;%s&quot;\n', j, hdutype);
  endfor
  # close the file
  fits.closeFile (fd);
</pre></div>
<hr>
</div>
</div>
</div>
<div class="chapter-level-extent" id="Function-Reference">
<h2 class="chapter" id="Function-Reference-1">3 Function Reference</h2>
<a class="index-entry-id" id="index-Function-Reference"></a>
<p>The functions currently available in the toolkit are described below:
</p>
<hr>
<div class="section-level-extent" id="High-Level-File-Functions">
<h3 class="section" id="High-Level-File-Functions-1">3.1 High Level File Functions</h3>
<a class="index-entry-id" id="index-High-Level-File-Functions"></a>
<div class="subsection-level-extent" id="fitsdisp">
<h4 class="subsection">3.1.1 fitsdisp</h4>
<a class="index-entry-id" id="index-fitsdisp"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d"><span class="category-def">: </span><code class="def-type"><var class="var">info</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fitsdisp(<var class="var">filename</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-_003d-1"><span class="category-def">: </span><code class="def-type"><var class="var">info</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fitsdisp(<var class="var">filename</var>, <var class="var">propertyname</var>, <var class="var">propertyvalue</var>)</code></dt>
<dd><p>Display metadata about fits format file
</p>
<h4 class="subsubheading" id="Inputs">Inputs</h4>
<p><var class="var">filename</var> - filename to open.
</p>
<p><var class="var">propertyname</var>, <var class="var">propertyvalue</var> - property name/value pairs
</p>
<p>Known property names are:
</p><dl class="table">
<dt>&rsquo;Index&rsquo;</dt>
<dd><p>Value is a scalar or vector of hdu numbers to display
</p></dd>
<dt>&rsquo;Mode&rsquo;</dt>
<dd><p>display mode of &rsquo;standard&rsquo; (default), &rsquo;min&rsquo; or &rsquo;full&rsquo;
</p></dd>
</dl>
<p>&rsquo;standard&rsquo; display mode shows the standard keywords for the selected HDUs.<br>
 &rsquo;min&rsquo; display mode shows only the type and size of the selected HDUs.<br>
 &rsquo;full&rsquo; display shows all keywords for the selected HDU.
</p>
<h4 class="subsubheading" id="Outputs">Outputs</h4>
<p><var class="var">info</var> - the metadata of the file. If no output variable is provided, it displays
 to the screen.
</p>
<h4 class="subsubheading" id="Examples">Examples</h4>
<div class="example">
<pre class="example-preformatted"> filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;);
 fitsdisp(filename);
</pre></div>
</dd></dl>
</div>
<div class="subsection-level-extent" id="fitsinfo">
<h4 class="subsection">3.1.2 fitsinfo</h4>
<a class="index-entry-id" id="index-fitsinfo"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-2"><span class="category-def">: </span><code class="def-type"><var class="var">info</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fitsinfo(<var class="var">filename</var>)</code></dt>
<dd><p>Read information about fits format file
</p><h4 class="subsubheading" id="Inputs-1">Inputs</h4>
<p><var class="var">filename</var> - filename to open.
</p>
<h4 class="subsubheading" id="Outputs-1">Outputs</h4>
<p><var class="var">info</var> - a struct containing the structure and information about
 the fits file.
</p>
<h4 class="subsubheading" id="Examples-1">Examples</h4>
<div class="example">
<pre class="example-preformatted"> filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;);
 info = fitsinfo(filename);
</pre></div>
</dd></dl>
</div>
<div class="subsection-level-extent" id="fitsread">
<h4 class="subsection">3.1.3 fitsread</h4>
<a class="index-entry-id" id="index-fitsread"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-3"><span class="category-def">: </span><code class="def-type"><var class="var">data</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fitsread(<var class="var">filename</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-_003d-4"><span class="category-def">: </span><code class="def-type"><var class="var">data</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fitsread(<var class="var">filename</var>, 'raw')</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-_003d-5"><span class="category-def">: </span><code class="def-type"><var class="var">data</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fitsread(<var class="var">filename</var>, <var class="var">extname</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-_003d-6"><span class="category-def">: </span><code class="def-type"><var class="var">data</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fitsread(<var class="var">filename</var>, <var class="var">extname</var>, <var class="var">index</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-_003d-7"><span class="category-def">: </span><code class="def-type"><var class="var">data</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fitsread(<var class="var">filename</var>, ____, <var class="var">propertyname</var>, <var class="var">propertyvalue</var>)</code></dt>
<dd><p>Read the primary data, or specified extension data. It scales the data and applied Nan to any undefined values.
</p>
<h4 class="subsubheading" id="Inputs-2">Inputs</h4>
<p><var class="var">filename</var> - filename to open.
</p>
<p><var class="var">exttype</var> - can be  &rsquo;primary&rsquo;, &rsquo;asciitable&rsquo;, &rsquo;binarytable&rsquo;, &rsquo;image&rsquo;, &rsquo;unknown&rsquo;.
</p>
<p><var class="var">index</var> - can be used to specify which table when more than one of a given type exists.
</p>
<p>&rsquo;raw&rsquo;-  If the &rsquo;raw&rsquo; keyword is used, the raw data from the file will be used without replacing
 undefined values with Nan
</p>
<p>Known property names are:
</p><dl class="table">
<dt>Info</dt>
<dd><p>input info from fitsinfo call.
</p></dd>
<dt>PixelRegion</dt>
<dd><p>pixel region to extract data for in an image. It expects a cell array of same size as
 the number of axis in the image. Each cell should be in vector format of: start, [start stop]
 or [start, increment, stop].
</p></dd>
<dt>TableColumns</dt>
<dd><p>A list of columns to extract from a ascii or binary table.
</p></dd>
<dt>TableRows</dt>
<dd><p>A list of rows to extract from an ascii or binary table.
</p></dd>
</dl>
<h4 class="subsubheading" id="Outputs-2">Outputs</h4>
<p><var class="var">data</var> - The read data from the table or image.
</p>
<h4 class="subsubheading" id="Examples-2">Examples</h4>
<div class="example">
<pre class="example-preformatted"> filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;);
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
<div class="subsection-level-extent" id="fitswrite">
<h4 class="subsection">3.1.4 fitswrite</h4>
<a class="index-entry-id" id="index-fitswrite"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-fitswrite_0028data_002c"><span class="category-def">: </span><strong class="def-name">fitswrite(<var class="var">data</var>,</strong> <code class="def-code-arguments"><var class="var">filename</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-fitswrite_0028data_002c-1"><span class="category-def">: </span><strong class="def-name">fitswrite(<var class="var">data</var>,</strong> <code class="def-code-arguments"><var class="var">filename</var>, <var class="var">propertyname</var>, <var class="var">propertyvalue</var>)</code></dt>
<dd><p>Write image data <var class="var">data</var>  to FITS file <var class="var">filename</var>. If the fie already exists, overwrite it.
</p>
<h4 class="subsubheading" id="Inputs-3">Inputs</h4>
<p><var class="var">data</var> - imagedata to write to a file.
</p>
<p><var class="var">filename</var> - filename to write to.
</p>
<p><var class="var">propertyname</var>, <var class="var">propertyvalue</var> - property name/value pairs
</p>
<p>Additional properties can be set as <var class="var">propertyname</var>, <var class="var">propertyvalue</var> pairs.
 Known property names are:
</p><dl class="table">
<dt>WriteMode</dt>
<dd><p>Set mode for writing to image as &rsquo;overwrite&rsquo; (default) or &rsquo;append&rsquo; to append images.
</p></dd>
<dt>Compression</dt>
<dd><p>Set compression type to use for image as
 &rsquo;none&rsquo; (default), &rsquo;gzip&rsquo;, &rsquo;rice&rsquo;, &rsquo;hcompress&rsquo; or &rsquo;plio&rsquo;.
</p></dd>
</dl>
<h4 class="subsubheading" id="Outputs-3">Outputs</h4>
<p>None
</p>
<h4 class="subsubheading" id="Examples-3">Examples</h4>
<div class="example">
<pre class="example-preformatted"> filename = tempname();
 X =  double([1:3;4:6]);
 fitswrite(X, filename);
</pre></div>
</dd></dl>
<hr>
</div>
</div>
<div class="section-level-extent" id="Low-Level-Functions">
<h3 class="section" id="Low-Level-Functions-1">3.2 Low Level Functions</h3>
<a class="index-entry-id" id="index-Low-Level-Functions"></a>
<hr>
<div class="subsection-level-extent" id="Low-Level-Functions-_002d-File-Functions">
<h4 class="subsection" id="File-Functions">3.2.1 File Functions</h4>
<a class="index-entry-id" id="index-Low-Level-Functions-_002d-File-Functions"></a>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ecloseFile">
<h4 class="subsubsection">3.2.1.1 matlab.io.fits.closeFile</h4>
<a class="index-entry-id" id="index-closeFile"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-closeFile_0028file_0029"><span class="category-def">: </span><strong class="def-name">closeFile(<var class="var">file</var>)</strong></dt>
<dd><p>Close the opened fits file
</p>
<p>This is the equivalent of the fits_close_file function.
</p>
<h4 class="subsubheading" id="Inputs-4">Inputs</h4>
<p><var class="var">file</var> - opened file returned from openFile or createFile.
</p>
<h4 class="subsubheading" id="Outputs-4">Outputs</h4>
<p>None
</p>
<h4 class="subsubheading" id="Examples-4">Examples</h4>
<div class="example">
<pre class="example-preformatted"> import_fits;
 filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;)
 fd = fits.openFile(filename);
 fits.closeFile(fd);
</pre></div>
<p><strong class="strong">See also:</strong> matlab.io.fits.createFile, matlab.io.fits.openFile.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ecreateFile">
<h4 class="subsubsection">3.2.1.2 matlab.io.fits.createFile</h4>
<a class="index-entry-id" id="index-createFile"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-8"><span class="category-def">: </span><code class="def-type"><var class="var">file</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">createFile(<var class="var">filename</var>)</code></dt>
<dd><p>Attempt to create  a file of the given input name.
</p>
<p>If the filename starts with ! and the file exists, it will create a new file, otherwise, if the
 file exists, the create will fail.
</p>
<p>This is the equivalent of the cfitsio fits_create_file function.
</p>
<h4 class="subsubheading" id="Inputs-5">Inputs</h4>
<p><var class="var">filename</var> - filename to open.
</p>
<h4 class="subsubheading" id="Outputs-5">Outputs</h4>
<p><var class="var">file</var> - opened file identifier.
</p>
<h4 class="subsubheading" id="Examples-5">Examples</h4>
<div class="example">
<pre class="example-preformatted"> import_fits;
 fd = fits.createFile(&quot;myfitsfile.fits&quot;);
 fits.createImg(fd, 'uint16', [100 100]);
 fits.closeFile(fd);
</pre></div>
<p><strong class="strong">See also:</strong> matlab.io.fits.openFile.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002edeleteFile">
<h4 class="subsubsection">3.2.1.3 matlab.io.fits.deleteFile</h4>
<a class="index-entry-id" id="index-deleteFile"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-deleteFile_0028file_0029"><span class="category-def">: </span><strong class="def-name">deleteFile(<var class="var">file</var>)</strong></dt>
<dd><p>Force a close and delete of a fits file.
</p>
<p>This is the equivalent of the fits_delete_file function.
</p>
<h4 class="subsubheading" id="Inputs-6">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-6">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002efileMode">
<h4 class="subsubsection">3.2.1.4 matlab.io.fits.fileMode</h4>
<a class="index-entry-id" id="index-fileMode"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-9"><span class="category-def">: </span><code class="def-type"><var class="var">mode</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fileMode(<var class="var">file</var>)</code></dt>
<dd><p>Return the file mode of the opened fits file.
</p>
<p>This is the equivalent of the fits_file_mode function.
</p>
<h4 class="subsubheading" id="Inputs-7">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-7">Outputs</h4>
<p><var class="var">mode</var> - The mode will return as a string &rsquo;READWRITE&rsquo; or &rsquo;READONLY&rsquo;
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002efileName">
<h4 class="subsubsection">3.2.1.5 matlab.io.fits.fileName</h4>
<a class="index-entry-id" id="index-fileName"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-10"><span class="category-def">: </span><code class="def-type"><var class="var">filename</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">fileName(<var class="var">file</var>)</code></dt>
<dd><p>Return the file name of the opened fits file.
</p>
<p>This is the equivalent of the fits_file_name function.
</p>
<h4 class="subsubheading" id="Inputs-8">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-8">Outputs</h4>
<p><var class="var">filename</var> - name of the fits file.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002eopenDiskFile">
<h4 class="subsubsection">3.2.1.6 matlab.io.fits.openDiskFile</h4>
<a class="index-entry-id" id="index-openDiskFile"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-11"><span class="category-def">: </span><code class="def-type"><var class="var">file</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">openDiskFile(<var class="var">filename</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-_003d-12"><span class="category-def">: </span><code class="def-type"><var class="var">file</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">openDiskFile(<var class="var">filename</var>, <var class="var">mode</var>)</code></dt>
<dd><p>Attempt to open a file of the given input name, ignoring any special processing of the filename.
</p>
<p>This is the equivalent of the cfitsio fits_open_diskfile function.
</p>
<h4 class="subsubheading" id="Inputs-9">Inputs</h4>
<p><var class="var">filename</var> - filename to open.
</p>
<p><var class="var">mode</var> - If the option mode string &rsquo;READONLY&rsquo; (default) or &rsquo;READWRITE&rsquo; is provided,
 open the file using that mode.
</p>
<h4 class="subsubheading" id="Outputs-9">Outputs</h4>
<p><var class="var">file</var> - opened file identifier.
</p>
<h4 class="subsubheading" id="Examples-6">Examples</h4>
<div class="example">
<pre class="example-preformatted"> import_fits;
 filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;)
 fd = fits.openDiskFile(filename, 'READONLY');
 fits.closeFile(fd);
</pre></div>
<p><strong class="strong">See also:</strong> openFile, createFile.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002eopenFile">
<h4 class="subsubsection">3.2.1.7 matlab.io.fits.openFile</h4>
<a class="index-entry-id" id="index-openFile"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-13"><span class="category-def">: </span><code class="def-type"><var class="var">file</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">openFile(<var class="var">filename</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-_003d-14"><span class="category-def">: </span><code class="def-type"><var class="var">file</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">openFile(<var class="var">filename</var>, <var class="var">mode</var>)</code></dt>
<dd><p>Attempt to open a file of the given input name.
</p>
<p>This is the equivalent of the cfitsio fits_open_file function.
</p>
<h4 class="subsubheading" id="Inputs-10">Inputs</h4>
<p><var class="var">filename</var> - filename to open.
</p>
<p><var class="var">mode</var> - If the option mode string &rsquo;READONLY&rsquo; (default) or &rsquo;READWRITE&rsquo; is provided,
 open the file using that mode.
</p>
<h4 class="subsubheading" id="Outputs-10">Outputs</h4>
<p><var class="var">file</var> - opened file identifier.
</p>
<h4 class="subsubheading" id="Examples-7">Examples</h4>
<div class="example">
<pre class="example-preformatted"> import_fits;
 filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;)
 fd = fits.openFile(filename, 'READONLY');
 fits.closeFile(fd);
</pre></div>
<p><strong class="strong">See also:</strong> matlab.io.fits.openDiskFile, matlab.io.fits.createFile.
</p></dd></dl>
<hr>
</div>
</div>
<div class="subsection-level-extent" id="Low-Level-Functions-_002d-HDU-Functions">
<h4 class="subsection" id="HDU-Functions">3.2.2 HDU Functions</h4>
<a class="index-entry-id" id="index-Low-Level-Functions-_002d-HDU-Functions"></a>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ecopyHDU">
<h4 class="subsubsection">3.2.2.1 matlab.io.fits.copyHDU</h4>
<a class="index-entry-id" id="index-copyHDU"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-copyHDU_0028infile_002c"><span class="category-def">: </span><strong class="def-name">copyHDU(<var class="var">infile</var>,</strong> <code class="def-code-arguments"><var class="var">outfile</var>)</code></dt>
<dd><p>Copy current HDU from one infile to another.
</p>
<p>This is the equivalent of the cfitsio fits_copy_hdu function.
</p>
<h4 class="subsubheading" id="Inputs-11">Inputs</h4>
<p><var class="var">filename</var> - filename to open.
</p>
<h4 class="subsubheading" id="Outputs-11">Outputs</h4>
<p><var class="var">infile</var> - opened input file identifier.
</p>
<p><var class="var">outfile</var> - opened output file identifier.
</p>
<h4 class="subsubheading" id="Examples-8">Examples</h4>
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
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002edeleteHDU">
<h4 class="subsubsection">3.2.2.2 matlab.io.fits.deleteHDU</h4>
<a class="index-entry-id" id="index-deleteHDU"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-15"><span class="category-def">: </span><code class="def-type"><var class="var">type</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">deleteHDU(<var class="var">file</var>)</code></dt>
<dd><p>Delete the current HDU and go to next HDU.
</p>
<p>Returns the newly current HDU type as a string.
</p>
<p>This is the equivalent of the cfitsio fits_delete_hdu function.
</p>
<h4 class="subsubheading" id="Inputs-12">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-12">Outputs</h4>
<p><var class="var">type</var> - string value for type of the next HDU.
</p>
</dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetHDUnum">
<h4 class="subsubsection">3.2.2.3 matlab.io.fits.getHDUnum</h4>
<a class="index-entry-id" id="index-getHDUnum"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-16"><span class="category-def">: </span><code class="def-type"><var class="var">num</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">getHDUnum(<var class="var">file</var>)</code></dt>
<dd><p>Return the index of the current HDU.
</p>
<p>This is the equivalent of the cfitsio fits_get_hdu_num function.
</p><h4 class="subsubheading" id="Inputs-13">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-13">Outputs</h4>
<p><var class="var">num</var> - current hdu number.
</p>
</dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetHDUoff">
<h4 class="subsubsection">3.2.2.4 matlab.io.fits.getHDUoff</h4>
<a class="index-entry-id" id="index-getHDUoff"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-17"><span class="category-def">: </span><code class="def-type">[<var class="var">headtstart</var>, <var class="var">datastart</var>, <var class="var">dataend</var>]</code> <strong class="def-name">=</strong> <code class="def-code-arguments">getHDUoff(<var class="var">file</var>)</code></dt>
<dd><p>Return offsets of the current HDU.
</p>
<p>This is the equivalent of the cfitsio fits_get_hduoff function.
</p>
<h4 class="subsubheading" id="Inputs-14">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-14">Outputs</h4>
<p><var class="var">headtstart</var>, <var class="var">datastart</var>, <var class="var">dataend</var> - offset information for the current HDU.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetHDUtype">
<h4 class="subsubsection">3.2.2.5 matlab.io.fits.getHDUtype</h4>
<a class="index-entry-id" id="index-getHDUtype"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-18"><span class="category-def">: </span><code class="def-type"><var class="var">type</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">getHDUtype(<var class="var">file</var>)</code></dt>
<dd><p>Return the current HDUs type as a string.
</p>
<p>This is the equivalent of the cfitsio fits_get_hdu_type function.
</p>
<h4 class="subsubheading" id="Inputs-15">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-15">Outputs</h4>
<p><var class="var">type</var> - current hdu type
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetNumHDUs">
<h4 class="subsubsection">3.2.2.6 matlab.io.fits.getNumHDUs</h4>
<a class="index-entry-id" id="index-getNumHDUs"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-19"><span class="category-def">: </span><code class="def-type"><var class="var">num</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">getNumHDUs(<var class="var">file</var>)</code></dt>
<dd><p>Return the count of HDUs in the file.
</p>
<p>This is the equivalent of the cfitsio fits_get_num_hdus function.
</p>
<h4 class="subsubheading" id="Inputs-16">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-16">Outputs</h4>
<p><var class="var">num</var> - return the number of HDUs in the file.
</p><h4 class="subsubheading" id="Examples-9">Examples</h4>
<div class="example">
<pre class="example-preformatted"> import_fits;
 testname = file_in_loadpath(&quot;demos/tst0012.fits&quot;);
 fd = fits.openFile(testname);
 hducount = getNumHDUs(fd), 5);
 fits.closeFile(fd);
</pre></div>
</dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002emovAbsHDU">
<h4 class="subsubsection">3.2.2.7 matlab.io.fits.movAbsHDU</h4>
<a class="index-entry-id" id="index-movAbsHDU"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-movAbsHDU_0028file_002c"><span class="category-def">: </span><code class="def-type"><var class="var">type</var> =</code> <strong class="def-name">movAbsHDU(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">hdunum</var>)</code></dt>
<dd><p>Go to absolute HDU index <var class="var">hdunum</var>
</p>
<p>Returns the newly current HDU type as a string.
</p>
<p>This is the equivalent of the cfitsio fits_movabs_hdu function.
</p>
<h4 class="subsubheading" id="Inputs-17">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">hdunum</var> - HDU number to move to.
</p>
<h4 class="subsubheading" id="Outputs-17">Outputs</h4>
<p><var class="var">type</var> - hdu type of the now current HDU.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002emovNamHDU">
<h4 class="subsubsection">3.2.2.8 matlab.io.fits.movNamHDU</h4>
<a class="index-entry-id" id="index-movNamHDU"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-movNamHDU_0028file_002c"><span class="category-def">: </span><code class="def-type"><var class="var">hdutype</var> =</code> <strong class="def-name">movNamHDU(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">hdutype</var>, <var class="var">extname</var>, <var class="var">extver</var>)</code></dt>
<dd><p>Go to HDU matching <var class="var">hdutype</var>, <var class="var">extname</var>, <var class="var">extver</var>.
</p>
<p>This is the equivalent of the cfitsio fits_movnam_hdu function.
</p>
<h4 class="subsubheading" id="Inputs-18">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">hdutype</var> - HDU number to move to.
 Valid hdutype values are &rsquo;IMAGE_HDU&rsquo;, &rsquo;ASCII_TBL&rsquo;, &rsquo;BINARY_TBL&rsquo;, &rsquo;ANY_HDU&rsquo;.
</p>
<p><var class="var">extname</var>, <var class="var">extver</var> - EXTNAME and EXTVER keywords to match.
</p>
<h4 class="subsubheading" id="Outputs-18">Outputs</h4>
<p><var class="var">hdutype</var> - hdu type of the now current HDU.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002emovRelHDU">
<h4 class="subsubsection">3.2.2.9 matlab.io.fits.movRelHDU</h4>
<a class="index-entry-id" id="index-movRelHDU"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-20"><span class="category-def">: </span><code class="def-type"><var class="var">type</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">movRelHDU(<var class="var">file</var>, <var class="var">hdunum</var>)</code></dt>
<dd><p>Go to relative HDU index <var class="var">hdunum</var>.
</p>
<p>Returns the newly current HDU type as a string.
</p>
<p>This is the equivalent of the cfitsio fits_movrel_hdu function.
</p>
<h4 class="subsubheading" id="Inputs-19">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">hdunum</var> - relative HDU number to move to.
</p>
<h4 class="subsubheading" id="Outputs-19">Outputs</h4>
<p><var class="var">type</var> - hdu type of the now current HDU.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ewriteChecksum">
<h4 class="subsubsection">3.2.2.10 matlab.io.fits.writeChecksum</h4>
<a class="index-entry-id" id="index-writeChecksum"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-writeChecksum_0028file_0029"><span class="category-def">: </span><strong class="def-name">writeChecksum(<var class="var">file</var>)</strong></dt>
<dd><p>Recalculate the HDU checksum and if required, write the new value.
</p>
<p>This is the equivalent of the cfitsio fits_write_chksum function.
</p>
<h4 class="subsubheading" id="Inputs-20">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-20">Outputs</h4>
<p>None
</p></dd></dl>
<hr>
</div>
</div>
<div class="subsection-level-extent" id="Low-Level-Functions-_002d-Keyword-Functions">
<h4 class="subsection" id="Keyword-Functions">3.2.3 Keyword Functions</h4>
<a class="index-entry-id" id="index-Low-Level-Functions-_002d-Keyword-Functions"></a>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002edeleteKey">
<h4 class="subsubsection">3.2.3.1 matlab.io.fits.deleteKey</h4>
<a class="index-entry-id" id="index-deleteKey"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-deleteKey_0028file_002c"><span class="category-def">: </span><strong class="def-name">deleteKey(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">key</var>)</code></dt>
<dd><p>Delete a key in the fits file.
</p>
<p>This is the equivalent of the cfitsio fits_delete_key function.
</p>
<h4 class="subsubheading" id="Inputs-21">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">key</var> - Key name to remove.
</p>
<h4 class="subsubheading" id="Outputs-21">Outputs</h4>
<p>None
</p>
</dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002edeleteRecord">
<h4 class="subsubsection">3.2.3.2 matlab.io.fits.deleteRecord</h4>
<a class="index-entry-id" id="index-deleteRecord"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-deleteRecord_0028file_002c"><span class="category-def">: </span><strong class="def-name">deleteRecord(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">keynum</var>)</code></dt>
<dd><p>Delete a key in the fits file.
</p>
<p>This is the equivalent of the cfitsio fits_delete_record function.
</p>
<h4 class="subsubheading" id="Inputs-22">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">keynum</var> - Record number to remove.
</p>
<h4 class="subsubheading" id="Outputs-22">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetHdrSpace">
<h4 class="subsubsection">3.2.3.3 matlab.io.fits.getHdrSpace</h4>
<a class="index-entry-id" id="index-getHdrSpace"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-getHdrSpace_0028file_0029"><span class="category-def">: </span><code class="def-type">[<var class="var">numkeys</var>, <var class="var">freekeys</var>] =</code> <strong class="def-name">getHdrSpace(<var class="var">file</var>)</strong></dt>
<dd><p>Get the number of keyword records used and available.
</p>
<p>This is the equivalent of the cfitsio fits_get_hdrspace function.
</p>
<h4 class="subsubheading" id="Inputs-23">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-23">Outputs</h4>
<p><var class="var">numkeys</var> - number of existing keys.
</p>
<p><var class="var">freekeys</var> - number of free key space.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ereadCard">
<h4 class="subsubsection">3.2.3.4 matlab.io.fits.readCard</h4>
<a class="index-entry-id" id="index-readCard"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-readCard_0028file_002c"><span class="category-def">: </span><code class="def-type"><var class="var">card</var> =</code> <strong class="def-name">readCard(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">recname</var>)</code></dt>
<dd><p>Read the keyword card for name <var class="var">recname</var>
</p>
<p>This is the equivalent of the cfitsio fits_read_card function.
</p>
<h4 class="subsubheading" id="Inputs-24">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">recname</var> - record name to read
</p>
<h4 class="subsubheading" id="Outputs-24">Outputs</h4>
<p><var class="var">card</var> - unparsed record value string
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ereadKey">
<h4 class="subsubsection">3.2.3.5 matlab.io.fits.readKey</h4>
<a class="index-entry-id" id="index-readKey"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-readKey_0028file_002c"><span class="category-def">: </span><code class="def-type">[<var class="var">keyvalue</var>, <var class="var">keycomment</var>] =</code> <strong class="def-name">readKey(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">recname</var>)</code></dt>
<dd><p>Read the keyword value and comment for name <var class="var">recname</var>.
</p>
<p>This is the equivalent of the cfitsio fits_read_key_str function.
</p>
<h4 class="subsubheading" id="Inputs-25">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">recname</var> - keyword name.
</p>
<h4 class="subsubheading" id="Outputs-25">Outputs</h4>
<p><var class="var">keyvalue</var> - string value of record.
</p>
<p><var class="var">keycomment</var> - comment string
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ereadKeyCmplx">
<h4 class="subsubsection">3.2.3.6 matlab.io.fits.readKeyCmplx</h4>
<a class="index-entry-id" id="index-readKeyCmplx"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-readKeyCmplx_0028file_002c"><span class="category-def">: </span><code class="def-type">[<var class="var">value</var>, <var class="var">comment</var>] =</code> <strong class="def-name">readKeyCmplx(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">recname</var>)</code></dt>
<dd><p>Read the key value <var class="var">recname</var> as a complex double.
</p>
<p>This is the equivalent of the cfitsio fits_read_key_dblcmp function.
</p>
<h4 class="subsubheading" id="Inputs-26">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">recname</var> - keyword name.
</p>
<h4 class="subsubheading" id="Outputs-26">Outputs</h4>
<p><var class="var">value</var> - complex value of record.
</p>
<p><var class="var">comment</var> - comment string
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ereadKeyDbl">
<h4 class="subsubsection">3.2.3.7 matlab.io.fits.readKeyDbl</h4>
<a class="index-entry-id" id="index-readKeyDbl"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-readKeyDbl_0028file_002c"><span class="category-def">Function File: </span><code class="def-type">[<var class="var">value</var>, <var class="var">comment</var>] =</code> <strong class="def-name">readKeyDbl(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">recname</var>)</code></dt>
<dd><p>Read the key value <var class="var">recname</var> as a double.
</p>
<p>This is the equivalent of the cfitsio fits_read_key_dbl function.\n \
</p>
<h4 class="subsubheading" id="Inputs-27">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">recname</var> - keyword name.
</p>
<h4 class="subsubheading" id="Outputs-27">Outputs</h4>
<p><var class="var">value</var> - double value of record.
</p>
<p><var class="var">comment</var> - comment string
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ereadKeyLongLong">
<h4 class="subsubsection">3.2.3.8 matlab.io.fits.readKeyLongLong</h4>
<a class="index-entry-id" id="index-readKeyLongLong"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-readKeyLongLong_0028file_002c"><span class="category-def">: </span><code class="def-type">[<var class="var">value</var>, <var class="var">comment</var>] =</code> <strong class="def-name">readKeyLongLong(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">recname</var>)</code></dt>
<dd><p>Read the key value <var class="var">recname</var> as a long long.
</p>
<p>This is the equivalent of the cfitsio fits_read_key_lnglng function.
</p>
<h4 class="subsubheading" id="Inputs-28">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">recname</var> - keyword name.
</p>
<h4 class="subsubheading" id="Outputs-28">Outputs</h4>
<p><var class="var">value</var> - int64 value of record.
</p>
<p><var class="var">comment</var> - comment string
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ereadKeyLongStr">
<h4 class="subsubsection">3.2.3.9 matlab.io.fits.readKeyLongStr</h4>
<a class="index-entry-id" id="index-readKeyLongStr"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-readKeyLongStr_0028file_002c"><span class="category-def">: </span><code class="def-type">[<var class="var">value</var>, <var class="var">comment</var>] =</code> <strong class="def-name">readKeyLongStr(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">recname</var>)</code></dt>
<dd><p>Read the key value <var class="var">recname</var> as a string.
</p>
<p>This is the equivalent of the cfitsio fits_read_key_longstr function.
</p>
<h4 class="subsubheading" id="Inputs-29">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">recname</var> - keyword name.
</p>
<h4 class="subsubheading" id="Outputs-29">Outputs</h4>
<p><var class="var">value</var> - string value of record.
</p>
<p><var class="var">comment</var> - comment string
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ereadKeyUnit">
<h4 class="subsubsection">3.2.3.10 matlab.io.fits.readKeyUnit</h4>
<a class="index-entry-id" id="index-readKeyUnit"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-readKeyUnit_0028file_002c"><span class="category-def">: </span><code class="def-type"><var class="var">keyunit</var> =</code> <strong class="def-name">readKeyUnit(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">recname</var>)</code></dt>
<dd><p>Read the physical key units value <var class="var">recname</var>.
</p>
<p>This is the equivalent of the cfitsio fits_read_key_unit function.
</p>
<h4 class="subsubheading" id="Inputs-30">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">recname</var> - keyword name.
</p>
<h4 class="subsubheading" id="Outputs-30">Outputs</h4>
<p><var class="var">keyunit</var> - units value of record.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ereadRecord">
<h4 class="subsubsection">3.2.3.11 matlab.io.fits.readRecord</h4>
<a class="index-entry-id" id="index-readRecord"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-readRecord_0028file_002c"><span class="category-def">: </span><code class="def-type"><var class="var">rec</var> =</code> <strong class="def-name">readRecord(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">recidx</var>)</code></dt>
<dd><p>Read the keyword record at <var class="var">recidx</var>.
</p>
<p>This is the equivalent of the cfitsio fits_read_record function.
</p>
<h4 class="subsubheading" id="Inputs-31">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">recidx</var> - record number.
</p>
<h4 class="subsubheading" id="Outputs-31">Outputs</h4>
<p><var class="var">rec</var> - full keyword record
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ewriteComment">
<h4 class="subsubsection">3.2.3.12 matlab.io.fits.writeComment</h4>
<a class="index-entry-id" id="index-writeComment"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-writeComment_0028file_002c"><span class="category-def">: </span><strong class="def-name">writeComment(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">comment</var>)</code></dt>
<dd><p>Append a comment to to the fits file.
</p>
<p>This is the equivalent of the cfitsio fits_write_comment function.
</p>
<h4 class="subsubheading" id="Inputs-32">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">comment</var> - comment to append
</p>
<h4 class="subsubheading" id="Outputs-32">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ewriteDate">
<h4 class="subsubsection">3.2.3.13 matlab.io.fits.writeDate</h4>
<a class="index-entry-id" id="index-writeDate"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-writeDate_0028file_0029"><span class="category-def">: </span><strong class="def-name">writeDate(<var class="var">file</var>)</strong></dt>
<dd><p>Write the date keyword.
</p>
<p>This is the equivalent of the cfitsio fits_write_date function.
</p>
<h4 class="subsubheading" id="Inputs-33">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-33">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ewriteHistory">
<h4 class="subsubsection">3.2.3.14 matlab.io.fits.writeHistory</h4>
<a class="index-entry-id" id="index-writeHistory"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-writeHistory_0028file_002c"><span class="category-def">: </span><strong class="def-name">writeHistory(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">history</var>)</code></dt>
<dd><p>Append a history to to the fits file.
</p>
<p>This is the equivalent of the cfitsio fits_write_history function.
</p><h4 class="subsubheading" id="Inputs-34">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">history</var> - history string.
</p>
<h4 class="subsubheading" id="Outputs-34">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ewriteKey">
<h4 class="subsubsection">3.2.3.15 matlab.io.fits.writeKey</h4>
<a class="index-entry-id" id="index-writeKey"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-writeKey_0028file_002c"><span class="category-def">: </span><strong class="def-name">writeKey(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">key</var>, <var class="var">value</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-writeKey_0028file_002c-1"><span class="category-def">: </span><strong class="def-name">writeKey(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">key</var>, <var class="var">value</var>, <var class="var">comment</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-writeKey_0028file_002c-2"><span class="category-def">: </span><strong class="def-name">writeKey(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">key</var>, <var class="var">value</var>, <var class="var">comment</var>, <var class="var">decimals</var>)</code></dt>
<dd><p>Append or replace a key in the fits file.
</p>
<p>This is the equivalent of the cfitsio fits_write_key and fits_update_key function.
</p><h4 class="subsubheading" id="Inputs-35">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">key</var> - keyword name.
</p>
<p><var class="var">value</var> - keyword value.
</p>
<p><var class="var">comment</var> - keyword comment.
</p>
<p><var class="var">decimals</var> - number of decimals.
</p>
<h4 class="subsubheading" id="Outputs-35">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ewriteKeyUnit">
<h4 class="subsubsection">3.2.3.16 matlab.io.fits.writeKeyUnit</h4>
<a class="index-entry-id" id="index-writeKeyUnit"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-writeKeyUnit_0028file_002c"><span class="category-def">: </span><strong class="def-name">writeKeyUnit(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">key</var>, <var class="var">unit</var>)</code></dt>
<dd><p>Write a key unit to the fits file.
</p>
<p>This is the equivalent of the cfitsio fits_write_key_unit function.
</p><h4 class="subsubheading" id="Inputs-36">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">key</var> - keyword name.
</p>
<p><var class="var">unit</var> - keyword units as string.
</p>
<h4 class="subsubheading" id="Outputs-36">Outputs</h4>
<p>None
</p></dd></dl>
<hr>
</div>
</div>
<div class="subsection-level-extent" id="Low-Level-Functions-_002d-Image-Manipulation">
<h4 class="subsection" id="Image-Manipulation">3.2.4 Image Manipulation</h4>
<a class="index-entry-id" id="index-Low-Level-Functions-_002d-Image-Manipulation"></a>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ecreateImg">
<h4 class="subsubsection">3.2.4.1 matlab.io.fits.createImg</h4>
<a class="index-entry-id" id="index-createImg"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-createImg_0028file_002c"><span class="category-def">: </span><strong class="def-name">createImg(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">bitpix</var>, <var class="var">naxis</var>)</code></dt>
<dd><p>create a new primary image or image extension.
</p>
<p>This is the equivalent of the cfitsio fits_create_imgll function.
</p>
<h4 class="subsubheading" id="Inputs-37">Inputs</h4>
<p><var class="var">file</var> - file previously opened with openFile, openDiskFile
 or createFile.
</p>
<p><var class="var">bitpix</var> - type for the data as a string in either matlab or cfitsio naming.
</p>
<p><var class="var">naxis</var> - axis values for the image.
</p>
<h4 class="subsubheading" id="Outputs-37">Outputs</h4>
<p>None
</p>
<h4 class="subsubheading" id="Examples-10">Examples</h4>
<div class="example">
<pre class="example-preformatted"> import_fits;
 fd = fits.createFile(&quot;test.fits&quot;);
 fits.createImg(fd,'int16',[10 20]);
 fits.close(fd);
</pre></div>
</dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetImgSize">
<h4 class="subsubsection">3.2.4.2 matlab.io.fits.getImgSize</h4>
<a class="index-entry-id" id="index-getImgSize"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-21"><span class="category-def">: </span><code class="def-type"><var class="var">size</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">getImgSize(<var class="var">file</var>)</code></dt>
<dd><p>Return size of a Image HDU.
</p>
<p>This is the equivalent of the cfitsio fits_get_img_size function.
</p>
<h4 class="subsubheading" id="Inputs-38">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-38">Outputs</h4>
<p><var class="var">size</var> - vector containing the image dimensions.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetImgType">
<h4 class="subsubsection">3.2.4.3 matlab.io.fits.getImgType</h4>
<a class="index-entry-id" id="index-getImgType"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-22"><span class="category-def">: </span><code class="def-type"><var class="var">type</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">getImgType(<var class="var">file</var>)</code></dt>
<dd><p>Return datatype of a Image HDU
</p>
<p>This is the equivalent of the cfitsio fits_get_img_type function.
</p>
<h4 class="subsubheading" id="Inputs-39">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-39">Outputs</h4>
<p><var class="var">type</var> - datatype as a string for the image type.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002einsertImg">
<h4 class="subsubsection">3.2.4.4 matlab.io.fits.insertImg</h4>
<a class="index-entry-id" id="index-insertImg"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-insertImg_0028file_002c"><span class="category-def">: </span><strong class="def-name">insertImg(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">bitpix</var>, <var class="var">naxis</var>)</code></dt>
<dd><p>Insert a new primary image or image extension at current HDU position.
</p>
<p>This is the equivalent of the cfitsio fits_insert_imgll function.
</p>
<h4 class="subsubheading" id="Inputs-40">Inputs</h4>
<p><var class="var">file</var> - file previously opened with openFile, openDiskFile
 or createFile.
</p>
<p><var class="var">bitpix</var> - type for the data as a string in either matlab or cfitsio naming.
</p>
<p><var class="var">naxis</var> - axis values for the image.
</p>
<h4 class="subsubheading" id="Outputs-40">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ereadImg">
<h4 class="subsubsection">3.2.4.5 matlab.io.fits.readImg</h4>
<a class="index-entry-id" id="index-readImg"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-23"><span class="category-def">: </span><code class="def-type"><var class="var">data</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">readImg(<var class="var">file</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-_003d-24"><span class="category-def">: </span><code class="def-type"><var class="var">data</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">readImg(<var class="var">file</var>, <var class="var">firstpix</var>, <var class="var">lastpix</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-_003d-25"><span class="category-def">: </span><code class="def-type"><var class="var">data</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">readImg(<var class="var">file</var>, <var class="var">firstpix</var>, <var class="var">lastpix</var>, <var class="var">inc</var>)</code></dt>
<dd><p>Read Image data.
</p>
<p>This is the equivalent of the cfitsio fits_read_subset function.
</p>
<h4 class="subsubheading" id="Inputs-41">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">firstpix</var> - first pile coordinate
</p>
<p><var class="var">lastpix</var> - last pixel coordinate
</p>
<p><var class="var">inc</var> -  pixel increment
</p>
<h4 class="subsubheading" id="Outputs-41">Outputs</h4>
<p><var class="var">data</var> - image data read
</p><h4 class="subsubheading" id="Examples-11">Examples</h4>
<div class="example">
<pre class="example-preformatted"> import_fits;
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
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002esetBscale">
<h4 class="subsubsection">3.2.4.6 matlab.io.fits.setBscale</h4>
<a class="index-entry-id" id="index-setBscale"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-setBscale_0028file_002c"><span class="category-def">: </span><strong class="def-name">setBscale(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">bscale</var>, <var class="var">bzero</var>)</code></dt>
<dd><p>Reset bscale and bzero to be used with reading and writing Images.
</p>
<p>This is the equivalent of the cfitsio fits_set_bscale function.
</p>
<h4 class="subsubheading" id="Inputs-42">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">bscale</var> - bscale value
</p>
<p><var class="var">bzero</var> - bzero value
</p>
<h4 class="subsubheading" id="Outputs-42">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002esetTscale">
<h4 class="subsubsection">3.2.4.7 matlab.io.fits.setTscale</h4>
<a class="index-entry-id" id="index-setTscale"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-setTscale_0028file_002c"><span class="category-def">: </span><strong class="def-name">setTscale(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">col</var>, <var class="var">scale</var>, <var class="var">zero</var>)</code></dt>
<dd><p>Reset scale and zero to be used with reading and writing table data.
</p>
<p>This is the equivalent of the cfitsio fits_set_tscale function.
</p>
<h4 class="subsubheading" id="Inputs-43">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">col</var> - column number
</p>
<p><var class="var">scale</var> - scale value
</p>
<p><var class="var">zero</var> - zero value
</p>
<h4 class="subsubheading" id="Outputs-43">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ewriteImg">
<h4 class="subsubsection">3.2.4.8 matlab.io.fits.writeImg</h4>
<a class="index-entry-id" id="index-writeImg"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-writeImg_0028file_002c"><span class="category-def">: </span><strong class="def-name">writeImg(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">imagedata</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-writeImg_0028file_002c-1"><span class="category-def">: </span><strong class="def-name">writeImg(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">imagedata</var>, <var class="var">fpixel</var>)</code></dt>
<dd><p>write imagedata to a FITS file. The rows and column size must match the size of NAXIS, NAXIS etc
</p>
<p>This is the equivalent of the cfitsio fits_write_subset function.
</p>
<h4 class="subsubheading" id="Inputs-44">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">imagedata</var> - Image data.
</p>
<p><var class="var">fpixel</var> - start pixel to write from.
</p>
<h4 class="subsubheading" id="Outputs-44">Outputs</h4>
<p>None
</p>
<h4 class="subsubheading" id="Examples-12">Examples</h4>
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
<hr>
</div>
</div>
<div class="subsection-level-extent" id="Low-Level-Functions-_002d-Utility-Functions">
<h4 class="subsection" id="Utility-Functions">3.2.5 Utility Functions</h4>
<a class="index-entry-id" id="index-Low-Level-Functions-_002d-Utility-Functions"></a>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetConstantNames">
<h4 class="subsubsection">3.2.5.1 matlab.io.fits.getConstantNames</h4>
<a class="index-entry-id" id="index-getConstantNames"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-26"><span class="category-def">: </span><code class="def-type"><var class="var">namelist</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">getConstantNames()</code></dt>
<dd><p>Return the names of all known fits constants.
</p>
<h4 class="subsubheading" id="Inputs-45">Inputs</h4>
<p>None
</p>
<h4 class="subsubheading" id="Outputs-45">Outputs</h4>
<p><var class="var">namelist</var> - cell array of all known fits constant names
</p>
<p><strong class="strong">See also:</strong> getConstantValue.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetConstantValue">
<h4 class="subsubsection">3.2.5.2 matlab.io.fits.getConstantValue</h4>
<a class="index-entry-id" id="index-getConstantValue"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-27"><span class="category-def">: </span><code class="def-type"><var class="var">value</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">getConstantValue(<var class="var">name</var>)</code></dt>
<dd><p>Return the value of a known fits constant.
</p>
<h4 class="subsubheading" id="Inputs-46">Inputs</h4>
<p><var class="var">name</var> - name of the constant to retrieve value of.
</p>
<h4 class="subsubheading" id="Outputs-46">Outputs</h4>
<p><var class="var">value</var> - value of the constant
</p>
<p><strong class="strong">See also:</strong> getConstantNames.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetOpenFiles">
<h4 class="subsubsection">3.2.5.3 matlab.io.fits.getOpenFiles</h4>
<a class="index-entry-id" id="index-getOpenFiles"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-28"><span class="category-def">: </span><code class="def-type"><var class="var">files</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">getOpenFiles()</code></dt>
<dd><p>Get the file handles of all open fits files.
</p>
<h4 class="subsubheading" id="Inputs-47">Inputs</h4>
<p>None
</p>
<h4 class="subsubheading" id="Outputs-47">Outputs</h4>
<p><var class="var">files</var> list of opened fits file handles.
</p>
<p><strong class="strong">See also:</strong> openFile.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetVersion">
<h4 class="subsubsection">3.2.5.4 matlab.io.fits.getVersion</h4>
<a class="index-entry-id" id="index-getVersion"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-29"><span class="category-def">: </span><code class="def-type"><var class="var">ver</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">getVersion()</code></dt>
<dd><p>Return the version number of the cfitsio library used.
</p>
<p>This is the equivalent of the cfitsio fits_get_version function.
</p>
<h4 class="subsubheading" id="Inputs-48">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-48">Outputs</h4>
<p><var class="var">ver</var> - version
</p></dd></dl>
<hr>
</div>
</div>
<div class="subsection-level-extent" id="Low-Level-Functions-_002d-Compression-Functions">
<h4 class="subsection" id="Compression-Functions">3.2.6 Compression Functions</h4>
<a class="index-entry-id" id="index-Low-Level-Functions-_002d-Compression-Functions"></a>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002eimgCompress">
<h4 class="subsubsection">3.2.6.1 matlab.io.fits.imgCompress</h4>
<a class="index-entry-id" id="index-imgCompress"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-imgCompress_0028infile_002c"><span class="category-def">: </span><strong class="def-name">imgCompress(<var class="var">infile</var>,</strong> <code class="def-code-arguments"><var class="var">outfile</var>)</code></dt>
<dd><p>Copy HDU and image data from one infile to another, using the outfiles compression type.
</p>
<p>This is the equivalent of the cfitsio fits_img_compress function.
</p>
<h4 class="subsubheading" id="Inputs-49">Inputs</h4>
<p><var class="var">infile</var> - opened input fits file.
</p>
<p><var class="var">outfile</var> - opened writable output fits file.
</p>
<h4 class="subsubheading" id="Outputs-49">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002eisCompressedImg">
<h4 class="subsubsection">3.2.6.2 matlab.io.fits.isCompressedImg</h4>
<a class="index-entry-id" id="index-isCompressedImg"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-isCompressedImg_0028file_0029"><span class="category-def">: </span><code class="def-type"><var class="var">comp</var> =</code> <strong class="def-name">isCompressedImg(<var class="var">file</var>)</strong></dt>
<dd><p>Return true if image is compressed.
</p>
<p>This is the equivalent of the cfitsio fits_is_compressed_image function.
</p>
<h4 class="subsubheading" id="Inputs-50">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-50">Outputs</h4>
<p><var class="var">comp</var> - boolean for whether image is compressed or not.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002esetCompressionType">
<h4 class="subsubsection">3.2.6.3 matlab.io.fits.setCompressionType</h4>
<a class="index-entry-id" id="index-setCompressionType"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-setCompressionType_0028file_002c"><span class="category-def">: </span><strong class="def-name">setCompressionType(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">comptype</var>)</code></dt>
<dd><p>Set compression type for writing FITS images.
</p>
<p>This is the equivalent of the cfitsio fits_set_compression_type function.
</p>
<h4 class="subsubheading" id="Inputs-51">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">comptype</var> - compression type.
 Valid comptype values are: &rsquo;GZIP&rsquo;, &rsquo;GZIP2&rsquo;, &rsquo;RICE&rsquo;, &rsquo;PLIO&rsquo;, &rsquo;HCOMPRESS&rsquo; or &rsquo;NOCOMPRESS&rsquo;.
</p>
<h4 class="subsubheading" id="Outputs-51">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002esetHCompScale">
<h4 class="subsubsection">3.2.6.4 matlab.io.fits.setHCompScale</h4>
<a class="index-entry-id" id="index-setHCompScale"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-setHCompScale_0028file_002c"><span class="category-def">: </span><strong class="def-name">setHCompScale(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">scale</var>)</code></dt>
<dd><p>Set scale to be used with HCOMPRESS compression.
</p>
<p>This is the equivalent of the cfitsio fits_set_hcomp_scale function.
</p>
<h4 class="subsubheading" id="Inputs-52">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">scale</var> - scale value
</p><h4 class="subsubheading" id="Outputs-52">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002esetHCompSmooth">
<h4 class="subsubsection">3.2.6.5 matlab.io.fits.setHCompSmooth</h4>
<a class="index-entry-id" id="index-setHCompSmooth"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-setHCompSmooth_0028file_002c"><span class="category-def">: </span><strong class="def-name">setHCompSmooth(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">smooth</var>)</code></dt>
<dd><p>Set smooth value to be used with HCOMPRESS compression.
</p>
<p>This is the equivalent of the cfitsio fits_set_hcomp_smooth function.
</p>
<h4 class="subsubheading" id="Inputs-53">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">smooth</var> - smooth value
</p>
<h4 class="subsubheading" id="Outputs-53">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002esetTileDim">
<h4 class="subsubsection">3.2.6.6 matlab.io.fits.setTileDim</h4>
<a class="index-entry-id" id="index-setTileDim"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-setTileDim_0028file_002c"><span class="category-def">: </span><strong class="def-name">setTileDim(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">tiledims</var>)</code></dt>
<dd><p>Set compression tile dims for writing FITS images.
</p>
<p>This is the equivalent of the cfitsio fits_set_tile_dim function.
</p>
<h4 class="subsubheading" id="Inputs-54">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">tiledims</var> - tile dimensions
</p>
<h4 class="subsubheading" id="Outputs-54">Outputs</h4>
<p>None
</p></dd></dl>
<hr>
</div>
</div>
<div class="subsection-level-extent" id="Low-Level-Functions-_002d-Binary-and-ASCII-Tables">
<h4 class="subsection" id="Binary-and-ASCII-Tables">3.2.7 Binary and ASCII Tables</h4>
<a class="index-entry-id" id="index-Low-Level-Functions-_002d-Binary-and-ASCII-Tables"></a>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ecreateTbl">
<h4 class="subsubsection">3.2.7.1 matlab.io.fits.createTbl</h4>
<a class="index-entry-id" id="index-createTbl"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-createTbl_0028file_002c"><span class="category-def">: </span><strong class="def-name">createTbl(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">tbltype</var>, <var class="var">nrows</var>, <var class="var">ttype</var>, <var class="var">tform</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-createTbl_0028file_002c-1"><span class="category-def">: </span><strong class="def-name">createTbl(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">tbltype</var>, <var class="var">nrows</var>, <var class="var">ttype</var>, <var class="var">tform</var>, <var class="var">tunit</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-createTbl_0028file_002c-2"><span class="category-def">: </span><strong class="def-name">createTbl(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">tbltype</var>, <var class="var">nrows</var>, <var class="var">ttype</var>, <var class="var">tform</var>, <var class="var">tunit</var>, <var class="var">extname</var>)</code></dt>
<dd><p>Create a new ASCII or bintable extension.
</p>
<p>This is the equivalent of the cfitsio fits_create_tbl function.
</p>
<h4 class="subsubheading" id="Inputs-55">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">tbltype</var> - table type &rsquo;binary&rsquo; or &rsquo;ascii&rsquo;.
</p>
<p><var class="var">nrows</var> - initial number of rows (normally 0)
</p>
<p><var class="var">ttype</var> - cell array of column type
</p>
<p><var class="var">tform</var> - cell array of column format
</p>
<p><var class="var">tunit</var> - cell array of column units
</p>
<p><var class="var">extname</var> - optional extension name
</p>
<p><var class="var">ttype</var>, <var class="var">tform</var>, <var class="var">tunit</var> are expected to be the same size.
</p>
<h4 class="subsubheading" id="Outputs-55">Outputs</h4>
<p>None
</p>
<h4 class="subsubheading" id="Examples-13">Examples</h4>
<div class="example">
<pre class="example-preformatted"> import_fits;
 fd = fits.createFile(&quot;test.fits&quot;);
 ttype = {'Col1','Col2','Col3','Col4'};
 tform = {'A9','A4','A3','A8'};
 tunit = {'m','s','kg','km'};
 fits.createTbl(fd,'binary',0,ttype,tform,tunit,'table-name');
 fits.closeFile(fd);
</pre></div>
</dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002edeleteCol">
<h4 class="subsubsection">3.2.7.2 matlab.io.fits.deleteCol</h4>
<a class="index-entry-id" id="index-deleteCol"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-deleteCol_0028file_002c"><span class="category-def">: </span><strong class="def-name">deleteCol(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">colnum</var>)</code></dt>
<dd><p>Delete a column from a table.
</p>
<p>This is the equivalent of the cfitsio fits_delete_col function.
</p>
<h4 class="subsubheading" id="Inputs-56">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">colnum</var> - Column to delete from current table.
</p>
<h4 class="subsubheading" id="Outputs-56">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002edeleteRows">
<h4 class="subsubsection">3.2.7.3 matlab.io.fits.deleteRows</h4>
<a class="index-entry-id" id="index-deleteRows"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-deleteRows_0028file_002c"><span class="category-def">: </span><strong class="def-name">deleteRows(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">firstrow</var>, <var class="var">numrows</var>)</code></dt>
<dd><p>Insert a rows into a table.
</p>
<p>This is the equivalent of the cfitsio fits_delete_rows function.
</p>
<h4 class="subsubheading" id="Inputs-57">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">firstrow</var> - Start row to delete.
</p>
<p><var class="var">numrows</var> - Number of rows to delete.
</p>
<h4 class="subsubheading" id="Outputs-57">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetAColParms">
<h4 class="subsubsection">3.2.7.4 matlab.io.fits.getAColParms</h4>
<a class="index-entry-id" id="index-getAColParms"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-30"><span class="category-def">: </span><code class="def-type">[<var class="var">ttype</var>,<var class="var">tbcol</var>,<var class="var">tunit</var>,<var class="var">tform</var>,<var class="var">scale</var>,<var class="var">zero</var>,<var class="var">nulstr</var>,<var class="var">tdisp</var>]</code> <strong class="def-name">=</strong> <code class="def-code-arguments">getAColParms(<var class="var">file</var>, <var class="var">colnum</var>)</code></dt>
<dd><p>Get ASCII table parameters.
</p>
<p>This is the equivalent of the cfitsio fits_get_acolparms function.
</p>
<h4 class="subsubheading" id="Inputs-58">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">colnum</var> - Column to retrieve.
</p>
<h4 class="subsubheading" id="Outputs-58">Outputs</h4>
<p><var class="var">ttype</var>,<var class="var">tbcol</var>,<var class="var">tunit</var>,<var class="var">tform</var>,<var class="var">scale</var>,<var class="var">zero</var>,<var class="var">nulstr</var>,<var class="var">tdisp</var>
 column information in same format as provided by fits_get_acolparms.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetBColParms">
<h4 class="subsubsection">3.2.7.5 matlab.io.fits.getBColParms</h4>
<a class="index-entry-id" id="index-getBColParms"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-31"><span class="category-def">: </span><code class="def-type">[<var class="var">ttype</var>,<var class="var">tunit</var>,<var class="var">typechar</var>,<var class="var">repeat</var>,<var class="var">scale</var>,<var class="var">zero</var>,<var class="var">nulval</var>,<var class="var">tdisp</var>]</code> <strong class="def-name">=</strong> <code class="def-code-arguments">getBColParms(<var class="var">file</var>, <var class="var">colnum</var>)</code></dt>
<dd><p>Get binary table parameters.
</p>
<p>This is the equivalent of the cfitsio  fits_get_bcolparms function.
</p>
<h4 class="subsubheading" id="Inputs-59">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">colnum</var> - Column to retrieve.
</p>
<h4 class="subsubheading" id="Outputs-59">Outputs</h4>
<p><var class="var">ttype</var>,<var class="var">tunit</var>,<var class="var">typechar</var>,<var class="var">repeat</var>,<var class="var">scale</var>,<var class="var">zero</var>,<var class="var">nulval</var>,<var class="var">tdisp</var>
 column information in same format as provided by fits_get_bcolparms.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetColName">
<h4 class="subsubsection">3.2.7.6 matlab.io.fits.getColName</h4>
<a class="index-entry-id" id="index-getColName"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-32"><span class="category-def">: </span><code class="def-type">[<var class="var">colnum</var>,<var class="var">colname</var>]</code> <strong class="def-name">=</strong> <code class="def-code-arguments">getColName(<var class="var">file</var>, <var class="var">template</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-_003d-33"><span class="category-def">: </span><code class="def-type">[<var class="var">colnum</var>,<var class="var">colname</var>]</code> <strong class="def-name">=</strong> <code class="def-code-arguments">getColName(<var class="var">file</var>, <var class="var">template</var>, <var class="var">casesens</var>)</code></dt>
<dd><p>Get column name.
</p>
<p>This is the equivalent of the cfitsio fits_get_colname function.
</p>
<h4 class="subsubheading" id="Inputs-60">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">template</var> - template string for matching column name.
</p>
<p><var class="var">casesens</var> - boolean whether to be case sensitive in match.
</p>
<h4 class="subsubheading" id="Outputs-60">Outputs</h4>
<p><var class="var">colnum</var> - column number of match.
</p>
<p><var class="var">colname</var> - column name of match.
</p>
<h4 class="subsubheading" id="Examples-14">Examples</h4>
<div class="example">
<pre class="example-preformatted"> import_fits;
 filename = file_in_loadpath(&quot;demos/tst0012.fits&quot;);
 fd = fits.openFile(filename);
 fits.movAbsHDU(fd,2);
 [colnum, colname] = fits.getColName(fd,&quot;C*&quot;);
 # returned 3, &quot;COUNTS&quot;
 fits.closeFile(fd);
</pre></div>
</dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetColType">
<h4 class="subsubsection">3.2.7.7 matlab.io.fits.getColType</h4>
<a class="index-entry-id" id="index-getColType"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-34"><span class="category-def">: </span><code class="def-type">[<var class="var">dtype</var>,<var class="var">repeat</var>,<var class="var">width</var>]</code> <strong class="def-name">=</strong> <code class="def-code-arguments">getColType(<var class="var">file</var>, <var class="var">colnum</var>)</code></dt>
<dd><p>Get column type.
</p>
<p>This is the equivalent of the cfitsio  fits_get_coltypell function.
</p>
<h4 class="subsubheading" id="Inputs-61">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">colnum</var> - Column to delete from current table.
</p>
<h4 class="subsubheading" id="Outputs-61">Outputs</h4>
<p><var class="var">dtype</var>,<var class="var">repeat</var>,<var class="var">width</var> - column information.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetEqColType">
<h4 class="subsubsection">3.2.7.8 matlab.io.fits.getEqColType</h4>
<a class="index-entry-id" id="index-getEqColType"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-35"><span class="category-def">: </span><code class="def-type">[<var class="var">dtype</var>,<var class="var">repeat</var>,<var class="var">width</var>]</code> <strong class="def-name">=</strong> <code class="def-code-arguments">getEqColType(<var class="var">file</var>, <var class="var">colnum</var>)</code></dt>
<dd><p>Get column type.
</p>
<p>This is the equivalent of the cfitsio  fits_get_eqcoltypell function.
</p>
<h4 class="subsubheading" id="Inputs-62">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">colnum</var> - Column number.
</p>
<h4 class="subsubheading" id="Outputs-62">Outputs</h4>
<p><var class="var">dtype</var>,<var class="var">repeat</var>,<var class="var">width</var> - column type
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetNumCols">
<h4 class="subsubsection">3.2.7.9 matlab.io.fits.getNumCols</h4>
<a class="index-entry-id" id="index-getNumCols"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-36"><span class="category-def">: </span><code class="def-type"><var class="var">ncols</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">getNumCols(<var class="var">file</var>)</code></dt>
<dd><p>Get number of columns.
</p>
<p>This is the equivalent of the cfitsio  fits_get_num_cols function.
</p>
<h4 class="subsubheading" id="Inputs-63">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-63">Outputs</h4>
<p><var class="var">ncols</var> - the number of columns in the table.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetNumRows">
<h4 class="subsubsection">3.2.7.10 matlab.io.fits.getNumRows</h4>
<a class="index-entry-id" id="index-getNumRows"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-37"><span class="category-def">: </span><code class="def-type"><var class="var">nrows</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">getNumRows(<var class="var">file</var>)</code></dt>
<dd><p>Get number of rows.
</p>
<p>This is the equivalent of the cfitsio fits_get_numrowsll function.
</p>
<h4 class="subsubheading" id="Inputs-64">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-64">Outputs</h4>
<p><var class="var">nrows</var> - the number of rows in in the current table.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002egetRowSize">
<h4 class="subsubsection">3.2.7.11 matlab.io.fits.getRowSize</h4>
<a class="index-entry-id" id="index-getRowSize"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-38"><span class="category-def">: </span><code class="def-type"><var class="var">nrows</var></code> <strong class="def-name">=</strong> <code class="def-code-arguments">getRowSize(<var class="var">file</var>)</code></dt>
<dd><p>Get optimum number of rows to read/write at one time.
</p>
<p>This is the equivalent of the cfitsio  fits_get_rowsize function.
</p>
<h4 class="subsubheading" id="Inputs-65">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-65">Outputs</h4>
<p><var class="var">nrows</var> - number of rows.
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002einsertATbl">
<h4 class="subsubsection">3.2.7.12 matlab.io.fits.insertATbl</h4>
<a class="index-entry-id" id="index-insertATbl"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-insertATbl_0028file_002c"><span class="category-def">: </span><strong class="def-name">insertATbl(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">rowlen</var>, <var class="var">nrows</var>, <var class="var">ttype</var>, <var class="var">tbcol</var>, <var class="var">tform</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-insertATbl_0028file_002c-1"><span class="category-def">: </span><strong class="def-name">insertATbl(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">rowlen</var>, <var class="var">nrows</var>, <var class="var">ttype</var>, <var class="var">tbcol</var>, <var class="var">tform</var>, <var class="var">tunit</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-insertATbl_0028file_002c-2"><span class="category-def">: </span><strong class="def-name">insertATbl(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">tbltype</var>, <var class="var">nrows</var>, <var class="var">ttype</var>, <var class="var">tbcol</var>, <var class="var">tform</var>, <var class="var">tunit</var>, <var class="var">extname</var>)</code></dt>
<dd><p>Insert a new ASCII table after current HDU.
</p>
<p>This is the equivalent of the cfitsio fits_insert_atbl function.
</p>
<h4 class="subsubheading" id="Inputs-66">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">rowlen</var> - row length. If set to 0, the function will calculate size based on
 tbcol and ttype.
</p>
<p><var class="var">nrows</var> - initial number of rows (normally 0)
</p>
<p><var class="var">ttype</var> - cell array of column type
</p>
<p><var class="var">tbcol</var> - array containing the start indices for each column.
</p>
<p><var class="var">tform</var> - cell array of column format
</p>
<p><var class="var">tunit</var> - cell array of column units
</p>
<p><var class="var">extname</var> - optional extension name
</p>
<h4 class="subsubheading" id="Outputs-66">Outputs</h4>
<p>None
</p>
</dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002einsertBTbl">
<h4 class="subsubsection">3.2.7.13 matlab.io.fits.insertBTbl</h4>
<a class="index-entry-id" id="index-insertBTbl"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-insertBTbl_0028file_002c"><span class="category-def">: </span><strong class="def-name">insertBTbl(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">nrows</var>, <var class="var">ttype</var>, <var class="var">tform</var>, <var class="var">tunit</var>, <var class="var">extname</var>, <var class="var">pcount</var>)</code></dt>
<dd><p>Insert a new bintable extension.
</p>
<p>This is the equivalent of the cfitsio fits_insert_btbl function.
</p>
<h4 class="subsubheading" id="Inputs-67">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">nrows</var> - initial number of rows (normally 0)
</p>
<p><var class="var">ttype</var> - cell array of column type
</p>
<p><var class="var">tform</var> - cell array of column format
</p>
<p><var class="var">tunit</var> - cell array of column units
</p>
<p><var class="var">extname</var> - optional extension name
</p>
<p><var class="var">pcount</var> - heap size.
</p>
<p><var class="var">ttype</var>, <var class="var">tform</var>, <var class="var">tunit</var> are expected to be the same size.
</p>
<h4 class="subsubheading" id="Outputs-67">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002einsertCol">
<h4 class="subsubsection">3.2.7.14 matlab.io.fits.insertCol</h4>
<a class="index-entry-id" id="index-insertCol"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-insertCol_0028file_002c"><span class="category-def">: </span><strong class="def-name">insertCol(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">colnum</var>, <var class="var">ttype</var>, <var class="var">tform</var>)</code></dt>
<dd><p>Insert a column into a table.
</p>
<p>This is the equivalent of the cfitsio fits_insert_col function.
</p>
<h4 class="subsubheading" id="Inputs-68">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">colnum</var> - Column to delete from current table.
</p>
<p><var class="var">ttype</var>, <var class="var">tform</var> - column type to insert
</p>
<h4 class="subsubheading" id="Outputs-68">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002einsertRows">
<h4 class="subsubsection">3.2.7.15 matlab.io.fits.insertRows</h4>
<a class="index-entry-id" id="index-insertRows"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-insertRows_0028file_002c"><span class="category-def">: </span><strong class="def-name">insertRows(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">firstrow</var>, <var class="var">numrows</var>)</code></dt>
<dd><p>Insert rows into a table.
</p>
<p>This is the equivalent of the cfitsio fits_insert_rows function.
</p>
<h4 class="subsubheading" id="Inputs-69">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">firstrow</var> - Start row to insert from.
</p>
<p><var class="var">numrows</var> - Number of rows to add.
</p>
<h4 class="subsubheading" id="Outputs-69">Outputs</h4>
<p>None
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ereadATblHdr">
<h4 class="subsubsection">3.2.7.16 matlab.io.fits.readATblHdr</h4>
<a class="index-entry-id" id="index-readATblHdr"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-39"><span class="category-def">: </span><code class="def-type">[<var class="var">rowlen</var>,<var class="var">nrows</var>,<var class="var">ttype</var>,<var class="var">tbcol</var>,<var class="var">tform</var>,<var class="var">tunit</var>,<var class="var">extname</var>]</code> <strong class="def-name">=</strong> <code class="def-code-arguments">readATblHdr(<var class="var">file</var>)</code></dt>
<dd><p>Get ASCII table parameters.
</p>
<p>This is the equivalent of the cfitsio  fits_read_atablhdrll function.
</p>
<h4 class="subsubheading" id="Inputs-70">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-70">Outputs</h4>
<p><var class="var">rowlen</var>,<var class="var">nrows</var>,<var class="var">ttype</var>,<var class="var">tbcol</var>,<var class="var">tform</var>,<var class="var">tunit</var>,<var class="var">extname</var> - table properties
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ereadBTblHdr">
<h4 class="subsubsection">3.2.7.17 matlab.io.fits.readBTblHdr</h4>
<a class="index-entry-id" id="index-readBTblHdr"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-40"><span class="category-def">: </span><code class="def-type">[<var class="var">nrows</var>,<var class="var">ttype</var>,<var class="var">tform</var>,<var class="var">tunit</var>,<var class="var">extname</var>,<var class="var">pcount</var>]</code> <strong class="def-name">=</strong> <code class="def-code-arguments">readBTblHdr(<var class="var">file</var>)</code></dt>
<dd><p>Get Binary table parameters.
</p>
<p>This is the equivalent of the cfitsio  fits_read_btablhdrll function.
</p>
<h4 class="subsubheading" id="Inputs-71">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<h4 class="subsubheading" id="Outputs-71">Outputs</h4>
<p><var class="var">nrows</var>,<var class="var">ttype</var>,<var class="var">tform</var>,<var class="var">tunit</var>,<var class="var">extname</var>,<var class="var">pcount</var>] - table properties
</p></dd></dl>
</div>
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ereadCol">
<h4 class="subsubsection">3.2.7.18 matlab.io.fits.readCol</h4>
<a class="index-entry-id" id="index-readCol"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-_003d-41"><span class="category-def">: </span><code class="def-type">[<var class="var">coldata</var>, <var class="var">nullval</var>]</code> <strong class="def-name">=</strong> <code class="def-code-arguments">readCol(<var class="var">file</var>, <var class="var">colnum</var>)</code></dt>
<dt class="deftypefnx def-cmd-deftypefn def-line" id="index-_003d-42"><span class="category-def">: </span><code class="def-type">[<var class="var">coldata</var>, <var class="var">nullval</var>]</code> <strong class="def-name">=</strong> <code class="def-code-arguments">readCol(<var class="var">file</var>, <var class="var">colnum</var>, <var class="var">firstrow</var>, <var class="var">numrows</var>)</code></dt>
<dd><p>Get table row data.
</p>
<p>This is the equivalent of the cfitsio  fits_read_col function.
</p>
<h4 class="subsubheading" id="Inputs-72">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">firstrow</var> - Start row
</p>
<p><var class="var">numrows</var> - Number of rows to read
</p>
<h4 class="subsubheading" id="Outputs-72">Outputs</h4>
<p><var class="var">coldata</var> - the column data rows
</p>
<p><var class="var">nulldata</var> - the null value flags
</p><h4 class="subsubheading" id="Examples-15">Examples</h4>
<div class="example">
<pre class="example-preformatted"> import_fits;
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
<div class="subsubsection-level-extent" id="matlab_002eio_002efits_002ewriteCol">
<h4 class="subsubsection">3.2.7.19 matlab.io.fits.writeCol</h4>
<a class="index-entry-id" id="index-writeCol"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-writeCol_0028file_002c"><span class="category-def">: </span><strong class="def-name">writeCol(<var class="var">file</var>,</strong> <code class="def-code-arguments"><var class="var">colnum</var>, <var class="var">firstrow</var>, <var class="var">data</var>)</code></dt>
<dd><p>Write elements to a table.
</p>
<p>This is the equivalent of the cfitsio fits_write_col function.
</p>
<h4 class="subsubheading" id="Inputs-73">Inputs</h4>
<p><var class="var">file</var> - opened fits file.
</p>
<p><var class="var">colnum</var> - column number.
</p>
<p><var class="var">firstrow</var> - first row number.
</p>
<p><var class="var">data</var> - data to write to column
</p>
<h4 class="subsubheading" id="Outputs-73">Outputs</h4>
<p>None
</p></dd></dl>
<hr>
</div>
</div>
<div class="subsection-level-extent" id="Low-Level-Functions-_002d-Import-functions">
<h4 class="subsection" id="Import-functions">3.2.8 Import functions</h4>
<a class="index-entry-id" id="index-Low-Level-Functions-_002d-Import-functions"></a>
<div class="subsubsection-level-extent" id="import_005ffits">
<h4 class="subsubsection">3.2.8.1 import_fits</h4>
<a class="index-entry-id" id="index-import_005ffits"></a>
<dl class="first-deftypefn def-block">
<dt class="deftypefn def-line" id="index-import_005ffits-1"><span class="category-def">: </span><strong class="def-name">import_fits</strong></dt>
<dd><p>Import the fits functions into a fits.xxxxx variable, to emulate importing the fits namespace.
</p></dd></dl>
<hr>
</div>
</div>
</div>
</div>
<div class="appendix-level-extent" id="Copying">
<h2 class="appendix" id="GNU-General-Public-License">Appendix A GNU General Public License</h2>
<a class="index-entry-id" id="index-warranty"></a>
<a class="index-entry-id" id="index-copyright"></a>
<div class="center">Version 3, 29 June 2007
</div>
<div class="display">
<pre class="display-preformatted">Copyright &copy; 2007 Free Software Foundation, Inc. <a class="url" href="http://fsf.org/">http://fsf.org/</a>
Everyone is permitted to copy and distribute verbatim copies of this
license document, but changing it is not allowed.
</pre></div>
<h3 class="heading" id="Preamble">Preamble</h3>
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
<h3 class="heading" id="TERMS-AND-CONDITIONS">TERMS AND CONDITIONS</h3>
<ol class="enumerate" start="0">
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
<ol class="enumerate" type="a" start="1">
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
<ol class="enumerate" type="a" start="1">
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
<ol class="enumerate" type="a" start="1">
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
<h3 class="heading" id="END-OF-TERMS-AND-CONDITIONS">END OF TERMS AND CONDITIONS</h3>
<h3 class="heading" id="How-to-Apply-These-Terms-to-Your-New-Programs">How to Apply These Terms to Your New Programs</h3>
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
<div class="example smallexample">
<pre class="example-preformatted"><var class="var">one line to give the program's name and a brief idea of what it does.</var>  
Copyright (C) <var class="var">year</var> <var class="var">name of author</var>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <a class="url" href="http://www.gnu.org/licenses/">http://www.gnu.org/licenses/</a>.
</pre></div>
<p>Also add information on how to contact you by electronic and paper mail.
</p>
<p>If the program does terminal interaction, make it output a short
notice like this when it starts in an interactive mode:
</p>
<div class="example smallexample">
<pre class="example-preformatted"><var class="var">program</var> Copyright (C) <var class="var">year</var> <var class="var">name of author</var> 
This program comes with ABSOLUTELY NO WARRANTY; for details type &lsquo;<samp class="samp">show w</samp>&rsquo;.
This is free software, and you are welcome to redistribute it
under certain conditions; type &lsquo;<samp class="samp">show c</samp>&rsquo; for details.
</pre></div>
<p>The hypothetical commands &lsquo;<samp class="samp">show w</samp>&rsquo; and &lsquo;<samp class="samp">show c</samp>&rsquo; should show
the appropriate parts of the General Public License.  Of course, your
program&rsquo;s commands might be different; for a GUI interface, you would
use an &ldquo;about box&rdquo;.
</p>
<p>You should also get your employer (if you work as a programmer) or school,
if any, to sign a &ldquo;copyright disclaimer&rdquo; for the program, if necessary.
For more information on this, and how to apply and follow the GNU GPL, see
<a class="url" href="http://www.gnu.org/licenses/">http://www.gnu.org/licenses/</a>.
</p>
<p>The GNU General Public License does not permit incorporating your
program into proprietary programs.  If your program is a subroutine
library, you may consider it more useful to permit linking proprietary
applications with the library.  If this is what you want to do, use
the GNU Lesser General Public License instead of this License.  But
first, please read <a class="url" href="http://www.gnu.org/philosophy/why-not-lgpl.html">http://www.gnu.org/philosophy/why-not-lgpl.html</a>.
</p>
<hr>
</div>
<div class="unnumbered-level-extent" id="Index">
<h2 class="unnumbered" id="Index-1">Index</h2>
 
<div class="printindex cp-printindex">
<table class="cp-letters-header-printindex"><tr><th>Jump to: &nbsp; </th><td><a class="summary-letter-printindex" href="#Index_cp_letter-B"><b>B</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-C"><b>C</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-D"><b>D</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-F"><b>F</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-G"><b>G</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-H"><b>H</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-I"><b>I</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-L"><b>L</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-M"><b>M</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-O"><b>O</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-R"><b>R</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-S"><b>S</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-U"><b>U</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-W"><b>W</b></a>
 &nbsp; 
</td></tr></table>
<table class="cp-entries-printindex">
<tr><td></td><th class="entries-header-printindex">Index Entry</th><th class="sections-header-printindex">Section</th></tr>
<tr><td colspan="3"><hr></td></tr>
<tr><th id="Index_cp_letter-B">B</th></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Basic-Usage-Overview">Basic Usage Overview</a></td><td class="printindex-index-section"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td colspan="3"><hr></td></tr>
<tr><th id="Index_cp_letter-C">C</th></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-closeFile">closeFile</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-File-Functions">Low Level Functions - File Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-copyHDU">copyHDU</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-HDU-Functions">Low Level Functions - HDU Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-copyright">copyright</a></td><td class="printindex-index-section"><a href="#Copying">Copying</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-createFile">createFile</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-File-Functions">Low Level Functions - File Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-createImg">createImg</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Image-Manipulation">Low Level Functions - Image Manipulation</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-createTbl">createTbl</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td colspan="3"><hr></td></tr>
<tr><th id="Index_cp_letter-D">D</th></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-deleteCol">deleteCol</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-deleteFile">deleteFile</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-File-Functions">Low Level Functions - File Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-deleteHDU">deleteHDU</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-HDU-Functions">Low Level Functions - HDU Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-deleteKey">deleteKey</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-deleteRecord">deleteRecord</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-deleteRows">deleteRows</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td colspan="3"><hr></td></tr>
<tr><th id="Index_cp_letter-F">F</th></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-fileMode">fileMode</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-File-Functions">Low Level Functions - File Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-fileName">fileName</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-File-Functions">Low Level Functions - File Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-fitsdisp">fitsdisp</a></td><td class="printindex-index-section"><a href="#High-Level-File-Functions">High Level File Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-fitsinfo">fitsinfo</a></td><td class="printindex-index-section"><a href="#High-Level-File-Functions">High Level File Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-fitsread">fitsread</a></td><td class="printindex-index-section"><a href="#High-Level-File-Functions">High Level File Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-fitswrite">fitswrite</a></td><td class="printindex-index-section"><a href="#High-Level-File-Functions">High Level File Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Function-Reference">Function Reference</a></td><td class="printindex-index-section"><a href="#Function-Reference">Function Reference</a></td></tr>
<tr><td colspan="3"><hr></td></tr>
<tr><th id="Index_cp_letter-G">G</th></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getAColParms">getAColParms</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getBColParms">getBColParms</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getColName">getColName</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getColType">getColType</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getConstantNames">getConstantNames</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Utility-Functions">Low Level Functions - Utility Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getConstantValue">getConstantValue</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Utility-Functions">Low Level Functions - Utility Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getEqColType">getEqColType</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getHdrSpace">getHdrSpace</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getHDUnum">getHDUnum</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-HDU-Functions">Low Level Functions - HDU Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getHDUoff">getHDUoff</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-HDU-Functions">Low Level Functions - HDU Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getHDUtype">getHDUtype</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-HDU-Functions">Low Level Functions - HDU Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getImgSize">getImgSize</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Image-Manipulation">Low Level Functions - Image Manipulation</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getImgType">getImgType</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Image-Manipulation">Low Level Functions - Image Manipulation</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getNumCols">getNumCols</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getNumHDUs">getNumHDUs</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-HDU-Functions">Low Level Functions - HDU Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getNumRows">getNumRows</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getOpenFiles">getOpenFiles</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Utility-Functions">Low Level Functions - Utility Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getRowSize">getRowSize</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-getVersion">getVersion</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Utility-Functions">Low Level Functions - Utility Functions</a></td></tr>
<tr><td colspan="3"><hr></td></tr>
<tr><th id="Index_cp_letter-H">H</th></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-High-Level-File-Functions">High Level File Functions</a></td><td class="printindex-index-section"><a href="#High-Level-File-Functions">High Level File Functions</a></td></tr>
<tr><td colspan="3"><hr></td></tr>
<tr><th id="Index_cp_letter-I">I</th></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-imgCompress">imgCompress</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Compression-Functions">Low Level Functions - Compression Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-import_005ffits">import_fits</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Import-functions">Low Level Functions - Import functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-insertATbl">insertATbl</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-insertBTbl">insertBTbl</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-insertCol">insertCol</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-insertImg">insertImg</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Image-Manipulation">Low Level Functions - Image Manipulation</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-insertRows">insertRows</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Installing-and-loading">Installing and loading</a></td><td class="printindex-index-section"><a href="#Installing-and-loading">Installing and loading</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-isCompressedImg">isCompressedImg</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Compression-Functions">Low Level Functions - Compression Functions</a></td></tr>
<tr><td colspan="3"><hr></td></tr>
<tr><th id="Index_cp_letter-L">L</th></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Loading">Loading</a></td><td class="printindex-index-section"><a href="#Installing-and-loading">Installing and loading</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Low-level-functionality">Low level functionality</a></td><td class="printindex-index-section"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Low-Level-Functions">Low Level Functions</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions">Low Level Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Low-Level-Functions-_002d-Compression-Functions">Low Level Functions - Compression Functions</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Compression-Functions">Low Level Functions - Compression Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Low-Level-Functions-_002d-File-Functions">Low Level Functions - File Functions</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-File-Functions">Low Level Functions - File Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Low-Level-Functions-_002d-HDU-Functions">Low Level Functions - HDU Functions</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-HDU-Functions">Low Level Functions - HDU Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Low-Level-Functions-_002d-Image-Manipulation">Low Level Functions - Image Manipulation</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Image-Manipulation">Low Level Functions - Image Manipulation</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Low-Level-Functions-_002d-Import-functions">Low Level Functions - Import functions</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Import-functions">Low Level Functions - Import functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Low-Level-Functions-_002d-Utility-Functions">Low Level Functions - Utility Functions</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Utility-Functions">Low Level Functions - Utility Functions</a></td></tr>
<tr><td colspan="3"><hr></td></tr>
<tr><th id="Index_cp_letter-M">M</th></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-movAbsHDU">movAbsHDU</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-HDU-Functions">Low Level Functions - HDU Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-movNamHDU">movNamHDU</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-HDU-Functions">Low Level Functions - HDU Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-movRelHDU">movRelHDU</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-HDU-Functions">Low Level Functions - HDU Functions</a></td></tr>
<tr><td colspan="3"><hr></td></tr>
<tr><th id="Index_cp_letter-O">O</th></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Off_002dline-install">Off-line install</a></td><td class="printindex-index-section"><a href="#Installing-and-loading">Installing and loading</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Online-install">Online install</a></td><td class="printindex-index-section"><a href="#Installing-and-loading">Installing and loading</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-openDiskFile">openDiskFile</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-File-Functions">Low Level Functions - File Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-openFile">openFile</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-File-Functions">Low Level Functions - File Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Overview">Overview</a></td><td class="printindex-index-section"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td colspan="3"><hr></td></tr>
<tr><th id="Index_cp_letter-R">R</th></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-readATblHdr">readATblHdr</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-readBTblHdr">readBTblHdr</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-readCard">readCard</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-readCol">readCol</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-readImg">readImg</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Image-Manipulation">Low Level Functions - Image Manipulation</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Reading-Data">Reading Data</a></td><td class="printindex-index-section"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Reading-Information">Reading Information</a></td><td class="printindex-index-section"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-readKey">readKey</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-readKeyCmplx">readKeyCmplx</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-readKeyDbl">readKeyDbl</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-readKeyLongLong">readKeyLongLong</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-readKeyLongStr">readKeyLongStr</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-readKeyUnit">readKeyUnit</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-readRecord">readRecord</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td colspan="3"><hr></td></tr>
<tr><th id="Index_cp_letter-S">S</th></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-setBscale">setBscale</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Image-Manipulation">Low Level Functions - Image Manipulation</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-setCompressionType">setCompressionType</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Compression-Functions">Low Level Functions - Compression Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-setHCompScale">setHCompScale</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Compression-Functions">Low Level Functions - Compression Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-setHCompSmooth">setHCompSmooth</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Compression-Functions">Low Level Functions - Compression Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-setTileDim">setTileDim</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Compression-Functions">Low Level Functions - Compression Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-setTscale">setTscale</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Image-Manipulation">Low Level Functions - Image Manipulation</a></td></tr>
<tr><td colspan="3"><hr></td></tr>
<tr><th id="Index_cp_letter-U">U</th></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Using-the-toolkit">Using the toolkit</a></td><td class="printindex-index-section"><a href="#Basic-Usage-Overview">Basic Usage Overview</a></td></tr>
<tr><td colspan="3"><hr></td></tr>
<tr><th id="Index_cp_letter-W">W</th></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-warranty">warranty</a></td><td class="printindex-index-section"><a href="#Copying">Copying</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-Windows-install">Windows install</a></td><td class="printindex-index-section"><a href="#Installing-and-loading">Installing and loading</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-writeChecksum">writeChecksum</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-HDU-Functions">Low Level Functions - HDU Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-writeCol">writeCol</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Binary-and-ASCII-Tables">Low Level Functions - Binary and ASCII Tables</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-writeComment">writeComment</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-writeDate">writeDate</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-writeHistory">writeHistory</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-writeImg">writeImg</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Image-Manipulation">Low Level Functions - Image Manipulation</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-writeKey">writeKey</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td></td><td class="printindex-index-entry"><a href="#index-writeKeyUnit">writeKeyUnit</a></td><td class="printindex-index-section"><a href="#Low-Level-Functions-_002d-Keyword-Functions">Low Level Functions - Keyword Functions</a></td></tr>
<tr><td colspan="3"><hr></td></tr>
</table>
<table class="cp-letters-footer-printindex"><tr><th>Jump to: &nbsp; </th><td><a class="summary-letter-printindex" href="#Index_cp_letter-B"><b>B</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-C"><b>C</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-D"><b>D</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-F"><b>F</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-G"><b>G</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-H"><b>H</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-I"><b>I</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-L"><b>L</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-M"><b>M</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-O"><b>O</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-R"><b>R</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-S"><b>S</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-U"><b>U</b></a>
 &nbsp; 
<a class="summary-letter-printindex" href="#Index_cp_letter-W"><b>W</b></a>
 &nbsp; 
</td></tr></table>
</div>
 
</div>
</div>
