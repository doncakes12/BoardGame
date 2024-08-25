//Author: Donovan Coleman
//Date started: 3/26/24

#ifndef board_h
#define board_h

//could use vectors for the extra bound check safety but not for now
#include <array>
//Might not need arrays with swapping to vector (allows for easy board size determining during runtime)
#include <vector>
#include "piece.h"

//Struct for each tile of the board
//All public  
struct Tile {	
    //Might not need occupied cause I can check if the pointer is null or not (if I am not careful with pointers it won't work) but easy enough to keep for now
    bool occupied = 0;
    Piece* piece = nullptr;  //initally empty 
    //pointer to object occupying square

    //constructor
    Tile() {}
    ~Tile() {}
};

class Board {
  private:
    //May want to make static later so only one instance of board can be altered (easy enough to implement in the actual main loop since there should only be one board anyways)

    unsigned int bWidth;
    unsigned int bHeight;

    //made vector represent 2d array size of bWidth x bHeight (can be seen in declaration)
    std::vector<std::vector<Tile*>> boardSpace;

//    Tile* boardSpace[8][8];

    //Helper functions
    inline bool boundCheck(unsigned int rank, unsigned int file) const {return ((rank < bWidth)&&(file < bHeight));}
    char printTile(unsigned int, unsigned int) const;

  public:
    //constructor & destructor
    Board(const unsigned int, const unsigned int);
    //default makes 8x8
    Board(): Board(8,8) {}
    ~Board();
    
    //mutators
    void updatePieceOnTile(Piece*, unsigned int, unsigned int); //will only update piece on tile not check for legality in games
    inline void updateOccupied(bool occup, unsigned int rank, unsigned int file) {boardSpace[rank][file]->occupied = occup;}
    
    //accessors
    inline Tile& getTile(unsigned int rank, unsigned int file) const {return *boardSpace[rank][file];}
    //currently just prints out the 'checker' board
    void printBoard() const;
};

#endif
