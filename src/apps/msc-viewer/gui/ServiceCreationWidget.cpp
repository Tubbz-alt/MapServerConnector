/**
 * @file    ServiceCreationWidget.cpp
 * @date    3/12/2017
 * @author  Marvin Smith
*/
#include "ServiceCreationWidget.hpp"


/********************************************************/
/*          ServiceCreationWidget Constructor           */
/********************************************************/
ServiceCreationWidget::ServiceCreationWidget( Options::ptr_t options,
                                              QWidget*       parent )
  : QWidget(parent),
    m_options(options)
{
    // Create the main Widget
    m_main_layout = new QVBoxLayout();
    m_main_layout->setAlignment(Qt::AlignTop);

    // Build the title Widget
    Build_Title_Widget();

    // Build the Configuration Widget
    Build_Configuration_Widget();

    // Build the Toolbar Widget
    Build_Toolbar_Widget();

    // Set the Layout
    setLayout(m_main_layout);

}

/****************************************/
/*        Build the Title Widget        */
/****************************************/
void ServiceCreationWidget::Build_Title_Widget()
{

}

/*************************************************/
/*         Build the Configuration Widget        */
/*************************************************/
void ServiceCreationWidget::Build_Configuration_Widget()
{


}

/*********************************************/
/*          Build the Toolbar Widget         */
/*********************************************/
void ServiceCreationWidget::Build_Toolbar_Widget()
{


}
