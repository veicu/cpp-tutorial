/*
    Classes - Part II (Constructor, Destructor, Assignment)
*/

#include <iostream>

class data
{
public:
    data();
    data( int p_id );

    ~data();

    data( data&& other );
    data( const data& other );
    data& operator=( data&& other );
    data& operator=( const data& other );

    int id();

private:
    int m_id;
};


data::data() : m_id( 0 )
{
    std::cout << "[" << id() << "]" << "ctor" << std::endl;
}

data::data( int p_id ) : m_id( p_id )
{
    std::cout << "[" << id() << "]" << "ctor" << std::endl;
}

data::data( const data& other )
{
    m_id = other.m_id;

    std::cout << "[" << id() << "]" << "copy ctor" << std::endl;
}

data::data( data&& other )
{
    m_id = other.m_id;
    other.m_id = 0;

    std::cout << "[" << id ()<< "]" << "move ctor" << std::endl;
}

data::~data()
{
    std::cout << "[" << id() << "]" << "dtor" << std::endl;
}

data& data::operator=( data&& other )
{
    m_id = other.m_id;
    other.m_id = 0;

    std::cout << "[" << id() << "]" << "move asign" << std::endl;

    return *this;
}

data& data::operator=( const data& other )
{
    m_id = other.m_id;

    std::cout << "[" << id() << "]" << "copy asign" << std::endl;

    return *this;
}

int data::id()
{
    return m_id;
}



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
        data d2( (data&&)d1 );
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
        data d2 = (data&&)d1;
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
