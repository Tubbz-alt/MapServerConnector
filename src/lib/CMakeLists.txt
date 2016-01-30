#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    1/27/2016
#
#    Purpose:  Create library
#


#---------------------#
#-     Find Curl     -#
#---------------------#
find_package(CURL)
include_directories(${CURL_INCLUDE_DIRS})


#------------------------------#
#-    Project Source Files    -#
#------------------------------#
set( LIBRARY_SOURCES
     MSC/Base_Connector.cpp
     MSC/Configuration.cpp
     MSC/MapServiceConnector.cpp
     MSC/MapServiceConnectorFactory.cpp
     MSC/Status.cpp
     MSC/esri/ArcGIS_Connector.cpp
     MSC/io/ConfigParser.cpp
     MSC/ogc/OGC_Connector.cpp
)


#---------------------------------#
#-     Project Header Files      -#
#---------------------------------#
set( LIBRARY_HEADERS
     MSC.hpp
     MSC/Base_Connector.hpp
     MSC/Configuration.hpp
     MSC/MapServiceConnector.hpp
     MSC/MapServiceConnectorFactory.hpp
     MSC/Status.hpp
     MSC/esri/ArcGIS_Connector.hpp
     MSC/io/ConfigParser.hpp
     MSC/ogc/OGC_Connector.hpp
)


#----------------------------#
#-      Create Library      -#
#----------------------------#
add_library(MSC SHARED
            ${LIBRARY_SOURCES}
            ${LIBRARY_HEADERS}
)
            
target_link_libraries( MSC             
                       ${CURL_LIBRARIES}
)

