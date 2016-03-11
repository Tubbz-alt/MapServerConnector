/**
 * @file    LogHandler.cpp
 * @author  Marvin Smith
 * @date    3/11/2016
 */
#include "LogHandler.hpp"

// C++ Libraries
#include <memory>

// Boost Libraries
#include <boost/algorithm/string.hpp>


/***********************************************/
/*          Convert String to Log Level        */
/***********************************************/
LogLevel StringToLogLevel( const std::string& log_level_str )
{
    // Convert to Upper Case
    std::string log_level = log_level_str;
    boost::to_upper( log_level );

    // Check values
    if( log_level == "TRACE" ){
        return LogLevel::TRACE;
    }

    if( log_level == "DEBUG" ){
        return LogLevel::DEBUG;
    }

    if( log_level == "INFO" ){
        return LogLevel::INFO;
    }

    if( log_level == "WARNING" ){
        return LogLevel::WARNING;
    }

    if( log_level == "ERROR" ){
        return LogLevel::ERROR; 
    }

    if( log_level == "FATAL" ){
        return LogLevel::FATAL;
    }

    return LogLevel::UNKNOWN;
}


/***********************************************/
/*          Convert Log Level to String        */
/***********************************************/
std::string LogLevelToString( const LogLevel& log_level )
{
    switch( log_level ){

        case LogLevel::UNKNOWN:
            return "UNKNOWN";
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::DEBUG:
            return "DEBUG";
        case LogLevel::TRACE:
            return "TRACE";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
        case LogLevel::FATAL:
            return "FATAL";
        default:
            return "UNNOWN";
    }
    return "UNKNOWN";
}



/********************************************/
/*          Get the Current Time            */
/********************************************/
std::string NowTime()
{
    std::string theString;
    struct tm the_tmTime;
    struct timeval timevalTime; 
    gettimeofday(&(timevalTime), NULL);
    gmtime_r(&timevalTime.tv_sec, &the_tmTime);

    char *YYYYMMDD_String = new char[9];
    char *HHMMSS_String = new char[7];
    char *YYYNNDD_HHMMSS_String = new char[16];
    size_t size = 15;

    memset (YYYNNDD_HHMMSS_String, 0, sizeof(YYYNNDD_HHMMSS_String));

    strftime(YYYYMMDD_String, size, "%Y%m%d", &the_tmTime);
    strftime(HHMMSS_String, size, "%H%M%S", &the_tmTime);

    strcat(YYYNNDD_HHMMSS_String, YYYYMMDD_String);
    strcat(YYYNNDD_HHMMSS_String, "_");
    strcat(YYYNNDD_HHMMSS_String, HHMMSS_String);

    theString = "";

    theString.append(YYYNNDD_HHMMSS_String);

    delete [] YYYYMMDD_String;
    delete [] HHMMSS_String;
    delete [] YYYNNDD_HHMMSS_String;

    return theString;
}


