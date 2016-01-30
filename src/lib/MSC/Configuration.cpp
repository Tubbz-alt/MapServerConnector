/**
 * @file    Configuration.cpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#include "Configuration.hpp"

// C++ Libraries
#include <iostream>


namespace MSC{

/************************************/
/*          Constructor             */
/************************************/
Configuration::Configuration()
  : m_class_name("Configuration")
{

}


/**************************************/
/*           insert new pair          */
/**************************************/
void Configuration::Insert( const std::string& key,
                            const std::string& value )
{
    m_pairs[key] = value;
}


/**************************************/
/*          Log Configuration         */
/**************************************/
void Configuration::Log()const
{
    for( auto it=m_pairs.begin(); it != m_pairs.end(); it++ )
    {
        std::cout << it->first << "=" << it->second << std::endl;
    }

}


} // End of MSC Namespace

