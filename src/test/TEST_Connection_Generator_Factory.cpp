/**
 * @file    TEST_Connection_Generator_Factory.cpp
 * @author  Marvin Smith
 * @date    1/31/2016
*/
#include <gtest/gtest.h>

// MSC Libraries
#include <MSC/Initialization.hpp>
#include <MSC/Connection_Generator_Factory.hpp>


/*******************************************************/
/*      Test the Generation of an OGC Connector        */
/*******************************************************/
TEST( Connection_Generator_Factory, Create_OGC_Connector )
{
    // Create Configuration
    MSC::Configuration config;
    config.Insert("log_severity","info");
    config.Insert("log_path","info");
    config.Insert("connector","ogc");

    // Misc Variables
    MSC::Status status;

    // Initialize if needed
    if( MSC::Is_Initialized() == false ){
        status = MSC::Initialize( config );
    }


    // Check the create method
    MSC::Base_Connector::ptr_t  connector = MSC::Connection_Generator_Factory::Create( config, status );

    // Check the status
    ASSERT_EQ( status.Get_Code(), MSC::StatusCode::SUCCESS );

}

