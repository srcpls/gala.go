//
// gala.go
// collect.hpp
//

#ifndef collect_hpp
#define collect_hpp

#include <iostream>

#include "group.hpp"

class collect
{
public:
    
    //constructor && destructor
    collect();
    ~collect();
    
    //addgroup adds the given group 'g' to the vector of groups called 'groups'
    //minusgroup subtracts the group from the vector of groups called 'groups'
    //the second minus group takes in a group, will find it within the vector
    //and then remove from the list
    void addgroup(group g);
    void minusgroup(int index);
    void minusgroup(group *g);
    
    //mergegroups merges two groups into a new one, usually the new one being the
    //stone just placed. g2 is the group with the new stone placed and g1 is merged into g2
    void mergegroups(group *g1, group *g2);
    
    //adds the given coordinate 'c' to the group at index 'index' within
    //the vector 'groups'
    void addcoordtogroup(coordinate c,int index);
    
    group retrievegroupat(int index);
    //returns the group at the given index 'index' from 'groups'
    group * retrievegroup(int index);
    
    //returns the private member variable 'numofgroups'
    int retrievenumofgroups();
    
    //hasgroup checks if the given group 'g' is contained within the vector of
    //groups 'groups': If so, it will the return the index of the group within
    //the vector. Otherwise it will return a -1 if the group is not found
    int hasgroup(group g);
    
    //hascoord checks if the given coordinate 'c' is contained within
    //any of the groups contained within the vector 'groups': If it
    //does, it will return the index of the group that contains it,
    //otherwise it will return -1 if no group has 'c'
    int hascoord(coordinate c);
    
private:
    
    //the number of groups in 'groups'
    int numofgroups;
    
    //vector of groups that are contained within this group
    std::vector<group> groups;
    
};


#endif /* collect_hpp */
