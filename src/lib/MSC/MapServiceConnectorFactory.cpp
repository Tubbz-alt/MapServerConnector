/**
 * @file    MapServiceConnectorFactory.cpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#include "MapServiceConnectorFactory.hpp"

// MSC Libraries
#include "Initialization.hpp"
#include "io/ConfigParser.hpp"

// C++ Libraries
#include <iostream>

namespace MSC{


/****************************/
/*      Static Method       */
/****************************/
MapServiceConnector::ptr_t MapServiceConnectorFactory::Create( const std::string& config_pathname,
                                                               Status&            status )
{
    // Load the Configuration
    Configuration options = ConfigParser(config_pathname).Load_Configuration(status);
    
    // Check if Initialized
    if( Is_Initialized() == false ){
        status = Initialize( options );
        if( status.Get_Code() != StatusCode::SUCCESS ){
            return nullptr;
        }
    }
    

    // Check the status
    if( status.Get_Code() != StatusCode::SUCCESS ){
        return nullptr;
    }

    // Load and return the new connector
    MapServiceConnector::ptr_t connector = std::make_shared<MapServiceConnector>( options );

    // Return Success
    status = Status( StatusCode::SUCCESS );
    return connector;
}


} // End of MSC Namespace

