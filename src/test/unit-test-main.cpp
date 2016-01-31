/**
 * @file    unit-test-main.cpp
 * @author  Marvin Smith
 * @date    1/31/2016
*/


// C++ Standard Libraries
#include <iostream>

// Google Test
#include <gtest/gtest.h>


/**
 * @brief Main Function
*/
int main( int argc, char* argv[] )
{

    // Print Entry
    std::cout << "Running main() from " << __FILE__ << std::endl;

    // Initialize Google Test Framework
    testing::InitGoogleTest(&argc, argv);
  
    // Perform Tests
    return RUN_ALL_TESTS();
}

