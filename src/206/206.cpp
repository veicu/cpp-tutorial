/*
    C++11 shared_ptr / unique_ptr
*/

#include <iostream>
#include <memory>

class raw_data
{
public:
    raw_data()
    {
        std::cout << "raw_data CTOR" << std::endl;
    }

    ~raw_data()
    {
        std::cout << "raw_data DTOR" << std::endl;
    }
};

class data
{
public:
    using ptr = std::shared_ptr<data>;

    data() : m_raw_data( nullptr )
    {
        std::cout << "data CTOR" << std::endl;

        m_raw_data = std::make_unique<raw_data>();
    }

    ~data()
    {
        std::cout << "data CTOR" << std::endl;
    }

private:
    std::unique_ptr<raw_data> m_raw_data;
};


void do_something( data::ptr p_data )
{

}

int main()
{
    data::ptr the_data = std::make_shared<data>();
    do_something( the_data );
}
