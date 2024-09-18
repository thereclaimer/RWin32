#pragma once

#include "r-win32-internal.hpp"

r_external const r_u64 
r_win32::system_ticks(
    r_void) {

    LARGE_INTEGER win32_large_int = {0};
    QueryPerformanceCounter(&win32_large_int);

    const r_u64 ticks = win32_large_int.QuadPart;

    return(ticks);
}

r_external const r_u64 
r_win32::system_frequency(
    r_void) {

    //get system frequency (Hz)
    LARGE_INTEGER win32_large_int = {0};
    QueryPerformanceFrequency(&win32_large_int);

    const r_u64 frequency = win32_large_int.QuadPart;

    return(frequency);
}

r_external const r_u64 
r_win32::system_process_id(
    r_void) {

    const r_u64 process_id = GetCurrentProcessId();

    return(process_id);
}

r_external const r_u64 
r_win32::system_thread_id(
    r_void) {

    const r_u64 thread_id = GetCurrentThreadId();

    return(thread_id);
}

r_external void
r_win32::system_sleep(
    const r_timems milliseconds) {

    Sleep(milliseconds);
}
