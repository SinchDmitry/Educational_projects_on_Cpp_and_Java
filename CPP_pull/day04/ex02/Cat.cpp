#include "Cat.hpp"

Cat::Cat() {
	std::cout <<  "cat default constructor" << std::endl;
	_type = "Cat";
	b = new Brain;
}

Cat::~Cat() {
	delete	b;
	std::cout <<  "cat default destructor" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal::Animal(copy), b(NULL) {
	*this = copy;
	std::cout << "cat copy constructor" << std::endl;
}

Cat	&Cat::operator = (const Cat &op) {
	if (this != &op) {
		_type = op._type;
		if (b) {
			delete b;
		}
		b = new Brain(*op.b);
	}
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "*! Ya kot, a ne hleb. Ne esh, podumoy !*" << std::endl;
}

const std::string	&Cat::getType() const {
	return _type;
}