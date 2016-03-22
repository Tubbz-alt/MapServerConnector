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
    // Log Entry
    BOOST_LOG_TRIVIAL(debug) << "Parsing WMS 1.3.0 Service XML Node.";

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


/***********************************************************/
/*          Process the WMS 1.3.0 Capability Node          */
/***********************************************************/
void Parse_WMS_1_3_0_Capability_Node( Capabilities::ptr_t capabilities,
                                      pugi::xml_node&     root_node,
                                      Status&             status )
{
    // Log Entry
    BOOST_LOG_TRIVIAL(debug) << "Parsing WMS 1.3.0 Capability XML Node.";

    // Iterate over child nodes
    std::string node_name;
    pugi::xml_node_iterator nit = root_node.begin();
    for( ; nit != root_node.end(); nit++ )
    {
        node_name = nit->name();

        // Check if Request Node
        if( node_name == "Request" )
        {
             
            // Parse the Request Node
            Parse_WMS_1_3_0_Request_Node( capabilities,
                                         (*nit),
                                          status );
            
        }
        
        // Check if Layer Node
        else if( node_name == "Layer" )
        {

            // Parse the Layer Node
            Parse_WMS_1_3_0_Layer_Node( capabilities,
                                        (*nit),
                                        status );

        }

        // Otherwise, print warning
        else{
            BOOST_LOG_TRIVIAL(warning) << "Found unknown node: " << nit->name();
        }
    }
    
    
    // Log Exit
    BOOST_LOG_TRIVIAL(debug) << "Finished Parsing WMS 1.3.0 Capability XML Node.";

    // Return Success
    status = Status(StatusCode::SUCCESS);

}

/********************************************************/
/*          Process the WMS 1.3.0 Request Node          */
/********************************************************/
void Parse_WMS_1_3_0_Request_Node( Capabilities::ptr_t capabilities,
                                   pugi::xml_node&     root_node,
                                   Status&             status )
{
    // Log Entry
    BOOST_LOG_TRIVIAL(debug) << "Parsing WMS 1.3.0 Request XML Node.";

    // Iterate over child nodes
    std::string node_name;
    pugi::xml_node_iterator nit = root_node.begin();
    for( ; nit != root_node.end(); nit++ )
    {
        node_name = nit->name();

        // Otherwise, print warning
        //else{
        //    BOOST_LOG_TRIVIAL(warning) << "Found unknown node: " << nit->name();
        //}
    }

    // Return Success
    status = Status(StatusCode::SUCCESS);

}


/******************************************************/
/*          Process the WMS 1.3.0 Layer Node          */
/******************************************************/
void Parse_WMS_1_3_0_Layer_Node( Capabilities::ptr_t capabilities,
                                 pugi::xml_node&     root_node,
                                 Status&             status )
{
     // Log Entry
    BOOST_LOG_TRIVIAL(debug) << "Parsing WMS 1.3.0 Layer XML Node.";

    // Create New Layer
    OGC_Layer::ptr_t new_layer = std::make_shared<OGC_Layer>();

    // Iterate over child nodes
    std::string node_name;
    pugi::xml_node_iterator nit = root_node.begin();
    for( ; nit != root_node.end(); nit++ )
    {
        node_name = nit->name();

        // Check Name Node
        if( node_name == "Name" )
        {
            new_layer->Set_Name( nit->text().as_string() );
        }

        // Check Node Title
        else if( node_name == "Title" )
        {
            new_layer->Set_Title( nit->text().as_string() );
        }

        // Check Layer Node
        else if( node_name == "Layer" )
        {
            // Create the Layer
            OGC_Layer::ptr_t layer = std::make_shared<OGC_Layer>();

            // Parse Layer Node
            Parse_WMS_1_3_0_Layer_Node( capabilities,
                                        layer,
                                        (*nit), 
                                        status );

            // Add layer
            new_layer->Add_Layer( layer );
        }
        
        // Otherwise, print warning
        else{
            BOOST_LOG_TRIVIAL(warning) << "Found unknown node: " << nit->name();
        }
    }

    // Add Layer
    capabilities->Add_Layer(new_layer);

    // Return Success
    status = Status(StatusCode::SUCCESS);


}



/******************************************************/
/*          Process the WMS 1.3.0 Layer Node          */
/******************************************************/
void Parse_WMS_1_3_0_Layer_Node( Capabilities::ptr_t capabilities,
                                 OGC_Layer::ptr_t    layer_node,
                                 pugi::xml_node&     root_node,
                                 Status&             status )
{
     // Log Entry
    BOOST_LOG_TRIVIAL(debug) << "Parsing WMS 1.3.0 Layer XML Node.";

    // Iterate over child nodes
    std::string node_name;
    pugi::xml_node_iterator nit = root_node.begin();
    for( ; nit != root_node.end(); nit++ )
    {
        node_name = nit->name();
        
        // Check Name
        if( node_name == "Name" )
        {
            layer_node->Set_Name( nit->text().as_string() );
        }

        // Check Title
        else if( node_name == "Title" )
        {
            layer_node->Set_Title( nit->text().as_string() );
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
