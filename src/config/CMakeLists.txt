include(FetchContent)

FetchContent_Declare(
        yaml-cpp
        GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
        GIT_TAG 0.8.0 # Can be a tag (yaml-cpp-x.x.x), a commit hash, or a branch name (master)
)
FetchContent_MakeAvailable(yaml-cpp)

add_library(fen_config fen_config.cpp)

target_link_libraries(fen_config PUBLIC yaml-cpp::yaml-cpp) # The library or executable that require yaml-cpp library
