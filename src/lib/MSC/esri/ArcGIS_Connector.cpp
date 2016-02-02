/**
 * @file    ArcGIS_Connector.cpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#include "ArcGIS_Connector.hpp"


namespace MSC{


/*************************************/
/*        ArcGIS Constructor         */
/*************************************/
ArcGIS_Connector::ArcGIS_Connector( Configuration const& configuration )
 : Base_Connector( configuration ),
   m_class_name("ArcGIS_Connector"),
   m_curl(nullptr)
{

}


/********************************/
/*         Destructor           */
/********************************/
ArcGIS_Connector::~ArcGIS_Connector()
{
    // Check if still connected
    if( Is_Connected() == true )
    {
        Status status;
        Disconnect( status );
    }
}


/****************************/
/*          Connect         */
/****************************/
void ArcGIS_Connector::Connect( Status& status )
{
    // Create the network connection
    curl_global_init(CURL_GLOBAL_ALL);
    m_curl = curl_easy_init();

    
    // Set the Connection Status
    m_is_connected = true;

    // Return success
    status = Status(StatusCode::SUCCESS);
}


/*********************************/
/*          Disconnect           */
/*********************************/
void ArcGIS_Connector::Disconnect( Status& status )
{
    // Finalize Curl
    curl_easy_cleanup(m_curl);
    curl_global_cleanup();
    
    // Set the connection status
    m_is_connected = false;

    // Return success
    status = Status(StatusCode::SUCCESS);
}


/*********************************/
/*       Get the Request         */
/*********************************/
MapResponse  ArcGIS_Connector::Get_Map( MapRequest const& request )
{
    return MapResponse(Status(StatusCode::NOT_IMPLEMENTED_YET,
                              "ArcGIS_Connector Get_Map not implemented yet."));
}


/********************************************************/
/*          Constructor of Connector Generator          */
/********************************************************/
ArcGIS_Connector_Generator::ArcGIS_Connector_Generator()
 : m_class_name("ArcGIS_Connector_Generator")
{
}



/**********************************************/
/*            Create the Generator            */
/**********************************************/
Base_Connector::ptr_t  ArcGIS_Connector_Generator::Create( const Configuration& configuration,
                                                           Status&              status )
{
    // Return the connector
    status = Status(StatusCode::SUCCESS);
    return std::make_shared<ArcGIS_Connector>( configuration );
}


} // End of MSC Namespace

