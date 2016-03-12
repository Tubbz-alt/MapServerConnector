/**
 * @file    MapViewerWidget.hpp
 * @author  Marvin Smith
 * @date    3/12/2016
*/
#ifndef __MSC_APP_MSC_VIEWER_GUI_MAP_VIEWER_WIDGET_HPP__
#define __MSC_APP_MSC_VIEWER_GUI_MAP_VIEWER_WIDGET_HPP__

// Qt Libraries
#include <QtGui>
#include <QWidget>

// MSC Viewer Libraries
#include "../Options.hpp"

/**
 * @class MapViewerWidget
*/
class MapViewerWidget : public QWidget
{
    Q_OBJECT

    public:
        
        /**
         * @brief Constructor
        */
        MapViewerWidget( Options::ptr_t options,
                         QWidget*       parent );

        
    private:
        
        /// Configuration Options
        Options::ptr_t m_options;

}; // End of MapViewerWidget Class

#endif
