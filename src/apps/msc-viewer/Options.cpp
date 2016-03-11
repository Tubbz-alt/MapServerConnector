/**
 * @file    Options.cpp
 * @author  Marvin Smith
 * @date    3/11/2016
 */
#include "Options.hpp"

// MSC Libraries
#include "log/LogHandler.hpp"
#include "utils/FilePath.hpp"


// C++ Libraries
#include <cstdlib>
#include <deque>
#include <sstream>

// Boost Libraries
#include <boost/filesystem.hpp>


/****************************************/
/*              Constructor             */
/****************************************/
Options::Options( int argc, char* argv[] )
  : m_class_name("Options")
{

    // Load Default Settings
    Load_Default_Settings();


    // Parse Command-Line Options
    Parse_Command_Line( argc, argv );
    
    
    // Check configuration files
    Check_Configuration_Directory();

    
    // Load Configuration File
    Load_Configuration_File();


    // Print the MSC Home
    LOG_MSG( LogLevel::DEBUG ) << "Loading Configuration file at " << m_gui_config_settings["MSC_HOME"];


    // Load Services
    Load_Map_Services();

}


/********************************************/
/*        Get GUI Config Setting            */
/********************************************/
std::string Options::Get_GUI_Config_Parameter( const std::string& key, bool& found )const
{
    if( m_gui_config_settings.find(key) == m_gui_config_settings.end() ){
        found = false;
        return "";
    }
    
    found = true;
    return m_gui_config_settings.find(key)->second;
    
}


/********************************************/
/*        Get GUI Config Setting            */
/********************************************/
std::string Options::Get_GUI_Config_Parameter( const std::string& key, 
                                               const std::string& default_value )const
{
    if( m_gui_config_settings.find(key) == m_gui_config_settings.end() ){
        return default_value;
    }
    return m_gui_config_settings.find(key)->second;
    
}


/**********************************************/
/*          Load Default Settings             */
/**********************************************/
void Options::Load_Default_Settings()
{
    // Set Default MSC Home
#if defined(__unix) || defined(__APPLE__)
    if( getenv("MSC_HOME") != NULL ){
        m_gui_config_settings["MSC_HOME"] = getenv("MSC_HOME");
	}
    else{
        m_gui_config_settings["MSC_HOME"] = std::string(getenv("HOME")) + "/.msc-viewer";
    }
#else
    #error "Not implemented yet."
#endif

    // Set the Default Log Level
    m_gui_config_settings["LOG_MIN_SEVERITY"] = "INFO";


}




/********************************************/
/*          Parse the Command-Line          */
/********************************************/
void Options::Parse_Command_Line( int argc, char* argv[] )
{



}


/********************************************************/
/*          Check the Configuration Directory           */
/********************************************************/
void Options::Check_Configuration_Directory()
{
    // Create Configuration Directory If Needed
    FilePath config_dir(m_gui_config_settings["MSC_HOME"]);
    if( !config_dir.Exists() || !config_dir.Is_Directory() )
    {
        if( config_dir.Create_Directory( true ) ){
            LOG_MSG(LogLevel::INFO) << "Created MSC Home Directory at " << config_dir.ToString();
        }
        else{
            LOG_MSG(LogLevel::ERROR) << "Unable to Create Directory (" << config_dir.ToString() << ")";
        }
    }



}


/***********************************************/
/*          Load the Configuration File        */
/***********************************************/
void Options::Load_Configuration_File()
{

}


/****************************************/
/*          Load Map Services           */
/****************************************/
void Options::Load_Map_Services()
{


}


