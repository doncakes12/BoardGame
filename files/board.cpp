#include "../headers/board.h"

#include <iostream>
//included typeinfo for debugging
#include <typeinfo>

//if no width or height is defined place board of 8x8
Board::Board(const unsigned int wdth, const unsigned int hght) {
    this->bWidth = wdth;
    this->bHeight = hght; 

    //Creates vector column of tile pointers and pushed row number of times to build 2d array
    for(unsigned int i = 0; i < this->bWidth; i++){
        std::vector<Tile*> vec;
        for(unsigned int j = 0; j < this->bHeight; j++){
            vec.push_back(new Tile());
        }
        this->boardSpace.push_back(vec);
    }
}


Board::~Board() {
    for(unsigned int i = 0; i < bWidth; i++){
        for(unsigned int j = 0; j < bHeight; j++){
	    delete this->boardSpace[i][j];
	}
    }
}

// does bound check on the entered rank and file values and then puts the piece there (does not remove piece from other locations if already there). WIll probably change this so that it more accurately matches what it does and then can be part of a larger move function where it will make sure there is only one pointer to the piece
void Board::updatePieceOnTile(Piece* p,unsigned int rank,unsigned int file) {
    if(this->boundCheck(rank, file)){
        this->boardSpace[rank][file]->piece = p;
    }
    return;
}

//Helper function that will print out the color if piece exists else will print appropriate char for board tile
char Board::printTile(unsigned int rank, unsigned int file) const{
    //nullptr check
    char rChar;
    if(this->getTile(rank,file).piece != nullptr) { //piece exists
        rChar = (this->getTile(rank,file).piece->getColor());
    } else {
        ((rank + file) % 2 == 0) ? rChar= ' ' : rChar= char(219);
    }
    return rChar;
}

//currently just prints board ( each 'title' is three char wide important to keep in mind moving forward) swapped to 3 since itll be easier to center things
void Board::printBoard() const{

    //Building top/bottom edge
    std::string edge = "__________________________";
    std::cout << edge << "\n" << std::endl;

    //main print loop
    for(unsigned int i = 0; i < bWidth; i++) {
    	std::cout << "|";
	    for(unsigned int j = 0; j < bHeight; j++){
	        //Alternates black and white squares and outputs their occupied piece ('r' red / 'b' black) else it will just have a space if there is no tile on he square
	        (((i + j) % 2) == 0) ? std::cout << " " << printTile(i, j) << " " : std::cout << char(219) << printTile(i, j) << char(219);
	    }
	    std::cout << "|" << std::endl;
    }
    std::cout << edge << std::endl;
}
