#include "Ghost.h"

void Ghost::setPoint(int x, int y) {
	point.setPoint(x, y);
}
Point Ghost::getPoint() const {
	return point;
}
char Ghost::getSign() const {
	return sign;
}
void Ghost::moveGhost(Board& b)
{
	/*bool validMove;
	Point nP;
	nP = getNextMove(m_direction);
	isGhostNextMoveIsValid(b, m_direction);
	*/
	int 
	switch (m_direction)
	{
	case RIGHT1:
	{
		
		point.setPoint(row, col + 1);
	}
	}
}
Point Ghost::getNextMove(char key)
{
	Point nP;
	int row = point.getPointX();
	int col = point.getPointY();
	switch (key)
	{
	case RIGHT1:
		nP.setPoint(row, col + 1);
		break;

	case LEFT1:
		nP.setPoint(row, col - 1);
		break;

	case DOWN1:
		nP.setPoint(row + 1, col);
		break;

	case UP1:
		nP.setPoint(row - 1, col);
		break;
	}
	return nP;
}
bool Ghost::isGhostNextMoveIsValid(Board b, char key)
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
	if (b.getPointofBoard(nRow, nCol) == SPECIAL_TUNNEL) {
		return false;
	}
	return true;
}
Ghost::Ghost() {
	point.setPoint(10, 10);
}