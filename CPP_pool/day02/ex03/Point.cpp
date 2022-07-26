#include "Point.hpp"

Point::Point(void) {
}

Point::~Point(void) {
}

Point::Point(const float a, const float b) : _x(a), _y(b) {
	// _x.setRawBits(a);
	// _y.setRawBits(b);
}

Point::Point(const Point &copy) : _x(copy._x), _y(copy._y){
	// _x.setRawBits(copy._x.getRawBits());
	// _y.setRawBits(copy._y.getRawBits());
}

Point &Point::operator = (const Point &op) {
	if (this != &op) {
		_x.setRawBits(op._x.getRawBits());
		_y.setRawBits(op._y.getRawBits());
	}
	return *this;
}

const Fixed &Point::getX(void) const {
    return _x;
}

const Fixed &Point::getY(void) const {
    return _y;
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
    float   x1;
    float   x2;
    float   x3;

    x1 = (b.getX() - a.getX()).toFloat() * (p.getY() - a.getY()).toFloat() -
        (b.getY() - a.getY()).toFloat() * (p.getX() - a.getX()).toFloat();
    // std::cout << x1 << std::endl;
	x2 = (c.getX() - b.getX()).toFloat() * (p.getY() - b.getY()).toFloat() -
        (c.getY() - b.getY()).toFloat() * (p.getX() - b.getX()).toFloat();
    // std::cout << x2 << std::endl;
	x3 = ((a.getX() - c.getX()).toFloat() * (p.getY() - c.getY()).toFloat()) -
        (a.getY() - c.getY()).toFloat() * (p.getX() - c.getX()).toFloat();
	// std::cout << x3 << std::endl;
	if ((x1 > 0 && x2 > 0 && x3 > 0) || (x1 < 0 && x2 < 0 && x3 < 0))
        return (true);
    return (false);
}