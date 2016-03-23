/**
 * @file    OGC_Layer.hpp
 * @author  Marvin Smith
 * @date    3/21/2016
*/
#ifndef __MSC_OGC_OGC_LAYER_HPP__
#define __MSC_OGC_OGC_LAYER_HPP__

// C++ Libraries
#include <cinttypes>
#include <memory>
#include <string>
#include <vector>

// MSC Libraries
#include "OGC_BoundingBox.hpp"

namespace MSC{
namespace OGC{


/**
 * @class OGC_Layer
*/
class OGC_Layer
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<OGC_Layer> ptr_t;

        
        /**
         * @brief Constructor
        */
        OGC_Layer();

        
        /**
         * @brief Set the Name
        */
        inline void Set_Name( const std::string& name ){
            m_name = name;
        }


        /**
         * @brief Get the name
        */
        inline std::string Get_Name()const{
            return m_name;
        }


        /**
         * @brief Set the Title
         * 
         * @param[in] title
        */
        inline void Set_Title( const std::string& title ){
            m_title = title;
        }


        /**
         * @brief Get the Title
        */
        inline std::string Get_Title()const{
            return m_title;
        }
        

        /**
         * @brief Add Layer
         *
         * @param[in] layer Layer information to add.
        */
        inline void Add_Layer( OGC_Layer::ptr_t layer ){
            m_layers.push_back(layer);
        }


        /**
         * @brief Add CRS
         *
         * @param[in] crs Coordinate Reference System to add.
        */
        void Add_CRS( const std::string& crs );
        

        /**
         * @brief Add Bounding Box
        */
        void Add_BBox( const BoundingBox& bbox );

        /**
         * @brief Print to String
        */
        std::string ToString( const int& offset = 0 )const;
    

    private:
        
        /// Class Name
        std::string m_name;

        /// Layer Title
        std::string m_title;

        /// List of Layers
        std::vector<OGC_Layer::ptr_t> m_layers;
        
        /// List of Coordinate Systems
        std::vector<std::string> m_crs_list;

        /// List of Bounding Boxes
        std::vector<BoundingBox> m_bbox_list;

}; // End of OGC_Layer Class




} // End of OGC Namespace
} // End of MSC Namespace


#endif
