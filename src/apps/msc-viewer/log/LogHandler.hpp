/**
 * @file    LogHandler.hpp
 * @author  Marvin Smith
 * @date    3/11/2016
 */
#ifndef __MSC_APPS_MSC_VIEWER_LOG_LOG_HANDLER_HPP__
#define __MSC_APPS_MSC_VIEWER_LOG_LOG_HANDLER_HPP__

// C++ Libraries
#include <cinttypes>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>


/**
 * @enum Log Level
*/
enum class LogLevel : int8_t
{
    UNKNOWN = -1 /**< This should be an error condition.*/,
    TRACE   =  0 /**< Minimum level, lowest priority.*/,
    DEBUG   =  1 /**< Standard debugging output.*/,
    INFO    =  2 /**< Information.*/,
    WARNING =  3 /**< Warning data.*/,
    ERROR   =  4 /**< Error Condition.*/,
    FATAL   =  5 /**< Application will probably crash.*/,
}; // End of LogLevel Enumeration.


/**
 * @brief Convert String to Log Level.
 */
LogLevel StringToLogLevel( const std::string& log_level );


/**
 * @brief Convert Log Level to String
 */
std::string LogLevelToString( const LogLevel& log_level );



/**
 * @brief Get the Current Time String
 */
std::string NowTime();



/**
 * @class LogHandler
 */
template <typename T>
class LogHandler
{
    public:
        
        /**
         * @brief Log Handler Constructor
         */
        LogHandler()
        {
        }
       
        
        /**
         * @brief Destructor
         */
        ~LogHandler()
        {
            os << std::endl;
            T::Output(os.str());
        }


        /**
         * @brief Get the Output Stream
         */
        std::ostringstream& Get( const LogLevel& level = LogLevel::INFO ){
            os << "- " << NowTime();
            os << " " << LogLevelToString(level) << ": ";
            
            os << std::string((int)level > (int)LogLevel::DEBUG ? (int)level - (int)LogLevel::DEBUG : 0, '\t');
            return os;
        }


        /**
         * @brief Get the Min Severity
         */
        static LogLevel& Get_Log_Severity(){
            static LogLevel min_severity = LogLevel::INFO;
            return min_severity;
        }

    protected:
        
        /// Stringstream
        std::ostringstream os;
        
    private:
    
        /**
         * @brief Removed Copy Constructor
         */
        LogHandler( LogHandler const& handler ) = delete;


        /**
         * @brief Removed Assignment Oprator
         */
        LogHandler& operator = ( const LogHandler& rhs ) = delete;

}; // End of LogHandler Class



/*
 * @brief Handler Class
 */
class Output2FILE
{
    public:
        
        inline static FILE*& Stream(){
            static FILE* pStream = stderr;
            return pStream;
        }


        /**
         * @brief Return the Output
         */
        inline static void Output(const std::string& msg)
        {   
            FILE* pStream = Stream();
            if (!pStream)
                return;
            fprintf(pStream, "%s", msg.c_str());
            fflush(pStream);
        }
}; // End of Output2File

/**
  * @brief Overload the Default Logger
 */
class Logger : public LogHandler<Output2FILE> {};


/**
 * @brief Load a Message
 */
#define LOG_MSG( severity ) \
    if( (int)severity > (int)Logger::Get_Log_Severity() || !Output2FILE::Stream()) ; \
    else Logger().Get( severity )

#endif
