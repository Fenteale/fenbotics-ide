//
// Created by fenteale on 1/26/25.
//

#ifndef FEN_CONFIG_H
#define FEN_CONFIG_H

#include "yaml-cpp/yaml.h"
#include <string>

#define CONFIG_PATH "fenbotics.yaml"

class fen_config {
  private:
  	YAML::Node config;
    void write_config();
  public:
    fen_config();
    std::string getProjPath();
    void setProjPath(std::string projPath);

};



#endif //FEN_CONFIG_H
