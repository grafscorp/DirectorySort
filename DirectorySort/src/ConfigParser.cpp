#include <ConfigParser.hpp>

ConfigParser::ConfigParser() {

}

ConfigParser::~ConfigParser() {

}

std::vector<DirectoryTypeConfig> ConfigParser::parse(const std::string data) {
    nlohmann::json resJson = nlohmann::json::parse(data);
    
    std::vector<DirectoryTypeConfig> ConfigDatas;
    

    size_t sizeConfigTypes = resJson.size();

    for (size_t i = 0; i < sizeConfigTypes; i++)
    {
        DirectoryTypeConfig typeConfig;
        nlohmann::json typeObj = resJson.at(i);//Get Type 
        typeConfig.name =  typeObj.at(2)["name_directory"]; //Get Directory Name
        nlohmann::json formats = typeObj.at(0)["formats"];//Get Item Type's Formats 

        for (int i = 0; i < formats.size(); i++) 
        {
            typeConfig.formats .push_back(formats.at(i));
        }
        
        ConfigDatas.push_back(typeConfig);
    }

    return ConfigDatas;
}
