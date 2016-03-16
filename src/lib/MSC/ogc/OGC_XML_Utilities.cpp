/**
 * @file    OGC_XML_Utilities.cpp
 * @author  Marvin Smith
 * @date    3/15/2016
*/
#include "OGC_XML_Utilities.hpp"

// C++ Libraries
#include "../utilities/Log_Utilities.hpp"


namespace MSC{
namespace OGC{


/********************************************************/
/*          Process the WMS 1.3.0 Service Node          */
/********************************************************/
void Parse_WMS_1_3_0_Service_Node( Capabilities::ptr_t capabilities,
                                   pugi::xml_node&     root_node,
                                   Status&             status )
{
    
    // Iterate over child nodes
    std::string node_name;
    pugi::xml_node_iterator nit = root_node.begin();
    for( ; nit != root_node.end(); nit++ )
    {
        node_name = nit->name();

        // Check if Name Node
        if( node_name == "Name" ){
            capabilities->Set_Service_Name( nit->value() );
        }
        
        // Otherwise, print warning
        else{
            BOOST_LOG_TRIVIAL(warning) << "Found unknown node: " << nit->name();
        }
    }

    // Return Success
    status = Status(StatusCode::SUCCESS);

}



} // End of OGC Namespace
} // End of MSC Namespace

