#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout <<  "animal default constructor" << std::endl;
}

Animal::~Animal() {
	std::cout <<  "animal default destructor" << std::endl;

}

Animal::Animal(const Animal &copy) {
	*this = copy;
}

Animal	&Animal::operator = (const Animal &op) {
	if (this != &op) {
		_type = op._type;
	}
	return *this;
}

const std::string	&Animal::getType() const {
	return _type;
}