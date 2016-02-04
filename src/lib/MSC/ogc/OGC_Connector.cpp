/**
 * @file    OGC_Connector.cpp
 * @author  Marvin Smith
 * @date    1/29/2016
*/
#include "OGC_Connector.hpp"

// C++ Libraries
#include <iostream>
#include <string>

// MSC Libraries
#include "../utilities/Log_Utilities.hpp"


namespace MSC{


/***********************************************/
/*          OGC Connector Constructor          */
/***********************************************/
OGC_Connector::OGC_Connector( Configuration const& configuration )
 : Base_Connector( configuration ),
   m_class_name("OGC_Connector"),
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

    // Get WMS info
    m_wms_version = configuration.Get_Value("wms_version", status);
    
    // Log Exit
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", End of Method.";
}


/********************************/
/*         Destructor           */
/********************************/
OGC_Connector::~OGC_Connector()
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
void OGC_Connector::Connect( Status& status )
{
    
    // Check the initialization
    if( m_curl == nullptr ||
        m_curl == NULL )
    {
        status = Status( StatusCode::CONNECTION_ERROR,
                         "curl failed to initialize.");
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
                      &OGC_Connector::Init_Callback_Handler );
    curl_easy_setopt( m_curl,
                      CURLOPT_WRITEDATA,
                      this );
    //curl_easy_setopt(m_curl, CURLOPT_VERBOSE, 1L);

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
void OGC_Connector::Disconnect( Status& status )
{
    // Log Entry
    BOOST_LOG_TRIVIAL(debug) << CLASS_LOG << ", Disconnecting from OGC Connector.";

    // Finalize Curl
    curl_easy_cleanup(m_curl);
    curl_global_cleanup();
    
    // Set the connection status
    m_is_connected = false;

    // Return success
    status = Status(StatusCode::SUCCESS);
}


/*************************************************/
/*          Create a Get Features Query          */
/*************************************************/
std::string OGC_Connector::Create_Get_Capabilities_Query()const
{
    // Create string
    std::string output = m_url + "?SERVICE=WMS&";
    
    // Add the version
    output += "VERSION=" + m_wms_version + "&REQUEST=GetCapabilities";

    return output;
}


/**********************************************/
/*          Create a Get Map Query            */
/**********************************************/
std::string OGC_Connector::Create_Get_Map_Query( const MapRequest& request )
{
    // Create string
    std::string output = m_url + "?SERVICE=WMS&";

    // Add the version
    output += "VERSION=" + m_wms_version;

    // Add the request string
    output += request.To_WMS_URL();

    return output;
}


/************************************/
/*          Callback Handler        */
/************************************/
size_t OGC_Connector::Init_Callback_Handler( void *ptr, 
                                             size_t size,
                                             size_t nmemb, 
                                             void* pInstance )
{
    
    // Compute buffer size
    size_t num_bytes = size * nmemb;
    
    
    // Cast the instance
    OGC_Connector* inst = static_cast<OGC_Connector*>(pInstance);
    
    // Create iterators
    char *iter = (char*)ptr;
    char *iterEnd = iter + num_bytes;

    inst->m_features_output = std::string(iter,iterEnd);

    // Cast the handler
    return num_bytes;
}


/****************************************/
/*          Callback Handler            */
/****************************************/
size_t  OGC_Connector::Get_Map_Callback_Handler( void*  ptr,
                                                 size_t size,
                                                 size_t nmemb,
                                                 void*  pInstance )
{
    // Compute the buffer size
    size_t num_bytes = size * nmemb;

    // Cast the instance
    OGC_Connector* inst = static_cast<OGC_Connector*>(pInstance);

    // Create iterators
    char* iter = (char*)ptr;
    char* iterEnd = iter + num_bytes;

    // Allocate buffer
    char* buffer = (char*)ptr;
    

    // Push to the features
    inst->m_latest_response.Append_Image_Buffer( buffer,
                                                 num_bytes );
    
    return num_bytes;
}


/**********************************/
/*           Get the map          */
/**********************************/
MapResponse OGC_Connector::Get_Map( MapRequest const& request )
{
    // Log Entry
    BOOST_LOG_TRIVIAL(debug) << "Start of Get_Map Request.";

    // Create response
    CURLcode cresult;

    // Create URL
    std::string url = Create_Get_Map_Query( request );


    BOOST_LOG_TRIVIAL(debug) << CLASS_LOG << ", Constructing Get Map Query: " << url;
    curl_easy_setopt( m_curl,
                      CURLOPT_URL,
                      url.c_str());
    
    
    // Create callbacks and data
    curl_easy_setopt( m_curl, 
                      CURLOPT_WRITEFUNCTION, 
                      &OGC_Connector::Get_Map_Callback_Handler );
    curl_easy_setopt( m_curl,
                      CURLOPT_WRITEDATA,
                      this );
    //curl_easy_setopt(m_curl, CURLOPT_VERBOSE, 1L);

    cresult = curl_easy_perform(m_curl);

    // Request
    m_latest_response.Set_Status(Status(StatusCode::NOT_IMPLEMENTED_YET));
    
    // Log Entry
    BOOST_LOG_TRIVIAL(debug) << "End of Get_Map Request.";

    // Return response
    return m_latest_response;
}


/********************************************************/
/*          Constructor of Connector Generator          */
/********************************************************/
OGC_Connector_Generator::OGC_Connector_Generator()
 : m_class_name("OGC_Connector_Generator")
{
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", Running Constructor.";
}


/**********************************************/
/*            Create the Generator            */
/**********************************************/
Base_Connector::ptr_t  OGC_Connector_Generator::Create( const Configuration& configuration,
                                                        Status&              status )
{
    // Return the connector
    status = Status(StatusCode::SUCCESS);
    return std::make_shared<OGC_Connector>( configuration );
}


} // End of MSC Namespace
