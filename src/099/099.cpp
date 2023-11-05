/*
    Function pointers
*/

#include <string>
#include <iostream>
#include <functional>


void log_to_console( const std::string& msg )
{
    std::cout << "[C] " << msg << std::endl;
}

void log_to_file( const std::string& msg )
{
    std::cout << "[F] " << msg << std::endl;
}


typedef void ( *t_log_fn )( const std::string& ); // function pointer type definition

void do_something_x( t_log_fn log_fn ) // function pointer as parameter
{
    log_fn( "SYSTEM: did something x" );
}


using log_function_type = void (*)( const std::string& ); // function pointers type aliases since C++11

void do_something_y( log_function_type log_fn ) // function pointer as parameter
{
    log_fn( "SYSTEM: did something y" );
}


int main()
{
    {
        void ( *log_fn )( const std::string& )( log_to_console ); // initialize function pointer "log_fn" with function "log_to_console"
        (*log_fn)( "SYSTEM: startup" );                           // call function through function pointer via explicit dereference
        log_fn( "SYSTEM: startup" );                              // call function through function pointer via implicit dereference
    }

    {
        t_log_fn log_fn = nullptr;

        log_fn = log_to_console;
        log_fn( "SYSTEM: startup" );

        do_something_x( log_fn );

        log_fn = log_to_file;
        log_fn( "SYSTEM: shutdown");
    }

    {
        log_function_type log_fn = nullptr;
        log_fn = log_to_console;
        log_fn( "SYSTEM: startup" );

        do_something_y( log_fn );

        log_fn = log_to_file;
        log_fn( "SYSTEM: shutdown");
    }

    {
        std::function<void(const std::string&)> log_fn = nullptr; // store function pointer in a C++11 std::function object
        log_fn = log_to_console;
        log_fn( "SYSTEM: startup" );
    }
}
