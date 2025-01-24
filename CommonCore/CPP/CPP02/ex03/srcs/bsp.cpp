#include "../includes/Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point) {
	Fixed p1 = point.getX();
	Fixed p2 = point.getY();
	Fixed a1 = a.getX();
	Fixed a2 = a.getY();
	Fixed b1 = b.getX();
	Fixed b2 = b.getY();
	Fixed c1 = c.getX();
	Fixed c2 = c.getY();
	Fixed cross1 = (b1 - a1) * (p2 - a2) - (b2 - a2) * (p1 - a1);
	Fixed cross2 = (c1 - b1) * (p2 - b2) - (c2 - b2) * (p1 - b1);
	Fixed cross3 = (a1 - c1) * (p2 - c2) - (a2 - c2) * (p1 - c1);
	if ((cross1 > 0 && cross2 > 0 && cross3 > 0) || (cross1 < 0 && cross2 < 0 && cross3 < 0))
		return true;
	return false;
}
