#include "board.h"

//#include <iostream>

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
