/**
 * @file    OGC_BoundingBox.cpp
 * @author  Marvin Smith
 * @date    3/22/2016
*/
#include "OGC_BoundingBox.hpp"

// C++ Libraries
#include <iostream>
#include <sstream>


namespace MSC{
namespace OGC{


/***************************************/
/*              Constructor            */
/***************************************/
BoundingBox::BoundingBox()
{
}

/***************************************/
/*              Constructor            */
/***************************************/
BoundingBox::BoundingBox( const std::string&   crs,
                          const Rect<double>&  bbox )
 : m_crs(crs),
   m_bbox(bbox)
{
}


/************************************/
/*          Print to String         */
/************************************/
std::string BoundingBox::ToString( const int& offset )const
{
    // Compute gap
    std::string gap( offset, ' ');

    // Create stream
    std::stringstream sin;
    sin << gap << "BoundingBox:\n";
    sin << gap << "  CRS: " << m_crs << "\n";
    sin << gap << "  BBox: MinX: " << m_bbox.BL().X() << ", MinY: " << m_bbox.BL().Y() << ", W: " << m_bbox.Width() << ", H: " << m_bbox.Height() << std::endl;
    
    return sin.str();
}

} // End of OGC Namespace
} // End of MSC Namespace

