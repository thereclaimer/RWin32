::----------------------------------------------------------------
:: START
::----------------------------------------------------------------

@echo off

pushd ..

::----------------------------------------------------------------
:: VARIABLES
::----------------------------------------------------------------

@set path_bin_r_win32=      bin\debug-x64
@set path_include_r_common= modules\r-common\include

if not exist %path_bin_r_win32% (
    mkdir %path_bin_r_win32%
)


::----------------------------------------------------------------
:: ARGUMENTS
::----------------------------------------------------------------

@set cl_flags=        /c  ^
                      /Zi

@set cl_output=       /Fo:%path_bin_r_win32%\RWin32.obj ^
                      /Fd:%path_bin_r_win32%\RWin32.pdb


@set cl_includes=     /I src                ^
                      /I include            ^
                      /I internal           ^
                      /I %path_include_r_common%

@set cl_source=       src\r-win32.cpp

@set cl_link=         /link        ^
                      user32.lib   ^
                      advapi32.lib ^
                      gdi32.lib

::----------------------------------------------------------------
:: COMPILE
::----------------------------------------------------------------

call cl.exe       ^
    %cl_flags%    ^
    %cl_output%   ^
    %cl_includes% ^
    %cl_source%   ^
    %cl_link%

::----------------------------------------------------------------
:: LINK
::----------------------------------------------------------------

call lib.exe /out:bin\debug-x64\RWin32.lib bin\debug-x64\RWin32.obj

::----------------------------------------------------------------
:: END
::----------------------------------------------------------------

popd