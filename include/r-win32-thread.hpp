#ifndef R_WIN32_THREAD_HPP
#define R_WIN32_THREAD_HPP

#include <r-common.hpp>

typedef r_handle RWin32ThreadHandle;

typedef r_void* 
(*r_win32_funcptr_thread_routine)(
    r_memory thread_data);

namespace r_win32 {

    r_external RWin32ThreadHandle thread_create();

};

#endif //R_WIN32_THREAD_HPP