#include "../headers/board.h"

#include <iostream>

Board::Board() {
    //hard coding board sizes for now will need adjustment later
    for(unsigned int i = 0; i < 8; i++){
        for(unsigned int j = 0; j < 8; j++){
	    this->boardSpace[i][j] = new Tile();
	}
    }
}

Board::~Board() {
    for(unsigned int i = 0; i < 8; i++){
        for(unsigned int j = 0; j < 8; j++){
	    delete this->boardSpace[i][j];
	}
    }
}

void Board::updatePieceOnTile(Piece* p,unsigned int rank,unsigned int file) {
    if(this->boundCheck(rank, file)){
        this->boardSpace[rank][file]->piece = p;
    }
    return;
}


//currently just prints board ( each 'title' is two char wide important to keep in mind moving forward)
const void Board::printBoard() {
    std::string edge = "__________________";
    std::cout << edge << "\n" << std::endl;
    for(unsigned int i = 0; i < 8; i++) {
    	std::cout << "|";
	    for(unsigned int j = 0; j < 8; j++){
	        //Alternates 'red/positive and black/negative'
	        (((i + j) % 2) == 0) ? std::cout << "  " : std::cout << char(219) << char(219);
	    }
	    std::cout << "|" << std::endl;
    }
    std::cout << edge << std::endl;
}
