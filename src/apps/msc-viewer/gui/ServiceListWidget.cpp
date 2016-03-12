/**
 * @file    ServiceListWidget.cpp
 * @author  Marvin Smith
 * @date    3/12/2016
*/
#include "ServiceListWidget.hpp"


/*********************************/
/*          Constructor          */
/*********************************/
ServiceListWidget::ServiceListWidget( Options::ptr_t  options,
                                      QWidget*        parent )
 : QWidget(parent),
   m_options(options)
{

}


