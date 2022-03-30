function fits = __get_fits_imports__ ()
  fits = {};
  pkg_dir = fileparts (fullfile (mfilename ("fullpath")));
  x = fileparts(pkg_dir);
  x = fullfile(x, "+matlab/+io/+fits");
  #x = file_in_loadpath ("+matlab/+io/+fits/readCol.m")
  #x = fileparts(x)
  files = dir (fullfile(x, "*.m"));
  for x = 1:length(files)
    [~,f,~] = fileparts(files(x).name);
    fits.(f) = str2func(["matlab.io.fits." f]);
  endfor
endfunction
