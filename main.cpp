#include <iostream>
#include <DirectorySort.hpp>

int main(int argc, char const *argv[])
{
    DirectorySort ds;
    
    ds.sort_directory(argv[1]);
    //ds.create_local_architecture_directory("E:/test");
    return 0;
}
