#ifndef R_WIN32_INTERNAL_FILE_HPP
#define R_WIN32_INTERNAL_FILE_HPP

#include "r-win32.hpp"

#define R_WIN32_FILE_MANAGER_MAX_FILES 64

struct RWin32File {
    HANDLE               win32_handle;
    r_size               file_size;
    RWin32FilePermission permission;
};

struct RWin32FileManager {
    r_size     file_count;
    RWin32File file_array[R_WIN32_FILE_MANAGER_MAX_FILES];
};

#endif //R_WIN32_INTERNAL_FILE_HPP