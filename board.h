#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

class Board {
    int len;
public:
    Piece *b[8][8];
	Board();
	void showBoard();
	void updateBoard();
};

#endif
