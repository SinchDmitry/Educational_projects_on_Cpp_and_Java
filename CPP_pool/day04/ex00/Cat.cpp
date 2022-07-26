#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	std::cout <<  "cat default constructor" << std::endl;
}

Cat::~Cat() {
	std::cout <<  "cat default destructor" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal::Animal(copy) {
	*this = copy;
}

Cat	&Cat::operator = (const Cat &op) {
	if (this != &op) {
		_type = op._type;
	}
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "*! Ya kot, a ne hleb. Ne esh, podumoy !*" << std::endl;
}

const std::string	&Cat::getType() const {
	return _type;
}