#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    1/27/2016
#
#    Purpose:  Create library
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



#---------------------#
#-     Find Curl     -#
#---------------------#
find_package(CURL)
include_directories(${CURL_INCLUDE_DIRS})


#--------------------------#
#-       Find GDAL        -#
#--------------------------#
find_package( GDAL )
include_directories( ${GDAL_INCLUDE_DIR} )

#------------------------------#
#-    Project Source Files    -#
#------------------------------#
set( LIBRARY_SOURCES
     MSC/Base_Connector.cpp
     MSC/Capabilities.cpp
     MSC/Connection_Generator_Factory.cpp
     MSC/Configuration.cpp 
     MSC/Enumerations.cpp
     MSC/Initialization.cpp
     MSC/MapRequest.cpp
     MSC/MapServiceConnector.cpp
     MSC/MapServiceConnectorFactory.cpp
     MSC/Status.cpp
     MSC/esri/ArcGIS_Connector.cpp
     MSC/io/ConfigParser.cpp
     MSC/ogc/OGC_Capabilities.cpp
     MSC/ogc/OGC_Connector.cpp
     MSC/ogc/OGC_XML_Utilities.cpp
     MSC/thirdparty/pugixml/src/pugixml.cpp
     MSC/utilities/GDAL_Utilities.cpp
     MSC/utilities/Log_Utilities.cpp
)


#---------------------------------#
#-     Project Header Files      -#
#---------------------------------#
set( LIBRARY_HEADERS
     MSC.hpp
     MSC/Base_Connector.hpp
     MSC/Capabilities.hpp
     MSC/Connection_Generator_Factory.hpp
     MSC/Configuration.hpp
     MSC/Enumerations.hpp
     MSC/Initialization.hpp
     MSC/MapRequest.hpp
     MSC/MapServiceConnector.hpp
     MSC/MapServiceConnectorFactory.hpp
     MSC/Status.hpp
     MSC/esri/ArcGIS_Connector.hpp
     MSC/io/ConfigParser.hpp
     MSC/ogc/OGC_Capabilities.hpp
     MSC/ogc/OGC_Connector.hpp
     MSC/ogc/OGC_XML_Utilities.hpp
     MSC/thirdparty/pugixml/src/pugixml.hpp
     MSC/thirdparty/pugixml/src/pugiconfig.hpp
     MSC/utilities/GDAL_Utilities.hpp
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
                       ${GDAL_LIBRARY} 
)

