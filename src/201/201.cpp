/*
    C++ 11 auto
*/

#include <vector>
#include <iostream>

int answer()
{
    return 42;
}

int main()
{
    auto c = 'a';      // char
    auto d = 3.14;     // double
    auto i = answer(); // int

    std::cout << c << std::endl;
    std::cout << d << std::endl;
    std::cout << i << std::endl;


    std::vector<int> integers{ 1, 2, 3 };

    for( auto it = integers.begin(); it != integers.end(); ++it )
    {
        std::cout << *it << std::endl;
    }
}
