#include <DirectorySort.hpp>

DirectorySort::DirectorySort(/* args */)
{
}

DirectorySort::~DirectorySort()
{
}

void DirectorySort::sort_directory(const std::string path) {
    
    std::filesystem::path directory(path);


    if (! std::filesystem::is_directory(directory))
    {
        throw NOT_DIRECTORY;
        return; 
    }



}

void DirectorySort::create_default_architecture_directory() {
    //TODO 
    std::ofstream default_file_config("default_config.json");
    default_file_config << "" << std::endl;
    default_file_config.close();
}

void DirectorySort::get_default_archirecture_directory() {

}

void DirectorySort::get_local_architecture_diretory(const std::filesystem::path& dir) {
    
    for(const auto& entry : std::filesystem::directory_iterator(dir))
    {
        if (entry.path().filename() == NAME_LOCAL_CONFIG) 
        {
            DirectoryTypeConfig localConfig;
            
        }
    }

}
