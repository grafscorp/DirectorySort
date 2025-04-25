#include <DirectorySort.hpp>

DirectorySort::DirectorySort(/* args */)
{
    configParser = new ConfigParser();
}

DirectorySort::~DirectorySort()
{
    delete configParser;
}

void DirectorySort::sort_directory(const std::string path) {
    
    std::filesystem::path directory(path);


    if (! std::filesystem::is_directory(directory))
    {
        throw NOT_DIRECTORY;
        return; 
    }
    //TODO

    //All config rules
    std::vector<DirectoryTypeConfig> configSort;
    try
    {
        configSort = get_local_architecture_diretory(directory);
    }
    catch(const int code_err )
    {
        //TODO LOGER
        std::cerr << "HASNT LOCAL CONFIG FILE. " << code_err << '\n';
        configSort = get_default_archirecture_directory();
    }
    
    

}

void DirectorySort::create_default_architecture_directory() {
    //TODO 
    std::ofstream default_file_config(NAME_DEFAULT_CONFIG);
    default_file_config << "" << std::endl;
    default_file_config.close();
}

std::vector<DirectoryTypeConfig> DirectorySort::get_default_archirecture_directory() {
    //TODO 
}

void DirectorySort::create_local_architecture_directory() {
    //TODO
}

std::vector<DirectoryTypeConfig> DirectorySort::get_local_architecture_diretory(const std::filesystem::path& dir) {
    //TODO
    for(const auto& entry : std::filesystem::directory_iterator(dir))
    {
        if (entry.path().filename() == NAME_LOCAL_CONFIG) 
        {
            
            return configParser->parse();
            
        }
    }
    throw LOCAL_CONFIG_DOEST_EXIST;

}
