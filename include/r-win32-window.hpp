#ifndef R_WIN32_WINDOW_HPP
#define R_WIN32_WINDOW_HPP

#include <Windows.h>
#include <r-common.hpp>

struct RWin32WindowDimensions {
    const r_u32 position_x;
    const r_u32 position_y;
    const r_u32 width;
    const r_u32 height;    
};

enum RWin32WindowRenderingContextType_ {
     RWin32WindowRenderingContextType_None     = 0,
     RWin32WindowRenderingContextType_OpenGL   = 1,
     RWin32WindowRenderingContextType_Direct3D = 2
};

enum RWin32WindowUseImGui_ {
     RWin32WindowUseImGui_Yes,
     RWin32WindowUseImGui_No
};

typedef r_u32 RWin32WindowRenderingContextType;
typedef r_u32 RWin32WindowUseImGui;

namespace r_win32 {

    r_external const r_b8
    window_create(
        const r_cstr                           title,
        const r_u32                            position_x,
        const r_u32                            position_y,
        const r_u32                            width,
        const r_u32                            height,
        const RWin32WindowRenderingContextType rendering_context,
        const RWin32WindowUseImGui             use_imgui);

    r_external const r_b8
    window_create_centered(
        const r_cstr                           title,
        const r_u32                            width,
        const r_u32                            height,
        const RWin32WindowRenderingContextType rendering_context,
        const RWin32WindowUseImGui             use_imgui);

    r_external const r_b8 window_show(r_b8);
    r_external const r_b8 window_hide(r_b8);

    r_external r_void window_dimensions(RWin32WindowDimensions& dimensions);
    
    r_external const r_b8 window_frame_start      (r_void);
    r_external const r_b8 window_frame_render     (r_void);
    r_external const r_64 window_frame_delta_time (r_void);
};

#endif //R_WIN32_WINDOW_HPP