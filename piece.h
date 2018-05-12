#ifndef PIECE_H
#define PIECE_H

#include <string>

class Board;

class Piece {
  
protected:
    Board *b;
    char type;
    bool isKing;
    int x;
    int y;

public:
    Piece(Board*, char);
    char getType();
    bool checkKing();
    void setIsKing();
    void setCoords(int, int); 
    virtual ~Piece()=0;   
};

#endif
