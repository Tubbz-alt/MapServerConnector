/**
 * @file    ArcGIS_Connector.hpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#ifndef __MSC_ArcGIS_Connector_HPP__
#define __MSC_ArcGIS_Connector_HPP__

// Project Libraries
#include "../Base_Connector.hpp"
#include "../Configuration.hpp"


// C++ Libraries
#include <memory>
#include <string>


// Curl
#include <curl/curl.h>


namespace MSC{

/**
 * @class ArcGIS_Connector
*/
class ArcGIS_Connector : public Base_Connector
{
    public:
        
        /// Pointer Type
        typedef std::shared_ptr<ArcGIS_Connector> ptr_t;


        /**
         * @brief Constructor
         */
        ArcGIS_Connector( Configuration const& configuration );

        
        /**
         * @brief Destructor
         */
        ~ArcGIS_Connector();


        /**
         * @brief Connect
         */
        virtual void Connect( Status& status );
        

        /**
         * @brief Disconnect
         */
        virtual void Disconnect( Status& status );


        /**
         * @brief Get Map
        */
        virtual MapResponse Get_Map( const MapRequest& request );


    private:
        
        /**
         * @brief Create Get Map Query.
         */
         std::string Create_Get_Map_Query( const MapRequest& request );


        /// Class Name
        std::string m_class_name;

        /// Curl Instance
        CURL* m_curl;
        
        /// URL
        std::string m_url;

}; // End of ArcGIS_Connector Class


/**
 * @class ArcGIS_Connector_Generator
*/
class ArcGIS_Connector_Generator : public Base_Connector_Generator
{
    public:
        
        /// Pointer Type
        typedef std::shared_ptr<ArcGIS_Connector_Generator> ptr_t;


        /**
         * @brief Constructor
        */
        ArcGIS_Connector_Generator();

        
        /**
         * @brief Create Generator
        */
        virtual Base_Connector::ptr_t Create( const Configuration&  configuration,
                                              Status&               status );
    
        
    private:
        
        /// Class Name
        std::string m_class_name;

}; // End of ArcGIS_Connector_Generator


} // End of MSC Namespace

#endif
