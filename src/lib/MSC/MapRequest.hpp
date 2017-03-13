/**
 * @file    MapRequest.hpp
 * @author  Marvin Smith
 * @date    2/1/2016
*/
#ifndef __MSC_MAPREQUEST_HPP__
#define __MSC_MAPREQUEST_HPP__

// C++ Libraries
#include <cinttypes>
#include <memory>
#include <string>
#include <vector>

// MSC Libraries
#include "Enumerations.hpp"
#include "Status.hpp"


namespace MSC{

/**
 * @class MapRequest
*/
class MapRequest
{
    public:
        
        /// Pointer Type
        typedef std::shared_ptr<MapRequest> ptr_t;

        
        /**
         * @brief MapRequest
         *
         * @param[in] image_cols  Number of image cols.
         * @param[in] image_rows  Number of image rows.
         * @param[in] srs         Geographic Coordinate System.        
         */
        MapRequest( const int&          image_cols,
                    const int&          image_rows,
                    const std::string&  crs,
                    const double&       bbox_min_x,
                    const double&       bbox_min_y,
                    const double&       bbox_max_x,
                    const double&       bbox_max_y,
                    const ImageType&    format );
        

        /**
         * @brief Get Image Rows
        */
        inline int Get_Image_Rows()const{
            return m_image_rows;
        }


        /**
         * @brief Get Image Cols
        */
        inline int Get_Image_Cols()const{
            return m_image_cols;
        }
        
        /**
         * @brief Get the CRS
        */
        inline std::string Get_CRS()const{
            return m_crs;
        }


        /**
         * @brief Add Layer
        */
        inline void Add_Layer( std::string const& layer ){
            m_layers.push_back(layer);
        }

        
        /**
         * @brief To WMS URL
        */
        std::string To_WMS_URL()const;
        

        /**
         * @brief To ArcGIS URL
        */
        std::string To_ArcGIS_URL()const;

    private:

        /// Class Name
        std::string m_class_name;


        /// Image Rows
        int m_image_rows;


        /// Image Cols
        int m_image_cols;
        

        /// Layer Name List
        std::vector<std::string> m_layers;
        
        /// Coordinate System
        std::string m_crs;

        /// Coordinate Range
        double m_bbox_min_x; 
        double m_bbox_min_y;
        double m_bbox_max_x;
        double m_bbox_max_y;

        /// Format
        ImageType m_format;

}; // End of MapRequest


/********************************/
/*         Map Response         */
/********************************/
class MapResponse
{
    public:
        
        /// Pointer Type
        typedef std::shared_ptr<MapResponse> ptr_t;


        /**
         * @brief Constructor
        */
        MapResponse();


        /**
         * @brief Status Constructor
        */
        MapResponse( Status const& status );
        

        /**
         * @brief Destructor
        */
        ~MapResponse();
        

        /**
         * @brief Assignment Operator
        */
        MapResponse& operator = ( MapResponse const& response );


        /**
         * @brief Finalize
        */
        void Finalize();

        
        /**
         * @brief Get status
        */
        inline Status Get_Status()const{
            return m_status;
        }

        /**
         * @brief Set the Status
        */
        void Set_Status( Status const& status );

        
        /**
         * @brief Set Buffer
         *
         * @param[in] buffer
         * @param[in] buffer_size_bytes
        */
        void Set_Image_Buffer( char*           buffer,
                               const uint64_t& buffer_size_bytes );

        
        /**
         * @brief Append Image Data
        */
        void Append_Image_Buffer( char*           buffer,
                                  const uint64_t& buffer_size_bytes );
        
        /**
         * @brief Get the Image Buffer
        */
        inline char* Get_Image_Buffer()const{
            return m_image_buffer;
        }


        /**
         * @brief Get the Image Buffer Size
        */
        inline uint64_t Get_Image_Buffer_Size_Bytes()const{
            return m_image_buffer_size_bytes;
        }


        /**
         * @brief Unpack the Image Buffer
        */
        void Get_Unpacked_Image( char*& buffer,
                                 int&   rows,
                                 int&   cols,
                                 int&   channels );

    private:
        
        /// Class Name
        std::string m_class_name;

        // Status
        Status m_status;

        /// Buffer
        char* m_image_buffer;

        /// Image Buffer Size Bytes
        uint64_t m_image_buffer_size_bytes;

}; // End of MapResponse Class

} // End of MSC Namespace

#endif
