/**
 * @file    ToolbarWidget.hpp
 * @author  Marvin Smith
 * @date    3/12/2016
*/
#ifndef __MSC_APPS_MSC_VIEWER_GUI_TOOLBAR_WIDGET_HPP__
#define __MSC_APPS_MSC_VIEWER_GUI_TOOLBAR_WIDGET_HPP__


// Qt Libraries
#include <QtGui>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>


// MSC Viewer Libraries
#include "../Options.hpp"
#include "AddServiceWidget.hpp"
#include "ServiceListWidget.hpp"
#include "ViewerStatusWidget.hpp"


/**
 * @class ToolbarWidget
*/
class ToolbarWidget : public QWidget
{
    Q_OBJECT

    public:
        
        /**
         * @brief Constructor
         *
         * @param[in] options Configuration options.
         * @param[in] parent  Parent widget.
        */
        ToolbarWidget( Options::ptr_t options,
                       QWidget*       parent );

        
    private:
        
        /// Configuration Options
        Options::ptr_t m_options;

        /// Tabbed Widget
        QTabWidget* m_tab_widget;

        /// Layout
        QVBoxLayout* m_layout;

}; // End of ToolbarWidget Class


#endif
