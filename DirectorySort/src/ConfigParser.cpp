#include <ConfigParser.hpp>

ConfigParser::ConfigParser() {

}

ConfigParser::~ConfigParser() {

}

std::vector<DirectoryTypeConfig> ConfigParser::parse(const std::string data) {
    //TODO LOGER
    std::cout<< "Start parsing... " <<std::endl;
    nlohmann::json resJson = nlohmann::json::parse(data);
    
    std::vector<DirectoryTypeConfig> ConfigDatas;
    

    size_t sizeConfigTypes = resJson.size();

    for (size_t i = 0; i < sizeConfigTypes; i++)
    {
        DirectoryTypeConfig typeConfig;
        nlohmann::json typeObj = resJson.at(i);//Get Type 
        typeConfig.directory_name =  typeObj.at(2)["name_directory"]; //Get Directory Name
        nlohmann::json formats = typeObj.at(0)["formats"];//Get Item Type's Formats 

        for (size_t i = 0; i < formats.size(); i++) 
        {
            typeConfig.formats .push_back(formats.at(i));
        }
        if(typeConfig.is_empty()) continue;
        
        ConfigDatas.push_back(typeConfig);
        //TODO LOGER
        std::cout << "Added type " << typeConfig.directory_name << std::endl;
    }
    if(ConfigDatas.empty()) {
        //TODO LOGER
        std::cout << "Empty data\n";
        throw EMPTY_DATA;
    }
    //TODO LOGER
    std::cout <<"Parse success\n";
    return ConfigDatas;
}
