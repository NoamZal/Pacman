#pragma once
#include "Utility.h"
#include "Point.h"
#include "Board.h"

class Board;
class Pacman;

class Ghost {

	Point point;
	char sign = GSIGN;
	char m_direction;


public:
	Ghost();
	void setPoint(int x, int y);
	Point getPoint() const;
	char getSign()const;

	void moveGhost(Board& b);
	Point getNextMove(char key);
	bool isGhostNextMoveIsValid(Board b, char key);

};