#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

class Player {
    char type;
    Board *b1;
    int x1, x2, y1, y2;
    int piecesGained;
public:
    Player(Board *, char type);
    int getPiecesGained();
    void makeTurn();
    void gotKing();
};

#endif
