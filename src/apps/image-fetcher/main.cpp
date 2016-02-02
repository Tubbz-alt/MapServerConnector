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
#include <MSC/utilities/Log_Utilities.hpp>

/**
 * Main Function
*/
int main( int argc, char* argv[] )
{
    // Misc variables
    std::string config_pathname(argv[1]);
    std::string output_pathname(argv[2]);
    MSC::Status status = MSC::Status(MSC::StatusCode::SUCCESS);

    // Create a MapServiceConnector
    MSC::MapServiceConnector::ptr_t connector = MSC::MapServiceConnectorFactory::Create( config_pathname, status );

    //  Make sure the creation succeeded
    if( status.Get_Code() != MSC::StatusCode::SUCCESS ){
        throw std::runtime_error("Initialization of connector failed. Details: " + status.ToString());
    }

    
    // Connect the server
    BOOST_LOG_TRIVIAL(info) << "Connecting" << std::endl;
    connector->Connect( status );


    // Check the status
    if( status.Get_Code() != MSC::StatusCode::SUCCESS ){
        throw std::runtime_error("Unable to Connect. Details: " + status.ToString() );
    }

    // Get the feature list


    // Disconnect the Server
    BOOST_LOG_TRIVIAL(info) << "Disconnecting" << std::endl;
    connector->Disconnect( status );
    if( status.Get_Code() != MSC::StatusCode::SUCCESS ){
        std::cerr << "Error during the disconnect. Details: " + status.ToString() << std::endl;
    }

    // Finalize MSC
    status = MSC::Finalize();
    BOOST_LOG_TRIVIAL(info) << "Finalizing MSC";
    if( status.Get_Code() != MSC::StatusCode::SUCCESS ){
        std::cerr << "Error during Finalize. Details: " + status.ToString() << std::endl;
    }


    // Exit
    BOOST_LOG_TRIVIAL(info) << "Shutting down application" << std::endl;
    return 0;
}


