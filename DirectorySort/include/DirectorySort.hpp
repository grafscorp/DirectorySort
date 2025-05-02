#ifndef DIRECTORYSORT_HPP
#define DIRECTORYSORT_HPP

#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <DirectoryTypeConfig.hpp>
#include <ConfigParser.hpp>

#pragma region ErrorCodes 

#define NOT_DIRECTORY 1010
#define LOCAL_CONFIG_DOEST_EXIST 1050
#define CANT_OPEN_CONFIG_FILE 2050
#define CANT_OPEN_DEF_CONFIG_FILE 2040
#define INVALID_DEFAULT_CONFIG_FILE 2010
#pragma endregion ErrorCodes

#define NAME_DEFAULT_CONFIG "default_config.json"
#define NAME_LOCAL_CONFIG ".ds_config.json"

#define CONTENT_DEFAULT_CONFIG "[[{\"formats\":[\".webp\",\".png\",\".jpeg\",\".jpg\",\".gif\",\".bmp\"]},{\"exceptions\":[]},{\"name_directory\":\"Images\"}],[{\"formats\":[\".mp4\",\".avi\"]},{\"exceptions\":[]},{\"name_directory\":\"Videos\"}],[{\"formats\":[\".txt\",\".doc\",\".rtf\"]},{\"exceptions\":[]},{\"name_directory\":\"Text\"}],[{\"formats\":[\".wav\",\".midi\",\".mp3\",\".wma\"]},{\"exceptions\":[]},{\"name_directory\":\"Sounds\"}],[{\"formats\":[\".rar\",\".zip\",\".tgz\",\".arj\"]},{\"exceptions\":[]},{\"name_directory\":\"Archive\"}]]"


/*
Main Class for sorting directories

*/
class DirectorySort
{
public:
    DirectorySort();
    ~DirectorySort();

public:
    //Сортировка директории, принимает в качестве аргумента uri директории, правила сортировки берёт из локального файла конфигурации(create_local_architecture_directory), если такого нет то правила берёт из стандартного файла конфигурации
    void sort_directory(const std::string& path);
    //Создать локальный файл конфигурации на базе стандартного файла конфигурации.(При сортировке директории будет сортироваться по этому файлу)
    void create_local_architecture_directory(const std::string& localPath);
    //Создать локальный файл конфигурации, на основе пользовательских данных.(При сортировке директории будет сортироваться по этому файлу)
    void create_local_architecture_directory(const std::string& localPath, const std::string& dataConfig);

protected:
    //Создает файл конфигурации, который будет использоваться по умолчанию 
    void create_default_architecture_directory();
    //Получить данные из файла конфигурации по умолчанию
    std::vector<DirectoryTypeConfig> get_default_archirecture_directory();
    //Получить данные из локального файла конфигурации
    std::vector<DirectoryTypeConfig> get_local_architecture_diretory(const std::filesystem::path& dir);

private:

    ConfigParser* configParser ;

};





#endif 

