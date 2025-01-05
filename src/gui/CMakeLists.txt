add_library(fengui fen_gui_init.cpp fen_gui_init.h)

find_path(SDL2_INCLUDE_DIR SDL2/SDL.h)
#message(STATUS Yam ${SDL2_INCLUDE_DIR})
find_library(SDL2_LIBRARY SDL2)

target_include_directories(fengui PUBLIC ${SDL2_INCLUDE_DIR} ${SDL2_INCLUDE_DIR}/SDL2)
target_link_libraries(fengui imgui ${SDL2_LIBRARY})