#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    1/27/2016
#
#    Purpose:  Image Fetcher
#


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


#----------------------------------------#
#-        Find OpenCV Libraries         -#
#----------------------------------------#
find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

#-------------------------------#
#-        Header Files         -#
#-------------------------------#
set( IMAGE_FETCHER_HEADERS
)


#-------------------------------#
#-        Source Files         -#
#-------------------------------#
set( IMAGE_FETCHER_SOURCES
     main.cpp
)


#----------------------------------#
#-      Add MSC to the path       -#
#----------------------------------#
include_directories(../../lib)

#----------------------------------#
#-     Build the Application      -#
#----------------------------------#
add_executable( image-fetcher
                ${IMAGE_FETCHER_SOURCES}
                ${IMAGE_FETCHER_HEADERS} )


#-------------------------------------------#
#-     Link against required libraries     -#
#-------------------------------------------#
target_link_libraries( image-fetcher
                       MSC
                       pthread
                       ${Boost_LIBRARIES}
                       ${OpenCV_LIBS}
)

