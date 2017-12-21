//
// gala.go
// main.cpp
//

#include <iostream>

#include "gamewindow.hpp"

int main(int argc, const char * argv[]) {

    board mboard;
    int i,j;
    
    while(1)
    {
        mboard.printboard();
        
        std::cin>>i;
        std::cin>>j;
        
        mboard.addstone(i,j);
    }
    
    return 0;
}
