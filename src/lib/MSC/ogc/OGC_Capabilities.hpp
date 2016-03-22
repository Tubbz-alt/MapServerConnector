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
#include <vector>


// MSC Libraries
#include "../Capabilities.hpp"
#include "../Status.hpp"
#include "OGC_Enumerations.hpp"
#include "OGC_Layer.hpp"


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
         *
         * @param[in] service_type  Version type of OGC Service (WMS/WMTS/WFS/WCS)
         * @param[in] service_version  Version of the service.
        */
        Capabilities( const OGC_Service& service_type,
                      const std::string& service_version );
        
        
        /**
         * @brief Set the Service Type
        */
        inline void Set_Service_Type( const OGC_Service& service_type ){
            m_service_type = service_type;
        }

        
        /**
         * @brief Get the Service Type
        */
        inline OGC_Service Get_Service_Type()const{
            return m_service_type;
        }
        

        /**
         * @brief Get the Service Version
        */
        inline std::string Get_Service_Version()const{
            return m_service_version;
        }


        /**
         * @brief Set the Service Name
        */
        inline void Set_Service_Name( const std::string& name ){
            m_service_name = name;
        }


        /**
         * @brief Get the Service name
        */
        inline std::string Get_Service_Name()const{
            return m_service_name;
        }
        

        /**
         * @brief Add Layer to Capability
        */
        void Add_Layer( OGC_Layer::ptr_t layer );

        
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
        
        /// Service Type
        OGC_Service m_service_type;
        
        /// Service Version
        std::string m_service_version;

        /// Service name
        std::string m_service_name;
        
        /// List of Layers
        std::vector<OGC_Layer::ptr_t> m_layers;

}; // End of Capabilities Class

} // End of OGC Namespace
} // End of MSC Namespace

#endif
