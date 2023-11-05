/*
    C++11 nullptr keyword
*/

class point
{
public:
    point() : m_x( 0 ), m_y( 0 ) {}

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

void foo( int i )
{

}

void foo( point* p )
{
    if( p != nullptr )
    {

    }
}

int main()
{
    foo( 0 );
    foo( nullptr );
}
