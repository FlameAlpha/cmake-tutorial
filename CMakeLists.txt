# set the minimum required version of cmake for a project
cmake_minimum_required(VERSION 3.14)

# set the project name and version
project(CMakeTutorial VERSION 1.3.0.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# provide an option "USE_USER_TOOLS" for the user to select as True or False
set(USE_USER_TOOLS True)

# provide an option "USE_EXISTIONG_USER_TOOLS" for the user to select as True or False
set(USE_EXISTIONG_USER_TOOLS True)

if(${USE_USER_TOOLS})
    if(${USE_EXISTIONG_USER_TOOLS})
        message("Use author provided existing tools implementation")
        # appends elements to the list "EXTRA_LIBS"
        list(APPEND EXTRA_LIBS libtools)
        # appends elements to the list "EXTRA_INCLUDES"
        list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/tools")
        ## copy library to the binary tree
        file(COPY ${PROJECT_BINARY_DIR}/tools/libtools.dll DESTINATION ${PROJECT_SOURCE_DIR}/tools/)
    else()
        message("Use author provided tools implementation")
        # add a subdirectory to the build
        add_subdirectory(tools)
        # appends elements to the list "EXTRA_LIBS"
        list(APPEND EXTRA_LIBS tools)
        # appends elements to the list "EXTRA_INCLUDES"
        list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/tools")
    endif()
endif()

# configure a header file to pass some of the CMake settings to the source code
configure_file (
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_BINARY_DIR}/config.h"
        )

# find all source files in a directory.
aux_source_directory(. SRCS_LIST)

# add the executable
add_executable(CMakeTutorial ${SRCS_LIST})

# specify the paths in which the linker should search for libraries when linking a given target
target_link_directories(CMakeTutorial PUBLIC ${EXTRA_INCLUDES})

# link libraries to target
target_link_libraries(CMakeTutorial PUBLIC ${EXTRA_LIBS})

# specifies include directories to use when compiling a given target
# add the binary tree to the search path for include files
# so that we will find config.h and source
target_include_directories(CMakeTutorial PUBLIC
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_BINARY_DIR}
        ${EXTRA_INCLUDES}
        )