#include "../includes/Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y) {}
Point::Point(const Point &point) : _x(point.getX()), _y(point.getY()) {}
Point::~Point() {}
Point &Point::operator=(const Point &point) {
	_x = point.getX();
	_y = point.getY();
	return *this;
}

Fixed Point::getX(void) const {return _x;}
Fixed Point::getY(void) const {return _y;}
