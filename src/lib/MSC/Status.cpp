/** 
 * @file    Status.cpp
 * @author  Marvin Smith
 * @date    1/27/2016
*/
#include "Status.hpp"

// C++ Libraries
#include <sstream>


namespace MSC{


/*****************************/
/*      Write to string      */
/*****************************/
std::string StatusCodeToString( StatusCode const& code )
{
    // Successful
    if( code == StatusCode::SUCCESS ){
        return "SUCCESS";
    }

    // Not Implemented Yet
    else if( code == StatusCode::NOT_IMPLEMENTED_YET ){
        return "NOT_IMPLEMENTED_YET";
    }

    // No Connector Found
    else if( code == StatusCode::NO_CONNECTOR_FOUND ){
        return "NO_CONNECTOR_FOUND";
    }

    // No Configuration Value Found
    else if( code == StatusCode::NO_KEY_FOUND ){
        return "NO_KEY_FOUND";
    }

    // Connection Error
    else if( code == StatusCode::CONNECTION_ERROR ){
        return "CONNECTION_ERROR";
    }
    
    // Duplicate Generator
    else if( code == StatusCode::DUPLICATE_GENERATOR ){
        return "DUPLICATE_GENERATOR";
    }

    // Invalid Format
    else if( code == StatusCode::INVALID_FORMAT ){
        return "INVALID_FORMAT";
    }
        
    return "UNKNOWN";
}


/**************************/
/*      Constructor       */
/**************************/
Status::Status()
 : m_code(StatusCode::UNKNOWN),
   m_message(""),
   m_set(false)
{
}

 
/**************************/
/*      Constructor       */
/**************************/
Status::Status( const StatusCode&   code )
 : m_code(code),
   m_message(""),
   m_set(true)
{
}


/**************************/
/*      Constructor       */
/**************************/
Status::Status( const StatusCode&   code,
                const std::string&  message )
 : m_code(code),
   m_message(message),
   m_set(true)
{
}


/************************************/
/*          Append Status           */
/************************************/
void Status::Update( Status const& status )
{
    if( Get_Code() ==  StatusCode::SUCCESS )
    {
        (*this) = status;
    }

}



/**********************************/
/*        Print to String         */
/**********************************/
std::string Status::ToString()const
{
    std::stringstream sin;
    sin << "Code: " << StatusCodeToString(m_code) << ", Details: " << m_message;
    return sin.str();
}


} // End of MSC Namespace

