#include "../headers/piece.h"

//Piece is virtual
Piece::~Piece() {}

//Checker is declareable
Checker::Checker(char c, unsigned int rank, unsigned int file) : Piece(c), promoted(0), rank(rank), file(file) {}

Checker::~Checker() {}

//starts with a check to see if the user has the same rank or file. If that is the case just return since it is an invalid movement. Then check if promoted,(if not promoted and try to move backward fail) and finishes with a color for direction check. Do this after promotion since if it is promoted color does not matter in movement (can go forward and backward). Will need to do another check from board to see if the move is possible on the board (seperate function I think)
void Checker::move(unsigned int newRank, unsigned int newFile) {
    //Means movement does not occur since it is impossible to have the same rank or file in checkers
    if(newRank == this->rank || newFile == this->file)
        return;

    if(this->promoted) { //Can move in up to 4 directions
        //Movement
    } else { //Will check direction by color
        char c = this->getColor();
        switch(c) {
            case('r'): //red :=> moves neg in rank
            break;
            
            case('b'): //black :=> moves pos in rank
            break;
        }
    }
}
