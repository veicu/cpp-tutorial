/*
    Classes - Part III
*/

class shape
{
public:
    shape() : m_x( 0 ), m_y( 0 ) {}

    int x()
    {
        return m_x;
    }

    int y()
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

class rect : public shape
{
public:
    rect() : shape(), m_width( 0 ), m_height( 0 ) {}

    int width()
    {
        return m_width;
    }

    int height()
    {
        return m_height;
    }

    void width( int p_width )
    {
        m_width = p_width;
    }

    void height( int p_height )
    {
        m_height = p_height;
    }

private:
    int m_width;
    int m_height;
};

class circle : public shape
{
public:
    circle() : shape(), m_radius( 0 ) {}

    int radius()
    {
        return m_radius;
    }

    void radius( int p_radius )
    {
        m_radius = p_radius;
    }

private:
    int m_radius;
};

int main()
{
    rect r1;

    r1.x( 10 );
    r1.y( 10 );
    r1.width( 100 );
    r1.height( 50 );

    circle c1;

    c1.x( 200 );
    c1.y( 250 );
    c1.radius( 25 );
}
