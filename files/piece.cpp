#include "../headers/piece.h"


Piece::Piece() : color("occupied") {}

Piece::~Piece() {}
//Unique to type of piece
const void Piece::move(){ 
    return;
}

Checker::Checker(std::string c, const unsigned int rank, const unsigned int file) : Piece(c), promoted(0), initRank(rank), initFile(file) {}

Checker::~Checker() {}
