/**
 * @file    OGC_Enumerations.cpp
 * @author  Marvin Smith
 * @date    3/11/2016
 */
#include "OGC_Enumerations.hpp"

namespace MSC{
namespace OGC{


/*************************************************/
/*            String to OGC Service              */
/*************************************************/
OGC_Service StringToOGC_Service( const std::string& service )
{
    if( service == "WMS" || service == "wms" ){
        return OGC_Service::WMS;
    }
    if( service == "WMTS" || service == "wmts" ){
        return OGC_Service::WMTS;
    }
    if( service == "WFS" || service == "wfs" ){
        return OGC_Service::WFS;
    }
    return OGC_Service::UNKNOWN;
}


/**
 * @brief OGC_Service to String
*/
std::string OGC_ServiceToString( const OGC_Service& service )
{
    switch(service)
    {
        // WMS
        case OGC_Service::WMS:
            return "WMS";

        // WMTS
        case OGC_Service::WMTS:
            return "WMTS";
        
        // WFS
        case OGC_Service::WFS:
            return "WFS";

        // Default
        case OGC_Service::UNKNOWN:
        default:
            return "UNKNOWN";
    }
    return OGC_Service::UNKNOWN;
}


} // End of OGC Namespace
} // End of MSC Namespace

