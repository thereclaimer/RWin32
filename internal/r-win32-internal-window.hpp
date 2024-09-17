#ifndef R_WIN32_INTERNAL_WINDOW_HPP
#define R_WIN32_INTERNAL_WINDOW_HPP

#include "r-win32-window.hpp"

struct RWin32WindowRenderingContext {
    
};

struct RWin32Window {
    HWND window_handle;
    HDC  device_context;


};

#endif //R_WIN32_INTERNAL_WINDOW_HPP