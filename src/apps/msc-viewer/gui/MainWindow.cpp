/**
 * @file    MainWindow.cpp
 * @author  Marvin Smith
 * @date    3/11/2016
 */
#include "MainWindow.hpp"


// C++ Libraries
#include <iostream>


/**************************************/
/*            Constructor             */
/**************************************/
MainWindow::MainWindow( Options::ptr_t  options )
 : QMainWindow(),
   m_class_name("MainWindow"),
   m_options(options)
{

    // Set Window Title
    setWindowTitle(options->Get_GUI_Config_Parameter("GUI_TITLE", "MSC-Viewer").c_str());

    // Set the Window Size
    resize(1000,500);
    
    // Build Docket Windows
    Build_Dock_Windows();
    
    // Define a strong focus 
    setFocusPolicy ( Qt::StrongFocus );
}

/************************************/
/*          Keyboard Event          */
/************************************/
void MainWindow::keyPressEvent( QKeyEvent* event )
{
    std::cout << m_class_name << "::keyPressEvent, Keyboard detected: " << event->key() << std::endl;
}


/**********************************************/
/*          Build all Dock Windows            */
/**********************************************/
void MainWindow::Build_Dock_Windows()
{



}

