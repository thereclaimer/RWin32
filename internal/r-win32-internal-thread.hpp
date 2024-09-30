#ifndef R_WIN32_INTERNAL_THREAD_HPP
#define R_WIN32_INTERNAL_THREAD_HPP

#include "r-win32.hpp"

struct RWin32Thread {
    DWORD                          thread_id;
    DWORD                          processor_core_id;
    r_win32_funcptr_thread_routine routine;
    r_memory                       data;
};


#endif //R_WIN32_INTERNAL_THREAD_HPP