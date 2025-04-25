#ifndef CONFIG_PARSER_HPP
#define CONFIG_PARSER_HPP


#include <string>
#include <nlohmann/json.hpp>
#include <DirectoryTypeConfig.hpp>

class ConfigParser
{
private:
    /* data */
public:
    ConfigParser(/* args */);
    ~ConfigParser();
    //Parse data from config file
    DirectoryTypeConfig parse(const std::string data);
};



#endif