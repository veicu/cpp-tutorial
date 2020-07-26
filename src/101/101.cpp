/*
    std::string
*/

#include <string>
#include <iostream>

int main()
{
    std::string s = "Hello";

    s += " ";

    s.append( "World" );

    std::cout << s << std::endl;
}
