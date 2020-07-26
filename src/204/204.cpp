/*
    C++11 Delegating Constructors
*/

#include <iostream>

class point
{
public:
    point() : point( 0, 0 ) // delegating ctor
    {
        std::cout << "CTOR-1" << std::endl;
    }

    point( int x, int y ) : m_x( x ), m_y( y )
    {
        std::cout << "CTOR-2" << std::endl;
    }

    ~point() = default;

    point( point&& )                 = delete;
    point( const point& )            = delete;
    point& operator=( point&& )      = delete;
    point& operator=( const point& ) = delete;

    int x() { return m_x; }
    int y() { return m_y; }

    void x( int p_x ) { m_x = p_x; }
    void y( int p_y ) { m_y = p_y; }

private:
    int m_x;
    int m_y;
};


int main()
{
    point p1;
    point p2( 10, 20 );
}
