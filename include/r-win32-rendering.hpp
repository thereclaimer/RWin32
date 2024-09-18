#ifndef R_WIN32_RENDERING_HPP
#define R_WIN32_RENDERING_HPP

#include <r-common.hpp>

enum RWin32RenderingContextType_ {
     RWin32RenderingContextType_None     = 0,
     RWin32RenderingContextType_OpenGL   = 1,
     RWin32RenderingContextType_Direct3D = 2
};

typedef r_u32 RWin32RenderingContextType;

#endif //R_WIN32_RENDERING_HPP