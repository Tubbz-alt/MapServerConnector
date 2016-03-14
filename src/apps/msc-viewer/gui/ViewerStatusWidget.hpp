/**
 * @file    ViewerStatusWidget.hpp
 * @author  Marvin Smith
 * @date    3/14/2016
*/
#ifndef __MSC_APPS_MSC_VIEWER_GUI_VIEWERSTATUS_WIDGET_HPP__
#define __MSC_APPS_MSC_VIEWER_GUI_VIEWERSTATUS_WIDGET_HPP__

// MSC-Viewer Libraries
#include "../Options.hpp"

// Qt Libraries
#include <QtGui>
#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>


/**
 * @class ViewerStatusWidget
*/
class ViewerStatusWidget : public QWidget
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
        */
        ViewerStatusWidget( Options::ptr_t  options,
                            QWidget*        parent = NULL);


    private:
        
        /**
         * @brief Build the Title Widget
        */
        void Build_Title_Widget();


        /**
         * @brief Build the Projection Widget
        */
        void Build_Proj_Widget();

        /// Options
        Options::ptr_t m_options;
        
        // Main Layout
        QVBoxLayout* m_main_layout;

        /// Title Widget
        QWidget*      m_title_widget;
        QHBoxLayout*  m_title_layout;
        QLabel*       m_title_label;


        /// Main Widget
        QWidget*      m_proj_widget;
        QVBoxLayout*  m_proj_layout;
        QLabel*       m_proj_label;

        QWidget*      m_proj_current_widget;
        QHBoxLayout*  m_proj_current_layout;
        QLabel*       m_proj_current_label;
        QLineEdit*    m_proj_current_edit;

        QWidget*      m_proj_select_widget;
        QHBoxLayout*  m_proj_select_layout;
        QLabel*       m_proj_select_label;
        QComboBox*    m_proj_select_combo;
        QPushButton*  m_proj_select_button;

}; // End of ViewerStatusWidget Class

#endif
