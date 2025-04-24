cmake_minimum_required(VERSION 3.10.0)
project(DirectorySortLib VERSION 0.1.0 LANGUAGES C CXX)

set(DirectorySortIncludePath include)
set(DirectorySortSourcePath src)

set(HEADERS_FILES 
    ${DirectorySortIncludePath}/DirectorySort.hpp
    ${DirectorySortIncludePath}/DirectoryTypeConfig.hpp
)

set(SOURCE_FILES
    ${DirectorySortSourcePath}/DirectorySort.cpp
    ${DirectorySortSourcePath}/DirectoryTypeConfig.cpp
)

add_library(DirectorySortLib 
    ${SOURCE_FILES}
    ${HEADERS_FILES}

)

target_include_directories(DirectorySortLib PRIVATE ${DirectorySortIncludePath})

