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
## @deftypefn {} {} fits_is_file(@var{filename})
## Private function
## @end deftypefn
function yes = fits_is_file (filename)
  yes = false;
  if exist("isfile") == 2
    yes = isfile(filename);
  else
    [info, err] = stat (filename);
    yes = (! err && S_ISREG (info.mode));
  endif
endfunction
 
