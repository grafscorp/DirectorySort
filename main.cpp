#include <iostream>
#include <DirectorySort.hpp>

int main(int argc, char const *argv[])
{

    if(argc != 2)
    {
        std::cerr << "Error\nUse: program <Path for sort>\n";
        return 1;
    }


    DirectorySort ds;
    try
    {
        ds.sort_directory(argv[1]);
    }
    catch(const int e)
    {
        std::cerr << "Check is directory valid\nCode error : " << e << '\n';
    }
    
    
    //ds.create_local_architecture_directory("E:/test");
    return 0;
}
