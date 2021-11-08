#include "Point.h"

void Point::setPoint(int x_, int y_)
{
	x = x_;
	y = y_;
}
int Point::getPointX() const {
	return x;
}
int Point::getPointY() const {
	return y;
}