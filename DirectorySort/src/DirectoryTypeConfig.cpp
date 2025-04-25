#include <DirectoryTypeConfig.hpp>

bool DirectoryTypeConfig::is_empty()
{
    //TODO LOGER
    if (
        directory_name.empty() 
        ||
        formats.empty()
        )
    {
        return true;
    }
    return false;
}
