/**
 * @file    ToolbarWidget.cpp
 * @author  Marvin Smith
 * @date    3/12/2016
*/
#include "ToolbarWidget.hpp"


/**********************************/
/*          Constructor           */
/**********************************/
ToolbarWidget::ToolbarWidget( Options::ptr_t options,
                              QWidget*       parent )
 : QWidget(parent),
   m_options(options)
{
    // Create the Layout
    m_layout = new QVBoxLayout();

    
    // Create the TabWidget
    m_tab_widget = new QTabWidget(this);
    m_layout->addWidget(m_tab_widget);

    
    // Create various sub-widgets
    ViewerStatusWidget* viewerStatusWidget = new ViewerStatusWidget( m_options );
    m_tab_widget->addTab( viewerStatusWidget, "Viewer Options");

    ServiceListWidget* serviceListWidget = new ServiceListWidget( m_options );
    m_tab_widget->addTab( serviceListWidget, "Services" );

    AddServiceWidget* addServiceWidget = new AddServiceWidget( m_options );
    m_tab_widget->addTab( addServiceWidget, "Add Service");
    
    // Set the Layout
    setLayout(m_layout);

}

