/**
 * @file    AddServiceWidget.cpp
 * @author  Marvin Smith
 * @date    3/16/2016
*/
#include "AddServiceWidget.hpp"


/*********************************/
/*          Constructor          */
/*********************************/
AddServiceWidget::AddServiceWidget( Options::ptr_t options,
                                    QWidget*       parent )
 : QWidget(parent),
   m_options(options)
{
    // Create the main layout
    m_main_layout = new QVBoxLayout();
    m_main_layout->setAlignment(Qt::AlignTop);

    // Create the Title Widget
    Build_Title_Widget();

    // Create the selector widget
    Build_Selector_Widget();

    // Set the Layout
    setLayout(m_main_layout);
}


/****************************************************/
/*          Change the Current Method Widget        */
/****************************************************/
void AddServiceWidget::Change_Current_Method_Widget( const int& method_id )
{
    // Set the Selector
    m_stack_widget->setCurrentIndex(method_id);
}

/****************************************/
/*        Build the Title Widget        */
/****************************************/
void AddServiceWidget::Build_Title_Widget()
{
    // Create title widget
    m_title_widget = new QWidget(this);

    // Create title widget layout
    m_title_layout = new QHBoxLayout();
    m_title_layout->setAlignment( Qt::AlignLeft );

    // Create the label
    m_title_label = new QLabel("Add Map Service", m_title_widget );
    m_title_layout->addWidget(m_title_label);

    // Add to title widget
    m_title_widget->setLayout(m_title_layout);

    // Add to main layout
    m_main_layout->addWidget(m_title_widget);

}


/**********************************************/
/*          Build the Selector Widget         */
/**********************************************/
void AddServiceWidget::Build_Selector_Widget()
{
    // Create the Main Widget
    m_selector_widget = new QWidget(this);

    // Create the layout
    m_selector_layout = new QHBoxLayout();
    m_selector_layout->setAlignment(Qt::AlignLeft);
    
    
    // Set the label
    m_selector_label = new QLabel("Method", m_selector_widget );
    m_selector_layout->addWidget(m_selector_label);

    // Set the Combo
    m_selector_combo = new QComboBox( m_selector_widget );
    m_selector_combo->addItem("Import Service File");
    m_selector_combo->addItem("Define Service Parameters");
    m_selector_layout->addWidget(m_selector_combo);
    connect( m_selector_combo, SIGNAL(currentIndexChanged(int)),
             this, SLOT(Change_Current_Method_Widget(const int&)));

    // Set the layout
    m_selector_widget->setLayout(m_selector_layout);

    // Add to main widget
    m_main_layout->addWidget(m_selector_widget);


    // Create the Stack Widget
    m_stack_widget = new QStackedWidget();
    
    
    // Build the Import Widget
    Build_Import_Widget();
    
    // Add the Define Widget
    m_define_widget = new QWidget();
    m_define_layout = new QVBoxLayout();
    m_define_title_widget = new QWidget(m_define_widget);
    m_define_title_layout = new QHBoxLayout();
    m_define_title_widget->setLayout(m_define_title_layout);

    m_define_title_label = new QLabel("Define Map Service Parameters");
    m_define_title_layout->addWidget(m_define_title_label);
    m_define_layout->addWidget(m_define_title_widget);

    m_define_widget->setLayout(m_define_layout);
    m_stack_widget->addWidget(m_define_widget);

    // add to main layout
    m_main_layout->addWidget( m_stack_widget );
}


/*********************************************/
/*          Build the Import Widget          */
/*********************************************/
void AddServiceWidget::Build_Import_Widget()
{
    // Add the Import Widget
    m_import_widget = new QWidget();
    
    // Add the Import Layout 
    m_import_layout = new QVBoxLayout();
    m_import_layout->setAlignment( Qt::AlignTop );

    // Create the title widget
    m_import_title_widget = new QWidget(m_import_widget);
    m_import_title_layout = new QHBoxLayout();
    m_import_title_layout->setAlignment(Qt::AlignLeft);
    m_import_title_widget->setLayout(m_import_title_layout);
    m_import_layout->addWidget(m_import_title_widget);

    m_import_title_label = new QLabel("Import Map Service File.");
    m_import_title_layout->addWidget(m_import_title_label);
    
    // Create the Path Widget
    QWidget*      import_path_widget = new QWidget(m_import_widget);
    QHBoxLayout*  import_path_layout = new QHBoxLayout();
    import_path_layout->setAlignment(Qt::AlignLeft);

    QLabel* import_path_label = new QLabel("Path", import_path_widget);
    import_path_layout->addWidget(import_path_label);
    
    QLineEdit* import_path_edit = new QLineEdit(import_path_widget);
    import_path_layout->addWidget(import_path_edit);

    QPushButton* import_path_button = new QPushButton("Select", import_path_widget);
    import_path_layout->addWidget(import_path_button);
    import_path_widget->setLayout(import_path_layout);

    m_import_layout->addWidget(import_path_widget);

    // Set the Main Layout
    m_import_widget->setLayout(m_import_layout);

    // Add to the Stack Widget
    m_stack_widget->addWidget(m_import_widget);
}

