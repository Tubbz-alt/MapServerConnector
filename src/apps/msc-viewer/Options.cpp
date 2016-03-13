/**
 * @file    Options.cpp
 * @author  Marvin Smith
 * @date    3/11/2016
 */
#include "Options.hpp"

// MSC Libraries
#include "log/LogHandler.hpp"
#include "utils/FilePath.hpp"
#include "utils/String_Utilities.hpp"


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
    FilePath config_path = FilePath(m_gui_config_settings["MSC_HOME"]) / FilePath("options.cfg");
    Load_Configuration_File(config_path);


    // Print the MSC Home


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


/*********************************************/
/*          Close all map services           */
/*********************************************/
void Options::Close_Map_Services()
{
    // Log
    LOG_MSG(LogLevel::INFO) << "Closing Map-Services.";

    // Iterate over connectors
    MSC::Status msc_status;
    for( auto it=m_map_services.begin(); it != m_map_services.end(); it++ )
    {
        it->second->Disconnect( msc_status );
    }
    m_map_services.clear();
    
    // Finalize MSC
    MSC::Finalize();

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
    

    // Check the Configuration File
    FilePath config_file_path = config_dir / FilePath("options.cfg");
    if( !config_file_path.Exists() )
    {
        // Generate the Config File
        Generate_Configuration_File( config_file_path );
    }

    // check the services directory
    FilePath services_path = config_dir / FilePath("services");
    if( !services_path.Exists() || !services_path.Is_Directory() ){
        LOG_MSG(LogLevel::INFO) << "Creating Services Directory: " << services_path.ToString();
        if( !services_path.Create_Directory() ){
            LOG_MSG(LogLevel::ERROR) << "Unable to create service directory: " << services_path.ToString();
        }
    }

}


/************************************************/
/*        Generate the Configuration File       */
/************************************************/
void Options::Generate_Configuration_File( const FilePath& config_path )
{
    // Open the File
    std::ofstream fout;
    fout.open(config_path.ToString().c_str());
    fout << std::endl;
    
    
    // Write the Program Configuration
    fout << "#  Program Configuration Information" << std::endl;
    fout << "SERVICES_REGEX_PATTERN=.*\\.cfg" << std::endl;
    fout << std::endl;

    // Write the GUI Configuration
    fout << "#  GUI Configuration Information" << std::endl;
    fout << "GUI_TITLE=Map Service Connector Viewer" << std::endl;
    fout << std::endl;

    // Close the File
    fout.close();

}

/***********************************************/
/*          Load the Configuration File        */
/***********************************************/
void Options::Load_Configuration_File( const FilePath& config_path )
{

    // open the file
    std::ifstream fin;
    fin.open( config_path.ToString().c_str());

    // read the first line
    std::string line;
    std::getline( fin, line);

    // split the string
    std::vector<std::string> components = String_Split(line,"="); 
    
    // pass components to set function
    if( components.size() > 1 ){
        m_gui_config_settings[components[0]] = components[1];
    }

    // iterate until empty
    while( !fin.eof() )
    {
        // grab the next line
        std::getline( fin, line);
        std::vector<std::string> components = String_Split(line,"="); 

        // set the item        
        if( components.size() > 1 ){
            m_gui_config_settings[components[0]] = components[1];
        }
    }

    // close the file
    fin.close();

}


/****************************************/
/*          Load Map Services           */
/****************************************/
void Options::Load_Map_Services()
{
    // MSC Variables
    MSC::Status msc_status;
    
    // Define the services directory
    FilePath config_dir(m_gui_config_settings["MSC_HOME"]);
    FilePath services_dir = config_dir / FilePath("services");
    
    std::string services_regex_pattern = m_gui_config_settings["SERVICES_REGEX_PATTERN"];

    // Get a list of service config files in the services directory
    std::vector<FilePath> service_files = services_dir.Get_Contents(services_regex_pattern);
    
    // Print the services list
    LOG_MSG(LogLevel::INFO) << "Detected " << service_files.size() << " service files.";
    for( size_t i=0; i<service_files.size(); i++ )
    {
        LOG_MSG(LogLevel::INFO) << " - " << service_files[i];

        // Check if already added
        if( m_map_services.find(service_files[i]) != m_map_services.end() ){
            LOG_MSG(LogLevel::INFO) << " Already added.";
        }

        // Add otherwise
        else{
            // Create MSC
            auto connector = MSC::MapServiceConnectorFactory::Create( service_files[i].ToString(), msc_status );

            // check connector status for errors
            if( connector == nullptr || msc_status.Get_Code() != MSC::StatusCode::SUCCESS ){
                LOG_MSG(LogLevel::ERROR) << "Unable to Create Map-Service-Connector. Details: " << msc_status.ToString();
            }

            // Add to service list
            else{
                m_map_services[service_files[i]] = connector;
            }
        }
    }

}


