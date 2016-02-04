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
                    int&             output_cols )
{
    // Create memory file system object
    VSIFCloseL( VSIFileFromMemBuffer( "/vsimem/work.dat", 
                                      (unsigned char*)input_buffer,
                                      input_buffer_size,
                                      false ));

 

     // Open memory buffer for read.
     GDALDataset* dataset = (GDALDataset*)GDALOpen( "/vsimem/work.dat", 
                                                    GA_ReadOnly ); 

     // Get output format driver. 
     GDALDriver* driver = (GDALDriver*)GDALGetDriverByName( "PNG" );//GTiff" );
    

    // Set the parameters
    if( driver == NULL ){
        BOOST_LOG_TRIVIAL(error) << "Unable to parse GDAL raster";
        return;
    }

    output_cols = dataset->GetRasterXSize();
    output_rows = dataset->GetRasterYSize();
    BOOST_LOG_TRIVIAL(debug) << "Raster Rows: " << output_rows << ", Raster Cols: " << output_cols;

 
     // close source file, and "unlink" it.  
     GDALClose( dataset );
     VSIUnlink( "/vsimem/work.dat" );
 
     // seize the buffer associated with the output file. 
     //return VSIGetMemFileBuffer( "/vsimem/out.tif", pnOutDataLength, TRUE );

}


} // End of MSC Namespace

