//
// gala.go
// group.hpp
//

#ifndef group_hpp
#define group_hpp

#include <iostream>
#include <vector>

#include "coordinate.hpp"

class group
{
public:
    
    //constructor && destructor
    group(int color);
    ~group();
    
    //functions for either adding or subtracting a coordinate from the vector of coordinates
    //addcoordinate takes in the coordinate you want to add and minuscoordinate subtracts the coordinate at
    //the index in the vector
    void addcoordinate(coordinate c);
    void minuscoordinate(int index);
    
    void makenilcoordinates();
    
    //retrievecoordinate returns the coordinate at the given index from the vector of coordinates
    //retrievenumofcoordinates returns the private member variable 'numofcoordinates'
    coordinate retrievecoordinate(int index);
    int retrievenumofcoordinates();
    
    //retrievecolor returns the color of this group
    int retrievecolor();
    
    //hascoordinate checks if this group contains the given coordinate 'c': If it does it will return a
    //integer greater than -1 which is also the index at which the coordinate can be found in the
    //vector of coordinates called 'coordinates'
    int hascoordinate(coordinate c);
    
    //overloaded comparison operator to compare two groups
    bool operator== (const group& g2);
    
    //wierd, I know, but this checks if all of g2 is contained within g1, as in: g2 is a subset of g1
    bool operator -=(const group & g2);
    
    
private:
    
    //the number of coordinates in the vector
    int numofcoordinates;
    
    //1 for black, 2 for white
    int color;
    
    //vector of coordinates that are contained within this group
    std::vector<coordinate> coordinates;
    
};


#endif /* group_hpp */
