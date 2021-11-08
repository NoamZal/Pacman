#include "Game.h"

int Game::getKey() {
	// This function gets keyCodes for special keys such as arrows , escape and others
	// It returns the Key code such as 72 for arrow up, 27 for Escape... 
	char KeyStroke = _getch();
	if (KeyStroke == 0 || KeyStroke == -32)
		KeyStroke = _getch();
	return (KeyStroke);
}

void Game::startGame()
{
	bool alive;
	char key = RIGHT1;
	Pacman p;
	Board b;
	Ghost g1;
	Ghost g2;
	int menuChoice;

	b.initBoardToStart(p, g1, g2);
	Menu(b);

	while (!_kbhit()); // wait untill a key is pressed
	alive = true;



	while (p.getLives() > 0)
	{

		int x = p.getPoint().getPointX();
		int y = p.getPoint().getPointY();
		Sleep(100);	// sleeps for less than half a second before continuing to the next command
		if (_kbhit()) // if any key was hit
			key = getKey();  // change direction
		if (isValidkey(key) && (p.isPacmanNextMoveIsValid(b, key)))
			if (key != STAY1 && key != STAY2)
				p.movePacman(b, key);
		if (key == ESC) {
			pauseGame(b);
			key = STAY1;
		}





		b.gotoxy(24, 30);
		cout << "Lives : " << p.getLives();
		cout << " Crumbs Eaten : " << p.getCrumbsCounter() << endl;


	}

}
void Game::pauseGame(Board b) {
	int key;
	system("cls");
	b.gotoxy(12, 15);
	cout << "Game paused, press ESC again to continue";
	while (!_kbhit()); // wait untill a key is pressed
	if (_kbhit()) // if any key was hit
		key = getKey();
	if (key == ESC) {
		system("cls");
		b.printBoard();
	}
}


void Game::print_Menu() {

	cout << "***************************************************" << endl << endl;
	cout << "                  WELCOME TO PACMAN " << endl << endl;
	cout << "                PLEASE CHOOSE OPTION : " << endl << endl;
	cout << "          (1) Start a new game" << endl << endl;
	cout << "          (8) Present instructions and keys" << endl << endl;
	cout << "          (9) EXIT" << endl << endl;
	cout << "***************************************************" << endl << endl;

}

void Game::Menu(Board b) {
	bool valid = false;
	int menuChoice;

	do {
		system("cls");
		print_Menu();
		cin >> menuChoice;
		if (menuChoice == 1) {
			system("cls");
			b.gotoxy(0, 0);
			b.printBoard();
			valid = true;
		}
		else if (menuChoice == 8) {
			system("cls");
			b.gotoxy(0, 0);
			printInstructions();

		}
		else if (menuChoice == 9) {
			cout << "It was a plassure, Bye!";
			exit(1);
		}
		else
		{
			system("cls");
			cout << "Invalid Choice!!!" << endl;

		}

	} while (!valid);

}
void Game::printInstructions() {
	cout << "***************************************************" << endl << endl;
	cout << "             Instructions and Keys - " << endl << endl;
	cout << "                                                   " << endl << endl;
	cout << "***************************************************" << endl << endl;
	cout << "             press any key to back to menu          " << endl << endl;


	while (!_kbhit());
}

bool Game::isValidkey(char key) {

	if (key == STAY1 || key == STAY2 ||
		key == RIGHT1 || key == RIGHT2 ||
		key == LEFT1 || key == LEFT2 ||
		key == UP1 || key == UP2 ||
		key == DOWN1 || key == DOWN2 ||
		key == ESC) {

		return true;
	}
	return false;
}
