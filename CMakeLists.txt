cmake_minimum_required (VERSION 2.6)
project (moonstone)

add_definitions(-Wno-c++11-extensions)

# http://www.cmake.org/pipermail/cmake/2012-June/050674.html
macro(header_directories return_list)
        FILE(GLOB_RECURSE new_list *.h)
        SET(dir_list "")
        FOREACH(file_path ${new_list})
            GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
            SET(dir_list ${dir_list} ${dir_path})
        ENDFOREACH()
        LIST(REMOVE_DUPLICATES dir_list)
        SET(${return_list} ${dir_list})
endmacro()

header_directories(dirs)
include_directories(${dirs})

file(GLOB_RECURSE HEADER_FILES ${PROJECT_SOURCE_DIR}/include/*.h)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(Moonstone ${SRC_FILES} ${HEADER_FILES})