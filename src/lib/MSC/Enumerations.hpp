/**
 * @file    Enumerations.hpp
 * @author  Marvin Smith
 * @date    2/2/2016
*/
#ifndef __MSC_ENUMERATIONS_HPP__
#define __MSC_ENUMERATIONS_HPP__

// C++ Libraries
#include <cinttypes>
#include <string>


namespace MSC{


/**
 * @brief ImageType
*/
enum class ImageType : int8_t
{
    UNKNOWN = 0 /**< Used as an error condition.*/,
    PNG     = 1 /**< Portable Network Graphic*/,
    JPEG    = 2,
    TIFF    = 3,
    GIF     = 4,
}; // End of ImageType Enumerations


/**
 * @brief Convert ImageType enum to a string.
 *
 * @param[in] tp
 *
 * @return string format.
*/
std::string ImageTypeToString( const ImageType& tp );


/**
 * @brief Convert string to ImageType
*/
ImageType StringToImageType( const std::string& tp );


/**
 * @brief Convert Image Type to WMS String
*/
std::string ImageTypeToWMSFormat( const ImageType& format );


} // End of MSC Namespace

#endif
