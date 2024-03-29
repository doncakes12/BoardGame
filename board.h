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
    bool occupied = 0;
    Piece* piece = nullptr;  //initally empty 
    //pointer to object occupying square
    Tile() {}
};

class Board {
  private:
    //May want to make static later so only one instance of board can be altered
    Tile* boardSpace[8][8];

  public:
    //constructor & destructor
    Board();
    ~Board();
    
    //mutators
    void updatePieceOnTile(Piece*, unsigned int, unsigned int); //will only update piece on tile not check for legality in games
    inline void updateOccupied(unsigned int rank, unsigned int file, bool occup) {boardSpace[rank][file]->occupied = occup;}
    
    //accessors
    inline const Tile& getTile(unsigned int rank, unsigned int file){return *boardSpace[rank][file];}
    inline const bool boundCheck(unsigned int rank, unsigned int file) {return ((rank < 7)&&(file < 7));}
    //currently just prints out the 'checker' board not actual pieces
    const void printBoard();
};

#endif
