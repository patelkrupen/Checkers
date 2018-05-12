#include "board.h"
#include "xx.h"
#include "oo.h"
#include <iostream>

Board::Board() : len(8) {
	for (int x = 0; x < len; x++) {
		if (x == 0 || x == 2) {
			for (int y = 1; y < len; y += 2) {
				b[x][y] = new xx(this, 'X');
			}
			for (int y = 0; y < len; y += 2) {
				b[x][y] = NULL;
			}
		} else if (x == 1) {
			for (int y = 0; y < len; y += 2) {
				b[x][y] = new xx(this, 'X');
			}
			for (int y = 1; y < len; y += 2) {
				b[x][y] = NULL;
			}
		} else if (x == 3 || x == 4) {
			for (int y = 0; y < len; y++) {
				b[x][y] = NULL;
			}
		} else if (x == 5 || x == 7) {
			for (int y = 0; y < len; y += 2) {
				b[x][y] = new oo(this, 'O');
			}
			for (int y = 1; y < len; y += 2) {
				b[x][y] = NULL;
			}
		} else {
			for (int y = 1; y < len; y += 2) {
				b[x][y] = new oo(this, 'O');
			}
			for (int y = 0; y < len; y += 2) {
				b[x][y] = NULL;
			}
		}
	}
}

// display the board
void Board::showBoard(void) {
	std::cout << "       0     1     2     3     4     5     6     7  " << std::endl;
	std::cout << "    _________________________________________________  " << std::endl;

	for (int x = 0; x < len; x++) {
		std::cout << x << "  | ";
		for (int y = 0; y < len; y++) {
			if (b[x][y] != NULL && b[x][y]->getType() == 'X') {
				std::string t = b[x][y]->checkKing() ? "  KX" : "  X ";  
				std::cout << t;
			} else if (b[x][y] != NULL && b[x][y]->getType() == 'O') {
				std::string t = b[x][y]->checkKing() ? "  KO " : "  O ";  
				std::cout << t;
			} else {
				std::cout << "    ";
			}
			std::cout << " |";
		}
		std::cout << std::endl;
		std::cout << "   |______|_____|_____|_____|_____|_____|_____|_____|";
		std::cout << std::endl;
	}
}
