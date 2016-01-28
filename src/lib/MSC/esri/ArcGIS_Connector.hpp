/**
 * @file    ArcGIS_Connector.hpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#ifndef __MSC_ArcGIS_Connector_HPP__
#define __MSC_ArcGIS_Connector_HPP__

// Project Libraries
#include "../Base_Connector.hpp"

// C++ Libraries
#include <memory>
#include <string>


namespace MSC{

/**
 * @class ArcGIS_Connector
*/
class ArcGIS_Connector : public Base_Connector
{
    public:
        
        ArcGIS_Connector();

    
    private:
        
        /// Class Name
        std::string m_class_name;


}; // End of ArcGIS_Connector Class


} // End of MSC Namespace

#endif
