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


namespace MSC{

/**
 * @class Base_Connector
*/
class Base_Connector
{
    public:
        
        /// Shared Pointer
        std::shared_ptr<Base_Connector> ptr_t;
        

        /**
         * @brief Constructor
        */
        Base_Connector();

    private:
        
        /// Class Name
        std::string m_class_name;

}; // End of Base_Connector Class

} // End of MSC Namespace

#endif
