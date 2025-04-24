#ifndef DIRECTORY_TYPE_CONFIG_HPP
#define DIRECTORY_TYPE_CONFIG_HPP

#include <iostream>
#include <vector>


struct DirectoryTypeConfig
{
public:
    std::string name;
    std::string directory_name;
    std::vector<std::string> formats;
};



#endif