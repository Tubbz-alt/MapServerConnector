/**
 * @file    ToolbarWidget.cpp
 * @author  Marvin Smith
 * @date    3/12/2016
*/
#include "ToolbarWidget.hpp"


/**********************************/
/*          Constructor           */
/**********************************/
ToolbarWidget::ToolbarWidget( Options::ptr_t options,
                              QWidget*       parent )
 : QWidget(parent),
   m_options(options)
{

}

