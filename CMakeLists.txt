cmake_minimum_required(VERSION 3.16)
project(NixRar VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Platform-specific configuration
if(APPLE)
    set(CMAKE_PREFIX_PATH "/opt/homebrew")
    include_directories("/opt/homebrew/opt/libarchive/include")
    link_directories("/opt/homebrew/opt/libarchive/lib")
    set(LibArchive_INCLUDE_DIR "/opt/homebrew/opt/libarchive/include")
    set(LibArchive_LIBRARY_DIR "/opt/homebrew/opt/libarchive/lib")
endif()

find_package(Qt6 COMPONENTS
    Core
    Gui
    Widgets
    REQUIRED)

# Find libarchive differently based on platform
if(APPLE)
    # Use original approach for macOS
    find_package(LibArchive REQUIRED)
else()
    # Use pkg-config for Linux
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(LibArchive REQUIRED IMPORTED_TARGET libarchive)
endif()

add_executable(NixRar main.cpp
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
        NixRar.qrc
        FileExplorerModel.cpp
        FileExplorerModel.h
        Archive.cpp
        Archive.h
        FileExplorer.cpp
        FileExplorer.h
        AboutDialog.cpp
        AboutDialog.h
        AboutDialog.ui
)

target_link_libraries(NixRar
    Qt::Core
    Qt::Gui
    Qt::Widgets
)

# Link libarchive differently based on platform
if(APPLE)
    # Use the original static library approach that was working
    target_link_libraries(NixRar libarchive.a)
else()
    target_link_libraries(NixRar PkgConfig::LibArchive)
endif()

# Version information
target_compile_definitions(NixRar PRIVATE
    NIXRAR_VERSION="${PROJECT_VERSION}"
    $<$<CONFIG:Debug>:DEBUG_BUILD>
)

# Install configuration
install(TARGETS NixRar
    RUNTIME DESTINATION bin
)

# Linux desktop integration
if(UNIX AND NOT APPLE)
    install(FILES resources/nixrar.desktop
        DESTINATION share/applications
    )
    install(FILES resources/nixrar.png
        DESTINATION share/icons/hicolor/256x256/apps
    )
endif()

