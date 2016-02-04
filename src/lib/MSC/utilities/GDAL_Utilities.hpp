/**
 * @file    GDAL_Utilities.hpp
 * @author  Marvin Smith
 * @date    2/2/2016
*/
#ifndef __MSC_GDAL_UTILITIES_HPP__
#define __MSC_GDAL_UTILITIES_HPP__


// C++ Libraries
#include <cinttypes>
#include <unistd.h>

namespace MSC{


/**
 * @brief
*/
void Decode_Raster( char*            input_buffer,
                    const uint64_t&  input_buffer_size,
                    char*&           output_buffer,
                    int&             output_rows,
                    int&             output_cols );


} // End of MSC Namespace


#endif
