/**
 * @file    Connection_Generator_Factory.hpp
 * @author  Marvin Smith
 * @date    1/30/2016
*/
#ifndef __MSC_CONNECTION_GENERATOR_FACTORY_HPP__
#define __MSC_CONNECTION_GENERATOR_FACTORY_HPP__

// C++ Libraries
#include <map>
#include <string>


// MSC Libraries
#include "Base_Connector.hpp"
#include "Status.hpp"


namespace MSC{


/**
 * @class Connection_Generator_Factory
*/
class Connection_Generator_Factory
{
    public:

        /**
         * @brief Destructor
        */
        ~Connection_Generator_Factory();
        

        /**
         * @brief Initialize the Generator
         *
         * @return Status of the initialization
        */
        static Status Initialize();
        

        /**
         * @brief Finalize the Generator
        */
        static Status Finalize();


        /**
         * @brief Add Generator
         *
         * @param[in[ st
        */
        static Status Add_Generator( const std::string&                name,
                                     Base_Connector_Generator::ptr_t   generator );

        /**
         * @brief Create Connection Generator
        */
        static Base_Connector::ptr_t Create( const Configuration&  configuration,
                                             Status&               status );
        

        /**
         * @brief Print as Log String
        */
        static std::string To_Log_String();

    private:

        /**
         * @brief Constructor
        */
        Connection_Generator_Factory();
        
        
        /**
         * @brief Get the instance of the factory.
         * 
         * @param[out] status
         *
         * @return Instance of the Generator Factory.
        */
        static std::shared_ptr<Connection_Generator_Factory> Get_Instance( Status& status );


        /// Class Name
        std::string m_class_name;

        
        /// Map of Names to Generators
        std::map<std::string,Base_Connector_Generator::ptr_t> m_generator_map;


}; // End of Connection_Generator_Factory Class

} // End of MSC Namespace
    
#endif
