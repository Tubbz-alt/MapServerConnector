/**
 * @file    Geometries.hpp
 * @author  Marvin Smith
 * @date    3/21/2016
*/
#ifndef __MSC_LIB_GEOMETRIES_HPP__
#define __MSC_LIB_GEOMETRIES_HPP__

namespace MSC{


/**
 * @class Point2
*/
template <typename TP>
class Point2
{
    public:
        
        /**
         * @brief Constructor
        */
        Point2()
        {
            m_data[0] = 0;
            m_data[1] = 0;
        }


        /**
         * @brief Constructor
        */
        Point2( const TP& x, 
                const TP& y )
        {
            m_data[0] = x;
            m_data[1] = y;
        }


        /**
         * @brief Get the X Value
        */
        TP X()const{
            return m_data[0];
        }


        /**
         * @brief Get the X Reference
        */
        TP& X(){
            return m_data[0];
        }
        
        
        /**
         * @brief Get the Y Value
        */
        TP Y()const{
            return m_data[1];
        }


        /**
         * @brief Get the X Reference
        */
        TP& Y(){
            return m_data[1];
        }

        
        /**
         * @brief Addition Operator
        */
        Point2<TP> operator + ( const Point2<TP>& pt )const{
            return Point2<TP>( m_data[0] + pt.m_data[0],
                               m_data[1] + pt.m_data[1] );
        }


    private:
        
        /// Data
        TP m_data[2];

}; // End of Point2 Class


/**
 * @class Rect
*/
template <typename TP>
class Rect
{
    public:
        
        /**
         * @brief Constructor
        */
        Rect()
          : m_min_corner(Point2<TP>()),
            m_width(0),
            m_height(0)
        {
        }


        /**
         * @brief Constructor
        */
        Rect( const Point2<TP>& min_corner,
              const TP&         width,
              const TP&         height )
          : m_min_corner(min_corner),
            m_width(width),
            m_height(height)
        {
        }
        

        /**
         * @brief Get the Width
         */
        inline TP Width()const{
            return m_width;
        }

        /**
         * @brief Get the Height
        */
        inline TP Height()const{
            return m_height;
        }


        /**
         * @brief Get the Top-Left Corner
        */
        Point2<TP> TL()const{
            return m_min_corner + Point2<TP>(0, m_height);
        }


        /**
         * @brief Get the Top-Right Corner
        */
        Point2<TP> TR()const{
            return m_min_corner + Point2<TP>(m_width,m_height);
        }


        /**
         * @brief Get the Bottom-Right Corner
        */
        Point2<TP> BR()const{
            return m_min_corner + Point2<TP>(m_width, 0);
        }


        /**
         * @brief Get the Bottom-Left Corner
        */
        Point2<TP> BL()const{
            return m_min_corner;
        }

    
    private:
        
        /// Bottom-Left Corner
        Point2<TP> m_min_corner;

        /// Width
        TP m_width;

        /// Height
        TP m_height;

}; // End of Rect Class


} // End of MSC Namespace

#endif
