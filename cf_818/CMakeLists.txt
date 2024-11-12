cmake_minimum_required(VERSION 3.16)
project(cp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -O0 -ggdb")

add_definitions(-DLOCAL)
include_directories(${CMAKE_SOURCE_DIR})

add_executable(Template template.cpp)

file(MAKE_DIRECTORY src)
file(MAKE_DIRECTORY in)

file(GLOB_RECURSE sources RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")

foreach(path ${sources})
    # Creating basic target
    string(REPLACE "src/" "" name ${path})
    string(REPLACE "/" "-" name ${name})
    add_executable(${name} ${path})

    # Creating automatic input reading target
    string(REPLACE ".cpp" "" folder_name ${name})
    set(folder ${CMAKE_SOURCE_DIR}/in/${folder_name})
    file(MAKE_DIRECTORY ${folder})
    set(filee ${folder}/in.txt)
    file(TOUCH ${filee})
    file(GLOB_RECURSE inputs "in/${folder_name}/*")
    foreach(input_loc ${inputs})
        get_filename_component(input ${input_loc} NAME)
        set(target_name ${name}_${input})
        add_custom_target(
                ${target_name}
                COMMAND printf \"======================\\n\"
                COMMAND ${name} < ${input_loc}
                COMMAND printf \"\\n======================\\n\"
                SOURCES ${path}
        )
        add_dependencies(${target_name} ${name})
    endforeach()
endforeach()