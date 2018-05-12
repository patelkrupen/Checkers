#include <iostream>
#include "board.h"
#include "player.h"

int turn = 0;

int main() {
	Board b1;
	Player p1(&b1, 'X');
	Player p2(&b1, 'O');
	b1.showBoard();

	std::cout << "GAME OF CHECKERS:" << std::endl;
	std::cout << "" << std::endl;

	while (true) {

		if(p1.getPiecesGained() == 12) {
			std::cout << "Player X has one." << std::endl;
			break;
		}

		if(p2.getPiecesGained() == 12) {
			std::cout << "Player O has one." << std::endl;
			break;
		}

		if(turn % 2 == 0) {
			// player one turn
			std::cout << "It is player X's turn." << std::endl;
			std::cout << "You have " << p1.getPiecesGained() << "/12 pieces in possession." << std::endl;
			p1.makeTurn();
		} else {
			// player two turn
			std::cout << "It is player O's turn." << std::endl;
			std::cout << "You have " << p2.getPiecesGained() << "/12 pieces in possession." << std::endl;
			p2.makeTurn();
		}
		b1.showBoard();
		turn+=1;
	}
}
