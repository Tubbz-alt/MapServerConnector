/**
 * @file    OGC_XML_Utilities.hpp
 * @author  Marvin Smith
 * @date    3/15/2016
*/
#ifndef __MSC_LIB_MSC_OGC_OGC_XML_UTILITIES_HPP__
#define __MSC_LIB_MSC_OGC_OGC_XML_UTILITIES_HPP__

// MSC Libraries
#include "../thirdparty/pugixml/src/pugixml.hpp"
#include "OGC_Capabilities.hpp"

namespace MSC{
namespace OGC{

/**
 * @brief Process a WMS 1.3.0 Service Node
*/
void Parse_WMS_1_3_0_Service_Node( Capabilities::ptr_t capabilities,
                                   pugi::xml_node&     root_node,
                                   Status&             status );

/**
 * @brief Process a WMS 1.3.0 Capability Node
*/
void Parse_WMS_1_3_0_Capability_Node( Capabilities::ptr_t capabilities,
                                      pugi::xml_node&     root_node,
                                      Status&             status );

/**
 * @brief Process a WMS 1.3.0 Request Node
*/
void Parse_WMS_1_3_0_Request_Node( Capabilities::ptr_t capabilities,
                                   pugi::xml_node&     root_node,
                                   Status&             status );


/**
 * @brief Process a WMS Layer Node
*/
void Parse_WMS_1_3_0_Layer_Node( Capabilities::ptr_t  capabilities,
                                 pugi::xml_node&      root_node,
                                 Status&              status );


/**
 * @brief Process a WMS Layer Node
*/
void Parse_WMS_1_3_0_Layer_Node( Capabilities::ptr_t  capabilities,
                                 OGC_Layer::ptr_t     layer_node,
                                 pugi::xml_node&      root_node,
                                 Status&              status );


} // End of OGC Namespace
} // End of MSC Namespace

#endif
