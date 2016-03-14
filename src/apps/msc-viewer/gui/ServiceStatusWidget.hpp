/**
 * @file    ServiceStatusWidget.hpp
 * @author  Marvin Smith
 * @date    3/14/2016
 */
#ifndef __MSC_APPS_MSC_VIEWER_GUI_SERVICE_STATUS_WIDGET_HPP__
#define __MSC_APPS_MSC_VIEWER_GUI_SERVICE_STATUS_WIDGET_HPP__

// MSC-Viewer Libraries
#include "../Options.hpp"


// Qt Libraries
#include <QtGui>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>


/**
 * @class ServiceStatusWidget
 */
class ServiceStatusWidget : public QWidget
{
    Q_OBJECT

    public:
        
        /**
         * @brief Constructor
         */
        ServiceStatusWidget( FilePath const&  map_service_config,
                             Options::ptr_t   options,
                             QWidget*         parent = NULL );

        

    private:

        /**
         * @brief Build the Default Widget
         */
        void Build_Empty_Status();


        /**
         * @brief Build the Normal Status
         */
        void Build_Service_Status();

        
        /**
         * @brief Build the Status Widget
         */
        void Build_Service_Connection_Widget();


        
        /// Map Service Configuration File
        FilePath m_map_config_path;

        /// Options
        Options::ptr_t m_options;

        /// Main Layout
        QVBoxLayout* m_main_layout;


        /// Empty Status Widget
        QLabel*       m_empty_label;

        
        /// Connection Widget
        QWidget*     m_conn_widget;
        QGridLayout* m_conn_layout;
        QLabel*      m_conn_label;
        QLabel*      m_conn_status_label;
        QTextEdit*   m_conn_status_edit;

        /// Capabilities Widget


}; // End of ServiceStatusWidget Class


#endif
