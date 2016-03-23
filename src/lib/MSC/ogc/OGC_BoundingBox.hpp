/**
 * @file    OGC_BoundingBox.hpp
 * @author  Marvin Smith
 * @date    3/22/2016
*/
#ifndef __MSC_LIB_MSC_OGC_OGC_BOUNDING_BOX_HPP__
#define __MSC_LIB_MSC_OGC_OGC_BOUNDING_BOX_HPP__

// C++ Libraries
#include <memory>
#include <string>

// MSC Libraries
#include "../Geometries.hpp"

namespace MSC{
namespace OGC{

/**
 * @class BoundingBox
*/
class BoundingBox
{
    public:
    
        /// Pointer Type
        typedef std::shared_ptr<BoundingBox> ptr_t;

        
        /**
         * @brief Default Constructor
        */
        BoundingBox();


        /**
         * @brief Constructor
         * 
         * @param[in] crs  Coordinate Reference System.
         * @param[in] bbox Bounding Box.
        */
        BoundingBox( const std::string&   crs,
                     const Rect<double>&  bbox );
        

        /**
         * @brief Get the CRS
        */
        inline std::string Get_CRS()const{
            return m_crs;
        }


        /**
         * @brief Get the Bounding Box
        */
        inline Rect<double> Get_BBox()const{
            return m_bbox;
        }
        
        /**
         * @brief Print to String
        */
        std::string ToString( const int& offset = 0)const;

    private:
        
        /// CRS
        std::string m_crs;

        /// BBox
        Rect<double> m_bbox;

}; // End of BoundingBox Class

} // End of OGC Namespace
} // End of MSC Namespace


#endif
