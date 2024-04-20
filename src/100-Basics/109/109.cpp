/*
    Namespace
*/

#include <iostream>

void foo() // global namespace
{
    std::cout << "global::foo" << std::endl;
}

namespace // unnamed namespace not accessible from other translation units
{
    void bar()
    {
        std::cout << "bar" << std::endl;
    }
}

namespace abc // library abc
{
    void foo()
    {
        std::cout << "library abc::foo" << std::endl;
    }
}

namespace xyz // library xyz
{
    void foo()
    {
        std::cout << "library xyz::foo" << std::endl;
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

    abc::foo();
    xyz::foo();

    my_company::my_department::my_function();
}
