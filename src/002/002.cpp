/*
    Build in data types.
*/

#include <limits>

int main()
{
    // boolean type

    bool b;

    // character type

    char c = 'A';

    // signed integer typs

    signed char s_c;
    short       s;
    int         i;
    long        l;
    long long   ll;

    // unsigned integer types

    unsigned char      u_c;
    unsigned short     u_s;
    unsigned int       u_i;
    unsigned long      u_l;
    unsigned long long u_ll;

    // floating point number types

    float       f;
    double      d;
    long double ld;

    // 

    int short_size  = sizeof( short );
    int int_size    = sizeof( int );
    int long_size   = sizeof( long );
    int float_size  = sizeof( float );
    int double_size = sizeof( double );

    // numeric limits

    int int_min = std::numeric_limits<int>::min();
    int int_max = std::numeric_limits<int>::max();

    //

    b = true;
    b = false;

    int x = 0;
    x = 7 + 3;
    x = x + 1;

    double pos = 0;
    pos = 4.5;
    pos = 4.5 + 5.5;

}
