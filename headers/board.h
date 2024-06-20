//Author: Donovan Coleman
//Date started: 3/26/24

#ifndef board_h
#define board_h

//could use vectors for the extra bound check safety but not for now
#include <array>
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
};

class Board {
  private:
    //May want to make static later so only one instance of board can be altered (easy enough to implement in the actual main loop since there should only be one board anyways)
    Tile* boardSpace[8][8];

    inline bool boundCheck(unsigned int rank, unsigned int file) const {return ((rank < 7)&&(file < 7));}

  public:
    //constructor & destructor
    Board();
    ~Board();
    
    //mutators
    void updatePieceOnTile(Piece*, unsigned int, unsigned int); //will only update piece on tile not check for legality in games
    inline void updateOccupied(unsigned int rank, unsigned int file, bool occup) {boardSpace[rank][file]->occupied = occup;}
    
    //accessors
    inline Tile& getTile(unsigned int rank, unsigned int file) const {return *boardSpace[rank][file];}
    //currently just prints out the 'checker' board not actual pieces
    const void printBoard();
};

#endif
