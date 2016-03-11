/**
 * @file    FilePath.cpp
 * @author  Marvin Smith
 * @date    3/11/2016
 */
#include "FilePath.hpp"


// Prevent stupid bug in Boost-Filesystem
#define BOOST_NO_CXX11_SCOPED_ENUMS

// include boost
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>


namespace bf=boost::filesystem;


/************************************************/
/*            Default Constructor               */
/************************************************/
FilePath::FilePath() 
  : m_pathname("")
{
}


/***********************************************************/
/*               Parameterized Constructor                 */
/***********************************************************/
FilePath::FilePath(std::string const& pathname ) 
  : m_pathname(pathname)
{
}


/****************************************************/
/*               Check if file exists               */
/****************************************************/
bool FilePath::Exists()const{
    return bf::exists( bf::path(m_pathname));
}


/*****************************************************/
/*              Check if item is directory           */
/*****************************************************/
bool FilePath::Is_Directory()const{
    return bf::is_directory(bf::path(m_pathname));
}


/**************************************************/
/*         Check if item is a regular file        */
/**************************************************/
bool FilePath::Is_Regular_File()const{
    return bf::is_regular_file(bf::path(m_pathname));
}


/**************************************************/
/*               Get the File Size                */
/**************************************************/
int FilePath::Get_File_Size_Bytes()const{

    if( !Exists() ){
        return -1;
    }

    // Open the file
    try{
        return bf::file_size(bf::path(m_pathname));
    } catch (...){
        return -1;
    }
}


/************************************************/
/*         Get the parent directory             */
/************************************************/
FilePath FilePath::Get_Parent_Path()const{
    return FilePath(bf::path(m_pathname).parent_path().native());
}


/************************************************/
/*              Get the basename                */
/************************************************/
FilePath  FilePath::Get_Basename()const{
    return FilePath( bf::path(m_pathname).filename().native());
}


/*********************************************************/
/*                 Get the extension                     */
/*********************************************************/
FilePath  FilePath::Get_Extension()const{
    return FilePath( bf::path(m_pathname).extension().native());
}


/***************************************************/
/*               Get the stem                      */
/***************************************************/
FilePath  FilePath::Get_Stem()const{
    return  FilePath( bf::path(m_pathname).stem().native());
}


/*************************************************/
/*             Convert to string                 */
/*************************************************/
std::string FilePath::ToString()const{
    return m_pathname;
}


/*************************************************/
/*                Convert to C String            */
/*************************************************/
const char* FilePath::ToCString()const{
    return m_pathname.c_str();
}


/*************************************************/
/*              Comparison operator              */
/*************************************************/
bool FilePath::operator==( const FilePath& path )const{
    return (m_pathname == path.m_pathname);
}


/************************************************************/
/*          Get the Contents of the Subdirectory            */
/************************************************************/
std::vector<FilePath>  FilePath::Get_Contents()const{
    return Get_Contents(".*");
}


/****************************************************/
/*      Get the Contents of the Directory (ls)      */
/****************************************************/
std::vector<FilePath>  FilePath::Get_Contents( const std::string& pattern )const{

    // create output
    std::vector<FilePath> output;

    // make sure the directory exists
    if( Exists() == false ){
        return std::vector<FilePath>();
    }

    // make sure the path is a directory
    if( Is_Directory() == false ){
        return std::vector<FilePath>();
    }

    //iterate through it and pull out all files matching the flag description
    bf::directory_iterator iter(m_pathname);
    bf::directory_iterator end_iter;

    std::string filename, extension;

    for( ; iter != end_iter; iter++){

        // get the filename
        filename = (*iter).path().string();

        // make sure it matches the pattern
        if(  boost::regex_match( filename, boost::regex(pattern)) == false){
            continue;
        }

        // add it to the list
        output.push_back(filename);
    }

    // return the list
    return output;
}


/*****************************************/
/*                Remove                 */
/*****************************************/
bool FilePath::Remove()const{
    return boost::filesystem::remove(boost::filesystem::path(m_pathname));
}


/*****************************************/
/*               Remove All              */
/*****************************************/
bool FilePath::Remove_All()const{
    return boost::filesystem::remove_all(boost::filesystem::path(m_pathname));
}


/*******************************************/
/*              Append the Path            */
/*******************************************/
FilePath  FilePath::operator / ( FilePath const& other )const
{
    return FilePath( (bf::path(m_pathname) / bf::path(other.m_pathname)).native());
}


/*******************************************/
/*              Append the Path            */
/*******************************************/
FilePath FilePath::operator /= ( FilePath const& other )
{
    // Append to ourselves
    m_pathname = FilePath( (bf::path(m_pathname) / bf::path(other.m_pathname)).native());

    // Return ourselves
    return (*this);
}



/**************************************/
/*          Create Directory          */
/**************************************/
bool FilePath::Create_Directory( const bool& recursive )const
{
    // Check if empty
    if( m_pathname == "" ){
        return false;
    }


    // Convert to boost path
    boost::filesystem::path temp_path(m_pathname);

    // These operations may throw exceptions, so catch everything
    try{
        
        // Check if recursive
        if( recursive == true )
        {
            // Call the directories method
            create_directories( temp_path );

        }

        // Otherwise, call singular method
        else{
            create_directory(temp_path);
        }
    
    }

    // If Exception Caught, return false
    catch( std::exception& e )
    {
        return false;
    }
    catch(...)
    {
        return false;
    }

    // Otherwise, declare victory
    return true;
}


/*******************************************/
/*          Create Symbolic Link           */
/*******************************************/
bool FilePath::Create_Symlink( const FilePath& link_path )const
{
    try{
        boost::filesystem::create_symlink( boost::filesystem::path(m_pathname),
                                           boost::filesystem::path(link_path.m_pathname));
    }
    catch(...)
    {
        return false;
    }
    return true;
}


/************************************/
/*          Copy File Path          */
/************************************/
bool  FilePath::Copy_File(  FilePath const& new_path )const
{
    try
    {
        // Copy the file
        bf::copy_file( bf::path(m_pathname),
                       bf::path(new_path.ToString()),
                       bf::copy_option::overwrite_if_exists);

    }
    catch(...)
    {
        return false;
    }
    return true;
}


/*******************************************************/
/*               Output stream operator                */
/*******************************************************/
std::ostream& operator << ( std::ostream& ostr, FilePath const& path ){
    ostr << path.ToString();
    return ostr;
}

