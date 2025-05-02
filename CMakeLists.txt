cmake_minimum_required(VERSION 3.10.0)
project(DirectorySort VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)



#link_directories(DirectorySort/lib)

add_subdirectory(DirectorySort)


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    link_directories(DirectorySort/lib/Debug)
else()
    link_directories(DirectorySort/lib/Release)
endif()



add_executable(DirectorySort main.cpp)

set(DS_INCLUDE_PATH DirectorySort/include)
#set(DS_LIB DirectorySort/lib/DirectorySortLib)
target_include_directories(DirectorySort PUBLIC  ${DS_INCLUDE_PATH})


target_link_libraries(DirectorySort PUBLIC DirectorySortLib)