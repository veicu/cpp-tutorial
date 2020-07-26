/*
    std::vector
*/

#include <vector>
#include <iostream>

int main()
{
    typedef std::vector<int> int_vector;

    using double_vector = std::vector<double>;

    std::vector<int> i_vec;

    double_vector my_double_values;

    my_double_values.push_back( 1.0 );
    my_double_values.push_back( 2.0 );
    my_double_values.push_back( 3.0 );

    for( auto it = my_double_values.begin(); it != my_double_values.end(); ++it )
    {
        std::cout << *it << std::endl;
    }
}
