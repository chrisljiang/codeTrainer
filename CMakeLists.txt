cmake_minimum_required (VERSION 2.6)
project (codeTrainer)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

set(CMAKE_BUILD_TYPE Debug)

configure_file (
  "${PROJECT_SOURCE_DIR}/lookupTables/tables.h"
  "${PROJECT_BINARY_DIR}/tables.h"
)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}"
                    "${PROJECT_BINARY_DIR}/lookupTables")

# add the executable
add_executable(codeTrainer
                main.cpp
                lookupTables/braille.cpp
                lookupTables/morse.cpp
                lookupTables/nato.cpp
                lookupTables/semaphore.cpp
                lookupTables/general.cpp)
