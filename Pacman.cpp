#include "Pacman.h"

void Pacman::setPoint(int x, int y)
{
	point.setPoint(x, y);
}
Point Pacman::getPoint()const
{
	return point;
}
void Pacman::lowerLive() {
	lives = lives - 1;
}
char Pacman::getSign()const {
	return sign;
}
Pacman::Pacman() {
	point.setPoint(2, 2);
}
int Pacman::getLives()const {
	return lives;
}
int Pacman::getCrumbsCounter()const {
	return crumbsCounter;
}

void Pacman::movePacman(Board& b, char key) {
	int row = point.getPointX();
	int col = point.getPointY();

	switch (key)
	{
	case RIGHT1:
	case RIGHT2:
		point.setPoint(row, col + 1);
		if (b.getPointofBoard(row, col + 1) == BREADCRUMB)
		{
			crumbsCounter++;
		}
		b.updateBoard(row, col + 1, sign);
		break;

	case LEFT1:
	case LEFT2:
		point.setPoint(row, col - 1);
		if (b.getPointofBoard(row, col - 1) == BREADCRUMB)
		{
			crumbsCounter++;
		}
		b.updateBoard(row, col - 1, sign);
		break;

	case DOWN1:
	case DOWN2:
		point.setPoint(row + 1, col);
		if (b.getPointofBoard(row + 1, col) == BREADCRUMB)
		{
			crumbsCounter++;
		}
		b.updateBoard(row + 1, col, sign);
		break;

	case UP1:
	case UP2:
		point.setPoint(row - 1, col);
		if (b.getPointofBoard(row - 1, col) == BREADCRUMB)
		{
			crumbsCounter++;
		}
		b.updateBoard(row - 1, col, sign);
		break;

	}
	if (key != ESC)
		b.updateBoard(row, col, BLANK);

}
bool Pacman::isPacmanNextMoveIsValid(Board b, char key)
{
	Point pNext;
	pNext = getNextMove(key);
	int pRow = point.getPointX();
	int pCol = point.getPointY();
	int nRow = pNext.getPointX();
	int nCol = pNext.getPointY();
	if (b.getPointofBoard(nRow, nCol) == WALL) {
		return false;
	}


	return true;
}

Point Pacman::getNextMove(char key) {
	Point nP;
	int row = point.getPointX();
	int col = point.getPointY();
	switch (key)
	{

	case STAY1:
	case STAY2:
		nP.setPoint(row, col);
		break;

	case RIGHT1:
	case RIGHT2:
		nP.setPoint(row, col + 1);
		break;

	case LEFT1:
	case LEFT2:
		nP.setPoint(row, col - 1);
		break;

	case DOWN1:
	case DOWN2:
		nP.setPoint(row + 1, col);
		break;

	case UP1:
	case UP2:
		nP.setPoint(row - 1, col);
		break;

	case ESC:
		nP.setPoint(row, col);
		break;

	}
	return nP;
}