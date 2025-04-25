cmake_minimum_required(VERSION 3.10.0)
project(DirectorySortLib VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(DirectorySortIncludePath include)
set(DirectorySortSourcePath src)

set(HEADERS_FILES 
    ${DirectorySortIncludePath}/DirectorySort.hpp
    ${DirectorySortIncludePath}/DirectoryTypeConfig.hpp
    ${DirectorySortIncludePath}/ConfigParser.hpp
)


set(JSON_LIB_PATH  ${DirectorySortIncludePath}/nlohmann)
set(JSON_INCLUDES 
    ${JSON_LIB_PATH}/json.hpp
    ${JSON_LIB_PATH}/json_fwd.hpp
    )


set(SOURCE_FILES
    ${DirectorySortSourcePath}/DirectorySort.cpp
    ${DirectorySortSourcePath}/DirectoryTypeConfig.cpp
    ${DirectorySortSourcePath}/ConfigParser.cpp
)

add_library(DirectorySortLib 
    ${SOURCE_FILES}
    ${HEADERS_FILES}
    ${JSON_INCLUDES}
)

target_include_directories(DirectorySortLib PRIVATE ${DirectorySortIncludePath} ${JSON_INCLUDES})

