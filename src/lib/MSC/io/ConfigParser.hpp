/**
 * @file    ConfigParser.hpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#ifndef __MSC_CONFIG_PARSER_HPP__
#define __MSC_CONFIG_PARSER_HPP__

// C++ Libraries
#include <map>
#include <string>

// MSC Libraries
#include "../Configuration.hpp"
#include "../Status.hpp"


namespace MSC{


/**
 * @class ConfigParser
*/
class ConfigParser
{
    public:
        
        /**
         * @brief ConfigParser
        */
        ConfigParser( const std::string& config_pathname );
        

        /**
         * @brief Get the loaded configuration.
        */
        Configuration Load_Configuration( Status& status );

    private:

        /// Class Name
        std::string m_class_name;
        
        /// Config File Pathname
        std::string m_config_pathname;

}; // End of ConfigParser Class

} // End of MSC Namespace

#endif
