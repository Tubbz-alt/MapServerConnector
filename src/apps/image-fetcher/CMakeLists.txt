#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    1/27/2016
#
#    Purpose:  Image Fetcher
#


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
)

