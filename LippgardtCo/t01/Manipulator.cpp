#include "Manipulator.hpp"
#include <sstream>

Manipulator::Manipulator() : 
	_name("no_name"),
	_manipPoint(),
	_basePoint(),
	_rad(1),
	_dist(0) {}

Manipulator::Manipulator(std::string nombre) : 
	_name(nombre),
	_manipPoint(),
	_basePoint(),
	_rad(1),
	_dist(0) {}

Manipulator::Manipulator(std::string nombre, double x, double y, double rad) : 
	_name(nombre),
	_manipPoint(x, y), 
	_basePoint(x, y),
	_rad(rad),
	_dist(0) {}

Manipulator::Manipulator(const Manipulator& copy) {
	*this = copy;
}

Manipulator& Manipulator::operator = (const Manipulator& op) {
	if (this != &op) {
		_manipPoint = op._manipPoint;
		_rad = op._rad;
	}
	return *this;
}

void	Manipulator::reInit() {
	_pointsMap.clear();
}

double	Manipulator::getDist(const Point &q) {
	_dist = sqrt(pow((q.getX() - _manipPoint.getX()), 2) + pow((q.getY() - _manipPoint.getY()), 2));
	// if (_dist > _rad) { 
	// 	_dist = -1;
	// }
	return _dist;
}

void	Manipulator::moveToPoint(const Point &q) {
	_manipPoint.setParam(q.getX(), q.getY());
}

// bool	Manipulator::moveToNearestPoint(const Point &q, Manipulator& otherManip, const int &i) {
void	Manipulator::moveToNearestPoint(const Point &q, Manipulator& otherManip, const int &i) {
	if (!this->cmpDist(otherManip, q, 0)) {
		_manipPoint.setParam(q.getX(), q.getY());
		_pointsMap.insert({ i, q });
	} else if (this->cmpDist(otherManip, q, 0) == 1) {
		otherManip._manipPoint.setParam(q.getX(), q.getY());
		otherManip._pointsMap.insert({ i, q });
	} 
	// return	0;
}

const std::string Manipulator::dtos(const double& x) {
    std::stringstream s;
    s << x;
    return s.str();
}

void	Manipulator::pointsDemo(const int &i) {
	std::map<int, Point>::iterator search = _pointsMap.find(i);
	if (search != _pointsMap.end()) {
		std::cout.width(13);
		std::string	output = "{" + dtos(search->second.getX()) + ", " \
			+ dtos(search->second.getY()) + "}";
		std::cout << output << " | ";
	} else {
		std::cout << "-------------" << " | ";
	}
}

const Point& Manipulator::getPoint() const {
    return _manipPoint;
}

double Manipulator::getRad() const {
    return _rad;
}

const std::string&	Manipulator::getName() const {
	return _name;
}

bool	Manipulator::setInputParam() {
	std::string	tmp;
	try {
		std::cout << "Waiting for info about " << _name << " manipulator : [coordinate X, coordinate Y, radius]: " << std::endl;
		_manipPoint.setInputParam();
		std::cout << "Input radius: " << std::flush;
		std::getline(std::cin, tmp);
		_rad = std::stod(tmp);
		return	0;
	} catch (std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
		return	1;
	} catch (std::out_of_range& e) {
		std::cout << e.what() << std::endl;
		return	1;
	}
}

int	Manipulator::cmpDist(Manipulator& otherManip, const Point &o, bool out) {
	// if (this->getDist(o) >= 0 || otherManip.getDist(o) >= 0) {
		if (out) { std::cout << o << " is target for "; }
		if (this->getDist(o) <= otherManip.getDist(o)) {
			if (out) { std::cout << this->getName() << std::endl;}
			return 0;
		} else {
			if (out) { std::cout << otherManip.getName() << std::endl; }
			return 1;
		}
	// }
	// } else {
	// 	if (out) { std::cout << "OUT IF RANGE!" << std::endl; }
		return -1;
	// }
}

std::ostream&	operator << (std::ostream& out, Manipulator const& other) {
	out << other.getName() << " manipulator stand in x : " << other.getPoint().getX() << " , y : " 
		<< other.getPoint().getY() << " , his action radius : " << other.getRad() << std::endl;
	return out;
}
