#include "player.h"
#include <cmath>
#include <iostream>

Player::Player(Board *b1, char type) : type(type), b1(b1), x1(0), x2(0), y1(0), y2(0), piecesGained(0) {}

// return the pieces gained
 int Player::getPiecesGained() {
     return piecesGained;
 }

// check if the final destination results in a king piece
void Player::gotKing() {
    if(x2 == 7 && type == 'X') {
        if(!b1->b[x2][y2]->checkKing()) {
            b1->b[x2][y2]->setIsKing();
        }
    } else if(x2 == 0 && type == 'O') {
        if(!b1->b[x2][y2]->checkKing()) {
            b1->b[x2][y2]->setIsKing();
        }
    }
}

// Player X or O makes a turn, gives coordinates and board updates after check.
void Player::makeTurn() {
    while (true) {
        std::cout << "Enter the piece to move." << std::endl;
        std::cout << "x coordinate: ";
        std::cin >> x1;
        std::cout << "y coordinate: ";
        std::cin >> y1;

        std::cout << std::endl;
        
        std::cout << "Enter the coordinates of your new square." << std::endl;
        std::cout << "x coordinate: ";
        std::cin >> x2;
        std::cout << "y coordinate: ";
        std::cin >> y2;

        int diff1 = 0;
        int diff2 = 0;
        diff1 = std::abs(x2-x1);
        diff2 = std::abs(y2-y1);

        Piece *spot;
        spot = b1->b[x1][y1];
        Piece *dest;
        dest = b1->b[x2][y2];

        // normal move
        if (spot != NULL && !spot->checkKing() && diff1 == 1 && diff2 == 1 && dest == NULL && spot->getType() == this->type) {
            b1->b[x2][y2] = b1->b[x1][y1];
            b1->b[x1][y1] = NULL;
            gotKing();
            break;
        }

        // capture piece
        if (spot != NULL && !spot->checkKing() && diff1 == 2 && diff2 == 2 && dest == NULL && spot->getType() == this->type) {
            int checkX = type == 'X' ? x1 + 1 : x1 - 1;
            int checkY = y1 < y2 ? y1 + 1 : y2 + 1; 
            Piece *temp = b1->b[checkX][checkY];
            if (temp->getType() != this->type) {
                b1->b[x2][y2] = b1->b[x1][y1];
                b1->b[x1][y1] = NULL;
                std::cout << "Piece captured at " << checkX << ","  << checkY << std::endl;
                delete b1->b[checkX][checkY];
                b1->b[checkX][checkY] = NULL;
                piecesGained+=1;
            } // if
            gotKing();
            break;
        } // if
    } // while

    // automatic check for additional jumps
    while(true) {
        int destX1 = 0;
        int destY1 = 0;
        int destY1_opp = 0;
        int destX2 = 0;
        int destY2 = 0;
        int destY2_opp = 0;
        if (type == 'X') {
            destX1 = x2 + 1;
            destY1 = y2 + 1;
            destY1_opp = y2-1;
            destX2 = x2 + 2;
            destY2 = y2 + 2;
            destY2_opp = y2-2;
        } else {
            destX1 = x2 - 1;
            destY1 = y2 + 1;
            destY1_opp = y2-1;
            destX2 = x2 - 2;
            destY2 = y2 + 2;
            destY2_opp = y2-2;
        }

        if((destX1 < 8 && destX1 >= 0) && (destY1 < 8 && destY1 >= 0) &&  b1->b[destX1][destY1] != NULL && b1->b[destX1][destY1]->getType() != this->type
           && (destX2 < 8 && destX2 >= 0) && (destY2 < 8 && destY2 >= 0) && b1->b[destX2][destY2] == NULL) {
                std::cout << "Jump again, piece at " << destX1 << "," << destY1 << std::endl; 
        } else if((destX1 < 8 && destX1 >= 0) && (destY1_opp < 8 && destY1_opp >= 0) &&  b1->b[destX1][destY1_opp] != NULL && b1->b[destX1][destY1_opp]->getType() != this->type
            && (destX2 < 8 && destX2 >= 0) && (destY2_opp < 8 && destY2_opp >= 0) && b1->b[destX2][destY2_opp] == NULL) {
                std::cout << "Jump again, piece at " << destX1 << "," << destY1_opp << std::endl; 
        } else {
            break;
        }

        x1 = x2;
        y1 = y2;
        while (true) {
            std::cout << "Enter coordinates to make double jump." << std::endl;
            std::cin >> x2;
            std::cin >> y2;
            if(x2 == destX2 && y2 == destY2) {
                b1->b[x2][y2] = b1->b[x1][y1];
                b1->b[x1][y1] = NULL;
                delete b1->b[destX1][destY1];
                piecesGained+=1;
                b1->b[destX1][destY1] = NULL;
                gotKing();
                break;
            }
            if(x2 == destX2 && y2 == destY2_opp) {
                b1->b[x2][y2] = b1->b[x1][y1];
                b1->b[x1][y1] = NULL;
                delete b1->b[destX1][destY1_opp];
                piecesGained+=1;
                b1->b[destX1][destY1_opp] = NULL;
                gotKing();
                break;
            }
        } // while
    } // while
}
	