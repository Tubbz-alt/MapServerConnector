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
#include "../Status.hpp"


namespace MSC{
namespace OGC{

/**
 * @class Capabilities
*/
class Capabilities : public MSC::Capabilities
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
        virtual std::string ToString()const;

        
        /**
         * @brief Parse WMS 1.3.0 File Data
         *
         * @param[in] contents String contents.
         * @param[out] status  Status of the operation.
         *
         * @return Capabilities results.  Null if failed.
        */
        static Capabilities::ptr_t  Parse_WMS_1_3_0( const std::string& contents,
                                                     Status&            status );

    
    private:
        
        /// Class Name
        std::string m_class_name;

}; // End of Capabilities Class

} // End of OGC Namespace
} // End of MSC Namespace

#endif
