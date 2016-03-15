/**
 * @file    TEST_OGC_Capabilities.cpp
 * @author  Marvin Smith
 * @date    3/14/2016
*/
#include <gtest/gtest.h>

// MSC Libraries
#include <MSC/ogc/OGC_Capabilities.hpp>

// C++ Libraries
#include <fstream>
#include <iostream>
#include <string>


/*********************************************************/
/*          Test the OGC Capabilities Parsing Given      */
/*          Valid Capabilities file.                     */
/*********************************************************/
TEST( OGC_Capabilities, Parse_Capabilities_WMS_1_3_0_Valid )
{
    
    // Load File
    std::ifstream fin;
    fin.open("../src/test/data/getcapabilities_wms_1_3_0.xml");

    // File Contents
    std::string contents;

    contents.assign(std::istreambuf_iterator<char>(fin),
                    std::istreambuf_iterator<char>());

    fin.close();


    // Get the file size
    ASSERT_EQ( contents.size(), 16285 );
    

    // Pass to Parser
    MSC::OGC::Capabilities::ptr_t capabilities = MSC::OGC::Capabilities::Parse_WMS_1_3_0( contents );

    FAIL();

}

