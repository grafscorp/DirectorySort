#ifndef CONFIG_PARSER_HPP
#define CONFIG_PARSER_HPP


#include <string>
#include <nlohmann/json.hpp>
#include <DirectoryTypeConfig.hpp>

#define NOT_VALID_DATA 1310
#define EMPTY_DATA 1300
class ConfigParser
{
private:
    /* data */
public:
    ConfigParser(/* args */);
    ~ConfigParser();
    //Parse data from config file
    std::vector<DirectoryTypeConfig> parse(const std::string data);
};



#endif