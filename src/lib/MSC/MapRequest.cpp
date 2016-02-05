/**
 * @file     MapRequest.cpp
 * @author   Marvin Smith
 * @date     2/1/2016
*/
#include "MapRequest.hpp"

// C++ Libraries
#include <cstring>
#include <sstream>

// MSC Libraries
#include "utilities/GDAL_Utilities.hpp"
#include "utilities/Log_Utilities.hpp"


namespace MSC{


/**********************************/
/*        Map Request Base        */
/**********************************/
MapRequest::MapRequest( const int&         image_cols,
                        const int&         image_rows,
                        const std::string& crs,
                        const double&      bbox_min_x,
                        const double&      bbox_min_y,
                        const double&      bbox_max_x,
                        const double&      bbox_max_y,
                        const ImageType&   format )
 : m_class_name("MapRequest"),
   m_image_cols(image_cols),
   m_image_rows(image_rows),
   m_crs(crs),
   m_bbox_min_x(bbox_min_x),
   m_bbox_min_y(bbox_min_y),
   m_bbox_max_x(bbox_max_x),
   m_bbox_max_y(bbox_max_y),
   m_format(format)
{

}


/*************************************/
/*          Write as WMS URL         */
/*************************************/
std::string MapRequest::To_WMS_URL()const
{
    // Create output string
    std::stringstream sin;

    // Set the service
    sin << "&REQUEST=Getmap";
    
    // Add Width
    sin << "&WIDTH="  << m_image_cols;
    sin << "&HEIGHT=" << m_image_rows;

    // Add the format
    sin << "&FORMAT=" << ImageTypeToWMSFormat(m_format);

    // Iterate over layers
    sin << "&Layers=";
    for( int i=0; i<m_layers.size(); i++ ){
        sin << m_layers[i];
        if( i < (m_layers.size()-1) ){
            sin << ",";   
        }
    }

    //CRS
    sin << "&SRS=" << m_crs;

    // BBOX
    sin << "&BBOX=" << std::fixed << m_bbox_min_x << "," << m_bbox_min_y << "," << m_bbox_max_x << "," << m_bbox_max_y;

    // return the output
    return sin.str();
}


/****************************************/
/*          Write to ArcGIS URL         */
/****************************************/
std::string MapRequest::To_ArcGIS_URL()const
{
    // Create output stream
    std::stringstream sin;

    sin << "";

    return sin.str();
}


/*****************************/
/*        Map Response       */
/*****************************/
MapResponse::MapResponse()
 : m_class_name("MapResponse"),
   m_image_buffer(nullptr),
   m_image_buffer_size_bytes(0)
{
}


/*****************************/
/*        Map Response       */
/*****************************/
MapResponse::MapResponse( Status const& status )
 : m_class_name("MapResponse"),
   m_status(status),
   m_image_buffer(nullptr),
   m_image_buffer_size_bytes(0)
{
}


/*****************************/
/*        Destructor         */
/*****************************/
MapResponse::~MapResponse()
{
    // Log Exit
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", Start of Destructor";
}


/************************************************/
/*              Assignment Operator             */
/************************************************/
MapResponse& MapResponse::operator= (MapResponse const& rhs )
{
    // Log
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", Start of Assignment Operator";

    // Make sure we don't assign ourselves
    if( this == (&rhs) )
    {
        return (*this);
    }

    // Otherwise, proceed
    m_status                  = rhs.m_status;
    m_image_buffer            = rhs.m_image_buffer;
    m_image_buffer_size_bytes = rhs.m_image_buffer_size_bytes;


    return (*this);
}

/****************************************/
/*      Finalize the Map Response       */
/****************************************/
void MapResponse::Finalize()
{
    // Log Entry
    BOOST_LOG_TRIVIAL(trace) << "Calling Finalize";

    // Delete
    if( m_image_buffer_size_bytes > 0 )
    {
        delete [] m_image_buffer;
        m_image_buffer = nullptr;
        m_image_buffer_size_bytes = 0;
    }
}


/************************************/
/*          Set the Status          */
/************************************/
void MapResponse::Set_Status( Status const& status )
{
    m_status = status;
}


/********************************************/
/*          Set the Image Buffer            */
/********************************************/
void MapResponse::Set_Image_Buffer( char*            buffer,
                                    const uint64_t&  buffer_size_bytes )
{
    // Log Entry
    BOOST_LOG_TRIVIAL(trace) << "Setting the image buffer";

    m_image_buffer            = buffer;
    m_image_buffer_size_bytes = buffer_size_bytes;

}


/**************************************************/
/*            Append an Image Buffer              */
/**************************************************/
void MapResponse::Append_Image_Buffer( char*            buffer,
                                       const uint64_t&  buffer_size_bytes )
{
    // Appending data
    BOOST_LOG_TRIVIAL(trace) << "Appending " << buffer_size_bytes << " bytes";

    
    // Ignore if the buffer is null or the size is empty
    if( buffer_size_bytes == 0 ){
        BOOST_LOG_TRIVIAL(warning) << "Buffer passed is empty";
        return;
    }

    // Set the starting position
    uint64_t start_pos = m_image_buffer_size_bytes;
    
    // Check if we need to allocate
    if( m_image_buffer_size_bytes == 0 ){
        
        // Allocate
        m_image_buffer_size_bytes = buffer_size_bytes;
        m_image_buffer = new char[m_image_buffer_size_bytes];
    
        // Copy
        memcpy( m_image_buffer, 
                buffer,
                m_image_buffer_size_bytes );
        
    }

    // Check if we need to re-allocate
    else
    {
        // Allocate Buffer
        m_image_buffer_size_bytes += buffer_size_bytes;
        char* new_buffer = new char[m_image_buffer_size_bytes];

        // Copy Original
        memcpy( new_buffer, 
                m_image_buffer,
                start_pos );
        
        // Copy New
        memcpy( new_buffer + start_pos,
                buffer,
                buffer_size_bytes );
        
        // Clear old buffer
        delete [] m_image_buffer;
        m_image_buffer = new_buffer;
    }
}


/*********************************************/
/*          Get the Unpacked Image           */
/*********************************************/
void MapResponse::Get_Unpacked_Image( char*&  buffer,
                                      int&    rows,
                                      int&    cols,
                                      int&    channels )
{
    
    // Call on GDAL
    Decode_Raster( m_image_buffer,
                   m_image_buffer_size_bytes,
                   buffer,
                   rows,
                   cols,
                   channels );

}


} // End of MSC Namespace

