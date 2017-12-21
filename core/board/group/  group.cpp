//
// gala.go
// group.cpp
//

#include "group.hpp"

group::group(int color)
{
    this->color=color;
    numofcoordinates=0;
}

group::~group()
{
    
}

void group::addcoordinate(coordinate c)
{
    std::cout<<"when addcoordinate, coordinate c: i:"<<c.i<<" j:"<<c.j<<std::endl;
    std::cout<<"when addcoordinate, numofcoordinates before"<<numofcoordinates<<std::endl;
    numofcoordinates++;
    coordinates.push_back(c);
    std::cout<<"when addcoordinate, numofcoordinates after"<<numofcoordinates<<std::endl;
}

void group::minuscoordinate(int index)
{
    numofcoordinates--;
    coordinates.erase(coordinates.begin()+index);
}

void group::makenilcoordinates()
{
    coordinates.clear();
    numofcoordinates=0;
}

coordinate group::retrievecoordinate(int index)
{
    return coordinates[index];
}

int group::retrievenumofcoordinates()
{
    return numofcoordinates;
}

int group::retrievecolor()
{
    return color;
}

int group::hascoordinate(coordinate c)
{
    std::cout<<"number of coordinates hascoordinate"<<numofcoordinates<<std::endl;
    for(int i=0;i<this->numofcoordinates;i++)
    {
        std::cout<<"checking comparison between coordinate i: "<<coordinates[i].i<<" j: "<<coordinates[i].j<<std::endl;
        std::cout<<"and coordinate given: i: "<<c.i<<" j: "<<c.j<<std::endl;
        if(coordinates[i]==c)
        {
            std::cout<<"found. returning index : "<<i<<std::endl;
            return i;
        }
    }
    std::cout<<"not found. returning -1"<<std::endl;
    return -1;
}

bool group::operator==(const group &g2)
{
    for(int i=0;i<numofcoordinates;i++)
    {
        if(this->coordinates[i]!=g2.coordinates[i])
        {
            return false;
        }
    }
    return true;
}

bool group::operator-=(const group &g2)
{
    for(int i=0;i<g2.numofcoordinates;i++)
    {
        if(this->hascoordinate(g2.coordinates[i])==-1)
        {
            return false;
        }
    }
    return true;
}
