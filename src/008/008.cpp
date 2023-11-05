/*
    Classes - Part IV
*/

#include <iostream>

class point
{
public:

    point() : m_x( 0 ), m_y( 0 )
    {

    }

    point( int x, int y ) : m_x( x ), m_y( y )
    {

    }

    ~point() = default;

    point( point&& other ) : m_x( 0 ), m_y( 0 )
    {
        m_x = other.m_x;
        m_y = other.m_y;

        other.m_x = 0;
        other.m_y = 0;
    }

    point( const point& other ) : m_x( 0 ), m_y( 0 )
    {
        m_x = other.m_x;
        m_y = other.m_y;
    }

    point& operator=( point&& other )
    {
        if( this != &other )
        {
            m_x = other.m_x;
            m_y = other.m_y;

            other.m_x = 0;
            other.m_y = 0;
        }

        return *this;
    }

    point& operator=( const point& other )
    {
        if( this != &other )
        {
            m_x = other.m_x;
            m_y = other.m_y;
        }

        return *this;
    }

    point& operator+=( const point& other ) // must be a member function since the object gets modified
    {
        m_x +=  other.m_x;
        m_y +=  other.m_y;

        return *this;
    }

    bool operator()() const // functor
    {
        if( m_x != 0 && m_y != 0 )
        {
            return true;
        }

        return false;
    }

    operator bool() const // conversion operator
    {
        if( m_x != 0 && m_y != 0 )
        {
            return true;
        }

        return false;
    }

    friend point operator-( const point& p1, const point& p2 ); // declare operator- as friend function

    int x() const
    {
        return m_x;
    }

    int y() const
    {
        return m_y;
    }

    void x( int p_x )
    {
        m_x = p_x;
    }

    void y( int p_y )
    {
        m_y = p_y;
    }

private:
    int m_x;
    int m_y;
};

point operator+( const point& p1, const point& p2 ) // operator+ as normal function
{
    return point( p1.x() + p2.x(), p1.y() + p2.y() );
}

point operator-( const point& p1, const point& p2 ) // operator- as friend function with access to members
{
    return point( p1.m_x - p2.m_x, p1.m_y - p2.m_y );
}

std::ostream& operator<< ( std::ostream& os, const point& p )
{
    os << "[" << p.x() << "," << p.y() << "]";
 
    return os; // return std::ostream to chain calls to operator<<
}

int main()
{
    point p1( 1, 2 );
    point p2( 3, 4 );
    point p3 = p1 + p2;

    std::cout << p3 << std::endl;

    p3 += p1;

    std::cout << p3 << std::endl;

    if( p3 )
    {
        std::cout << "P3 is valid" << std::endl;
    }
    else
    {
        std::cout << "P3 in origin" << std::endl;
    }
}
