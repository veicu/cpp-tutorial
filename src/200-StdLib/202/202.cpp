/*
    std::vector
*/

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> int_values{ 1, 2, 3 };

    int_values.push_back( 4 );
    int_values.push_back( 5 );
    int_values.push_back( 6 );

    int_values.insert(int_values.begin(), 0);

    int_values[1] = 10;
    int_values.at(2) = 20;

    for( const auto& int_val : int_values) // range-based for loop
    {
        std::cout << int_val << std::endl;
    }

    for( size_t i = 0; i< int_values.size(); ++i )
    {
        std::cout << int_values[i] << std::endl;
    }

    for( std::vector<int>::iterator it = int_values.begin(); it != int_values.end(); ++it )
    {
        std::cout << *it << std::endl;
    }



    typedef std::vector<int> int_vector;       // C style typedef
    using double_vector = std::vector<double>; // alias declaration

    double_vector double_values;

    double_values.push_back( 1.0 );
    double_values.push_back( 2.0 );
    double_values.push_back( 3.0 );

    for( double_vector::iterator it = double_values.begin(); it != double_values.end(); ++it )
    {
        std::cout << *it << std::endl;
    }

    for( auto it = double_values.begin(); it != double_values.end(); ++it )
    {
        std::cout << *it << std::endl;
    }
}
