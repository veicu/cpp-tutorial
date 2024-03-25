/*
    Namespace
*/

#include <iostream>

namespace // unnamed namespace not accessible from other translation units
{
    void bar()
    {
        std::cout << "bar" << std::endl;
    }
}

void foo()
{
    std::cout << "global::foo" << std::endl;
}

namespace client
{
    void foo()
    {
        std::cout << "client::foo" << std::endl;
    }
}

namespace server
{
    void foo()
    {
        std::cout << "server::foo" << std::endl;
    }
}

namespace my_company // nested namspace
{
    namespace my_department
    {
        void my_function()
        {
            std::cout << "my_company::my_department::my_function" << std::endl;
        }
    }
}


int main()
{
    bar();

    foo();
    ::foo(); // explicit global namespace

    client::foo();
    server::foo();

    my_company::my_department::my_function();
}
