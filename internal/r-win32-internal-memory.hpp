#ifndef R_WIN32_INTERNAL_MEMORY_HPP
#define R_WIN32_INTERNAL_MEMORY_HPP

#include "r-win32.hpp"

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

#endif //R_WIN32_INTERNAL_MEMORY_HPP