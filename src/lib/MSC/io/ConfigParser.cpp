/**
 * @file    ConfigParser.cpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#include "ConfigParser.hpp"

// C++ Libraries
#include <fstream>
#include <iostream>
#include <sstream>

// Boost Libraries
#include <boost/algorithm/string.hpp>


namespace MSC{


/************************************************/
/*          ConfigParser Constructor            */
/************************************************/
ConfigParser::ConfigParser( const std::string& config_pathname )
 : m_class_name("ConfigParser"),
   m_config_pathname(config_pathname)
{
}


/*****************************************/
/*        Load the Configuration         */
/*****************************************/
Configuration ConfigParser::Load_Configuration( Status& status )
{
    // Create the output configuration
    Configuration output;
    
    // Load the file
    std::ifstream fin;
    fin.open( m_config_pathname.c_str() );

    // Grab the first line
    std::string line;
    fin >> line;
    std::string key, value;
    size_t pos;

    // Load while lines are available
    while( fin.good() )
    {
        // Trim whitespaces
        boost::trim_if( line, boost::is_any_of(" "));

        // Check the length or if it is a comment
        if( line.size() <= 0 || line[0] == '#' )
        {
            fin >> line;
            continue;
        }

        // Split the line
        pos = line.find("=");

        // Check for no value
        if( pos == std::string::npos ){
            fin >> line;
            continue;
        }

        // Trim and create key/value pair
        key   = boost::trim_copy_if( line.substr(0,pos), boost::is_any_of(" "));
        value = boost::trim_copy_if( line.substr(pos+1),   boost::is_any_of(" "));

        // Add to the Config
        output.Insert( key, value );

        // Get the next line
        fin >> line;
    }

    // Close the file
    fin.close();
    
    // Return output
    status = Status( StatusCode::SUCCESS );
    return output;
}


} // End of MSC Namespace
