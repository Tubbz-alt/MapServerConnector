/**
 * @file    OGC_Capabilities.cpp
 * @author  Marvin Smith
 * @date    3/14/2016
*/
#include "OGC_Capabilities.hpp"

// PugiXML
#include "../thirdparty/pugixml/src/pugixml.hpp"
#include "../utilities/Log_Utilities.hpp"
#include "OGC_XML_Utilities.hpp"


// C++ Libraries
#include <iostream>
#include <stdexcept>


namespace MSC{
namespace OGC{

/***********************************/
/*          Constructor            */
/***********************************/
Capabilities::Capabilities()
 : MSC::Capabilities(),
   m_class_name("Capabilities")
{


}


/***************************************/
/*          Print to String            */
/***************************************/
std::string Capabilities::ToString()const
{
    return "";
}


/**************************************/
/*          Convert to String         */
/**************************************/
Capabilities::ptr_t Capabilities::Parse_WMS_1_3_0( const std::string&  contents,
                                                   Status&             status )
{
    //  Create the PugiXML Document
	pugi::xml_document xmldoc;
	pugi::xml_parse_result result = xmldoc.load_string( contents.c_str() );

    // check for loading errors
	if( result == false ){
		status = Status( StatusCode::INVALID_FORMAT,
                         "Unable to parse WMS Capabilities data.");
		return nullptr;
	}

    // XML Queries
    const std::string ROOT_NODE_QUERY = "WMS_Capabilities";
    //version="1.3.0" xmlns="http://www.opengis.net/wms" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://www.opengis.net/wms http://schemas.opengis.net/wms/1.3.0/capabilities_1_3_0.xsd">

    // Create Capabilities Object
    Capabilities::ptr_t cap = std::make_shared<Capabilities>();
    Status temp_status;

    try
    {

        // Get the Root Node
        pugi::xml_node root_node = xmldoc.child(ROOT_NODE_QUERY.c_str());
        if( root_node == pugi::xml_node() ){
            throw std::runtime_error("No Root Node Found.");
        }

        //  Start Iterating Over Nodes
        pugi::xml_node_iterator nit = root_node.begin();
        for( ; nit != root_node.end(); nit++ )
        {
            // Process the Service node
            if( std::string(nit->name()) == "Service" ){
                
               Parse_WMS_1_3_0_Service_Node( cap, (*nit), temp_status );
               if( temp_status.Get_Code() != StatusCode::SUCCESS ){
                    throw std::runtime_error("Unable to Parse Service Node. Details: " + temp_status.ToString());
               }
            }

            // Process the Capability Node
            else if( std::string(nit->name()) == "Capability" ){
                
                std::cout << "Processing Capability Node" << std::endl;
            }

            // Otherwise, error
            else{
                BOOST_LOG_TRIVIAL(warning) << "Unknown Node: " << nit->name();
            }

        }

    }
    catch( std::exception& e )
    {
        status = Status(StatusCode::INVALID_FORMAT,
                        "WMS Get Capabilities has invalid structure. " + std::string(e.what()));
        return nullptr;
    }
    catch(...){
        status = Status(StatusCode::INVALID_FORMAT,
                        "WMS Get Capabilities has invalid structure.");
        return nullptr;
    }

    // Return Success
    status = Status( StatusCode::SUCCESS );
    return cap;
}

} // End of OGC Namespace
} // End of MSC Namespace

