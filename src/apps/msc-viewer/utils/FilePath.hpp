/**
 * @file    FilePath.hpp
 * @author  Marvin Smith
 * @date    3/11/2016
 */
#ifndef __MSC_APP_MSC_VIEWER_UTILS_FILEPATH_HPP__
#define __MSC_APP_MSC_VIEWER_UTILS_FILEPATH_HPP__


// C++ Standard Libraries
#include <iostream>
#include <string>
#include <vector>


/**
 * @class FilePath
 */
class FilePath
{
    public:
        
        /**
         * @brief Default Constructor
         */
        FilePath();


        /**
         * @brief Parameterized Constructor
         */
        FilePath( const std::string& pathname );


        /**
         * @brief Check if File Exists.
         */
        bool Exists()const;

        
        /**
         * @brief Check if path is a directory
         *
         * @return True if directory, false otherwise.
         */
        bool Is_Directory()const;

        
        /**
         * @brief Check if path is file
         */
        bool Is_Regular_File()const;

        
        /**
         * @brief Get the File System in Bytes
         *
         * If the file does not exist or fails, then the function will return -1.
         */
        int Get_File_Size_Bytes()const;


        /**
         * @brief Return the parent directory
         */
        FilePath Get_Parent_Path()const;


        /**
         * @brief Get the basename
         */
        FilePath Get_Basename()const;


        /**
         * @brief Get the Extension
         */
        FilePath Get_Extension()const;


        /**
         * @brief Get the stem
         *
         * @brief Base directory without the extension.
         */
        FilePath Get_Stem()const;


        /**
         * @brief Convert to string
         */
        std::string ToString()const;


        /**
         * @brief Convert to C_String
         */
        const char* ToCString()const;


        /**
         * @brief Comparison Operator
         */
        bool operator == ( const FilePath& other )const;


        /**
         * @brief List Contents
         *
         * @return List of elements inside the directory.
         */
        std::vector<FilePath> Get_Contents()const;


        /**
         * @brief List Contents with a Regex Pattern.
         *
         * @param[in] pattern Regex pattern to apply.
         *
         * @return List of new paths that match the criteria.
         */
        std::vector<FilePath> Get_Contents( const std::string& pattern )const;


        /**
         * @brief Delete the file.
         *
         * @return True if success, false otherwise.
         */
        bool Remove()const;

        
        /**
         * @brief Remove contents recursively.  Use if item is directory with contents or subdirectories.
         *
         * @return True if success. False otherwise.
         */
        bool Remove_All()const;
        

        /**
         * @brief Return in a String format.
         *
         * @return String representation.
         */
        inline operator std::string()const{
            return ToString();
        }

        
        /**
         * @brief Append the Path
         */
        FilePath operator /( FilePath const& other )const;
 

        /**
         * @brief Append the path to yourself.
         *
         * @param[in] Path to append.
         *
         * @return Yourself for chaining.
         */
        FilePath operator /= ( FilePath const& other );

        
        /**
         * @brief Create the Directory.
         *
         * @param[in] recursive  Flag if you want to create any missing parent directories.
         *
         * @return True if successful, false otherwise.
         */
        bool Create_Directory( const bool& recursive = false )const;
        

        /**
         * @brief Create a Symbolic Link.
         *
         * @param[in] link_path
         * 
         * @return Flag if link succeeds.
         */
        bool Create_Symlink( const FilePath& link_path )const;


        /**
         * @brief Copy the File.
         *
         * @param[in] new_path
         *
         * @return True if success, false if failure.
         */
        bool Copy_File( const FilePath& new_path )const;


    private:

        /// Pathname parameter
        std::string m_pathname;


}; // End of FilePath Class


/**
 * @brief Output Stream Operator
 */
std::ostream& operator << ( std::ostream& ostr, const FilePath& rhs );


#endif
