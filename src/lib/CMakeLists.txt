#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    1/27/2016
#
#    Purpose:  Create library
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
     MSC/Connection_Generator_Factory.cpp
     MSC/Configuration.cpp 
     MSC/Initialization.cpp
     MSC/MapServiceConnector.cpp
     MSC/MapServiceConnectorFactory.cpp
     MSC/Status.cpp
     MSC/esri/ArcGIS_Connector.cpp
     MSC/io/ConfigParser.cpp
     MSC/ogc/OGC_Connector.cpp
     MSC/utilities/Log_Utilities.cpp
)


#---------------------------------#
#-     Project Header Files      -#
#---------------------------------#
set( LIBRARY_HEADERS
     MSC.hpp
     MSC/Base_Connector.hpp
     MSC/Connection_Generator_Factory.hpp
     MSC/Configuration.hpp
     MSC/Initialization.hpp
     MSC/MapServiceConnector.hpp
     MSC/MapServiceConnectorFactory.hpp
     MSC/Status.hpp
     MSC/esri/ArcGIS_Connector.hpp
     MSC/io/ConfigParser.hpp
     MSC/ogc/OGC_Connector.hpp
     MSC/utilities/Log_Utilities.hpp
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
                       ${Boost_LIBRARIES}
)

