/**
 * @file    msc-viewer.cpp
 * @author  Marvin Smith
 * @date    3/11/2016
 */

// Qt Libraries
#include <QApplication>


// MSC Viewer Libraries
#include "Options.hpp"
#include "gui/MainWindow.hpp"

/**
 * @brief Main Function
 */
int main( int argc, char* argv[] )
{

    // Create Qt Application
    QApplication app(argc, argv);

    // Parse Command-Line Options and Config Files
    Options::ptr_t options = std::make_shared<Options>(argc, argv);

    // Build User Interface
    MainWindow main_window( options );

    // Show and run app
    main_window.show();
    return app.exec();
}


