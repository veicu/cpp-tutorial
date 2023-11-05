/*
    C++11 lambda expressions
*/

#include <functional>
#include <string>
#include <vector>
#include <algorithm>

// General syntax
//
// [capture] (parameters) ->return-type {body}
//


// []        capture nothing
// [&]       capture any variable in scope by reference
// [=]       capture any variable in scopy as copy
// [=, &foo] capture any variable in scope as copy, but capture variable foo by reference
// [bar]     capture bar as copy
// [this]    capture the this pointer of the enclosing class


//
// Callback function pointer type definition
//

typedef void ( *callback )( const char* item, const char* value );
callback g_callback_handler = nullptr;


void bla( const char* item, const char* value )
{

}


using callback_function = std::function<void( const std::string& )>;

class callback_handler
{
public:
    callback_handler()
    {
    }

    void do_something( const std::string& s )
    {

    }
};

class range_checker
{
public:
    range_checker() : m_limit( 0 ) {}

    void limit( int p_limit ) { m_limit = p_limit; }

    bool check( int p_value )
    {
        if( p_value > m_limit )
        {
            return true;
        }

        return false;
    }

private:
    int m_limit;
};

int main()
{
    std::vector<int> container{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    {
        auto result = std::find_if( container.begin(), container.end(), []( int value ){ return value > 3; } );
    }

    {
        range_checker checker;
        checker.limit( 3 );

        auto result = std::find_if( container.begin(), container.end(), [&checker]( int value ){ return checker.check( value ); } );
    }

    callback_handler cbh;

    callback_function cbf = [&cbh] ( const std::string& s ) { cbh.do_something( s ); };

    cbf( "FOO" );

    g_callback_handler = &bla;
    g_callback_handler( "", "" );
}
