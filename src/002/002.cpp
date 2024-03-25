/*
    Build in data types.
*/

#include <limits>
#include <climits>

int main()
{
    // boolean type

    bool b;

    // character type

    char ch = 'A';

    // signed integer typs

    signed char c;
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

    // size of the object or type in bytes (multiples of the size of char)

    int size_char   = sizeof( char );
    int size_short  = sizeof( short );
    int size_int    = sizeof( int );
    int size_long   = sizeof( long );
    int size_float  = sizeof( float );
    int size_double = sizeof( double );

    int size_c = sizeof( c );
    int size_i = sizeof( i );
    int size_d = sizeof( d );

    // numeric limits

    int int_min = std::numeric_limits<int>::min();
    int int_max = std::numeric_limits<int>::max();

    int bits_per_byte = CHAR_BIT;

    // examples

    bool valid = false;
    valid = true;

    int score = 0;
    score = 7 + 3;
    score = score + 1;

    double pos = 0.0;
    pos = 4.5;
    pos = 4.5 + 5.5;
}
