/**
 * @file    Enumerations.cpp
 * @author  Marvin Smith
 * @date    2/2/2016
*/
#include "Enumerations.hpp"


namespace MSC{


/**********************************/
/*      ImageType to String       */
/**********************************/
std::string ImageTypeToString( ImageType const& tp )
{
    // PNG
    if( tp == ImageType::PNG ){
        return "PNG";
    }

    // JPEG
    if( tp == ImageType::JPEG ){
        return "JPEG";
    }

    // TIFF
    if( tp == ImageType::TIFF ){
        return "TIFF";
    }

    // GIF
    if( tp == ImageType::GIF ){
        return "GIF";
    }

    // Unknown
    return "UNKNOWN";
}


/****************************************/
/*      Convert String to ImageType     */
/****************************************/
ImageType  StringToImageType( const std::string& tp )
{
    // PNG
    if( tp == "png" || tp == "PNG" ){
        return ImageType::PNG;
    }

    // JPEG
    if( tp == "jpg" || tp == "jpeg" ||
        tp == "JPG" || tp == "JPEG" )
    {
        return ImageType::JPEG;
    }

    // TIFF
    if( tp == "tif" || tp == "tiff" ||
        tp == "TIF" || tp == "TIFF" )
    {
        return ImageType::TIFF;
    }

    // GIF
    if( tp == "gif" || tp == "GIF" )
    {
        return ImageType::GIF;
    }

    // Unknown
    return ImageType::UNKNOWN;
}


/*****************************************************/
/*      Convert ImageType to WMS Format String       */
/*****************************************************/
std::string ImageTypeToWMSFormat( const ImageType& format )
{
    switch(format)
    {
        
        // PNG
        case ImageType::PNG:
            return "image/png";

        // JPEG
        case ImageType::JPEG:
            return "image/jpeg";
        
        // GIF
        case ImageType::GIF:
            return "image/gif";

        // Remainders
        case ImageType::TIFF:
        default:
            return "";
    }
    return "";
}

} // End of MSC Namespace

