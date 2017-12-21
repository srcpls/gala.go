//
// gala.go
// coordinate.cpp
//

#include "coordinate.hpp"

coordinate::coordinate()
{
    t=-1;
}

coordinate::~coordinate()
{
    
}

bool coordinate::operator==(const coordinate &c2)
{
    return (this->i==c2.i && this->j==c2.j);
}

void coordinate::operator=(const coordinate &c2)
{
    this->i=c2.i;
    this->j=c2.j;
}

bool coordinate::operator!=(const coordinate& c2)
{
    return (this->i!=c2.i || this->j!=c2.j);
}
