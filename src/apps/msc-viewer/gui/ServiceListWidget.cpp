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
   m_class_name("ServiceListWidget"),
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
    m_title_label = new QLabel("Available Map Services", m_title_widget);
    m_title_label->setFont(m_options->Get_GUI_Font("GUI_H1_FONT"));

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
    // Get option items
    int column_0_width = m_options->Get_GUI_Config_Parameter_Int32("SERVICE_LIST_COLUMN_0_WIDTH", 25 );

    // Build the Header Items
    QStringList label_list;
    label_list.push_back("Display");
    label_list.push_back("File Path");
    label_list.push_back("Driver");
    label_list.push_back("Connection State");
    label_list.push_back("Protocol");

    // Build the Table Widget
    m_table_widget = new QTableWidget(0, label_list.size(), this);
    m_table_widget->setHorizontalHeaderLabels( label_list );
    m_table_widget->setColumnWidth(0, column_0_width );
    m_table_widget->horizontalHeader()->setStretchLastSection(true);


    //  Create the Status Widget
    m_status_widget = new QStackedWidget(this);

    
    // Update the table
    Update_Service_Table();

    

    // Connect Signals
    connect( m_table_widget->selectionModel(), SIGNAL(currentRowChanged( const QModelIndex&, const QModelIndex&)),
             this, SLOT(Detect_Selected_Row( const QModelIndex&, const QModelIndex& ))); 


                                                           
    // Add to main widget
    m_main_layout->addWidget( m_table_widget );
    m_main_layout->addWidget(m_status_widget);

}



/*********************************************/
/*          Update the Service Table         */
/*********************************************/
void ServiceListWidget::Update_Service_Table()
{
    // Get a list of all services
    std::map<FilePath,MSC::MapServiceConnector::ptr_t> service_list = m_options->Get_Map_Services();

    // Resize the table
    m_table_widget->setRowCount( service_list.size() );
    m_status_widget_map.clear();
    while( m_status_widget->count() > 0 ){
        m_status_widget->removeWidget(0);
    }

    // Add the default widget
    m_status_widget->addWidget(new ServiceStatusWidget(FilePath(),
                                                       m_options ));


    // Add each column
    int row = 0;
    int srow = 1;
    for( auto it=service_list.begin(); it != service_list.end(); it++, row++, srow++ )
    {
        // Set the Checkbox Field
        QTableWidgetItem* checkItem = new QTableWidgetItem();
        checkItem->setCheckState( Qt::Unchecked );
        m_table_widget->setItem( row, 0, checkItem );


        // Set the Path
        m_table_widget->setItem(row, 1, new QTableWidgetItem( it->first.ToString().c_str())); 
        
        // Set the Driver
        m_table_widget->setItem(row, 2, new QTableWidgetItem( it->second->Get_Connector_Impl()->Get_Driver_Name().c_str() ));
        

        // Set the Connection State
        QTableWidgetItem*  conn_state = new QTableWidgetItem();
        QTableWidgetItem*  proto_item = new QTableWidgetItem("Unknown");
        if( it->second->Is_Connected() ){
            conn_state->setText("Connected");
            conn_state->setBackground(QBrush(QColor(100,255,100)));
        }
        else{
            conn_state->setText("Disconnected");
            conn_state->setBackground(QBrush(QColor(255,100,100)));
        }
        m_table_widget->setItem( row, 3, conn_state );
        m_table_widget->setItem( row, 4, proto_item );

        
        // Build the status widget
        m_status_widget->addWidget( new ServiceStatusWidget(it->first,
                                                            m_options));
        
        m_status_widget_map[row] = srow;
    }

    for( int c=1; c<4; c++ ){
        m_table_widget->resizeColumnToContents(c);
    }
}


/***************************************/
/*          Detect Selected Row        */
/***************************************/
void ServiceListWidget::Detect_Selected_Row( const QModelIndex& current ,
                                             const QModelIndex& previous)
{

    LOG_MSG(LogLevel::TRACE) << "Detected New Row Selection: " << m_class_name << "::" << __func__;
    
    // Get the Row
    int row = current.row();

    m_status_widget->setCurrentIndex(m_status_widget_map[row]);
}


/*************************************/
/*           Event Filter            */
/*************************************/
bool ServiceListWidget::eventFilter( QObject* watched, QEvent* event )
{
    LOG_MSG(LogLevel::TRACE) << "Detected Event: " << m_class_name << "::" << __func__;

    return false;
}


