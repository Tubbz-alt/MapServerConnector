/**
 * @file    ServiceCreationWidget.hpp
 * @author  Marvin Smith
 * @date    3/12/2017
*/
#pragma once

// C++ Libraries


// Qt Libraries
#include <QtGui>
#include <QVBoxLayout>
#include <QWidget>


// Project Libraries
#include "../Options.hpp"


/**
 * @class ServiceCreationWidget
*/
class ServiceCreationWidget : public QWidget
{
    public:

        /**
        * @brief  Constructor
        */
        ServiceCreationWidget( Options::ptr_t options,
                               QWidget*       parent = NULL);


    protected:

        /**
         * @brief Build Header
        */
        void Build_Title_Widget();


        /**
         * @brief
        */
        void Build_Configuration_Widget();


        /**
         * @brief Build Toolbar Widget
        */
        void Build_Toolbar_Widget();

    private:

        /// Options
        Options::ptr_t m_options;

        /// Main Layout
        QVBoxLayout* m_main_layout;

}; // End of ServiceCreationWidget Class
