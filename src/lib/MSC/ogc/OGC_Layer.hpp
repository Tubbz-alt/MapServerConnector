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
        */
        inline void Add_Layer( OGC_Layer::ptr_t layer ){
            m_layers.push_back(layer);
        }


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

}; // End of OGC_Layer Class




} // End of OGC Namespace
} // End of MSC Namespace


#endif
