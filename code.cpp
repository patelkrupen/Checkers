/*
 * code.cpp
 *
 *  Created on: Jun 1, 2015
 *      Author: Krupen
 */

#include <iostream>
#include <cmath>
using namespace std;


// global variables
int b[8][8]; // playing board
const int len = 8;
int turn = 0;

//////////////////////////////////////////////////////////////////////////////////////
class Board {

public:
	Board();
	void showBoard();
	void updateBoard();

};

Board::Board(void) {

	for (int x = 0; x < len; x++) {

		if (x == 0 || x == 2) {
			for (int y = 1; y < len; y += 2) {
				b[x][y] = 1;
			}
			for (int y = 0; y < len; y += 2) {
				b[x][y] = 0;
			}
		} else if (x == 1) {
			for (int y = 0; y < len; y += 2) {
				b[x][y] = 1;
			}
			for (int y = 1; y < len; y += 2) {
				b[x][y] = 0;
			}
		} else if (x == 3 || x == 4) {
			for (int y = 0; y < len; y++) {
				b[x][y] = 0;
			}
		} else if (x == 5 || x == 7) {
			for (int y = 0; y < len; y += 2) {
				b[x][y] = 2;
			}
			for (int y = 1; y < len; y += 2) {
				b[x][y] = 0;
			}
		} else {
			for (int y = 1; y < len; y += 2) {
				b[x][y] = 2;
			}
			for (int y = 0; y < len; y += 2) {
				b[x][y] = 0;
			}

		}
	}
}

void Board::showBoard(void) {
	cout << "       0     1     2     3     4     5     6     7  " << endl;
	cout << "    _________________________________________________  " << endl;

	for (int x = 0; x < len; x++) {
		cout << x << "  | ";
		for (int y = 0; y < len; y++) {
			if (b[x][y] == 1) {
				cout << "  X ";
			} else if (b[x][y] == 2) {
				cout << "  O ";
			} else if (b[x][y] == 3) {
				cout << " K1 ";
			} else if (b[x][y] == 4) {
				cout << " K2 ";
			} else {
				cout << "    ";
			}
			cout << " |";
		}
		cout << endl;
		cout << "   |______|_____|_____|_____|_____|_____|_____|_____|";
		cout << endl;
	}
}

//////////////////////////////////////////////////////////////////////////////////

class Player: public Board {

public:
	int piecesGained;
	int x1, y1, x2, y2;
	//int bx, by;
	Player(int z);
	bool updateBoard1(int d1, int d2);
	bool updateBoard2(int d1, int d2);
	int updateBoard3();
	int updateBoard4();
	//int checkKingJump1();
	//int checkKingJump2();

};

Player::Player(int z) {
	x1 = z;
	x2 = z;
	y1 = z;
	y2 = z;
	//bx = z;
	//by = z;
	piecesGained = z;
}

bool Player::updateBoard1(int d1, int d2) {

	while (x1 != x2) {
		if (y2 > y1) {
			b[x1][y1] = 0;
			x1++;
			y1++;
			if (b[x1][y1] == 2)
				piecesGained++;
			b[x1][y1] = 1;
		} else {
			b[x1][y1] = 0;
			x1++;
			y1--;
			if (b[x1][y1] == 2)
				piecesGained++;
			b[x1][y1] = 1;
		}
	}

	if (x2 == 7) {
		b[x2][y2] = 3;
	}

	x1 = x2;
	y1 = y2;

	bool flag = false;

	if (d2 == 2) {

		if ((y2 == 0 || y2 == 1) && (x2 < 6)) {

			if ((b[x2 + 1][y2 + 1] == 2 || b[x2 + 1][y2 + 1] == 4)
					&& (b[x2 + 2][y2 + 2] == 0)) {
				cout << "There is another piece to jump at " << "[" << x2 + 1
						<< "]" << "[" << y2 + 1 << "]." << endl;
				cout << "Enter " << "[" << x2 + 2 << "]" << "[" << y2 + 2
						<< "]." << endl;
				flag = true;
			}
		} else if ((y2 == 6 || y2 == 7) && (x2 < 6)) {
			if ((b[x2 + 1][y2 - 1] == 2 || b[x2 + 1][y2 - 1] == 4)
					&& (b[x2 + 2][y2 - 2] == 0)) {
				cout << "There is another piece to jump at " << "[" << x2 + 1
						<< "]" << "[" << y2 - 1 << "]." << endl;
				cout << "Enter " << "[" << x2 + 2 << "]" << "[" << y2 - 2
						<< "]." << endl;
				flag = true;
			}
		} else if (((b[x2 + 1][y2 + 1] == 2 || b[x2 + 1][y2 + 1] == 4)
				&& (b[x2 + 2][y2 + 2] == 0)) && (x2 < 6)) {
			cout << "There is another piece to jump at " << "[" << x2 + 1 << "]"
					<< "[" << y2 + 1 << "]." << endl;
			cout << "Enter " << "[" << x2 + 2 << "]" << "[" << y2 + 2 << "]."
					<< endl;
			flag = true;

		} else if (((b[x2 + 1][y2 - 1] == 2 || b[x2 + 1][y2 - 1] == 4)
				&& (b[x2 + 2][y2 - 2] == 0)) && (x2 < 6)) {
			cout << "There is another piece to jump at " << "[" << x2 + 1 << "]"
					<< "[" << y2 - 1 << "]." << endl;
			cout << "Enter " << "[" << x2 + 2 << "]" << "[" << y2 - 2 << "]."
					<< endl;

			flag = true;

		}

	}

	return flag;
}

bool Player::updateBoard2(int d1, int d2) {

	while (x1 != x2) {
		if (y2 > y1) {
			b[x1][y1] = 0;
			x1--;
			y1++;
			if (b[x1][y1] == 1)
				piecesGained++;
			b[x1][y1] = 2;
		} else {
			b[x1][y1] = 0;
			x1--;
			y1--;
			if (b[x1][y1] == 1)
				piecesGained++;
			b[x1][y1] = 2;
		}
	}

	if (x2 == 0) {
		b[x2][y2] = 4;
	}

	x1 = x2;
	y1 = y2;

	bool flag = false;

	if (d2 == 2) {

		if ((y2 == 0 || y2 == 1) && (x2 > 1)) {

			if ((b[x2 - 1][y2 + 1] == 1 || b[x2 - 1][y2 + 1] == 3)
					&& (b[x2 - 2][y2 + 2] == 0)) {

				cout << "There is another piece to jump at " << "[" << x2 - 1
						<< "]" << "[" << y2 + 1 << "]." << endl;
				cout << "Enter " << "[" << x2 - 2 << "]" << "[" << y2 + 2
						<< "]." << endl;

				flag = true;
			}

		} else if ((y2 == 6 || y2 == 7) && (x2 > 1)) {

			if ((b[x2 - 1][y2 - 1] == 1 || b[x2 - 1][y2 - 1] == 3)
					&& (b[x2 - 2][y2 - 2] == 0)) {

				cout << "There is another piece to jump at " << "[" << x2 - 1
						<< "]" << "[" << y2 - 1 << "]." << endl;
				cout << "Enter " << "[" << x2 - 2 << "]" << "[" << y2 - 2
						<< "]." << endl;
				flag = true;
			}

		} else if (((b[x2 - 1][y2 + 1] == 1 || b[x2 - 1][y2 + 1] == 3)
				&& (b[x2 - 2][y2 + 2] == 0)) && (x2 > 1)) {

			cout << "There is another piece to jump at " << "[" << x2 - 1 << "]"
					<< "[" << y2 + 1 << "]." << endl;
			cout << "Enter " << "[" << x2 - 2 << "]" << "[" << y2 + 2 << "]."
					<< endl;
			flag = true;

		} else if (((b[x2 - 1][y2 - 1] == 1 || b[x2 - 1][y2 - 1] == 3)
				&& (b[x2 - 2][y2 - 2] == 0)) && (x2 > 1)) {

			cout << "There is another piece to jump at " << "[" << x2 - 1 << "]"
					<< "[" << y2 - 1 << "]." << endl;
			cout << "Enter " << "[" << x2 - 2 << "]" << "[" << y2 - 2 << "]."
					<< endl;

			flag = true;
		}

	}

	return flag;

}

int Player::updateBoard3(void) {

	//bx = x1;
	//by = y1;

	int pG = 0;

	while (x1 != x2) {

		b[x1][y1] = 0;

		if (x1 < x2) {
			x1 += 1;
		} else {
			x1 -= 1;
		}

		if (y1 < y2) {
			y1 += 1;
		} else {
			y1 -= 1;
		}

		if (b[x1][y1] == 2 || b[x1][y1] == 4) {
			piecesGained++;
			pG++;
		}

		b[x1][y1] = 3;

	}

	return pG;

}

int Player::updateBoard4(void) {

	//bx = x1;
	//by = y1;

	int pG = 0;

	while (x1 != x2) {

		b[x1][y1] = 0;

		if (x1 < x2) {
			x1 += 1;
		} else {
			x1 -= 1;
		}

		if (y1 < y2) {
			y1 += 1;
		} else {
			y1 -= 1;
		}

		if (b[x1][y1] == 1 || b[x1][y1] == 3) {
			piecesGained++;
			pG++;
		}

		b[x1][y1] = 4;

	}

	return pG;

}

////////////////////////////////////////////////////////////////////////////

int main() {

	Player p1(0);
	Player p2(0);
	Board b1;
	b1.showBoard();

	cout << "GAME OF CHECKERS:" << endl;
	cout << "" << endl;

	while (true) {

		if (p1.piecesGained == 12 || p2.piecesGained == 12) {

			if (p1.piecesGained == 12) {
				cout << endl;
				cout << "Player one is the winner! Congratulations." << endl;
			} else {
				cout << endl;
				cout << "Player two is the winner! Congratulations." << endl;
			}
			cout << "Thanks for playing." << endl;
			break;
		}

		if (turn % 2 == 0) {

			cout << "It is player one's turn." << endl;
			cout << "You have " << p1.piecesGained
					<< "/12 pieces in possession." << endl;

			while (true) {
				cout << "Enter the piece to move." << endl;
				cout << "x coordinate: ";
				cin >> p1.x1;
				cout << "y coordinate: ";
				cin >> p1.y1;

				if (p1.x1 > 7 || p1.y1 > 7 || p1.x1 < 0 || p1.y1 < 0
						|| b[p1.x1][p1.y1] == 2 || b[p1.x1][p1.y1] == 4
						|| b[p1.x1][p1.y1] == 0) {
					cout
							<< "These are invalid entries. Please enter new coordinates."
							<< endl;
					cout << endl;
				} else {
					break;
				}
			}

			cout << endl;
			int diff1 = 0;
			int diff2 = 0;

			if (b[p1.x1][p1.y1] == 3) {

				char response = 'y';
				int c = 0;

				while (response == 'y' || response != 'Y') {

					if (c != 0) {
						cout << "Would you like to move the king piece? ";
						cin >> response;
						cout << endl;
					}
					c++;

					if (response == 'n' || response == 'N') {
						break;
					}

					while (true) {
						cout << "Enter the coordinates of your new square."
								<< endl;
						cout << "x coordinate: ";
						cin >> p1.x2;
						cout << "y coordinate: ";
						cin >> p1.y2;

						diff1 = abs(p1.x1 - p1.x2);
						diff2 = abs(p1.y1 - p1.y2);

						if (p1.x2 > 7 || p1.y2 > 7 || p1.x2 < 0 || p1.y2 < 0
								|| b[p1.x2][p1.y2] != 0 || diff1 > 2
								|| diff2 > 2 || diff1 != diff2) {
							cout
									<< "These are invalid entries. Please enter new coordinates."
									<< endl;
							cout << endl;
						} else {
							break;
						}
					}

					if (p1.updateBoard3() != 0) {

						p1.showBoard();
						continue;

					} else {
						break;
					}
				}

				turn++;
				p1.showBoard();
				cout << endl;

			} else {

				int diff1 = 0;
				int diff2 = 0;

				while (true) {
					while (true) {
						cout << "Enter the coordinates of your new square."
								<< endl;
						cout << "x coordinate: ";
						cin >> p1.x2;
						cout << "y coordinate: ";
						cin >> p1.y2;

						diff1 = p1.x2 - p1.x1;
						diff2 = abs(p1.y2 - p1.y1);

						if (p1.x2 > 7 || p1.y2 > 7 || p1.x2 < 0 || p1.y2 < 0
								|| b[p1.x2][p1.y2] != 0 || p1.x2 <= p1.x1
								|| diff1 > 2 || diff2 > 2 || diff1 != diff2) {
							cout
									<< "These are invalid entries. Please enter new coordinates."
									<< endl;
							cout << endl;
						} else {
							break;
						}
					}

					if (p1.updateBoard1(diff1, diff2)) {
						continue;
					} else {
						cout << endl;
						p1.showBoard();
						turn++;
						break;
					}
				}
			}

		} else {

			cout << "It is player two's turn. " << endl;
			cout << "You have " << p2.piecesGained
					<< "/12 pieces in possession." << endl;

			while (true) {
				cout << "Enter the piece to move." << endl;
				cout << "x coordinate: ";
				cin >> p2.x1;
				cout << "y coordinate: ";
				cin >> p2.y1;

				if (p2.x1 > 7 || p2.y1 > 7 || p2.x1 < 0 || p2.y1 < 0
						|| b[p2.x1][p2.y1] == 1 || b[p2.x1][p2.y1] == 3
						|| b[p2.x1][p2.y1] == 0) {
					cout
							<< "These are invalid entries. Please enter new coordinates."
							<< endl;
					cout << endl;
				} else {
					break;
				}
			}

			cout << endl;

			if (b[p2.x1][p2.y1] == 4) {

				char response = 'y';
				int c = 0;

				while (response == 'y' || response == 'Y') {

					if (c != 0) {
						cout << "Would you like to move the king piece? ";
						cin >> response;
						cout << endl;
					}
					c++;

					if (response == 'n' || response == 'N') {
						break;
					}

					int diff1 = 0;
					int diff2 = 0;

					while (true) {
						cout << "Enter the coordinates of your new square."
								<< endl;
						cout << "x coordinate: ";
						cin >> p2.x2;
						cout << "y coordinate: ";
						cin >> p2.y2;

						diff1 = abs(p2.x1 - p2.x2);
						diff2 = abs(p2.y1 - p2.y2);

						if (p2.x2 > 7 || p2.y2 > 7 || p2.x2 < 0 || p2.y2 < 0
								|| b[p2.x2][p2.y2] != 0 || diff1 > 2
								|| diff2 > 2 || diff1 != diff2) {
							cout
									<< "These are invalid entries. Please enter new coordinates."
									<< endl;
							cout << endl;
						} else {
							break;
						}
					}

					if (p2.updateBoard4() != 0) {

						p2.showBoard();
						continue;

					} else {
						break;
					}
				}

				turn++;
				p2.showBoard();
				cout << endl;

			} else {

				int diff1 = 0;
				int diff2 = 0;

				while (true) {
					while (true) {
						cout << "Enter the coordinates of your new square."
								<< endl;
						cout << "x coordinate: ";
						cin >> p2.x2;
						cout << "y coordinate: ";
						cin >> p2.y2;

						diff1 = p2.x1 - p2.x2;
						diff2 = abs(p2.y2 - p2.y1);

						if (p2.x2 > 7 || p2.y2 > 7 || p2.x2 < 0 || p2.y2 < 0
								|| b[p2.x2][p2.y2] != 0 || p2.x1 <= p2.x2
								|| diff1 > 2 || diff2 > 2 || diff1 != diff2) {
							cout
									<< "These are invalid entries. Please enter new coordinates."
									<< endl;
							cout << endl;
						} else {
							break;
						}
					}

					if (p2.updateBoard2(diff1, diff2) == true) {
						continue;
					} else {
						cout << endl;
						p2.showBoard();
						turn++;
						break;
					}
				}

			}

		}
	}
}












