/**
 * @file    MapRequest.hpp
 * @author  Marvin Smith
 * @date    2/1/2016
*/
#ifndef __MSC_MAPREQUEST_HPP__
#define __MSC_MAPREQUEST_HPP__

// C++ Libraries
#include <memory>
#include <string>
#include <vector>

// MSC Libraries
#include "Status.hpp"


namespace MSC{

/**
 * @brief MapRequest
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
        MapRequest( const int& image_cols,
                    const int& image_rows,
                    const std::string&  crs,
                    const double& bbox_min_x,
                    const double& bbox_min_y,
                    const double& bbox_max_x,
                    const double& bbox_max_y,
                    const std::string& format );
        

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
        std::string m_format;

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
         * @brief Get status
        */
        inline Status Get_Status()const{
            return m_status;
        }

        /**
         * @brief Set the Status
        */
        void Set_Status( Status const& status );


    private:
        
        /// Class Name
        std::string m_class_name;

        // Status
        Status m_status;

}; // End of MapResponse Class

} // End of MSC Namespace

#endif
