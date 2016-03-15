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


/**************************************/
/*          Convert to String         */
/**************************************/
Capabilities::ptr_t Capabilities::Parse_WMS_1_3_0( const std::string&  contents,
                                                   Status&             status )
{
    // 
    status = Status(StatusCode::NOT_IMPLEMENTED_YET,"Not implemented yet.");
    return nullptr;
}

} // End of OGC Namespace
} // End of MSC Namespace

