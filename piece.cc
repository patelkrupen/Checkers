#include "piece.h"

Piece::Piece(Board *b, char type): b(b), type(type), isKing(false) {
    x = -1;
    y = -1;
}

// return piece type
char Piece::getType() {
    return type;
}

// check if piece is king
bool Piece::checkKing() {
    return isKing;
}

void Piece::setIsKing() {
    isKing = true;
}

void Piece::setCoords(int x1, int y1) {
	x = x1;
	y = y1;
}

Piece::~Piece() {}
