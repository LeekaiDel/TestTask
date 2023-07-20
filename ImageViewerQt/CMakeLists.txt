cmake_minimum_required(VERSION 3.5)

project(ImageViewerQt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core REQUIRED)    
find_package(Qt5Gui REQUIRED) 
find_package(Qt5Widgets REQUIRED) 

find_package(Eigen3 REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        
        imageviewer.cpp
        imageviewer.h
        imageviewer.ui

        enterpathwin.cpp
        enterpathwin.h
        enterpathwin.ui
        
        rgbsliders.h
        rgbsliders.cpp
        rgbsliders.ui
        
        setcontrast.h
        setcontrast.cpp
        setcontrast.ui

        translate.h
        translate.cpp
        translate.ui

        gaussianblur.h
        gaussianblur.cpp

        saveresult.h
        saveresult.cpp
        saveresult.ui
)

add_executable(ImageViewerQt ${PROJECT_SOURCES})

target_link_libraries(ImageViewerQt PRIVATE Qt5::Widgets Eigen3::Eigen)

set_target_properties(ImageViewerQt PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

