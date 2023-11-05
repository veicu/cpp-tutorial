/*
    Classes - Part II
*/

#include <iostream>

class data
{
public:
    data() : m_id( 0 )
    {
        std::cout << "[" << id() << "]" << "ctor" << std::endl;
    }

    data( int p_id ) : m_id( p_id )
    {
        std::cout << "[" << id() << "]" << "ctor" << std::endl;
    }

    data( const data& other )
    {
        m_id = other.m_id;

        std::cout << "[" << id() << "]" << "copy ctor" << std::endl;
    }

    data( data&& other )
    {
        m_id = other.m_id;
        other.m_id = 0;

        std::cout << "[" << id ()<< "]" << "move ctor" << std::endl;
    }

    ~data()
    {
        std::cout << "[" << id() << "]" << "dtor" << std::endl;
    }

    data& operator=( const data& other )
    {
        m_id = other.m_id;

        std::cout << "[" << id() << "]" << "copy asign" << std::endl;

        return *this;
    }

    data& operator=( data&& other )
    {
        m_id = other.m_id;
        other.m_id = 0;

        std::cout << "[" << id() << "]" << "move asign" << std::endl;

        return *this;
    }

    int id()
    {
        return m_id;
    }

private:
    int m_id;
};


int main()
{
    {
        data d;
        std::cout << "DATA: " <<d.id() << std::endl;
    }

    {
        data d( 4711 );
        std::cout << "DATA: " <<d.id() << std::endl;
    }

    {
        data d1( 4711 );
        data d2( d1 );
    }

    {
        data d1( 4711 );
        data d2( std::move( d1 ) );
    }

    {
        data d1( 4711 );
        data d2 = d1;
    }

    {
        data d1( 4711 );
        data d2 = std::move( d1 );
    }

    {
        data d1( 4711 );
        data d2;

        d2 = d1;
    }

    {
        data d1( 4711 );
        data d2;

        d2 = std::move( d1 );
    }

}
