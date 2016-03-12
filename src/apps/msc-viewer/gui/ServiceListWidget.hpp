/**
 * @file    ServiceListWidget.hpp
 * @author  Marvin Smith
 * @date    3/12/2016
*/
#ifndef __MSC_APPS_MSC_VIEWER_GUI_SERVICE_LIST_WIDGET_HPP__
#define __MSC_APPS_MSC_VIEWER_GUI_SERVICE_LIST_WIDGET_HPP__

// Qt Libraries
#include <QtGui>
#include <QWidget>

// MSC Viewer Libraries
#include "../Options.hpp"

/**
 * @class ServiceListWidget
*/
class ServiceListWidget : public QWidget
{
    Q_OBJECT

    public:
        
        /**
         * @brief Constructor
        */
        ServiceListWidget( Options::ptr_t options,  
                           QWidget*       parent = NULL );

    
    private:
        
        /// Options
        Options::ptr_t m_options;

}; // End of ServiceListWidget Class

#endif
