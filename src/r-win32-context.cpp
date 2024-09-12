#pragma once

#include "r-win32-internal.hpp"

const r_b8
r_win32::context_create(
    r_void) {

    r_b8 result = true;

    result &= r_win32_internal::memory_create();

    return(result);
}

const r_b8 
r_win32::context_destroy(
    r_void) {

    r_b8 result = true;

    result &= r_win32_internal::memory_destroy();

    return(result);
}