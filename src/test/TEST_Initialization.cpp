/**
 * @file    TEST_Initialization.cpp
 * @author  Marvin Smith
 * @date    1/31/2016
*/
#include <gtest/gtest.h>

// Include MSC
#include <MSC/Initialization.hpp>


/*************************************************************/
/*      Test the Initialization / Finalization methods       */
/*************************************************************/
TEST( Initialization, Initialize_Finalize_01 )
{
    // Create a Configuration
    MSC::Configuration config;
    config.Insert("log_severity","foo.txt");
    
    // Start off Finalized
    MSC::Finalize();

    // Check status
    ASSERT_FALSE( MSC::Is_Initialized() );

    // Initialize
    MSC::Status status = MSC::Initialize( config );
    ASSERT_EQ( status.Get_Code(), MSC::StatusCode::SUCCESS );
    
    // Check the Status
    ASSERT_TRUE( MSC::Is_Initialized() );

    // Finalize
    status = MSC::Finalize();
    ASSERT_EQ( status.Get_Code(), MSC::StatusCode::SUCCESS );

    // Check the status
    ASSERT_FALSE( MSC::Is_Initialized() );
}

