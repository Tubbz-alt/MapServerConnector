/**
 * @file   main.cpp
 * @author Marvin Smith
 * @date   1/27/2016
*/

// C++ Libraries
#include <fstream>
#include <iostream>
#include <stdexcept>

// OpenCV Libraries
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


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

    // Image Size
    const int image_rows = 1000;
    const int image_cols = 1000;

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

    // Build the request list
    MSC::MapRequest request( image_cols, 
                             image_rows,
                             "EPSG:4326",
                             -120,
                             39,
                             -119,
                             40,
                             "image/png");
    
    // Add layers
    request.Add_Layer("0");

    
    // Get the requested map
    MSC::MapResponse response = connector->Get_Map( request );

    // Disconnect the Server
    BOOST_LOG_TRIVIAL(info) << "Disconnecting" << std::endl;
    connector->Disconnect( status );
    if( status.Get_Code() != MSC::StatusCode::SUCCESS ){
        std::cerr << "Error during the disconnect. Details: " + status.ToString() << std::endl;
    }


    // Get the Unpacked Image
    char* unpacked_image;
    int   rows;
    int   cols;
    int   channels;
    response.Get_Unpacked_Image( unpacked_image,
                                 rows,
                                 cols,
                                 channels );

    
    // Create OpenCV Image
    int counter = 0;
    cv::Mat image(rows,cols,CV_8UC(channels));
    int X;
    for( int r=0; r<rows; r++ ){
    for( int c=0; c<cols; c++ ){
    for( int x=0; x<channels; x++ ){
        
        int X=x;
        if( x == 0 ){ X=2; }
        if( x == 2 ){ X=0; }

        if( channels == 1 ){
            image.at<uchar>(r,c) = unpacked_image[counter++];
        }
        else if( channels == 3){
            image.at<cv::Vec3b>(r,c)[X] = unpacked_image[counter++];
        }
        else{
            image.at<cv::Vec4b>(r,c)[X] = unpacked_image[counter++];
        }
    }}}

    // Delete the image
    if( rows * cols * channels > 0 ){
        delete [] unpacked_image;
    }


    // Show the image
    cv::imshow("Retrieved Image", image);
    cv::waitKey(0);

    // Write Image
    std::ofstream fout(output_pathname.c_str(), std::ios::binary );

    fout.write( response.Get_Image_Buffer(),
                response.Get_Image_Buffer_Size_Bytes());
    fout.close();
                
                        


    // Finalize MSC
    BOOST_LOG_TRIVIAL(info) << "Finalizing MSC";
    status = MSC::Finalize();
    if( status.Get_Code() != MSC::StatusCode::SUCCESS ){
        std::cerr << "Error during Finalize. Details: " + status.ToString() << std::endl;
    }
    


    // Remote the file
    response.Finalize();

    // Exit
    BOOST_LOG_TRIVIAL(info) << "Shutting down application" << std::endl;
    return 0;
}


