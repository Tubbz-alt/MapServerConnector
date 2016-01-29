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
        Base_Connector();

        
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


    protected:
        
        /// Connection Status
        bool m_is_connected;

    private:
        
        /// Class Name
        std::string m_class_name;

}; // End of Base_Connector Class

} // End of MSC Namespace

#endif
