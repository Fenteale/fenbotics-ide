
set(IMGUI_ROOT imgui)

include_directories(${IMGUI_ROOT} ${IMGUI_ROOT}/backends)

set(IMGUI_SRC
        ${IMGUI_ROOT}/imgui.cpp
        ${IMGUI_ROOT}/imgui_demo.cpp
        ${IMGUI_ROOT}/imgui_draw.cpp
        ${IMGUI_ROOT}/imgui_tables.cpp
        ${IMGUI_ROOT}/imgui_widgets.cpp
        ${IMGUI_ROOT}/backends/imgui_impl_sdl2.cpp
        ${IMGUI_ROOT}/backends/imgui_impl_sdl2.h
        ${IMGUI_ROOT}/backends/imgui_impl_opengl3.cpp)

find_path(SDL2_INCLUDE_DIR SDL2/SDL.h)
find_library(SDL2_LIBRARY SDL2)

add_library(imgui ${IMGUI_SRC})
target_include_directories(imgui PUBLIC ${SDL2_INCLUDE_DIR} ${SDL2_INCLUDE_DIR}/SDL2)
target_link_libraries(imgui ${SDL2_LIBRARY} GL)