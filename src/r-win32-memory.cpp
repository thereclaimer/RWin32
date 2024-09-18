#pragma once

#include "r-win32-internal.hpp"

/**********************************************************************************/
/* r_externalAL                                                                       */
/**********************************************************************************/

r_external const r_size
r_win32::memory_page_size(
    r_void) {

    const r_size page_size = r_win32_internal::memory_get_page_size();

    return(page_size);
}

r_external const r_size
r_win32::memory_large_page_size(
    r_void) {

    const r_size large_page_size = r_win32_internal::memory_get_page_size_large();

    return(large_page_size);
}

r_external const r_size
r_win32::memory_allocation_granularity(
    r_void) {

    const r_size granularity = r_win32_internal::memory_get_allocation_granularity();

    return(granularity);
}

r_external const r_b8
r_win32::memory_large_pages_enabled(
    r_void) {

    const r_b8 large_pages_enabled = r_win32_internal::memory_get_large_pages_enabled();

    return(large_pages_enabled);
}

r_external const r_b8
r_win32::memory_large_pages_set(
    const r_b8 set_value) {

    //TODO
    return(false);
}

r_external const r_size
r_win32::memory_align_to_page(
    const r_size size) {

    const r_size page_size    = r_win32_internal::memory_get_page_size(); 
    const r_size size_aligned = r_align_a_to_b(size,page_size); 

    return(size_aligned);
}

r_external const r_size
r_win32::memory_align_to_large_page(
    const r_size size) {

    const r_size large_page_size = r_win32_internal::memory_get_page_size_large(); 
    const r_size size_aligned    = r_align_a_to_b(size,large_page_size); 

    return(size_aligned);
}

r_external const r_size
r_win32::memory_align_to_allocation_granularity(
    const r_size size) {

    const r_size granularity  = r_win32_internal::memory_get_allocation_granularity(); 
    const r_size size_aligned = r_align_a_to_b(size,granularity); 

    return(size_aligned);
}

r_external r_memory
r_win32::memory_reserve(
    const r_size size) {

    const r_size size_aligned = r_win32::memory_align_to_page(size);

    r_memory reservation = 
        (r_memory)VirtualAlloc(
            NULL,
            size_aligned,
            MEM_RESERVE,
            PAGE_NOACCESS);
    
    return(reservation);
}

r_external r_void
r_win32::memory_release(
    const r_memory start,
    const r_size   size) {

    const r_size size_aligned = r_win32::memory_align_to_page(size);

    VirtualFree(
        start,
        size_aligned,
        MEM_RELEASE);
}

r_external r_memory
r_win32::memory_commit(
    const r_memory start, 
    const r_size   size) {

    const r_size size_aligned = r_win32::memory_align_to_page(size);

    r_memory commit = 
        (r_memory)VirtualAlloc(
            start,
            size_aligned,
            MEM_COMMIT,
            PAGE_READWRITE);

    return(commit);
}

r_external r_void
r_win32::memory_decommit(
    const r_memory start,
    const r_size   size) {

    const r_size size_aligned = r_win32::memory_align_to_page(size);

    VirtualFree(
        start,
        size_aligned,
        MEM_DECOMMIT);
}

r_external r_memory
r_win32::memory_reserve_and_commit(
    const r_size size) {

    const r_size size_aligned = r_win32::memory_align_to_page(size);

    r_memory commit = 
        (r_memory)VirtualAlloc(
            NULL,
            size_aligned,
            MEM_RESERVE | MEM_COMMIT,
            PAGE_READWRITE);

    return(commit);
}

r_external r_memory
r_win32::memory_reserve_and_commit_large_pages(
    const r_size size) {

    const r_size size_aligned = r_win32::memory_align_to_large_page(size);

    r_memory commit = 
        (r_memory)VirtualAlloc(
            NULL,
            size_aligned,
            MEM_RESERVE | MEM_COMMIT | MEM_LARGE_PAGES,
            PAGE_READWRITE);

    return(commit);
}

/**********************************************************************************/
/* INTERNAL                                                                       */
/**********************************************************************************/

r_internal const r_b8
r_win32_internal::memory_create(
    r_void) {

    RWin32Memory& memory = r_win32_internal::context_get_memory();

    SYSTEM_INFO system_info;
    GetSystemInfo(&system_info);

    memory.allocation_granularity = system_info.dwAllocationGranularity;
    memory.page_size              = system_info.dwPageSize;
    memory.page_size_large        = GetLargePageMinimum();

    r_b8 result = memory.allocation_granularity > 0 && memory.page_size > 0;

    return(result);
}

r_internal const r_b8
r_win32_internal::memory_destroy(
    r_void) {

    //TODO
    return(true);
}