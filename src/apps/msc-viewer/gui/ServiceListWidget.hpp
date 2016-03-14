/**
 * @file    ServiceListWidget.hpp
 * @author  Marvin Smith
 * @date    3/12/2016
*/
#ifndef __MSC_APPS_MSC_VIEWER_GUI_SERVICE_LIST_WIDGET_HPP__
#define __MSC_APPS_MSC_VIEWER_GUI_SERVICE_LIST_WIDGET_HPP__

// C++ Libraries
#include <map>

// Qt Libraries
#include <QtGui>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QStackedWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QWidget>


// MSC Viewer Libraries
#include "../Options.hpp"
#include "ServiceStatusWidget.hpp"


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

   
        /**
         * @brief Event Filter
         */
        virtual bool eventFilter( QObject* watched, QEvent* event );


    public slots:
        
        /**
         * @brief Update the Service Table
        */
        void Update_Service_Table();


        /**
         * @brief Detect Selected Row
         */
        void Detect_Selected_Row( const QModelIndex&, const QModelIndex& );

    private:

        /**
         * @brief Build the Title Widget
        */
        void Build_Title_Widget();


        /**
         * @brief Build the Table Widget
        */
        void Build_Table_Widget();
        


        /// Class name
        std::string m_class_name;
        
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
        QStackedWidget* m_status_widget;

        std::map<int,int> m_status_widget_map; 

}; // End of ServiceListWidget Class

#endif
