/**
 * @file    Initialization.cpp
 * @author  Marvin Smith
 * @date    1/30/2016
*/
#include "Initialization.hpp"


// MSC Libraries
#include "Connection_Generator_Factory.hpp"
#include "esri/ArcGIS_Connector.hpp"
#include "ogc/OGC_Connector.hpp"
#include "utilities/Log_Utilities.hpp"


// C++ Libraries
#include <memory>


namespace MSC{

/// Global Status
static bool init_status = false;

/********************************************/
/*          Initialize the Service          */
/********************************************/
Status Initialize( Configuration const& configuration )
{
    // Result Status
    Status status;


    // Initialize Logging
    std::string log_level = configuration.Get_Value( "log_severity", "info", status );
    std::string log_path  = configuration.Get_Value( "log_path", "output.log", status );
    Initialize_Logger( log_level, log_path );

    // Initialize the Connection Generator Factory
    status = Initialize_Connection_Generator_Factory();
    
    // Check the Status
    if( status.Get_Code() != StatusCode::SUCCESS ){
        return status;
    }

    
    // Return Success
    init_status = true;
    return Status(StatusCode::SUCCESS);
}


/************************************************/
/*          Finalize the Map Service            */
/************************************************/
Status Finalize( )
{
    // Clear the Factory
    Status status = Connection_Generator_Factory::Finalize();


    // Return Success
    init_status = false;
    return status;
}

/**********************************************/
/*      Return the Initialization Status      */
/**********************************************/
bool Is_Initialized()
{
    return init_status;
}


/**************************************************************/
/*          Initialize the Connector Generator Factory        */
/**************************************************************/
Status Initialize_Connection_Generator_Factory()
{
    // Initialize the Generator
    Status status(StatusCode::SUCCESS);
    status = Connection_Generator_Factory::Initialize();
    if( status.Get_Code() != StatusCode::SUCCESS ){
        return status;
    }

    // Add each factory
    status.Update( Connection_Generator_Factory::Add_Generator("ogc",  std::make_shared<OGC_Connector_Generator>()));
    status.Update( Connection_Generator_Factory::Add_Generator("esri", std::make_shared<ArcGIS_Connector_Generator>()));


    // Return Success
    return status;
}


} // End of MSC Namespace

