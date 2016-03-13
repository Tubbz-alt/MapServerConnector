/**
 * @file    ServiceListWidget.cpp
 * @author  Marvin Smith
 * @date    3/12/2016
*/
#include "ServiceListWidget.hpp"


/*********************************/
/*          Constructor          */
/*********************************/
ServiceListWidget::ServiceListWidget( Options::ptr_t  options,
                                      QWidget*        parent )
 : QWidget(parent),
   m_options(options)
{
    // Create the main layout
    m_main_layout = new QVBoxLayout();
    m_main_layout->setAlignment( Qt::AlignTop );

    
    // Create the Title Widget
    Build_Title_Widget();


    // Create the Table View
    Build_Table_Widget();
    

    // Set the main layout
    setLayout( m_main_layout );
}


/********************************************/
/*          Build the Title Widget          */
/********************************************/
void ServiceListWidget::Build_Title_Widget()
{
    // Create the Title Widget
    m_title_widget = new QWidget(this);

    // Create the Title Layout
    m_title_layout = new QHBoxLayout();
    m_title_layout->setAlignment(Qt::AlignLeft);
    
    // Create the Label
    m_title_label = new QLabel("Available Map Services");
    m_title_layout->addWidget(m_title_label);
    
    // Set the layout
    m_title_widget->setLayout(m_title_layout);

    // add to main widget
    m_main_layout->addWidget( m_title_widget );
}


/*******************************************/
/*          Build the Table Widget         */
/*******************************************/
void ServiceListWidget::Build_Table_Widget()
{
    // Build the Table Widget
    m_table_widget = new QTableView(this);
    
    // Update the table
    Update_Service_Table();

    // Add to main widget
    m_main_layout->addWidget( m_table_widget );
}

/*********************************************/
/*          Update the Service Table         */
/*********************************************/
void ServiceListWidget::Update_Service_Table()
{
    // Get a list of all services
    std::map<FilePath,MSC::MapServiceConnector::ptr_t> service_list = m_options->Get_Map_Services();

    // Check against current list

}

