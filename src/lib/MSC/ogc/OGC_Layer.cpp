/**
 * @file    OGC_Layer.cpp
 * @author  Marvin Smith
 * @date    3/21/2016
*/
#include "OGC_Layer.hpp"

// Utilities
#include "../utilities/Log_Utilities.hpp"


// C++ Libraries
#include <sstream>
#include <string>


namespace MSC{
namespace OGC{


/********************************************/
/*          OGC Layer Constructor           */
/********************************************/
OGC_Layer::OGC_Layer()
{


}


/*****************************/
/*          Add CRS          */
/*****************************/
void OGC_Layer::Add_CRS( const std::string& crs )
{
    // Check if Empty
    if( crs == "" ){
        BOOST_LOG_TRIVIAL(warning) << "CRS: " << crs;
    }
    else{
        m_crs_list.push_back(crs);
    }
}


/***************************************/
/*           Add Bounding Box          */
/***************************************/
void OGC_Layer::Add_BBox( const BoundingBox& bbox )
{
    m_bbox_list.push_back(bbox);
}


/************************************/
/*          Print to String         */
/************************************/
std::string OGC_Layer::ToString( const int& offset )const
{
    // Stringstream
    std::stringstream sin;
    std::string gap( offset, ' ');

    // Print info
    sin << gap << "OGC_Layer:" << std::endl;
    sin << gap << "    Name: " << m_name << std::endl;
    sin << gap << "    Title: " << m_title << std::endl;
    
    // Internal layers
    sin << gap << "    Layers:\n";
    for( auto it=m_layers.begin(); it != m_layers.end(); it++ )
    {
        sin << (*it)->ToString(offset+4) << std::endl;
    }
    
    // CRS List
    sin << gap << "    CRS List:\n";
    for( auto it=m_crs_list.begin(); it != m_crs_list.end(); it++ )
    {
        sin << gap << gap << gap << (*it) << std::endl;
    }

    // BBox List
    sin << gap << "   BBox List:\n";
    for( auto it=m_bbox_list.begin(); it != m_bbox_list.end(); it++ )
    {
        sin << (*it).ToString(offset+4) << std::endl;
    }

    // return string result
    return sin.str();
}


} // End of OGC Namespace
} // End of MSC Namespace

