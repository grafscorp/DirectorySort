#include <ConfigParser.hpp>

ConfigParser::ConfigParser() {

}

ConfigParser::~ConfigParser() {

}

DirectoryTypeConfig ConfigParser::parse(const std::string data) {
    nlohmann::json resJson = nlohmann::json::parse(data);
    
    DirectoryTypeConfig ConfigData;
    std::string nameConfig;
    std::string directory_nameConfig;
    std::vector<std::string> formatsConfig;


    ConfigData.name = nameConfig;
    ConfigData.directory_name = directory_nameConfig;
    ConfigData.formats = formatsConfig;
    return ConfigData;
}
