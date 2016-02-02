/**
 * @file    MapServiceConnector.cpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#include "MapServiceConnector.hpp"

// MSC Libraries
#include "Base_Connector.hpp"
#include "Connection_Generator_Factory.hpp"
#include "utilities/Log_Utilities.hpp"

namespace MSC{


/**********************************/
/*          Constructor           */
/**********************************/
MapServiceConnector::MapServiceConnector( Configuration const& configuration )
  : m_class_name("MapServiceConnector"),
    m_connection_manager(nullptr),
    m_configuration(configuration)
{
    // Log Entry
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", Start of Constructor";

    // Misc Variables
    Status status;

    m_connection_manager = Connection_Generator_Factory::Create( configuration, 
                                                                 status );
    
    
    // Log Exit
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", End of Constructor";

}


/**********************************/
/*          Destructor            */
/**********************************/
MapServiceConnector::~MapServiceConnector()
{
    // Log Entry
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", Start of Destructor";

    // Log Exit
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", End of Destructor";
}

/*****************************************/
/*     Connect to the Remote System      */
/*****************************************/
void MapServiceConnector::Connect( Status& status )
{
    
    // Check if the connector manager exists
    if( m_connection_manager == nullptr )
    {
        status = Status( StatusCode::NO_CONNECTOR_FOUND,
                         "Connection-Manager is currently null.");
        return;
    }

    //  Connect
    m_connection_manager->Connect( status );
    if( status.Get_Code() != StatusCode::SUCCESS ){
        return;
    }
    

    // Return success
    status = Status(StatusCode::SUCCESS);
}


/*******************************************/
/*          Disconnect the System          */
/*******************************************/
void MapServiceConnector::Disconnect( Status& status )
{
    // Default the status to success
    status = Status(StatusCode::SUCCESS);
    
    // Check if connected
    if( Is_Connected() == true ){
        m_connection_manager->Disconnect( status );
    }
}


/**********************************************/
/*         Check the Connection Status        */
/**********************************************/
bool MapServiceConnector::Is_Connected()const
{
    // Check manager if null
    if( m_connection_manager == nullptr ){
        return false;
    }

    // Check status
    return m_connection_manager->Is_Connected();
}


/*******************************************/
/*          Get the Requested Map          */
/*******************************************/
MapResponse MapServiceConnector::Get_Map( MapRequest const& request )
{ 
    // Check manager if null
    if( m_connection_manager == nullptr ){
        return MapResponse(Status(StatusCode::NO_CONNECTOR_FOUND,
                                  "Map-Connector is null"));
    }

    // return response
    return m_connection_manager->Get_Map(request);
}


}  // End of Namespace MSC

