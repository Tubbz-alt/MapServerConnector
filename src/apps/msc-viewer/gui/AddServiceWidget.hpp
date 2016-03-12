/**
 * @file    AddServiceWidget.hpp
 * @author  Marvin Smith
 * @date    3/16/2016
*/
#ifndef __MSC_APPS_MSC_VIEWER_GUI_ADD_SERVICE_WIDGET_HPP__
#define __MSC_APPS_MSC_VIEWER_GUI_ADD_SERVICE_WIDGET_HPP__

// Qt Libraries
#include <QtGui>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QWidget>

// MSC-Viewer Libraries
#include "../Options.hpp"

/**
 * @class AddServiceWidget
*/
class AddServiceWidget : public QWidget
{
    Q_OBJECT

    public:
        
        /**
         * @brief Constructor
        */
        AddServiceWidget( Options::ptr_t options,
                          QWidget*       parent = NULL );
    
    public slots:
       
       /**
        * @brief Change the Current Selector Widget
       */
       void Change_Current_Method_Widget( const int& method_id );

    private:

        /**
         * @brief Build the Title Widget
        */
        void Build_Title_Widget();
        

        /**
         * @brief Build Selector Widget
        */
        void Build_Selector_Widget();


        /**
         * @brief Build Import Widget
        */
        void Build_Import_Widget();
        

        /// Options
        Options::ptr_t m_options;

        /// Main Layout
        QVBoxLayout* m_main_layout;

        /// Main Label Widgets
        QWidget*     m_title_widget;
        QHBoxLayout* m_title_layout;
        QLabel*      m_title_label;
    
        /// Selector Widget
        QWidget*     m_selector_widget;
        QHBoxLayout* m_selector_layout;
        QLabel*      m_selector_label;
        QComboBox*   m_selector_combo;

        /// Method Stacked Widget
        QStackedWidget* m_stack_widget;

        /// Import Widget
        QWidget*     m_import_widget;
        QVBoxLayout* m_import_layout;
        QWidget*     m_import_title_widget;
        QHBoxLayout* m_import_title_layout;
        QLabel*      m_import_title_label;

        /// Define Widget
        QWidget*     m_define_widget;
        QVBoxLayout* m_define_layout;
        QWidget*     m_define_title_widget;
        QHBoxLayout* m_define_title_layout;
        QLabel*      m_define_title_label;

}; // End of AddServiceWidget Class


#endif
