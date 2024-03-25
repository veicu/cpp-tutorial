/*
    Functions.
*/

#include <iostream>

void f0()
{
    std::cout << "f0()" << std::endl;
}

void f1( int a )
{
    std::cout << "f1(" << a << ")" << std::endl;
}

void f2( int a, int b )
{
    std::cout << "f2(" << a << "," << b << ")" << std::endl;
}

int f3()
{
    std::cout << "f3()" << std::endl;

    return 10;
}

int sum( int a, int b )
{
    int x = a + b;

    return x;
}

void call_by_val( int a )
{
    a = 100;
}

void call_by_ref( int& a )
{
    a = 100;
}

void call_by_ptr( int* a )
{
    *a = 100;
}

int main()
{
    f0();
    f1( 10 );
    f2( 10, 20 );

    int x = 0;
    x = f3();
    std::cout << "x: " << x << std::endl;

    x = 0;
    x = sum( 5, 3 );
    std::cout << "x: " << x << std::endl;

    x = 0;
    call_by_val( x );
    std::cout << "x: " << x << std::endl;

    x = 0;
    call_by_ref( x );
    std::cout << "x: " << x << std::endl;

    x = 0;
    call_by_ptr( &x );
    std::cout << "x: " << x << std::endl;
}
