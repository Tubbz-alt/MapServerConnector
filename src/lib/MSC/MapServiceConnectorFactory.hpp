/**
 * @file    MapServiceConnectorFactory.hpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#ifndef __MSC_MAPSERVICE_CONNECTOR_FACTORY_HPP__
#define __MSC_MAPSERVICE_CONNECTOR_FACTORY_HPP__

// MSC Libraries
#include "MapServiceConnector.hpp"
#include "Status.hpp"

namespace MSC{

/**
 * @class MapServiceConnectorFactory
*/
class MapServiceConnectorFactory
{
    public:
        
        /**
         * @brief Construct new MapServiceConnection
        */
        static MapServiceConnector::ptr_t Create( const std::string& config_pathname,
                                                  Status&            status );




}; // End of MapServiceConnectorFactory Class

} // End of MSC Namespace

#endif
