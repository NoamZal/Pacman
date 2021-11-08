#pragma once
#include "Utility.h"
#include "Pacman.h"
#include "Ghost.h"


class Pacman;
class Ghost;

class Board {
private:

	char board[ROWS][COLS];

public:

	void initBoardToStart(Pacman& p, Ghost g1, Ghost g2);
	void setBreadcrumbs();
	void setPacman(Pacman& p);
	void setWalls();
	void setGhosts(Ghost g1, Ghost g2);
	void printBoard() const;
	void clrscr();
	void gotoxy(int x, int y);
	void updateBoard(int x, int y, char ch);
	char getPointofBoard(int row, int col);

};