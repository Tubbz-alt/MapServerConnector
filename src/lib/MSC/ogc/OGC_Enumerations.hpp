/**
 * @file    OGC_Enumerations.hpp
 * @author  Marvin Smith
 * @date    3/11/2016
 */
#ifndef __MSC_LIB_OGC_OGC_ENUMERATIONS_HPP__
#define __MSC_LIB_OGC_OGC_ENUMERATIONS_HPP__

// C++ Libraries
#include <cinttypes>
#include <string>


namespace MSC{
namespace OGC{


/**
 * @enum OGC_Service
 */
enum class OGC_Service : int8_t
{
    UNKNOWN = 0 /**< This should be an error condition.*/,
    WMS     = 1 /**< Web-Map-Service.*/,
    WMTS    = 2 /**< Web-Tile-Map Service.*/,
    WFS     = 3 /**< Web-Feature-Service.*/,
}; // End of OGC_Service Enumeration


} // End of OGC Namespace
} // End of OGC Namespace

#endif
