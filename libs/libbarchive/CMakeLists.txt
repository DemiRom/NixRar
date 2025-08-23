# libbarchive - Archive utility library for NixRar
cmake_minimum_required(VERSION 3.16)

# Library configuration
add_library(libbarchive STATIC
    src/archive_utils.cpp
        src/libbarchive.cpp
        include/libbarchive/libbarchive.h
)

# Set target properties
set_target_properties(libbarchive PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
)

# Include directories
target_include_directories(libbarchive
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Qt6 dependencies (Core for QString, QFileInfo, etc.)
find_package(Qt6 REQUIRED COMPONENTS Core)
target_link_libraries(libbarchive
    PUBLIC
        Qt6::Core
)

# Compiler-specific options
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(libbarchive PRIVATE -Wall -Wextra)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(libbarchive PRIVATE /W4)
endif()

# Export targets for potential external use
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    # Only create exports if this is the main project
    install(TARGETS libbarchive
        EXPORT libbarchiveTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
    )
    
    install(DIRECTORY include/ DESTINATION include)
    
    install(EXPORT libbarchiveTargets
        FILE libbarchiveTargets.cmake
        NAMESPACE libbarchive::
        DESTINATION lib/cmake/libbarchive
    )
endif()