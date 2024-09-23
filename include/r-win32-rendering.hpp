#ifndef R_WIN32_RENDERING_HPP
#define R_WIN32_RENDERING_HPP

#include <r-common.hpp>

enum RWin32RenderingContextType_ {
     RWin32RenderingContextType_None     = 0,
     RWin32RenderingContextType_OpenGL   = 1,
     RWin32RenderingContextType_Direct3D = 2
};

typedef r_u32 RWin32RenderingContextType;


struct RWin32RenderingViewport {
    r_u32 position_x;
    r_u32 position_y;
    r_u32 width;
    r_u32 height;
};

struct RWin32RenderingContextOpenGL {
    HDC   device_context;
    HGLRC gl_rendering_context;
};

struct RWin32RenderingContextDX3D {
    //TODO

};

struct RWin32RenderingContext {
    RWin32RenderingContextType type;
    RWin32RenderingViewport    viewport;
    union {
        RWin32RenderingContextOpenGL opengl;
        RWin32RenderingContextDX3D   dx3d;
    };
};


#endif //R_WIN32_RENDERING_HPP