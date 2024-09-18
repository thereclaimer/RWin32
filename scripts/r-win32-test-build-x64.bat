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

@set cl_flags=        /Zi

@set cl_output=       /Fe:%path_bin_r_win32%\RWin32Test.exe ^
                      /Fo:%path_bin_r_win32%\RWin32Test.obj ^
                      /Fd:%path_bin_r_win32%\RWin32Test.pdb


@set cl_includes=     /I src                ^
                      /I include            ^
                      /I internal           ^
                      /I test               ^
                      /I %path_include_r_common%

@set cl_source=       test\r-win32-test.cpp

@set cl_link=         /link                  ^
                      /LIBPATH:bin\debug-x64 ^
                      user32.lib             ^
                      RWin32.lib             ^
                      advapi32.lib           ^
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
:: END
::----------------------------------------------------------------

popd