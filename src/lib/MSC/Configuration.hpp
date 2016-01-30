/**
 * @file    Configuration.hpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#ifndef __MSC_CONFIGURATION_HPP__
#define __MSC_CONFIGURATION_HPP__

// C++ Libraries
#include <map>
#include <memory>
#include <string>


namespace MSC{

/**
 * @class Configuration
*/
class Configuration
{
    public:
        
        /// Pointer Type
        typedef std::shared_ptr<Configuration> ptr_t;

        
        /**
         * @brief Constructor
        */
        Configuration();
        

        /**
         * @brief Insert new KV Pair
        */
        void Insert( const std::string& key,
                     const std::string& value );

        
        /**
         * @brief Print to string
        */
        void Log()const;

    private:
        
        /// Class Name
        std::string m_class_name;
        
        // Key/Value Pairs
        std::map<std::string,std::string> m_pairs;

}; // End of Configuration Class

} // End of MSC Namespace

#endif
