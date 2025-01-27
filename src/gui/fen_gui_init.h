//
// Created by fenteale on 7/7/23.
//

#ifndef FENBOTICS_IDE_FEN_GUI_INIT_H
#define FENBOTICS_IDE_FEN_GUI_INIT_H

// Dear ImGui: standalone example application for SDL2 + OpenGL
// (SDL is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui.h"
#include "misc/cpp/imgui_stdlib.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <SDL.h>
#include <stdexcept>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL_opengles2.h>
#else
#include <SDL_opengl.h>
#endif

// This example can also compile and run with Emscripten! See 'Makefile.emscripten' for details.
#ifdef __EMSCRIPTEN__
#include "../libs/emscripten/emscripten_mainloop_stub.h"
#endif

class fen_gui_init {
private:
    SDL_Window* window;
    ImGuiIO* io;
    SDL_GLContext gl_context;
public:
    fen_gui_init();
    ~fen_gui_init();
    bool loop();
};


#endif //FENBOTICS_IDE_FEN_GUI_INIT_H
