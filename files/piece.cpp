#include "../headers/piece.h"

//Piece is virtual
Piece::~Piece() {}

//Checker is declareable

Checker::Checker(char c, unsigned int rank, unsigned int file) : Piece(c), promoted(0), rank(rank), file(file) {}

Checker::~Checker() {}

//starts with a check to see direction of movement, then checks if it can (if not promoted and try to move backward fail) Will need to do another check from board to see if the move is possible on the board
void Checker::move(unsigned int rank, unsigned int file) {
      
}
