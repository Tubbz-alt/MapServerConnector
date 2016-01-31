/**
 * @file    TEST_Configuration.cpp
 * @author  Marvin Smith
 * @date    1/31/2016
*/
#include <gtest/gtest.h>

// Add MSC Libraries
#include <MSC/Configuration.hpp>


/******************************************************/
/*        Test the Configuration Constructors         */
/******************************************************/
TEST( Configuration, Default_Constructor )
{
    // Create Empty Configuration
    MSC::Configuration config01;

    // Check the Sizes
    ASSERT_EQ( config01.Get_Number_Pairs(), 0 );

}

