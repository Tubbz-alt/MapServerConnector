/**
 * @file    MapServiceConnector.hpp
 * @author  Marvin Smith
 * @date    1/27/2015
*/
#ifndef __MSC_MapService_Connector_HPP__
#define __MSC_MapService_Connector_HPP__

// C++ Libraries
#include <memory>
#include <string>

// MSC Libraries
#include "Status.hpp"


namespace MSC{

/**
 * @class MapServiceConnector
*/
class MapServiceConnector
{
    public:
        
        /// Pointer Type
        typedef std::shared_ptr<MapServiceConnector> ptr_t;

        
        /**
         * @brief Constructor
        */
        MapServiceConnector();

        
        /**
         * @brief Connect to the Remote System
        */
        void Connect( Status& status );


    private:
        
        /// Class Name
        std::string m_class_name;


}; // End of MapServiceConnector Class

} // End of MSC Namespace

#endif
