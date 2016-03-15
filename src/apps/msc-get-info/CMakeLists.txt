#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    3/14/2016
#
#    Purpose:  MSC-Get-Info Application
#


#  Configure C++11
set( CMAKE_CXX_FLAGS "-std=c++11 -Wall")

#---------------------------------#
#-     Change the Output Path    -#
#---------------------------------#
SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )
SET( LIBRARY_OUTPUT_PATH    ${PROJECT_BINARY_DIR}/lib )




#---------------------------------#
#-     Find Boost Libraries      -#
#---------------------------------#
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
find_package( Boost REQUIRED
                COMPONENTS
                    system
                    filesystem
                    regex
                    log
                    thread
)
include_directories( ${Boost_INCLUDE_DIRS})


#-------------------------------#
#-        Header Files         -#
#-------------------------------#
set( MSC_GET_INFO_HEADERS
)


#-------------------------------#
#-        Source Files         -#
#-------------------------------#
set( MSC_GET_INFO_SOURCES
     msc-get-info.cpp
)


#----------------------------------#
#-      Add MSC to the path       -#
#----------------------------------#
include_directories(../../lib)

#----------------------------------#
#-     Build the Application      -#
#----------------------------------#
add_executable( msc-get-info
                ${MSC_GET_INFO_SOURCES}
                ${MSC_GET_INFO_HEADERS} )


#-------------------------------------------#
#-     Link against required libraries     -#
#-------------------------------------------#
target_link_libraries( msc-get-info
                       MSC
                       pthread
                       ${Boost_LIBRARIES}
                       ${OpenCV_LIBS}
)

