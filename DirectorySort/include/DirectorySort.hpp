#ifndef DIRECTORYSORT_HPP
#define DIRECTORYSORT_HPP

#include <iostream>
#include <fstream>

/*
Main Class for sorting directories

*/
class DirectorySort
{
public:
    DirectorySort();
    ~DirectorySort();

public:
    void sort_directory();

private:
    void create_default_architecture_directory();
    void get_default_archirecture_directory();
    void create_local_architecture_directory();
    void get_local_architecture_diretory();



};



#endif 