//
// gala.go
// board.hpp
//

#ifndef board_hpp
#define board_hpp

#include <iostream>

#include "collect.hpp"

//enums for when rules (chinese and japanese and others to come) and different player options(player vs.
//player && player vs. gala.go(a.i.)) are implemented
enum rules{chinese, japanese};
enum players{pvp, pvg};

class board
{
    
public:
    
    //constructor && destructor
    board();
    ~board();
    
    //alternate constructor for when rules players and files are implemented
    board(std::string n, rules r, players p);
    
    //adds stone to grid, either for 1 or 2, black or white respectively, depending on the turn
    void addstone(int i,int j);
    
    //takes in a group g and checks if the group has any liberties and returns that number. returns 0 if
    //the group has none
    int checkliberty(group g);
    
    //subtracts group g from collectofgroups and (I believe) makes the coordinates of g equal 0 in grid.
    //usually called when a group is found to have 0 liberties
    void makegroupnil(group *g);
    
    //reacts to the stone placed at i=gridi and j=gridj. places new stone in a group, creates a new group,
    //and does everything needed to fully react to the newly placed stone
    void reacttostoneat(int code,int gridi,int gridj);
    
    //counts space groups, creating groups and placing those groups into the collect spaces
    void countspacegroups();
    
    //so pretty sure label groups was the first step in creating the function gradeboard, a function that
    //would determine the victor of the game. label groups outputs to the console the board but instead of
    //x and o for black and white respectively, it prints the groups identified by a unifying number and for
    //space groups, with letters
    void labelgroups();
    
    //prints the board using x and o and _ for black and white and empty spaces respecitvely
    void printboard();
    
    //(work in progress) grades the board to determine the victor of the game
    void gradeboard(rules grules);
    
    //returns 1 if the gridpoint contains a black stone, 2 if the gridpoint contains a white stone, and 0 if
    //the gridpoint is empty
    int retrievegrid(int i, int j);
    
    //returns the turn the game is currently on. 1 if it's black's turn, and 2 if it's white's turn
    int retrieveturn();
    
    //increases the turn, thus making it the other players turn without having to make a move
    void passturn();
    
    //returns the number of groups stored in the collect "collectofgroups"
    int retrievenumofgroups();
    
    //returns the number of groups containing only empty space. not yet implemented
    int retrievenumofspacegroups();
    
    //returns the number of black stones captured
    int retrieveblackcaptured();
    
    //returns the number of white stones captured
    int retrievewhitecaptured();
    
    void testfunction();
    
private:
    
    //2d matrix representing the goban using 1 for a black stone, 2 for a white stone, and 0 for an empty
    //space
    int grid[20][20];
    
    //collectofgroups is an object of class collect which holds all the groups of stones on the board
    collect collectofgroups;
    
    //spaces is an object of class collect which will hold all of the groups of empty spaces on the board.
    //not yet implemented
    collect spaces;
    
    //the turn the game is currently on
    int turn;
    
    //number of black stones captured and white stones captured respectively
    int blackcaptured, whitecaptured;
    
    //the name of this game. named by user
    std::string name;
    
    //rules chosen by the user
    rules brules;
    
    //players chosen by the user (player vs. player or player vs. gala.go (a.i.))
    players bplayers;
};



#endif /* board_hpp */
