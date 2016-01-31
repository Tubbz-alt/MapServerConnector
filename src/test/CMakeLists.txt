#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    1/31/2016
#
#    Purpose:  Construct required unit tests
#


#---------------------------------#
#-     Find Boost Libraries      -#
#---------------------------------#
ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
find_package( Boost REQUIRED
                COMPONENTS
                    system
                    filesystem
                    regex
                    log
                    thread
)
include_directories( ${Boost_INCLUDE_DIRS})



#------------------------------------------#
#-     Build and Configure GoogleTest     -#
#------------------------------------------#
set( GOOGLE_TEST_BASE "${CMAKE_SOURCE_DIR}/src/thirdparty/googletest/googletest" )

set( GOOGLE_TEST_SOURCES
     ${GOOGLE_TEST_BASE}/include/gtest/gtest.h
     ${GOOGLE_TEST_BASE}/include/gtest/gtest-death-test.h
     ${GOOGLE_TEST_BASE}/include/gtest/gtest-message.h
     ${GOOGLE_TEST_BASE}/include/gtest/gtest-param-test.h
     ${GOOGLE_TEST_BASE}/include/gtest/gtest_pred_impl.h
     ${GOOGLE_TEST_BASE}/include/gtest/gtest-printers.h
     ${GOOGLE_TEST_BASE}/include/gtest/gtest_prod.h
     ${GOOGLE_TEST_BASE}/include/gtest/gtest-test-part.h
     ${GOOGLE_TEST_BASE}/include/gtest/gtest-spi.h
     ${GOOGLE_TEST_BASE}/include/gtest/gtest-typed-test.h
     ${GOOGLE_TEST_BASE}/include/gtest/internal/gtest-death-test-internal.h
     ${GOOGLE_TEST_BASE}/include/gtest/internal/gtest-filepath.h
     ${GOOGLE_TEST_BASE}/include/gtest/internal/gtest-internal.h
     ${GOOGLE_TEST_BASE}/include/gtest/internal/gtest-linked_ptr.h
     ${GOOGLE_TEST_BASE}/include/gtest/internal/gtest-param-util.h
     ${GOOGLE_TEST_BASE}/include/gtest/internal/gtest-param-util-generated.h
     ${GOOGLE_TEST_BASE}/include/gtest/internal/gtest-string.h
     ${GOOGLE_TEST_BASE}/include/gtest/internal/gtest-type-util.h
     ${GOOGLE_TEST_BASE}/include/gtest/internal/gtest-port.h
     ${GOOGLE_TEST_BASE}/src/gtest.cc
     ${GOOGLE_TEST_BASE}/src/gtest-death-test.cc
     ${GOOGLE_TEST_BASE}/src/gtest-filepath.cc
     ${GOOGLE_TEST_BASE}/src/gtest-internal-inl.h
     ${GOOGLE_TEST_BASE}/src/gtest-port.cc
     ${GOOGLE_TEST_BASE}/src/gtest-printers.cc
     ${GOOGLE_TEST_BASE}/src/gtest-test-part.cc
)

include_directories( ${GOOGLE_TEST_BASE}/include
                     ${GOOGLE_TEST_BASE}
)
 
#-----------------------------------#
#-      Add Unit Test Files        -#
#-----------------------------------#
set( UNIT_TEST_SOURCES
     unit-test-main.cpp
     TEST_Configuration.cpp
     TEST_Connection_Generator_Factory.cpp
     TEST_Initialization.cpp
)


#-----------------------------------#
#-    Include the MSC Libraries    -#
#-----------------------------------#
include_directories(../lib)

#------------------------------------------#
#-     Build and Link the Application     -#
#------------------------------------------#
add_executable( msc-unit-tests
                ${GOOGLE_TEST_SOURCES}
                ${UNIT_TEST_SOURCES}
)

target_link_libraries( msc-unit-tests
                       MSC
                       ${Boost_LIBRARIES}
)



