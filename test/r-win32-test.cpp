#define R_WIN32_MAIN_REDIRECT

#include <r-win32.hpp>


#pragma once

r_s32
r_win32_main(
    RWin32MainArgs& args) {

    //create the context
    if (!r_win32::context_create(args)) {
        return(S_FALSE);
    }

    //create the window
    if (!r_win32::window_create(
        "RWin32 Test",
        0,0,1920,1080,
        RColorFormat_RGBA,
        RWin32RenderingContextType_None,
        RWin32WindowUseImGui_No)) {

        return(S_FALSE);
    }

    r_win32::window_show();

    //main window loop
    r_b8 running = true;
    while(running) {

        //start a new frame
        running &= r_win32::window_frame_start();
        
        //render the frame
        running &= r_win32::window_frame_render();
    }

    //destroy the context
    if (!r_win32::context_destroy()) {
        return(S_FALSE);
    }

    //done
    return(S_OK);
}