/**
 * @file    MapServiceConnectorFactory.cpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#include "MapServiceConnectorFactory.hpp"

namespace MSC{


/****************************/
/*      Static Method       */
/****************************/
MapServiceConnector::ptr_t MapServiceConnectorFactory::Create( const std::string& config_pathname,
                                                               Status&            status )
{
    // Create output
    MapServiceConnector::ptr_t connector = std::make_shared<MapServiceConnector>();
    
    
    return connector;

    // Return output
    return nullptr;
}


} // End of MSC Namespace

