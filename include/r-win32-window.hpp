#ifndef R_WIN32_WINDOW_HPP
#define R_WIN32_WINDOW_HPP

#include <Windows.h>
#include <r-common.hpp>

#include "r-win32-rendering.hpp"

struct RWin32WindowDimensions {
    const r_u32 position_x;
    const r_u32 position_y;
    const r_u32 width;
    const r_u32 height;    
};

enum RWin32WindowUseImGui_ {
     RWin32WindowUseImGui_Yes,
     RWin32WindowUseImGui_No
};

typedef r_u32 RWin32WindowUseImGui;

namespace r_win32 {

    r_external const r_b8
    window_create(
        const r_cstr                     title,
        const r_u32                      position_x,
        const r_u32                      position_y,
        const r_u32                      width,
        const r_u32                      height,
        const RColorFormat               color_format,
        const RWin32RenderingContextType rendering_context,
        const RWin32WindowUseImGui       use_imgui);

    r_external const r_b8
    window_create_centered(
        const r_cstr                     title,
        const r_u32                      width,
        const r_u32                      height,
        const RWin32RenderingContextType rendering_context,
        const RColorFormat               color_format,
        const RWin32WindowUseImGui       use_imgui);

    r_external const r_b8 window_show(r_b8);
    r_external const r_b8 window_hide(r_b8);

    r_external r_void window_dimensions(RWin32WindowDimensions& dimensions);
    
    r_external const r_b8  window_frame_start      (r_void);
    r_external const r_b8  window_frame_render     (r_void);
    r_external const r_u64 window_frame_delta_time (r_void);
};

#endif //R_WIN32_WINDOW_HPP