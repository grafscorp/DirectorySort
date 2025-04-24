#include <DirectorySort.hpp>

DirectorySort::DirectorySort(/* args */)
{
}

DirectorySort::~DirectorySort()
{
}

void DirectorySort::sort_directory() {
    
}

void DirectorySort::create_default_architecture_directory() {
    //TODO 
    std::ofstream default_file_config("default_config.json");
    default_file_config << "" << std::endl;
    default_file_config.close();
}

void DirectorySort::get_default_archirecture_directory() {

}
