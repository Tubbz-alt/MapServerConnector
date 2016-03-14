/**
 * @file    ServiceListWidget.hpp
 * @author  Marvin Smith
 * @date    3/12/2016
*/
#ifndef __MSC_APPS_MSC_VIEWER_GUI_SERVICE_LIST_WIDGET_HPP__
#define __MSC_APPS_MSC_VIEWER_GUI_SERVICE_LIST_WIDGET_HPP__

// Qt Libraries
#include <QtGui>
#include <QHBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include <QVBoxLayout>
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

    
    public slots:
        
        /**
         * @brief Update the Service Table
        */
        void Update_Service_Table();

    private:

        /**
         * @brief Build the Title Widget
        */
        void Build_Title_Widget();


        /**
         * @brief Build the Table Widget
        */
        void Build_Table_Widget();
        

        /**
         * @brief Build Status Widget
        */
        void Build_Status_Widget();

        
        /// Options
        Options::ptr_t m_options;

        /// Main Layout
        QVBoxLayout* m_main_layout;

        /// Title Widget
        QWidget*     m_title_widget;
        QHBoxLayout* m_title_layout;
        QLabel*      m_title_label;

        /// List Widget
        QTableWidget* m_table_widget;


        /// Service Status Widget
        QWidget*      m_status_widget;
        QVBoxLayout*  m_status_layout;

        
}; // End of ServiceListWidget Class

#endif
