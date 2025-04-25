#ifndef DIRECTORY_TYPE_CONFIG_HPP
#define DIRECTORY_TYPE_CONFIG_HPP

#include <iostream>
#include <vector>


struct DirectoryTypeConfig
{
public:
    DirectoryTypeConfig()
    {

    }
    explicit  DirectoryTypeConfig( const std::string directory_name, const std::vector<std::string>formats):
     directory_name(directory_name), formats(formats)
    {

    }

    std::string directory_name;
    std::vector<std::string> formats;
    bool is_empty();
};



#endif