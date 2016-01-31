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


// MSC Libraries
#include "Status.hpp"


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
         * @brief Get the requested flag value.
        */
        std::string Get_Value( const std::string& key,
                               Status&            status )const;


        /**
         * @brief Get the requested flag value with a default.
        */
        std::string Get_Value( const std::string& key,
                               const std::string& default_value,
                               Status&            status )const;
        

        /**
         * @brief Get Number Pairs
        */
        inline size_t Get_Number_Pairs()const{
            return m_pairs.size();
        }

        
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
