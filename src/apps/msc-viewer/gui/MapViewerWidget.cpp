/**
 * @file    MapViewerWidget.cpp
 * @author  Marvin Smith
 * @date    3/12/2016
*/
#include "MapViewerWidget.hpp"


/********************************/
/*          Constructor         */
/********************************/
MapViewerWidget::MapViewerWidget( Options::ptr_t options,
                                  QWidget*       parent )
 : QWidget( parent ),
   m_options(options)
{
    // Create the Graphics Scene
    m_graphics_scene = new QGraphicsScene();

    // Create the Graphics View
    m_graphics_view = new QGraphicsView(this);
    m_graphics_view->setScene(m_graphics_scene);
    m_graphics_view->setFocusPolicy(Qt::NoFocus);
    
    // Create Layout
    m_layout = new QVBoxLayout();
    m_layout->addWidget( m_graphics_view );

    // Set the layout
    setLayout( m_layout );
    
    // Set Size Policy
    setSizePolicy( QSizePolicy::MinimumExpanding,
                   QSizePolicy::Minimum);
    
    // Setup Event Filters
    installEventFilter( m_graphics_view );
    setFocusPolicy( Qt::StrongFocus );

}


/***********************************/
/*          Event Filter           */
/***********************************/
bool MapViewerWidget::eventFilter(QObject *obj, QEvent *event)
{
    // Check for Keyboard Events
    if (event->type() == QEvent::KeyPress) 
    {
        // Cast to our keyboard event
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        keyPressEvent( keyEvent );
        qDebug("Ate key press %d", keyEvent->key());
        return true;
        
    } 
    
    // Otherwise, pass on
    else 
    {
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
}


/**************************************/
/*          Keyboard Events           */
/**************************************/
void MapViewerWidget::keyPressEvent( QKeyEvent* key_event )
{
    
    std::cout << "Detected Key: " << key_event->key() << std::endl;

}


