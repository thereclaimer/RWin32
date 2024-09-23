#pragma once

#include "r-win32-internal-context.hpp"

r_external const r_b8
r_win32::context_create(
    RWin32MainArgs& r_win32_args) {

    r_b8 result = true;

    //get the current system time
    FILETIME system_time_as_file_time;
    GetSystemTimeAsFileTime(&system_time_as_file_time);

    //convert the system time to milliseconds
    const r_timems time_initialized = 
        ((r_timems)system_time_as_file_time.dwLowDateTime + 
        ((r_timems)(system_time_as_file_time.dwHighDateTime) << 32LL)) / 10000;

    _r_win32_context.system_time_initialized = time_initialized;

    result &= r_win32_internal::memory_create();

    return(result);
}

r_external const r_b8 
r_win32::context_destroy(
    r_void) {

    r_b8 result = true;

    result &= r_win32_internal::memory_destroy();

    return(result);
}