/**
 * @file    Options.hpp
 * @author  Marvin Smith
 * @date    3/11/2016
 */
#ifndef __MSC_APP_MSC_VIEWER_OPTIONS_HPP__
#define __MSC_APP_MSC_VIEWER_OPTIONS_HPP__

// C++ Libraries
#include <map>
#include <memory>
#include <string>


// MSC Viewer Libraries
#include "log/LogHandler.hpp"
#include "utils/FilePath.hpp"


// MSC Library
#include <MSC.hpp>


// Qt Libraries
#include <QGuiApplication>
#include <QtGui>

/**
 * @class Options
 */
class Options
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Options> ptr_t;


        /**
         * @brief Constructor
         * 
         * @param[in] argc
         * @param[in] argv
         */
        Options( int argc, char* argv[] );
        

        /**
         * @brief Get the Current Projection
        */
        inline std::string Get_Current_Projection()const{
            return m_current_projection;
        }


        /**
         * @brief Get the list of Map Services.
         *
         * @preturn Map of services with their ID as the key.
         */
        inline std::map<FilePath, MSC::MapServiceConnector::ptr_t> Get_Map_Services()const{
            return m_map_services;
        }


        /**
         * @brief Get GUI Config Setting
         *
         * @param[in] key Key to search against.
         * @param[out] found True if value found.
         * 
         * @return Value of key.
        */
        std::string Get_GUI_Config_Parameter( const std::string& key, bool& found )const;
        
        
        /**
         * @brief Get GUI Config Setting.
         * 
         * @param[in] key Key to search against.
         * @param[in] default_value Value if search fails.
         *
         * @return Value of key.
         */
        std::string Get_GUI_Config_Parameter( const std::string& key, 
                                              const std::string& default_value )const;

         
        /**
         * @brief Get GUI Config Setting.
         * 
         * @param[in] key Key to search against.
         * @param[in] default_value Value if search fails.
         *
         * @return Value of key.
         */
        int Get_GUI_Config_Parameter_Int32( const std::string& key, 
                                            const int&         default_value )const;
                                                 
                                     
        
        /**
         * @brief Get the Requested GUI Font
         */
        QFont  Get_GUI_Font( const std::string& font_key = "GUI_H1_FONT" )const;


        /**
         * @brief Close map services.
        */
        void Close_Map_Services();


    private:

        /**
         * @brief Load Default Values
         */
        void Load_Default_Settings();


        /**
         * @brief Parse the Command-Line Options
         */
        void Parse_Command_Line( int argc, char* argv[] );


        /**
         * @brief Check the Configuration Directory
         */
        void Check_Configuration_Directory();


        /**
         * @brief Load Configuration Files
         */
        void Load_Configuration_File( const FilePath& config_path );


        /**
         * @brief Generate a Configuration File
        */
        void Generate_Configuration_File( const FilePath& config_path );


        /**
         * @brief Load Map Services
         */
        void Load_Map_Services();


        /// Class Name
        std::string m_class_name;

        /// GUI Config Settings
        std::map<std::string,std::string> m_gui_config_settings;
        
        /// List of Map Services
        std::map<FilePath, MSC::MapServiceConnector::ptr_t> m_map_services;
    
        /// Current Viewer Projection
        std::string m_current_projection;

}; // End of Options Class


#endif
