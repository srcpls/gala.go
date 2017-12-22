# current organization
within the board class all other classes are contained:

### coordinate
the struct coordinate contains a _j_ value and an _i_ value which correspond respectively with the conventional x and y values. they indicate where exactly a stone is located on the board, or within __gala.go__, the grid, which is a 19x19 integer matrix representation of the board with a 0 value for an empty space, a 1 for a black stone, and a 2 for a white stone. a coordinate can also contain a _t_ value which has yet to be implemented but will store the turn the coordinate was played (which I suspect will be helpful later in __gala.go__'s development).

### group
the class group contains a vector of coordinates and is used to represent a group of stones(or coordinates). a group must be initialized with an integer value for the color of the group, again 1 for black, 2 for white. information about the member functions of the class can be found within the documentation on group.hpp.

### collect
the class collect contains a vector of groups and is used to represent all of the groups on the board, and is a private member of every board object. collect also allows manipulation of the groups such as merging, deleting, etc.

### board
the board class contains all of the information of a game of go (thus far kept track of), including the a matrix representation of the board, called grid, a collect object containing all of the groups of stones of the board, the number of stones captured, the turn etc.
