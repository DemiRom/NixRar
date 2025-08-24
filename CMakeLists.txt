cmake_minimum_required(VERSION 3.30)
project(NixRar)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew")

find_package(Qt6 COMPONENTS
  Core
  Gui
  Widgets
  REQUIRED)

include_directories("/opt/homebrew/opt/libarchive/include")
link_directories("/opt/homebrew/opt/libarchive/lib")
set(LibArchive_INCLUDE_DIR "/opt/homebrew/opt/libarchive/include")
set(LibArchive_LIBRARY_DIR "/opt/homebrew/opt/libarchive/lib")

find_package(LibArchive REQUIRED)

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
  libarchive.a
)

