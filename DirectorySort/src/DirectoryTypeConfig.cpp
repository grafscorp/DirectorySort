#include <DirectoryTypeConfig.hpp>

bool DirectoryTypeConfig::is_empty()
{
    //TODO LOGER
    if (name.empty() &&
        directory_name.empty() &&
        formats.empty()
        )
    {
        return true;
    }
    return false;
}
