#include <DirectorySort.hpp>

DirectorySort::DirectorySort(/* args */)
{
    configParser = new ConfigParser();

}

DirectorySort::~DirectorySort()
{
    delete configParser;
}


void DirectorySort::sort_directory(const std::string& path) {
    //Сортируемая директория
    std::filesystem::path directory(path);


    if (! std::filesystem::is_directory(directory) || !std::filesystem::exists(directory))
    {
        //TODO LOGER
        std::cout << "NOT directory : " << directory <<std::endl;
        throw NOT_DIRECTORY;
        return; 
    }

    //All config rules
    std::vector<DirectoryTypeConfig> configSort = get_local_architecture_diretory(directory);
    if (configSort.empty())
    {
        configSort = get_default_archirecture_directory();
    }

    //Прохожусь по всем типам сортировки 
    for (const auto configType : configSort)
    {
        //Директория, которая создается для переменщения определенных файлов
        std::string typeDirectory = path + "/" +configType.directory_name;

        
        if (!std::filesystem::exists(typeDirectory)){
            //TODO LOGER
            std::cout << "Directory isnt exist\n";
                    //TODO LOGER
            std::cout << "Create path : " << typeDirectory << std::endl;
            if(!std::filesystem::create_directory(typeDirectory))
            {
                //Cant create directory
                //TODO LOGER
                std::cout << "Cant create directory " << typeDirectory << std::endl;
                continue;
            }
        }
        //Поиск нужных файлов и их перемещение в нужную директорию
        //TODO LOGER
        std::cout << "Start moving of " << configType.directory_name << std::endl;
        //Прохожусь по нужным форматам из Конфиг Файла
        for (const auto &formatConfig: configType.formats)
        {

            if(formatConfig == "*"){
                continue;
            }
            //Прохожусь по файлам из директории
            for (const auto &originFile : std::filesystem::directory_iterator(directory))
            {
                //TODO

                if(!originFile.is_regular_file()) continue;

                if (originFile.path().extension() == formatConfig )
                {
                    //Полный путь к отсортированному файлому 
                    std::string sortedFile(typeDirectory +"/"+originFile.path().filename().string());
                    //Moving file
                    std::filesystem::rename(originFile.path(),sortedFile );
                    //TODO LOGER
                    std::cout << "File  : " << originFile.path();
                    std::cout << ", moved to : " << typeDirectory << "/" << originFile.path().filename() << std::endl; 
                }
            }

        }
        //TODO LOGER 
        std::cout << "Stop moving of  " << configType.directory_name << std::endl;


        
        
    }
    std::cout << "Sorted.\n";


}

void DirectorySort::create_default_architecture_directory() {
    //TODO 
    std::cout << "Creating default config file\n";
    std::ofstream default_file_config(NAME_DEFAULT_CONFIG);
    default_file_config << CONTENT_DEFAULT_CONFIG << std::endl;
    default_file_config.close();
}

std::vector<DirectoryTypeConfig> DirectorySort::get_default_archirecture_directory() {
    //TODO LOGER
    std::cout << "getting def config file\n";
    std::ifstream configFile(NAME_DEFAULT_CONFIG);
    if(!configFile.is_open())
    {
        std::cout << "Cant open config file\n";
        throw CANT_OPEN_DEF_CONFIG_FILE;
        //create_default_architecture_directory();
    }

    std::vector<DirectoryTypeConfig> sortTypes;

    std::string configFileData;
    std::stringstream bufferData;
    bufferData << configFile.rdbuf();
    configFileData = bufferData.str();
    configFile.close();
    sortTypes =  configParser->parse(configFileData);
    if (sortTypes.empty()) throw INVALID_DEFAULT_CONFIG_FILE;
    return sortTypes;
}


void DirectorySort::create_local_architecture_directory(const std::string &localPath)
{
    //TODO Переделать чтобы данные брал из файла, если такой есть
    //TODO LOGER
    std::cout << "Creating local config file on base default config file.\n";
    std::string localFilePath = localPath;
    std::string nameLocalFile = NAME_LOCAL_CONFIG;
    localFilePath += "/" + nameLocalFile;
    std::cout << localFilePath;
    std::ofstream default_file_config(localFilePath);
    default_file_config << CONTENT_DEFAULT_CONFIG << std::endl;
    default_file_config.close();
}

void DirectorySort::create_local_architecture_directory(const std::string& localPath, const std::string& dataConfig) {
    //TODO LOGER
    std::cout << "Creating local config file on base user data.\n" ;
    std::string localFilePath = localPath;
    std::string nameLocalFile = NAME_LOCAL_CONFIG;
    localFilePath += "/" + nameLocalFile;
    std::cout << localFilePath;
    std::ofstream default_file_config(localFilePath);
    default_file_config << dataConfig << std::endl;
    default_file_config.close();
}

std::vector<DirectoryTypeConfig> DirectorySort::get_local_architecture_diretory(const std::filesystem::path& dir) {
    //TODO LOGER
    std::cout << "Getting local config file\n"<< dir << "\n";
    std::vector<DirectoryTypeConfig> sortTypes;
    for(const auto& entry : std::filesystem::directory_iterator(dir))
    {
        if(!entry.is_regular_file()) continue;

        if (entry.path().filename() == NAME_LOCAL_CONFIG) 
        {
            //TODO LOGER 
            std::cout << "Finded local config : " << entry.path().filename()<<std::endl;

            std::ifstream configFile(entry.path());
            if(!configFile.is_open())
            {
                throw CANT_OPEN_CONFIG_FILE;
            }

            //Read data from file to string
            std::string configFileData;
            std::stringstream bufferData;
            bufferData << configFile.rdbuf();
            configFileData = bufferData.str();
            configFile.close();
            
            sortTypes = configParser->parse(configFileData);
            
        }
    }
    
    return sortTypes;

}
