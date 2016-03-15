/**
 * @file    Capabilities.hpp
 * @author  Marvin Smith
 * @date    3/14/2016
*/
#ifndef __MSC_LIB_MSC_CAPABILITIES_HPP__
#define __MSC_LIB_MSC_CAPABILITIES_HPP__

// C++ Libraries
#include <memory>
#include <string>

namespace MSC{

/**
 * @class Capabilities
*/
class Capabilities
{
    public:
        
        /// Pointer Type
        typedef std::shared_ptr<Capabilities> ptr_t;


        /**
         * @brief Constructor
        */
        Capabilities();
        
        /**
         * @brief Print to String
        */
        virtual std::string ToString()const = 0;


    private:
        
        /// Class name
        std::string m_class_name;


}; /// End of Capabilities Class


} // End of MSC Namespace

#endif
