aux_source_directory(. TOOL_LIB_SRCS_LIST)
add_library(tools SHARED ${TOOL_LIB_SRCS_LIST})
target_include_directories(tools
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        )