/**
 * @file    Base_Connector.cpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#include "Base_Connector.hpp"


namespace MSC{


/**********************************************/
/*         Base Connector Constructor         */
/**********************************************/
Base_Connector::Base_Connector( Configuration const& configuration )
 : m_class_name("Base_Connector"),
   m_is_connected(false),
   m_configuration(configuration)
{

}


} // End of MSC Namespace
