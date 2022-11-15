# Minimum requirements for CMake version
cmake_minimum_required(VERSION 3.0.0)

# Project name and version
project(Schedule VERSION 0.1.0)

# Add configuration header file with CMake variables
configure_file(src/cmake/config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/src/cmake/config.h @ONLY)

# Global recursive search for source files
file(GLOB_RECURSE Schedule_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE Schedule_HEADERS CONFIGURE_DEPENDS "src/*.h")

# Get header files directories
set(Schedule_INCLUDE_DIRS "")
foreach (_headerFile ${Schedule_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND Schedule_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Schedule_INCLUDE_DIRS)

# Add source files to project
add_executable(Schedule ${Schedule_SOURCES})

# Include header files directories in project
target_include_directories(Schedule PRIVATE ${Schedule_INCLUDE_DIRS})