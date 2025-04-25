#ifndef DIRECTORYSORT_HPP
#define DIRECTORYSORT_HPP

#include <iostream>
#include <fstream>
#include <filesystem>
#include <DirectoryTypeConfig.hpp>


#pragma region ErrorCodes 

#define NOT_DIRECTORY 1010

#pragma endregion ErrorCodes

#define NAME_DEFAULT_CONFIG "default_config.json"
#define NAME_LOCAL_CONFIG ".ds_config.json"
/*
Main Class for sorting directories

*/
class DirectorySort
{
public:
    DirectorySort();
    ~DirectorySort();

public:
    void sort_directory(const std::string path);

private:
    void create_default_architecture_directory();
    void get_default_archirecture_directory();
    void create_local_architecture_directory();
    void get_local_architecture_diretory(const std::filesystem::path& dir);



};



#endif 