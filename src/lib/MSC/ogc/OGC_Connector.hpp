/**
 * @file    OGC_Connector.hpp
 * @author  Marvin Smith
 * @date    1/29/2016
*/
#ifndef __MSC_OGC_OGC_CONNECTOR_HPP__
#define __MSC_OGC_OGC_CONNECTOR_HPP__

// C++ Libraries
#include <memory>
#include <string>


// Project Libraries
#include "../Base_Connector.hpp"
#include "../Configuration.hpp"
#include "../MapRequest.hpp"
#include "OGC_Enumerations.hpp"


// Curl
#include <curl/curl.h>


namespace MSC{

/**
 * @class OGC_Connector
*/
class OGC_Connector : public Base_Connector
{
    public:
        
        /// Pointer Type
        typedef std::shared_ptr<OGC_Connector> ptr_t;


        /**
         * @brief Constructor
         */
        OGC_Connector( Configuration const& configuration );

        
        /**
         * @brief Destructor
         */
        ~OGC_Connector();


        /**
         * @brief Connect
         */
        virtual void Connect( Status& status );
        

        /**
         * @brief Disconnect
         */
        virtual void Disconnect( Status& status );
        

        /**
         * @brief Get the Capabilities
        */
        virtual MSC::Capabilities::ptr_t  Get_Capabilities( Status& status );


        /**
         * @brief Get Map
        */
        virtual MapResponse Get_Map( MapRequest const& request );

        
        /**
         * @brief Get Driver Name
         */
        inline virtual std::string Get_Driver_Name()const{
            return "ogc";
        }

    private:
        
        /**
         * @brief Construct Get Features Query
        */
        std::string Create_Get_Capabilities_Query()const;
        

        /**
         * @brief Create Get Map Query
        */
        std::string Create_Get_Map_Query( const MapRequest& request);


        /**
         * @brief Static runner method for the initialization connection.
         *
         * @param[in] ptr
         * @param[in] size
         * @param[in] nmemb
         * @param[in] pInstance
        */
        static size_t Init_Callback_Handler( void* ptr,
                                             size_t size,
                                             size_t nmemb,
                                             void*  pInstance );
        
        /**
         * @brief Static runner method for the Get-Map request
        */
        static size_t Get_Map_Callback_Handler( void*   ptr_t,
                                                size_t  size,
                                                size_t  nmemb,
                                                void*   pInstance );

        
        /// Class Name
        std::string m_class_name;

        /// Curl Instance
        CURL* m_curl;
        
        /// URL
        std::string m_url;
        
        /// Version Info
        std::string m_wms_version;
        std::string m_wmts_version;

        /// Service to Use
        OGC::OGC_Service m_current_service;


        /// Unparsed Features / Capabilities
        std::string m_features_output;
        
        /// Latest Request
        MapResponse  m_latest_response;

}; // End of OGC_Connector Class


/**
 * @class OGC_Connector_Generator
*/
class OGC_Connector_Generator : public Base_Connector_Generator
{
    public:
        
        /// Pointer Type
        typedef std::shared_ptr<OGC_Connector_Generator> ptr_t;


        /**
         * @brief Constructor
        */
        OGC_Connector_Generator();

        
        /**
         * @brief Create Generator
        */
        virtual Base_Connector::ptr_t Create( const Configuration&  configuration,
                                              Status&               status );
        

    private:
        
        /// Class Name
        std::string m_class_name;

}; // End of OGC_Connector_Generator Class


} // End of MSC Namespace

#endif
