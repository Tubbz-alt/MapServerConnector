#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    3/11/2016
#
#    Purpose: Build the C++ OpenCV Image Comparison Tool.
#


#  Configure C++11
set( CMAKE_CXX_FLAGS "-std=c++11 -Wall")

#---------------------------------#
#-     Change the Output Path    -#
#---------------------------------#
SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )
SET( LIBRARY_OUTPUT_PATH    ${PROJECT_BINARY_DIR}/lib )


#--------------------#
#-    Find GDAL     -#
#--------------------#
find_package(GDAL REQUIRED)
include_directories( ${GDAL_INCLUDE_DIRS})


#--------------------#
#-    Find OpenCV   -#
#--------------------#
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDES} )


#-------------------#
#-    Find Boost   -#
#-------------------#
set( Boost_USE_STATIC_LIBS OFF )
set( Boost_USE_MULTITHREADED ON )
find_package(Boost REQUIRED
                COMPONENTS
                system
                filesystem
            )
include_directories(${Boost_INCLUDE_DIRS})


#---------------------------#
#-      Configure Qt5      -#
#---------------------------#
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDES})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
add_definitions(${Qt5Widgets_DEFINITIONS})


#----------------------------------#
#-      Add MSC to the path       -#
#----------------------------------#
include_directories(../../lib)



#----------------------------#
#-    Define the Sources    -#
#----------------------------#
set( MSC_VIEWER_SOURCES
    msc-viewer.cpp
    Options.cpp
    Options.hpp
    gui/AddServiceWidget.cpp
    gui/AddServiceWidget.hpp
    gui/MainWindow.cpp
    gui/MainWindow.hpp
    gui/MapViewerWidget.cpp
    gui/MapViewerWidget.hpp
    gui/ServiceListWidget.cpp
    gui/ServiceListWidget.hpp
    gui/ToolbarWidget.cpp
    gui/ToolbarWidget.hpp
    gui/ViewerStatusWidget.cpp
    gui/ViewerStatusWidget.hpp
    log/LogHandler.cpp
    log/LogHandler.hpp
    utils/FilePath.cpp
    utils/FilePath.hpp
    utils/String_Utilities.cpp
    utils/String_Utilities.hpp
)



#--------------------------------#
#-     Build the Executable     -#
#--------------------------------#
add_executable( msc-viewer
                ${MSC_VIEWER_SOURCES}
)



#-------------------------------#
#-     Link the Executable     -#
#-------------------------------#
target_link_libraries( msc-viewer
                       MSC
                       ${GDAL_LIBRARY}
                       ${OpenCV_LIBRARIES}
                       ${Boost_LIBRARIES}
                       ${Qt5Widgets_LIBRARIES})

