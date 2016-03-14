/**
 * @file    ViewerStatusWidget.cpp
 * @author  Marvin Smith
 * @date    3/14/2016
*/
#include "ViewerStatusWidget.hpp"


/********************************/
/*          Constructor         */
/********************************/
ViewerStatusWidget::ViewerStatusWidget( Options::ptr_t   options,
                                        QWidget*         parent )
 : QWidget(parent),
   m_options(options)
{
    // Build the Main Layout
    m_main_layout = new QVBoxLayout();
    m_main_layout->setAlignment(Qt::AlignTop);
    
    // Build the Title Widget
    Build_Title_Widget();


    /// Build the Main Widget
    Build_Proj_Widget();

    // Set layout
    setLayout(m_main_layout);

}


/*******************************************/
/*          Build the Title Widget         */
/*******************************************/
void ViewerStatusWidget::Build_Title_Widget()
{
    // Create the widget
    m_title_widget = new QWidget(this);

    // Create the layout
    m_title_layout = new QHBoxLayout();
    m_title_layout->setAlignment(Qt::AlignLeft);

    // Set the layout
    m_title_widget->setLayout(m_title_layout);
    
    // Create the label
    m_title_label = new QLabel("Viewer Configuration");
    m_title_label->setFont(m_options->Get_GUI_Font("GUI_H1_FONT"));
    m_title_layout->addWidget(m_title_label);


    // Add to main widget
    m_main_layout->addWidget(m_title_widget);
}


/*************************************************/
/*          Build the Projection Widget          */
/*************************************************/
void ViewerStatusWidget::Build_Proj_Widget()
{
    // Create widget
    m_proj_widget = new QWidget(this);

    // Create layout
    m_proj_layout = new QVBoxLayout();
    m_proj_layout->setAlignment( Qt::AlignLeft | Qt::AlignTop );

    // Create Label
    m_proj_label = new QLabel("Projection Configuration");
    m_proj_label->setFont(m_options->Get_GUI_Font("GUI_H2_FONT"));
    m_proj_layout->addWidget(m_proj_label);

    // Create the Current Projection Widget
    m_proj_current_widget = new QWidget(m_proj_widget);
    
    // Add layout
    m_proj_current_layout = new QHBoxLayout();
    m_proj_current_layout->setAlignment(Qt::AlignLeft);

    m_proj_current_label = new QLabel("Current Projection");
    m_proj_current_label->setFont(m_options->Get_GUI_Font("GUI_H3_FONT"));
    m_proj_current_layout->addWidget(m_proj_current_label);

    m_proj_current_edit = new QLineEdit(m_options->Get_Current_Projection().c_str(), m_proj_current_widget);
    m_proj_current_layout->addWidget(m_proj_current_edit);

    m_proj_current_widget->setLayout(m_proj_current_layout);

    // Add to layout
    m_proj_layout->addWidget(m_proj_current_widget);


    // Create the Set Projection Widget
    m_proj_select_widget = new QWidget(m_proj_widget);

    // add layout
    m_proj_select_layout = new QHBoxLayout();
    m_proj_select_layout->setAlignment(Qt::AlignLeft);

    m_proj_select_label = new QLabel("Available Projections");
    m_proj_select_layout->addWidget(m_proj_select_label);

    m_proj_select_combo = new QComboBox(m_proj_select_widget);
    //m_proj_select_combo->addItem(
    m_proj_select_layout->addWidget(m_proj_select_combo);

    // Add button
    m_proj_select_button = new QPushButton("Update", m_proj_select_widget);
    m_proj_select_layout->addWidget(m_proj_select_button);

    m_proj_select_widget->setLayout(m_proj_select_layout);
    
    // add to layout
    m_proj_layout->addWidget(m_proj_select_widget);

    // Set layout
    m_proj_widget->setLayout(m_proj_layout);


    // Add to main widget
    m_main_layout->addWidget(m_proj_widget);

}


