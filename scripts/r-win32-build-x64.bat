@echo off

pushd ..

@set r_win32_bin_dir= bin_x64_debug

if not exist %r_win32_bin_dir% (
    mkdir %r_win32_bin_dir%
)


@set cl_flags=        /MD                              ^
                      /Zi                              ^
                      /Fd:%r_win32_bin_dir%\RWin32.pdb ^
                      /Fo:%r_win32_bin_dir%\RWin32.obj

@set cl_includes=     /I src                      ^
                      /I internal                 ^
                      /I include                  ^
                      /I modules\r-common\include

@set cl_source=       /c src\r-win32.cpp

@set cl_linker=       /link

@set cl_libs=         user32.lib

call cl.exe           ^
    %cl_flags%        ^
    %cl_includes%     ^
    %cl_source%       ^
    %cl_linker%       ^
    %cl_libs%

call lib.exe /out:bin_x64_debug\RWin32.lib bin_x64_debug\RWin32.obj 

popd