//
// Created by fenteale on 1/26/25.
//

#include "fen_config.h"
#include <fstream>
#include <filesystem>

fen_config::fen_config() {
  if (std::filesystem::is_regular_file(CONFIG_PATH))
    config = YAML::LoadFile(CONFIG_PATH);
}

std::string fen_config::getProjPath() {
  if (config["lastProjPath"])
    return config["lastProjPath"].as<std::string>();
  else
    return "";
}

void fen_config::setProjPath(std::string projPath) {
  config["lastProjPath"] = projPath;

  write_config();
}

void fen_config::write_config() {
  std::ofstream yamlFile;
  yamlFile.open(CONFIG_PATH);
  yamlFile << config;
  yamlFile.close();
}