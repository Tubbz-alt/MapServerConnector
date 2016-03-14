/**
 * @file    Base_Connector.hpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#ifndef __MSC_BASE_CONNECTOR_HPP__
#define __MSC_BASE_CONNECTOR_HPP__

// C++ Libraries
#include <memory>
#include <string>


// MSC Libraries
#include "Configuration.hpp"
#include "MapRequest.hpp"
#include "Status.hpp"


namespace MSC{

/**
 * @class Base_Connector
*/
class Base_Connector
{
    public:
        
        /// Shared Pointer
        typedef std::shared_ptr<Base_Connector> ptr_t;
        

        /**
         * @brief Constructor
        */
        Base_Connector( Configuration const& configuration );

        
        /**
         * @brief Connect to the remote system.
         */
        virtual void Connect( Status& status ) = 0;
    
        
        /**
         * @brief Disconnect the system
         */
        virtual void Disconnect( Status& status ) = 0;


        /**
         * @brief Check the Connection Status.
         */
        inline bool Is_Connected()const{
            return m_is_connected;
        }

        
        /**
         * @brief Get Map
        */
        virtual MapResponse Get_Map( MapRequest const& request ) = 0;


        /**
         * @brief Get Driver Name
         */
        inline virtual std::string Get_Driver_Name()const{
            return "base";
        }

    protected:
        
        /// Connection Status
        bool m_is_connected;

        /// Configuration 
        Configuration m_configuration;

    private:
        
        /// Class Name
        std::string m_class_name;

}; // End of Base_Connector Class


/**
 * @class Base_Connector_Generator
*/
class Base_Connector_Generator
{
    public:
        
        /// Pointer Type
        typedef std::shared_ptr<Base_Connector_Generator> ptr_t;

        /**
         * @brief Constructor
        */
        Base_Connector_Generator();


        /**
         * @brief Create Generator
        */
        virtual Base_Connector::ptr_t Create( const Configuration&  configuration,
                                              Status&               status ) = 0;
        
        /**
         * @brief Get the Class Name
        */
        inline virtual std::string Get_Class_Name()const{
            return m_class_name;
        }

        
    private:
        
        /// Class Name
        std::string m_class_name;

}; // End of Base_Connector_Generator Class

} // End of MSC Namespace

#endif
