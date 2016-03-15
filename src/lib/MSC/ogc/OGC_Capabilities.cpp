/**
 * @file    OGC_Capabilities.cpp
 * @author  Marvin Smith
 * @date    3/14/2016
*/
#include "OGC_Capabilities.hpp"


namespace MSC{
namespace OGC{

/***********************************/
/*          Constructor            */
/***********************************/
Capabilities::Capabilities()
 : MSC::Capabilities(),
   m_class_name("Capabilities")
{


}


/***************************************/
/*          Print to String            */
/***************************************/
std::string Capabilities::ToString()const
{
    return "";
}

} // End of OGC Namespace
} // End of MSC Namespace

