/**
 * @file    MapViewerWidget.hpp
 * @author  Marvin Smith
 * @date    3/12/2016
*/
#ifndef __MSC_APP_MSC_VIEWER_GUI_MAP_VIEWER_WIDGET_HPP__
#define __MSC_APP_MSC_VIEWER_GUI_MAP_VIEWER_WIDGET_HPP__

// Qt Libraries
#include <QtGui>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVBoxLayout>
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

    
        /**
         * @brief Detect Keyboard Actions.
        */
        void keyPressEvent( QKeyEvent* key_event ); 
        
        /**
         * @brief Event Filter
        */
        bool eventFilter(QObject *obj, QEvent *event);
       
    private:
        
        /// Configuration Options
        Options::ptr_t m_options;

        /// Graphics View
        QGraphicsView* m_graphics_view;

        /// Graphics Scene
        QGraphicsScene* m_graphics_scene;

        /// Layout
        QVBoxLayout* m_layout;

}; // End of MapViewerWidget Class

#endif
