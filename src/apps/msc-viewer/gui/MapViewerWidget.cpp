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
}

