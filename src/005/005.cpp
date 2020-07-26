/*
    Classes
*/

class point
{
public:

    point()
    {

    }

    point( int x, int y ) : m_x( x ), m_y( y )
    {

    }

    ~point() = default;

    point( point&& )                 = delete;
    point( const point& )            = delete;
    point& operator=( point&& )      = delete;
    point& operator=( const point& ) = delete;

    int x()
    {
        return m_x;
    }

    int y()
    {
        return m_y;
    }

    void x( int x )
    {
        m_x = x;
    }

    int y( int y )
    {
        m_y = y;
    }

private:
    int m_x;
    int m_y;
};


int main()
{
    point p1;
    point p2( 5, 3 );

    p1.x( 10 );
    p1.y( 20 );

}
