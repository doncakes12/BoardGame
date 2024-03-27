//Author: Donovan Coleman
//Date started: 3/26/24

#ifndef board_h
#define board_h

//could use vectors for the extra bound check safety but not for now
#include <array>

//Struct for each tile of the board
//All public  
struct Tile {	
    bool occupied = 0;
    //pointer to object occupying square
    Tile() {}
};

class Board {
  private:
    //May want to make static later so only one instance of board can be altered
    Tile* boardSpace[8][8];

  public:
    Board();
    //Board(int, int);
    Tile* getTile(int rank, int file){return boardSpace[rank][file];}
    ~Board();

};

#endif
