//
// gala.go
// collect.cpp
//

#include "collect.hpp"

collect::collect()
{
    numofgroups=0;
}

collect::~collect()
{
    
}

void collect::addgroup(group g)
{
    numofgroups++;
    groups.push_back(g);
    std::cout<<numofgroups<<"groups"<<std::endl;
}

void collect::minusgroup(int index)
{
    numofgroups--;
    groups.erase(groups.begin()+index);
}

void collect::minusgroup(group *g)
{
    for(int i=0;i<numofgroups;i++)
    {
        if(groups[i]==*g)
        {
            minusgroup(i);
            break;
        }
    }
}

void collect::mergegroups(group *g1, group *g2)
{
    for(int i=0;i<g1->retrievenumofcoordinates();i++)
    {
        g2->addcoordinate(g1->retrievecoordinate(i));
        std::cout<<"in merge groups, i:"<<i<<std::endl<<std::endl;
    }
    
    //testing
    std::cout<<"                                                     merge group testing:"<<std::endl<<"                                                g2 numofcoordinates:"<<g2->retrievenumofcoordinates()<<std::endl;
    coordinate testcoordinate;
    for(int i=0;i<g2->retrievenumofcoordinates();i++)
    {
        testcoordinate=g2->retrievecoordinate(i);
        std::cout<<"at index "<<i<<" coordinate i:"<<testcoordinate.i<<" and j:"<<testcoordinate.j<<std::endl;
    }
    
    minusgroup(g1);
}

void collect::addcoordtogroup(coordinate c, int index)
{
    std::cout<<"when addcoordtogroup, index="<<index<<"and coordinate c: i:"<<c.i<<" j:"<<c.j<<std::endl;
    groups[index].addcoordinate(c);
}

group collect::retrievegroupat(int index)
{
    return groups[index];
}

group * collect::retrievegroup(int index)
{
    return &groups[index];
}

int collect::retrievenumofgroups()
{
    return numofgroups;
}

int collect::hasgroup(group g)
{
    for(int i=0;i<numofgroups-1;i++)
    {
        if(groups[i]==g)
        {
            return i;
        }
    }
    
    return -1;
}

int collect::hascoord(coordinate c)
{
    std::cout<<"collect::hascoord being called"<<std::endl;
    for(int i=0;i<numofgroups;i++)
    {
        std::cout<<"loop entered"<<std::endl;
        //testing
        std::cout<<"testing group "<<i<<" which has "<<groups[i].retrievenumofcoordinates()<<" coordinates"<<std::endl;
        if(groups[i].hascoordinate(c)>-1)
        {
            return i;
        }
    }
    return -1;
}
