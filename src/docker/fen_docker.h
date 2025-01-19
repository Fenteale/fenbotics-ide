//
// Created by fenteale on 7/16/23.
//

#ifndef FENBOTICS_IDE_FEN_DOCKER_H
#define FENBOTICS_IDE_FEN_DOCKER_H

//#include "docker.h"
#include <string>
#include <nlohmann/json.hpp>
#include <curl/curl.h>
using json = nlohmann::json;

class fen_docker {
public:
    fen_docker();
    ~fen_docker();
    void list_docker_container();

private:
    CURL *_handle;
    json _fetch_docker_cmd(std::string path);
};


#endif //FENBOTICS_IDE_FEN_DOCKER_H
