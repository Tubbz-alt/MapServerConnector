/**
 * @file    OGC_Layer.cpp
 * @author  Marvin Smith
 * @date    3/21/2016
*/
#include "OGC_Layer.hpp"

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

    // return string result
    return sin.str();
}


} // End of OGC Namespace
} // End of MSC Namespace

