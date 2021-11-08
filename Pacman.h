#pragma once
#include "Utility.h"
#include "Point.h"
#include "Board.h"

class Board;
class Ghost;

class Pacman {

private:
	Point point;
	char sign = SIGN;
	int lives = LIVES;

	int crumbsCounter = 0;

public:
	Pacman();
	void setPoint(int x, int y);
	Point getPoint() const;
	void lowerLive();
	char getSign()const;
	int getLives()const;
	int getCrumbsCounter()const;

	void movePacman(Board& b, char key);
	Point getNextMove(char key);
	bool isPacmanNextMoveIsValid(Board b, char key);
};