## Copyright (C) 2022 John Donoghue <john.donoghue@ieee.org>
##
## This program is free software; you can redistribute it and/or modify it under
## the terms of the GNU General Public License as published by the Free Software
## Foundation; either version 3 of the License, or (at your option) any later
## version.
##
## This program is distributed in the hope that it will be useful, but WITHOUT
## ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
## FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
## details.
##
## You should have received a copy of the GNU General Public License along with
## this program; if not, see <http://www.gnu.org/licenses/>.

## -*- texinfo -*-
## @deftypefn {} {} __get_fits_imports__()
## Private function
## @end deftypefn
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
