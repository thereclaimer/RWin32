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
@set path_include_vcpkg=    vcpkg_installed\x64-windows\include
@set path_libpath_vcpkg=    vcpkg_installed\x64-windows\lib

::----------------------------------------------------------------
:: DEPENDENCIES
::----------------------------------------------------------------

if not exist %path_bin_r_win32% (
    mkdir %path_bin_r_win32%
)

if not exist %path_include_vcpkg% (
    call vcpkg install
)

::----------------------------------------------------------------
:: ARGUMENTS
::----------------------------------------------------------------

@set cl_flags=        /Zi

@set cl_output=       /Fe:%path_bin_r_win32%\RWin32Test.exe ^
                      /Fo:%path_bin_r_win32%\RWin32Test.obj ^
                      /Fd:%path_bin_r_win32%\RWin32Test.pdb

@set cl_includes=     /I src                     ^
                      /I include                 ^
                      /I internal                ^
                      /I test                    ^
                      /I %path_include_r_common% ^
                      /I %path_include_vcpkg%

@set cl_source=       test\r-win32-test.cpp

@set cl_link=         /link                  ^
                      /LIBPATH:bin\debug-x64 ^
                      /LIBPATH:vcpkg_installed\x64-windows\lib

@set cl_libs=         RWin32.lib   ^
                      user32.lib   ^
                      opengl32.lib ^
                      glew32.lib   ^
                      gdi32.lib    ^
                      imgui.lib    ^
                      Xinput.lib   

::----------------------------------------------------------------
:: COMPILE
::----------------------------------------------------------------

call cl.exe       ^
    %cl_flags%    ^
    %cl_output%   ^
    %cl_includes% ^
    %cl_source%   ^
    %cl_link%     ^
    %cl_libs%

::----------------------------------------------------------------
:: END
::----------------------------------------------------------------

popd