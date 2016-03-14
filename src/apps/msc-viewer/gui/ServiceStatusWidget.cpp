/**
 * @file    ServiceStatusWidget.cpp
 * @author  Marvin Smith
 * @date    3/14/2016
 */
#include "ServiceStatusWidget.hpp"



/********************************/
/*          Constructor         */
/********************************/
ServiceStatusWidget::ServiceStatusWidget( FilePath const& map_service_config,
                                          Options::ptr_t  options,
                                          QWidget*        parent )
  : QWidget(parent),
    m_map_config_path(map_service_config),
    m_options(options)
{
    // Create main layout
    m_main_layout = new QVBoxLayout();
    m_main_layout->setAlignment(Qt::AlignTop);

    
    // Check if config exists
    if( map_service_config.Exists() ){
        Build_Service_Status();
    }
    else{
        Build_Empty_Status();
    }


    // set the layout
    setLayout(m_main_layout);
}


/*********************************************/
/*          Build an Empty Status            */
/*********************************************/
void ServiceStatusWidget::Build_Empty_Status()
{

    // Create label
    m_empty_label = new QLabel("No Service Selected");
    m_empty_label->setFont(m_options->Get_GUI_Font("GUI_H2_FONT"));
    m_main_layout->addWidget(m_empty_label);

}


/************************************************/
/*          Build the Service Status            */
/************************************************/
void ServiceStatusWidget::Build_Service_Status()
{

    // Build the Connection Widget
    Build_Service_Connection_Widget();

}


/******************************************************/
/*         Build the Service Connection Widget        */
/******************************************************/
void ServiceStatusWidget::Build_Service_Connection_Widget()
{

    // Create the widget
    m_conn_widget = new QWidget(this);

    // Create the layout
    m_conn_layout = new QGridLayout();

    // Create the label
    m_conn_label = new QLabel("Connection");
    m_conn_layout->addWidget( m_conn_label, 0, 0);

    // Create the status label
    if( m_options->Get_Map_Services()[m_map_config_path]->Is_Connected() ){
        m_conn_status_label = new QLabel("Connected");
        m_conn_status_label->setStyleSheet("QLabel { background-color : green; }");
    }
    else{
        m_conn_status_label = new QLabel("Disconnected");
        m_conn_status_label->setStyleSheet("QLabel { background-color : red; }");
    }
    m_conn_layout->addWidget( m_conn_status_label, 0, 1);

    // Create the edit
    m_conn_status_edit = new QTextEdit();
    m_conn_layout->addWidget( m_conn_status_edit, 1, 0, 1, 2);

    // Set the layout
    m_conn_widget->setLayout(m_conn_layout);


    // add the widget
    m_main_layout->addWidget( m_conn_widget );

}

