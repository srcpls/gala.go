//
// gala.go
// coordinate.hpp
//

#ifndef coordinate_hpp
#define coordinate_hpp

#include <iostream>

struct coordinate
{
    //constructor && destructor
    coordinate();
    ~coordinate();
    
    //coordinates i and j instead of conventional x and y
    int i;
    int j;
    
    //holds the turn this coordinate was played
    int t;
    
    //overloaded comparison operators to compare two coordinates
    bool operator== (const coordinate& c2);
    
    void operator= (const coordinate& c2);
    
    bool operator!= (const coordinate& c2);
};

#endif /* coordinate_hpp */
