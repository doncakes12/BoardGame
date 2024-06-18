#ifndef piece_h
#define piece_h

#include <string>
class Piece {
  private:
    //denotes player
    std::string color;
      
  public:
    //Construct and destructor
    Piece();
    explicit Piece(std::string c) : color(c) {} 
    ~Piece();
    const void move();

    //accessor
    inline const std::string getColor() {return color;}
};


//Need to figure out how to move only "forward" since it will be opposite for both players

class Checker: public Piece {
  private:
    bool promoted = 0;
    //These will help with determining direction
    const unsigned int initRank;
    const unsigned int initFile;
  public:
    //Constructor & deconstructor
    Checker(std::string, const unsigned int, const unsigned int);
    ~Checker();
    const void move();
    //helper functions for moving forward and backward. This does the checks required and move<direction> just completes the action.
    const void moveForward(unsigned int, unsigned int);
    const void moveBackward(unsigned int, unsigned int);
    //mutator
    inline void promote() {promoted = 1;}
    const std::pair<const unsigned int, const unsigned int> getInitPos() {return std::pair<const unsigned int, const unsigned int> (initRank, initFile);}

};

#endif
