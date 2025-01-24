#include "../includes/Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point(const float x, const float y) : _x(x), _y(y) {}
Point::Point(const Point &point) : _x(point.getX()), _y(point.getY()) {}
Point &Point::operator=(const Point &point) {
	(void)point;
	return *this;
}
Point::~Point() {}

Fixed Point::getX(void) const {return _x;}
Fixed Point::getY(void) const {return _y;}
