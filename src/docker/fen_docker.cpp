//
// Created by fenteale on 7/16/23.
//

#include "fen_docker.h"
#include <iostream>

#define DOCKER_SOCK     "/var/run/docker.sock"
#define DOCKER_PATH_S   "http://localhost/v1.47/"

static size_t curl_write(char *data, size_t size, size_t nmemb, std::string *writerData) {
    if (writerData == nullptr)
        return 0;
    writerData->append(data, size*nmemb);
    return size*nmemb;
}

fen_docker::fen_docker() {
    curl_global_init(CURL_GLOBAL_ALL);
    _handle = curl_easy_init();

    //std::string test;

    curl_easy_setopt(_handle, CURLOPT_UNIX_SOCKET_PATH, DOCKER_SOCK);
    curl_easy_setopt(_handle, CURLOPT_WRITEFUNCTION, curl_write);
    //curl_easy_setopt(curlh, CURLOPT_WRITEDATA, test);

}

fen_docker::~fen_docker() {
    curl_global_cleanup();
}


void fen_docker::list_docker_container() {
    json test = _fetch_docker_cmd("images/json");
    for (const auto& item : test.items()) {
        std::cout << item.value()["Labels"]["os_release.name"] << std::endl;
        //for (const auto& val : item.value().items())
            //std::cout << val
            //std::cout << val.key() << ": " << val.value() << std::endl;
        std::cout << "##########################" << std::endl;
    }
        //std::cout << item.value()["os_release.name"] << std::endl;
    //std::cout << test.items() << std::endl;
}


json fen_docker::_fetch_docker_cmd(std::string path) {
    std::string url = DOCKER_PATH_S;
    std::string response_s;
    url.append(path);
    std::cout << "Curl URL: " << url << std::endl;

    curl_easy_setopt(_handle, CURLOPT_URL, url.c_str());
    curl_easy_setopt(_handle, CURLOPT_WRITEDATA, &response_s);

    curl_easy_perform(_handle);
    curl_easy_cleanup(_handle);

    //std::cout << "Curl response: " << response_s << std::endl;

    return json::parse(response_s);

}



