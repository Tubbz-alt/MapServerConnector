/**
 * @file    ArcGIS_Connector.cpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#include "ArcGIS_Connector.hpp"

// MSC Libraries
#include "../utilities/Log_Utilities.hpp"


// C++ Libraries
#include <sstream>


namespace MSC{


/*************************************/
/*        ArcGIS Constructor         */
/*************************************/
ArcGIS_Connector::ArcGIS_Connector( Configuration const& configuration )
 : Base_Connector( configuration ),
   m_class_name("ArcGIS_Connector"),
   m_curl(nullptr)
{
    // Log Entry
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", Start of Method.";
    
    // Create the network connection
    curl_global_init(CURL_GLOBAL_DEFAULT);
    m_curl = curl_easy_init();

    // Misc Variables
    Status status;

    // Get the URL
    m_url = configuration.Get_Value("url", status);

    // Log Exit
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", End of Method";
    
}


/********************************/
/*         Destructor           */
/********************************/
ArcGIS_Connector::~ArcGIS_Connector()
{
    // Log entry
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", Start of Destructor";
    
    // Check if still connected
    if( Is_Connected() == true )
    {
        Status status;
        Disconnect( status );
    }

    // Log Exit
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", End of Destructor";
}


/****************************/
/*          Connect         */
/****************************/
void ArcGIS_Connector::Connect( Status& status )
{
    // Check the initialization
    if( m_curl == nullptr || 
        m_curl == NULL )
    {
        status = Status( StatusCode::CONNECTION_ERROR,
                         "curl failed to initialize");
        return;
    }
    
    // Setup CURL
    char* typeinfo;
    CURLcode cresult;
    

    // Construct URL
    std::string url = Create_Get_Capabilities_Query();
    BOOST_LOG_TRIVIAL(debug) << CLASS_LOG << ", Constructing Feature Query: " << url;
    curl_easy_setopt( m_curl,
                      CURLOPT_URL,
                      url.c_str());
    
    
    // Create callbacks and data
    curl_easy_setopt( m_curl, 
                      CURLOPT_WRITEFUNCTION, 
                      &OGC_Connector::Callback_Handler );
    curl_easy_setopt( m_curl,
                      CURLOPT_WRITEDATA,
                      this );
    curl_easy_setopt(m_curl, CURLOPT_VERBOSE, 1L);

    cresult = curl_easy_perform(m_curl);
    

    /*
    curl_easy_getinfo( image, CURLINFO_CONTENT_TYPE, &typeinfo);
    imgresult = curl_easy_perform(image);
    */
   

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

/*******************************************/
/*        Construct a Get Map Query        */
/*******************************************/
std::string ArcGIS_Connector::Create_Get_Map_Query( MapRequest const& request )
{
    // Create output stream
    std::stringstream sin;
    sin << m_url << request.To_ArcGIS_URL();

    return sin.str();
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

