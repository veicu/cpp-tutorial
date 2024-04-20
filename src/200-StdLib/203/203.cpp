/*
    std::map
*/

#include <map>
#include <string>
#include <iostream>

int main()
{
    std::map<std::string, std::string> translation_map;

    //
    // insert or set
    //

    translation_map["Mann"]   = "man";
    translation_map["Frau"]   = "woman";
    translation_map["Kind"]   = "kid";
    translation_map["Frosch"] = "frog";

    //
    // remove item
    //

    translation_map.erase( "Frosch" );

    //
    // set
    //

    translation_map["Kind"] = "child";

    //
    // size
    //

    std::cout << "SIZE: " << translation_map.size() << std::endl;

    //
    // get - inserts new item if key does not exist
    //

    std::string s = translation_map["Mann"];

    //
    // find - does not modify the map like the []-operator
    //

    auto it = translation_map.find( "Kind" );
    if( it != translation_map.end() )
    {
        s = it->second;
    }

    //
    //
    //

    for( auto it = translation_map.begin(); it != translation_map.end(); ++it )
    {
        std::cout << it->first;
        std::cout << " : ";
        std::cout << it->second;
        std::cout << std::endl;
    }
}
