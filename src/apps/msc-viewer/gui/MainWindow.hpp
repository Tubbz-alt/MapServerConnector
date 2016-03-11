/**
 * @file    MainWindow.hpp
 * @author  Marvin Smith
 * @date    3/11/2016
 */
#ifndef __MSC_APP_MSC_VIEWER_GUI_MAIN_WINDOW_HPP__
#define __MSC_APP_MSC_VIEWER_GUI_MAIN_WINDOW_HPP__


// Qt Libraries
#include <QDockWidget>
#include <QMainWindow>
#include <QtGui>


// Pair Matcher Libraries
#include "../Options.hpp"


/**
 * @class MainWindow
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
    public:

        /**
         * @brief Constructor
         *
         * @param[in] options Configuration information.
        */
        MainWindow( Options::ptr_t options );

    
    protected:

        /**
         * @brief KeyPress Event
        */
        void keyPressEvent( QKeyEvent* key_event );

    private:
        
        /**
         * @brief Build Dock Widgets
        */
        void Build_Dock_Windows();


        /// Class Name
        std::string m_class_name;


        /// Configuration Options
        Options::ptr_t m_options;
        

        /// Dock Widgets
        QDockWidget* m_viewer_dock;

        /// Toolbar Dock Widget
        QDockWidget* m_toolbar_dock;

}; // End of MainWindow Class




#endif
