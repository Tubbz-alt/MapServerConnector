/**
 * @file   main.cpp
 * @author Marvin Smith
 * @date   1/27/2016
*/

// C++ Libraries
#include <iostream>
#include <stdexcept>


// MapServiceConnector
#include <MSC.hpp>


/**
 * Main Function
*/
int main( int argc, char* argv[] )
{
    // Misc variables
    std::string config_pathname(argv[1]);
    std::string output_pathname(argv[2]);
    MSC::Status status;

    // Create a MapServiceConnector
    MSC::MapServiceConnector::ptr_t connector = MSC::MapServiceConnectorFactory::Create( config_pathname, status );

    //  Make sure the creation succeeded
    if( status.Get_Code() != MSC::StatusCode::SUCCESS ){
        throw std::runtime_error("Initialization of connector failed. Details: " + status.ToString());
    }

    
    // Connect the server
    connector->Connect( status );


    // Check the status
    if( status.Get_Code() != MSC::StatusCode::SUCCESS ){
        throw std::runtime_error("Unable to Connect. Details: " + status.ToString() );
    }

    // Get the feature list


    // Disconnect the Server
    connector->Disconnect( status );
    if( status.Get_Code() != MSC::StatusCode::SUCCESS ){
        std::cerr << "Error during the disconnect. Details: " + status.ToString() << std::endl;
    }

    // Exit
    return 0;
}


