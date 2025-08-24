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

# Create executable - app bundle for macOS release, regular executable otherwise
if(APPLE AND CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(NixRar MACOSX_BUNDLE
        main.cpp
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
    
    # macOS App Bundle properties
    set_target_properties(NixRar PROPERTIES
        MACOSX_BUNDLE_BUNDLE_NAME "NixRar"
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION}
        MACOSX_BUNDLE_IDENTIFIER "com.nixrar.NixRar"
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.nixrar.NixRar"
        MACOSX_BUNDLE_EXECUTABLE_NAME "NixRar"
        MACOSX_BUNDLE_DISPLAY_NAME "NixRar Archive Manager"
        MACOSX_BUNDLE_COPYRIGHT "© 2024 NixRar Development Team"
        MACOSX_BUNDLE_ICON_FILE "nixrar.icns"
        MACOSX_BUNDLE_INFO_STRING "Modern cross-platform archive manager"
        # RPATH settings for proper Qt framework loading
        BUILD_WITH_INSTALL_RPATH TRUE
        INSTALL_RPATH "@executable_path/../Frameworks"
        INSTALL_RPATH_USE_LINK_PATH TRUE
    )
else()
    add_executable(NixRar 
        main.cpp
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
endif()

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

# Platform-specific install configuration
if(APPLE AND CMAKE_BUILD_TYPE STREQUAL "Release")
    # macOS App Bundle installation
    install(TARGETS NixRar
        BUNDLE DESTINATION .
        RUNTIME DESTINATION .
    )
    
    # Install app icon into the bundle
    install(FILES resources/nixrar.icns
        DESTINATION NixRar.app/Contents/Resources
    )
    
    # Configure Info.plist template
    set_target_properties(NixRar PROPERTIES
        MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/resources/Info.plist.in
    )
    
    # Find Qt deployment tool and Qt installation paths
    find_program(MACDEPLOYQT_EXECUTABLE macdeployqt HINTS ${Qt6_DIR}/../../../bin)
    
    # Determine Qt framework path
    get_target_property(QT_CORE_LOCATION Qt6::Core LOCATION)
    get_filename_component(QT_FRAMEWORK_DIR "${QT_CORE_LOCATION}" DIRECTORY)
    get_filename_component(QT_FRAMEWORK_DIR "${QT_FRAMEWORK_DIR}" DIRECTORY)
    get_filename_component(QT_FRAMEWORK_DIR "${QT_FRAMEWORK_DIR}" DIRECTORY)
    get_filename_component(QT_LIB_DIR "${QT_FRAMEWORK_DIR}" DIRECTORY)
    
    message(STATUS "Qt framework directory: ${QT_FRAMEWORK_DIR}")
    message(STATUS "Qt lib directory: ${QT_LIB_DIR}")
    
    # Custom target to run macdeployqt
    if(MACDEPLOYQT_EXECUTABLE)
        add_custom_target(deploy_qt
            COMMAND ${MACDEPLOYQT_EXECUTABLE} "$<TARGET_FILE_DIR:NixRar>/../.." 
                -verbose=2
                -libpath="${QT_LIB_DIR}"
                -always-overwrite
            DEPENDS NixRar
            COMMENT "Deploying Qt libraries to app bundle"
        )
        
        # Create a package target that builds and deploys
        add_custom_target(package_macos
            COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target install
            COMMAND ${CMAKE_COMMAND} -E echo "Deploying Qt frameworks from: ${QT_LIB_DIR}"
            COMMAND ${MACDEPLOYQT_EXECUTABLE} "${CMAKE_INSTALL_PREFIX}/NixRar.app" 
                -verbose=2
                -libpath="${QT_LIB_DIR}"
                -always-overwrite || true
            COMMAND ${CMAKE_COMMAND} -E echo "Running fallback deployment fix if needed..."
            COMMAND bash ${CMAKE_CURRENT_SOURCE_DIR}/scripts/fix-macos-deployment.sh "${CMAKE_INSTALL_PREFIX}/NixRar.app" || true
            COMMAND codesign --force --deep --sign - "${CMAKE_INSTALL_PREFIX}/NixRar.app" || true
            DEPENDS NixRar
            COMMENT "Creating distributable macOS app bundle"
        )
        
        # Optional: Create DMG target (requires create-dmg or hdiutil)
        find_program(HDIUTIL_EXECUTABLE hdiutil)
        if(HDIUTIL_EXECUTABLE)
            add_custom_target(create_dmg
                COMMAND ${CMAKE_COMMAND} -E remove_directory "${CMAKE_BINARY_DIR}/dmg_temp"
                COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/dmg_temp"
                COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_INSTALL_PREFIX}/NixRar.app" "${CMAKE_BINARY_DIR}/dmg_temp/NixRar.app"
                COMMAND ${CMAKE_COMMAND} -E create_symlink /Applications "${CMAKE_BINARY_DIR}/dmg_temp/Applications"
                COMMAND ${HDIUTIL_EXECUTABLE} create -volname "NixRar ${PROJECT_VERSION}" -srcfolder "${CMAKE_BINARY_DIR}/dmg_temp" -ov -format UDZO "${CMAKE_BINARY_DIR}/NixRar-${PROJECT_VERSION}-macOS.dmg"
                DEPENDS package_macos
                COMMENT "Creating DMG installer for macOS"
            )
        endif()
        
        # Convenience target that creates both app bundle and DMG
        if(HDIUTIL_EXECUTABLE)
            add_custom_target(package
                DEPENDS create_dmg
                COMMENT "Creating complete macOS distribution package"
            )
        else()
            add_custom_target(package
                DEPENDS package_macos
                COMMENT "Creating macOS app bundle (DMG creation not available)"
            )
        endif()
    endif()
    
elseif(UNIX AND NOT APPLE)
    # Linux installation
    install(TARGETS NixRar
        RUNTIME DESTINATION bin
    )
    
    # Linux desktop integration
    install(FILES resources/nixrar.desktop
        DESTINATION share/applications
    )
    install(FILES resources/nixrar.png
        DESTINATION share/icons/hicolor/256x256/apps
    )
else()
    # Windows or other platforms
    install(TARGETS NixRar
        RUNTIME DESTINATION bin
    )
endif()

