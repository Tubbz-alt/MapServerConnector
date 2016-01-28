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
    if( code == StatusCode::SUCCESS )
    {
        return "SUCCESS";
    }
    else if( code == StatusCode::NOT_IMPLEMENTED_YET )
    {
        return "NOT_IMPLEMENTED_YET";
    }
    return "UNKNOWN";
}


/**************************/
/*      Constructor       */
/**************************/
Status::Status()
 : m_code(StatusCode::UNKNOWN),
   m_message("")
{
}

 
/**************************/
/*      Constructor       */
/**************************/
Status::Status( const StatusCode&   code )
 : m_code(code),
   m_message("")
{
}


/**************************/
/*      Constructor       */
/**************************/
Status::Status( const StatusCode&   code,
                const std::string&  message )
 : m_code(code),
   m_message(message)
{
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

