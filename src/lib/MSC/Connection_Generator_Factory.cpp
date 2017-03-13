/**
 * @file    Connection_Generator_Factory.cpp
 * @author  Marvin Smith
 * @date    1/30/2016
*/
#include "Connection_Generator_Factory.hpp"

// C++ Libraries
#include <memory>
#include <iostream>
#include <sstream>

// MSC Libraries
#include "utilities/Log_Utilities.hpp"


namespace MSC{

// Create Pointer
typedef std::shared_ptr<Connection_Generator_Factory> gen_ptr;

gen_ptr generator;

/********************************/
/*          Constructor         */
/********************************/
Connection_Generator_Factory::Connection_Generator_Factory()
 : m_class_name("Connection_Generator_Factory")
{
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", Running Constructor.";
}


/********************************/
/*          Destructor          */
/********************************/
Connection_Generator_Factory::~Connection_Generator_Factory()
{
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", Running Destructor.";
}

/*********************************************/
/*          Initialize the Generator         */
/*********************************************/
Status Connection_Generator_Factory::Initialize()
{
    // Log Entry
    std::string m_class_name = "Connection_Generator_Factory";
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", Running Initialize.";

    if( generator == nullptr )
    {
        generator = gen_ptr(new Connection_Generator_Factory());
    }
    return Status(StatusCode::SUCCESS);
}


/******************************/
/*          Finalize          */
/******************************/
Status Connection_Generator_Factory::Finalize()
{
    // Log Entry
    std::string m_class_name = "Connection_Generator_Factory";
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", Finalizing";

    // Reset the generator
    Status status;
    if( generator != nullptr ){
        generator = nullptr;
    }
    
    status = Status(StatusCode::SUCCESS);

    return status;
}

/********************************************/
/*         Add Connection Generator         */
/********************************************/
Status Connection_Generator_Factory::Add_Generator( const std::string&               name,
                                                    Base_Connector_Generator::ptr_t  generator )
{
    // Log Entry
    std::string m_class_name = "Connection_Generator_Factory";
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", Start of Method.";
    
    // Get Instance
    Status status;
    gen_ptr instance = Get_Instance(status);

    
    // Check if Generator Already Exists
    if( instance->m_generator_map.find(name) != instance->m_generator_map.end() )
    {
        return Status(StatusCode::DUPLICATE_GENERATOR,
                      "Generator already found.");
    }
    instance->m_generator_map[name] = generator;
    return Status(StatusCode::SUCCESS);
}


/**************************************************/
/*         Create Connection Generator            */
/**************************************************/
Base_Connector::ptr_t Connection_Generator_Factory::Create( const Configuration&  configuration,
                                                            Status&               status )
{
    // Log Entry
    std::string m_class_name = "Connection_Generator_Factory";
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", Start of Method.";
    
    // Get the name
    std::string name = configuration.Get_Value("connector","",status );

    // Get instance
    gen_ptr instance = Get_Instance(status);
    if( status.Get_Code() != StatusCode::SUCCESS ){
        return nullptr;
    }
    
    // Log
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", Connector Found: " << name;

    // Check if name exists
    if( instance->m_generator_map.find(name) == 
        instance->m_generator_map.end() )
    {
        status = Status( StatusCode::NO_CONNECTOR_FOUND,
                         "No Connection Generator Found.");
        return nullptr;
    }

    // Return the result
    return instance->m_generator_map.find(name)->second->Create( configuration, status );

}


/**************************************************/
/*          Get Instance of the Generator         */
/**************************************************/
gen_ptr Connection_Generator_Factory::Get_Instance( Status& status )
{
    // Log Entry
    std::string m_class_name = "Connection_Generator_Factory";
    BOOST_LOG_TRIVIAL(trace) << CLASS_LOG << ", Start of Method.";

    status = Status(StatusCode::SUCCESS);
    if( generator == nullptr )
    {
        status = Initialize();
    }
    return generator;
}


/****************************************/
/*          Print as Log String         */
/****************************************/
std::string Connection_Generator_Factory::To_Log_String()
{
    // Get instance
    Status status;
    auto instance = Get_Instance(status);

    // Create output stream
    std::stringstream sin;

    auto it = instance->m_generator_map.begin();
    auto eit = instance->m_generator_map.end();
    
    sin << "Connection Generator Factory:" << std::endl;
    for(; it != eit; it++){
        sin << " - " << it->first << " = " << it->second->Get_Class_Name() << std::endl;
    }
    return sin.str();
}

} // End of MSC Namespace

