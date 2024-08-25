#ifndef piece_h
#define piece_h


#include <utility> //needed for pair (since i am using them as coords for the board) ~~~~ Currently not in use anywhere and I might not need it but here for now


//#include <string> //Shouldn't need if I use char instead

class Piece {
  private:
    //denotes player using char instead
    char color;
      
  public:
    //Construct and destructor
    Piece();
    explicit Piece(char c) : color(c) {} 
    ~Piece();
    
    //virtual function to abstract piece class and not const because derived classes will pieces will update dmSiata
    virtual void move(unsigned int, unsigned int) = 0;
    
    //accessor
    inline char getColor() const{return color;}
};


//Need to figure out how to move only "forward" since it will be opposite for both players
//using color (char) to determine direction (r => negative rank, b => positive rank) and then can use promoted to allow forward and backward
class Checker: public Piece {
  private:
    bool promoted = 0;
    //These will maintain curr pos (rank: row as file: column)
    unsigned int rank;
    unsigned int file;

  public:
    //Constructor & deconstructor
    Checker(char, unsigned int, unsigned int);
    ~Checker();
    
    //parameters are new pos
    void move(unsigned int, unsigned int) override;

    //mutator
    inline void promote() {this->promoted = 1;}

    //accessor
    inline bool isPromoted() const {return this->promoted;}
    inline std::pair<unsigned int, unsigned int> getCurrPos() const {return std::make_pair(this->rank, this->file);}

};

#endif
