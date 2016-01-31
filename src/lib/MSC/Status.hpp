/**
 * @file    Status.hpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#ifndef __MSC_STATUS_HPP__
#define __MSC_STATUS_HPP__

// C++ Libraries
#include <cinttypes>
#include <string>


namespace MSC{

/**
 * @enum StatusCode
*/
enum class StatusCode : int16_t{
    SUCCESS = 0,
    UNKNOWN = 1,
    NOT_IMPLEMENTED_YET = 2,
    NO_CONNECTOR_FOUND  = 3,
    NO_KEY_FOUND        = 4,
    CONNECTION_ERROR    = 5,
    DUPLICATE_GENERATOR = 6,
}; // End of StatusCode Enumeration


/**
 * @brief Convert StatusCode to String
*/
std::string StatusCodeToString( StatusCode const& code );


/**
 * @class Status
*/
class Status
{
    public:
        
        /**
         * @brief Constructor
        */
        Status();


        /**
         * @brief Constructor
        */
        Status( const StatusCode& code );


        /**
         * @brief Constructor
        */
        Status( const StatusCode&  code,
                const std::string& message );

        
        /**
         * @brief Get the code
        */
        inline StatusCode Get_Code()const{
            return m_code;
        }


        /**
         * @brief Get the message
        */
        inline std::string Get_Message()const{
            return m_message;
        }
        
        /**
         * @brief Append Status
        */
        void Update( Status const& status );


        /**
         * @brief Print to string
        */
        std::string ToString()const;

    private:
        
        /// Code
        StatusCode m_code;

        /// Status Message
        std::string m_message;
        
        /// Set
        bool m_set;

}; // End of Status Class


} // End of MSC Namespace

#endif
