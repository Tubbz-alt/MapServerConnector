/**
 * @file    msc-get-info.cpp
 * @author  Marvin Smith
 * @date    3/14/2016
*/

// MSC Libraries
#include <MSC.hpp>
#include <MSC/utilities/Log_Utilities.hpp>


// C++ Libraries
#include <iostream>


/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{

    // Misc variables
    std::string config_pathname(argv[1]);
    MSC::Status status = MSC::Status(MSC::StatusCode::SUCCESS);

    // Create a MapServiceConnector
    MSC::MapServiceConnector::ptr_t connector = MSC::MapServiceConnectorFactory::Create( config_pathname, 
                                                                                         status );

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
    

    // Get the list of capabilities
    MSC::Capabilities::ptr_t capabilities = connector->Get_Capabilities(status);

    // Check the status
    if( status.Get_Code() != MSC::StatusCode::SUCCESS ||
        capabilities      == nullptr )
    {
        throw std::runtime_error("Unable to Get-Capabilities. Details: " + status.ToString());
    }

    // Print the Capability Info
    BOOST_LOG_TRIVIAL(info) << "\n" << capabilities->ToString() << std::endl;

    // Disconnect the Server
    BOOST_LOG_TRIVIAL(info) << "Disconnecting" << std::endl;
    connector->Disconnect( status );
    if( status.Get_Code() != MSC::StatusCode::SUCCESS ){
        std::cerr << "Error during the disconnect. Details: " + status.ToString() << std::endl;
    }


    // Finalize MSC
    BOOST_LOG_TRIVIAL(info) << "Finalizing MSC";
    status = MSC::Finalize();
    if( status.Get_Code() != MSC::StatusCode::SUCCESS ){
        std::cerr << "Error during Finalize. Details: " + status.ToString() << std::endl;
    }
    
    
    // Exit
    BOOST_LOG_TRIVIAL(info) << "Shutting down application" << std::endl;
    return 0;
}

