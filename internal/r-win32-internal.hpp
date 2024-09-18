#ifndef R_WIN32_INTERNAL_HPP
#define R_WIN32_INTERNAL_HPP

#include "r-win32.hpp"

struct Test {
    r_s32 x;
};

r_global Test y;

/**********************************************************************************/
/* RENDERING                                                                      */
/**********************************************************************************/

struct RWin32RenderingViewport {
    r_u32 position_x;
    r_u32 position_y;
    r_u32 width;
    r_u32 height;
};

struct RWin32RenderingContextOpenGL {
    HDC                     device_context;
    HGLRC                   gl_rendering_context;
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

/**********************************************************************************/
/* WINDOW                                                                         */
/**********************************************************************************/

struct RWin32Window {
    HWND                   window_handle;
    HDC                    device_context;
    RWin32WindowDimensions dimensions;
    RWin32RenderingContext rendering_context;
};


/**********************************************************************************/
/* MEMORY                                                                         */
/**********************************************************************************/

struct RWin32Memory {
    r_size page_size;
    r_size page_size_large;
    r_size allocation_granularity;
    r_b32  large_pages_enabled;
};

namespace r_win32_internal {

    r_internal const r_b8 memory_create  (r_void);
    r_internal const r_b8 memory_destroy (r_void);
    

};

/**********************************************************************************/
/* CONTEXT                                                                        */
/**********************************************************************************/

struct RWin32Context {
    RWin32Memory memory;
    RWin32Window window;
};

r_global RWin32Context _r_win32_context;

namespace r_win32_internal {

    inline RWin32Memory& context_memory(r_void) { return(_r_win32_context.memory); }
    inline RWin32Window& context_window(r_void) { return(_r_win32_context.window); }

    inline const r_size memory_get_page_size              (void) { return(_r_win32_context.memory.page_size);              }
    inline const r_size memory_get_page_size_large        (void) { return(_r_win32_context.memory.page_size_large);        }
    inline const r_size memory_get_allocation_granularity (void) { return(_r_win32_context.memory.allocation_granularity); }
    inline const r_size memory_get_large_pages_enabled    (void) { return(_r_win32_context.memory.large_pages_enabled);    }

};

#endif //R_WIN32_INTERNAL_HPP