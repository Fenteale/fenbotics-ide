
add_subdirectory(docker)
add_subdirectory(gui)
add_subdirectory(config)

add_executable(fenbotics_ide main.cpp)


target_link_libraries(fenbotics_ide fengui fendocker fen_config)