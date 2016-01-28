/**
 * @file    MapServiceConnector.cpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#include "MapServiceConnector.hpp"


namespace MSC{


/**********************************/
/*          Constructor           */
/**********************************/
MapServiceConnector::MapServiceConnector()
  : m_class_name("MapServiceConnector")
{
}


/*****************************************/
/*     Connect to the Remote System      */
/*****************************************/
void MapServiceConnector::Connect( Status& status )
{
    // Connect


    // Return success
    status = Status(StatusCode::SUCCESS);
}


}  // End of Namespace MSC

