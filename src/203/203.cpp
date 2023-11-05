/*
    C++11 Deleted and Defaulted Functions
*/


class point
{
public:
    point() : m_x( 0 ), m_y( 0 ) {}

    point( int x, int y ) : m_x( x ), m_y( y ) {}

    ~point() = default;

    point( point&& )                 = delete;
    point( const point& )            = delete;
    point& operator=( point&& )      = delete;
    point& operator=( const point& ) = delete;

    int x() const { return m_x; }
    int y() const { return m_y; }

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

    //
    // Not possible - Copy constructor explicitly deleted
    //

    //point p3( p1 );


    //
    // Not possible - Copy assignment operator explicitly deleted
    //

    //p1 = p2;
}
