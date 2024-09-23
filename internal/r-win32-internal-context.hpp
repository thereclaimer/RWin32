#ifndef R_WIN32_INTERNAL_HPP
#define R_WIN32_INTERNAL_HPP

#include "r-win32.hpp"
#include "r-win32-internal-window.hpp"
#include "r-win32-internal-rendering.hpp"
#include "r-win32-internal-file.hpp"
#include "r-win32-internal-memory.hpp"

struct RWin32Window;

struct RWin32Context {
    r_timems          system_time_initialized;
    RWin32MainArgs    args;
    RWin32Memory      memory;
    RWin32Window      window;
    RWin32FileManager file_manager;     
};

r_global RWin32Context _r_win32_context;

namespace r_win32_internal {

    //---------------------------
    // context
    //---------------------------

    inline const r_b8 context_is_initialized(r_void) { return(_r_win32_context.system_time_initialized > 0); } 
    
    inline const r_timems           context_get_system_time_initialized (r_void) { return(_r_win32_context.system_time_initialized); }
    inline       RWin32Memory&      context_get_memory                  (r_void) { return(_r_win32_context.memory);                  }
    inline       RWin32MainArgs&    context_get_args                    (r_void) { return(_r_win32_context.args);                    } 
    inline       RWin32Window&      context_get_window                  (r_void) { return(_r_win32_context.window);                  }
    inline       RWin32FileManager& context_get_file_manager            (r_void) { return(_r_win32_context.file_manager);            }
    
    //---------------------------
    // args
    //---------------------------
    
    inline const HINSTANCE main_args_get_h_instance      (r_void) { return(_r_win32_context.args.h_instance);      }
    inline const HINSTANCE main_args_get_h_prev_instance (r_void) { return(_r_win32_context.args.h_prev_instance); }
    inline const PWSTR     main_args_get_p_cmd_line      (r_void) { return(_r_win32_context.args.p_cmd_line);      }
    inline const int       main_args_get_n_cmd_show      (r_void) { return(_r_win32_context.args.n_cmd_show);      }    

    //---------------------------
    // memory
    //---------------------------

    inline const r_size memory_get_page_size              (r_void) { return(_r_win32_context.memory.page_size);              }
    inline const r_size memory_get_page_size_large        (r_void) { return(_r_win32_context.memory.page_size_large);        }
    inline const r_size memory_get_allocation_granularity (r_void) { return(_r_win32_context.memory.allocation_granularity); }
    inline const r_size memory_get_large_pages_enabled    (r_void) { return(_r_win32_context.memory.large_pages_enabled);    }

    //---------------------------
    // window
    //---------------------------

    inline const r_b8
    window_initialized() {

        const r_b8 result = (
            _r_win32_context.system_time_initialized > 0 &&
            _r_win32_context.window.win32_handle_window != NULL);
    
        return(result);
    }

    inline const HWND              window_get_window_handle             (r_void) { return(_r_win32_context.window.win32_handle_window);         }
    inline const HDC               window_get_device_context_handle     (r_void) { return(_r_win32_context.window.win32_handle_device_context); }
    inline       MSG&              window_get_message                   (r_void) { return(_r_win32_context.window.message);                     }
    inline const r_u32             window_get_position_x                (r_void) { return(_r_win32_context.window.position_x);                  }
    inline const r_u32             window_get_position_y                (r_void) { return(_r_win32_context.window.position_y);                  }
    inline const r_u32             window_get_width                     (r_void) { return(_r_win32_context.window.width);                       }
    inline const r_u32             window_get_height                    (r_void) { return(_r_win32_context.window.height);                      }
    inline const r_b32             window_get_quit_received             (r_void) { return(_r_win32_context.window.quit_received);               }
    inline const r_u64             window_get_frame_system_ticks_start  (r_void) { return(_r_win32_context.window.frame_system_ticks_start);    }
    inline const r_u64             window_get_frame_system_ticks_render (r_void) { return(_r_win32_context.window.frame_system_ticks_render);   }
    inline const RColorFormat      window_get_color_format              (r_void) { return(_r_win32_context.window.color_format);                }
    inline RWin32RenderingContext& window_get_rendering_context         (r_void) { return(_r_win32_context.window.rendering_context);           }

    inline r_void window_set_position_x                (const r_u32 position_x)          { _r_win32_context.window.position_x                = position_x;    }
    inline r_void window_set_position_y                (const r_u32 position_y)          { _r_win32_context.window.position_y                = position_y;    }
    inline r_void window_set_width                     (const r_u32 width)               { _r_win32_context.window.width                     = width;         }
    inline r_void window_set_height                    (const r_u32 height)              { _r_win32_context.window.height                    = height;        }
    inline r_void window_set_quit_received             (const r_b32 quit_received)       { _r_win32_context.window.quit_received             = quit_received; }
    inline r_void window_set_color_format              (const RColorFormat color_format) { _r_win32_context.window.color_format              = color_format;  }
    inline r_void window_set_frame_system_ticks_start  (const r_u64 ticks_start)         { _r_win32_context.window.frame_system_ticks_start  = ticks_start;   }    
    inline r_void window_set_frame_system_ticks_render (const r_u64 ticks_render)        { _r_win32_context.window.frame_system_ticks_render = ticks_render;  }

    //---------------------------
    // file
    //---------------------------

    inline const r_size      file_manager_get_file_count(r_void) { return(_r_win32_context.file_manager.file_count); }
    inline       RWin32File* file_manager_get_file_array(r_void) { return(_r_win32_context.file_manager.file_array); }
};

#endif //R_WIN32_INTERNAL_HPP