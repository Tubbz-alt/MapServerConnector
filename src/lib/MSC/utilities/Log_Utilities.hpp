/**
 * @file    Log_Utilities.hpp
 * @author  Marvin Smith
 * @date    1/30/2016
*/
#ifndef __MSC_UTILITY_LOG_UTILITIES_HPP__
#define __MSC_UTILITY_LOG_UTILITIES_HPP__


// Boost Libraries
#include <boost/log/common.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/sink.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/severity_feature.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/trivial.hpp>

// C++ Standard Libraries
#include <string>


using namespace boost::log::trivial;

namespace MSC{

/**
 * @brief Macro for logging inside one of the classes.
*/
#define CLASS_LOG m_class_name + "::" + std::string(__func__) 

/**
 * @brief Macro for logging the entry of a class method.
*/
#define CLASS_LOG_ENTRY() BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", Start of Method.";
#define CLASS_LOG_EXIT() BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", End of Method.";


/**
 * @brief Initialize the Logger
 *
 * @param[in] severity Severity of messages to keep.
 * @param[in] log_path Path to logfile to write to.
 */
void Initialize_Logger( const std::string& severity,
                        const std::string& log_path );


} // End of MSC Namespace

#endif
