#ifndef R_WIN32_CONTEXT_HPP
#define R_WIN32_CONTEXT_HPP

#include <r-common.hpp>

#include "r-win32-main.hpp"

namespace r_win32 {

    const r_b8 context_create  (RWin32MainArgs& r_win32_args);
    const r_b8 context_destroy (r_void);
};


#endif //R_WIN32_CONTEXT_HPP