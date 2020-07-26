/*
    Control.
*/

#include <iostream>

int main()
{
    int x = 0;

    //
    // if
    //

    if( x == 0 )
    {
        std::cout << "x is 0" << std::endl;
    }
    else
    {
        std::cout << "x is not 0" << std::endl;
    }

    if( x < -10 )
    {
        std::cout << "x is too low" << std::endl;
    }
    else if( x > 10 )
    {
        std::cout << "x is too high" << std::endl;
    }
    else
    {
        std::cout << "x is in range" << std::endl;
    }

    //
    // switch -case
    //

    x = 2;

    switch( x )
    {
    case 1:
        std::cout << "case 1" << std::endl;
        break;
    case 2:
        std::cout << "case 2" << std::endl;
        break;
    case 3:
        std::cout << "case 3" << std::endl;
        break;
    default:
        std::cout << "default" << std::endl;
        break;
    }

    //
    // for loop
    //

    for( int i = 0; i < 10; i = i + 1 )
    {
        std::cout << "i[" << i << "]" << std::endl;
    }

    //
    // while loop
    //

    x = 0;

    while( x < 10 )
    {
        std::cout << "x[" << x << "]" << std::endl;
        x++;
    }

    //
    // do while loop
    //

    x = 0;

    do
    {
        std::cout << "x[" << x << "]" << std::endl;
        x++;
    }
    while( x < 10 );
}
