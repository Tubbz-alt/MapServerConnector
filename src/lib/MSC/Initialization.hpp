/**
 * @file    Initialization.hpp
 * @author  Marvin Smith
 * @date    1/30/2016
*/
#ifndef __MSC_INITIALIZATION_HPP__
#define __MSC_INITIALIZATION_HPP__

// MSC Libraries
#include "Configuration.hpp"
#include "Status.hpp"


namespace MSC{

/**
 * @brief Initialize the Map Connection Service
 *
 * @param[in] configuration
 *
 * @return Status of the operation.
*/
Status Initialize( Configuration const& configuration );


/**
 * @brief Finalize the Service
*/
Status Finalize();


/**
 * @brief Check if Initialized.
*/
bool Is_Initialized();


/**
 * @brief Initialize Connector Generator Factory
 * @note  This is called by Initialize.  
*/
Status Initialize_Connection_Generator_Factory();



} // End of MSC Namespace

#endif
