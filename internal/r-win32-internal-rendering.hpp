#ifndef R_WIN32_INTERNAL_RENDERING_CONTEXT_HPP
#define R_WIN32_INTERNAL_RENDERING_CONTEXT_HPP

#include <Windows.h>
#include <r-common.hpp>

struct RWin32RenderingViewport {
    r_u32 position_x;
    r_u32 position_y;
    r_u32 width;
    r_u32 height;
};

struct RWin32RenderingContextOpenGL {
    HDC                     device_context;
    HGLRC                   gl_rendering_context;
    RWin32RenderingViewport viewport;
};

struct RWin32RenderingContextDX3D {
    //TODO
    RWin32RenderingViewport viewport;
};




#endif //R_WIN32_INTERNAL_RENDERING_CONTEXT_HPP