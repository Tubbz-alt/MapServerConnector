/**
 * @file    GDAL_Utilities.cpp
 * @author  Marvin Smith
 * @date    2/2/2016
*/
#include "GDAL_Utilities.hpp"

#include "Log_Utilities.hpp"

#include <gdal_priv.h>


namespace MSC{


/******************************************************/
/*            Load Dataset from Virtual File          */
/******************************************************/
void Decode_Raster( char*            input_buffer,
                    const uint64_t&  input_buffer_size,
                    char*&           output_buffer,
                    int&             output_rows,
                    int&             output_cols,
                    int&             output_channels )
{
    // Log Entry
    BOOST_LOG_TRIVIAL(trace) << "Decode_Raster, Start of Method";

    // Error Checking
    if( input_buffer == nullptr )
    {
        BOOST_LOG_TRIVIAL(error) << "Decode_Raster, Input Buffer was Null.";
    }


    // Initialize Outputs 
    output_buffer   = nullptr;
    output_rows     = 0;
    output_cols     = 0;
    output_channels = 0;
    

    // Create memory file system object
    FILE* handle = VSIFileFromMemBuffer( "/vsimem/work.png", 
                                        (unsigned char*)input_buffer,
                                        input_buffer_size,
                                        false );

    if( handle == nullptr )
    {
        BOOST_LOG_TRIVIAL(error) << "Decode_Raster, Handle Returned was Null.";
        return;
    }

    VSIFCloseL( handle );

    // Opening Dataset
    BOOST_LOG_TRIVIAL(trace) << "Decode_Raster, Building Dataset.";
 

     // Open memory buffer for read.
     GDALDataset* dataset = (GDALDataset*)GDALOpen( "/vsimem/work.png", 
                                                    GA_ReadOnly ); 

     // Get output format driver. 
     GDALDriver* driver = (GDALDriver*)GDALGetDriverByName( "PNG" );//GTiff" );
    

    // Set the parameters
    if( driver == NULL ){
        BOOST_LOG_TRIVIAL(error) << "Unable to parse GDAL raster";
        return;
    }
    
    // Update outputs
    output_cols     = dataset->GetRasterXSize();
    output_rows     = dataset->GetRasterYSize();
    output_channels = dataset->GetRasterCount();
    output_buffer   = new char[output_cols * output_rows * output_channels];
    int osize = output_cols * output_rows * output_channels;

    int output_pos = 0;
    
    // Log Current
    BOOST_LOG_TRIVIAL(debug) << "Raster Rows: " << output_rows << ", Raster Cols: " << output_cols << ", Channels: " << output_channels;

    // Iterate over the bands
    uint8_t* scanline = new uint8_t[output_cols];
    int idx, channel;
    for( int bid=1; bid <= output_channels; bid++ )
    {
        // Get the band
        GDALRasterBand* band = dataset->GetRasterBand(bid);
        channel = bid-1;

        // Iterate over each row
        for( int r=0; r<output_rows; r++ )
        {

            // Fetch the buffer
            band->RasterIO( GF_Read, 0, r, 
                            output_cols,
                            1, 
                            scanline,
                            output_cols,
                            1, 
                            GDT_Byte,
                            0,
                            0);
        
            // Copy
            for( int c=0; c<output_cols; c++ )
            {
                // Compute the Index
                idx = (output_cols * output_channels * r) + (c * output_channels) + channel;
               
                if( idx >= osize ){
                    BOOST_LOG_TRIVIAL(error) << __func__ << "::" << __LINE__ << ", About to go out of bounds. IDX: " << idx << ", Length: " << osize;
                }

                // Update the buffer
                output_buffer[idx] = scanline[c];
            }
        }
    }

    // Clean up
    delete [] scanline;
 
    // close source file, and "unlink" it.  
    GDALClose( dataset );
    VSIUnlink( "/vsimem/work.png" );

}


} // End of MSC Namespace

