/**
 * @file     MapRequest.cpp
 * @author   Marvin Smith
 * @date     2/1/2016
*/
#include "MapRequest.hpp"

// C++ Libraries
#include <sstream>


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
                        const std::string& format )
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
    sin << "&FORMAT=" << m_format;

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
 : m_class_name("MapResponse")
{
}


/*****************************/
/*        Map Response       */
/*****************************/
MapResponse::MapResponse( Status const& status )
 : m_class_name("MapResponse"),
   m_status(status)
{
}



/************************************/
/*          Set the Status          */
/************************************/
void MapResponse::Set_Status( Status const& status )
{
    m_status = status;
}


} // End of MSC Namespace

