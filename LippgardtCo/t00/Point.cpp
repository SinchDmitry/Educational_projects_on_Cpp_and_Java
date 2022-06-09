#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
}

Point::~Point(void) {
}

Point::Point(const double a, const double b) : _x(a), _y(b) {
}

Point::Point(const Point& copy) : _x(copy._x), _y(copy._y) {
}

Point &Point::operator = (const Point& op) {
	if (this != &op) {
		_x = op._x;
		_y = op._y;
	}
	return *this;
}

const double& Point::getX(void) const {
    return _x;
}

const double& Point::getY(void) const {
    return _y;
}

std::ostream&	operator << (std::ostream& out, Point const& other) {
	out << "Point with x : " << other.getX() << " , y : " << other.getY() << std::endl;
	return out;
}

void	Point::setParam(const double a, const double b) {
	_x = a;
	_y = b;
}

bool	Point::setInputParam() {
	std::string	tmp;
	try {
		std::cout << "Input x: " << std::flush;
		std::getline(std::cin, tmp);
		_x = std::stod(tmp);
		std::cout << "Input y: " << std::flush;
		std::getline(std::cin, tmp);
		_y = std::stod(tmp);
		return	0;
	} catch (std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
		return	1;
	} catch (std::out_of_range& e) {
		std::cout << e.what() << std::endl;
		return	1;
	}
}