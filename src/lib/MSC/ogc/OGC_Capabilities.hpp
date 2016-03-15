/**
 * @file    OGC_Capabilities.hpp
 * @author  Marvin Smith
 * @date    3/14/2016
*/
#ifndef __MSC_LIB_MSC_OGC_OGC_CAPABILITIES_HPP__
#define __MSC_LIB_MSC_OGC_OGC_CAPABILITIES_HPP__

// C++ Libraries
#include <memory>
#include <string>

// MSC Libraries
#include "../Capabilities.hpp"


namespace MSC{
namespace OGC{

/**
 * @class Capabilities
*/
class Capabilities : public MSC::Capabilities
{
    public:
    
        /**
         * @brief Constructor
        */
        Capabilities();

        
        /**
         * @brief Print to String
        */
        virtual std::string ToString()const;

    
    private:
        
        /// Class Name
        std::string m_class_name;

}; // End of Capabilities Class

} // End of OGC Namespace
} // End of MSC Namespace

#endif
