find_package(CURL REQUIRED)

include_directories(${CURL_INCLUDE_DIRS})

add_library(fendocker fen_docker.cpp fen_docker.h)

target_link_libraries(fendocker ${CURL_LIBRARIES} nlohmann_json::nlohmann_json)