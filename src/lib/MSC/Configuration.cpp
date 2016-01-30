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


/************************************/
/*          Get Log Value           */
/************************************/
std::string Configuration::Get_Value( const std::string& key,
                                      Status&            status )const
{
    // Return Success
    status = Status( StatusCode::SUCCESS );

    // Check if the key exists
    if( m_pairs.find(key) != m_pairs.end() )
    {
        // Return the value
        return m_pairs.find(key)->second;
    }

    // Return Failure
    status = Status( StatusCode::NO_KEY_FOUND );
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

