#include "Dog.hpp"

Dog::Dog() {
	std::cout <<  "dog default constructor" << std::endl;
	_type = "Dog";
	b = new Brain;
}

Dog::~Dog() {
	delete b;
	std::cout <<  "dog default destructor" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal::Animal(copy), b(NULL) {
	*this = copy;
	std::cout << "dog copy constructor" << std::endl;
}

Dog	&Dog::operator = (const Dog &op) {
	if (this != &op) {
		_type = op._type;
		if (b) {
			delete b;
		}
		b = new Brain(*op.b);
	}
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "*! How good I am, how powerful my paws are !*" << std::endl;
}

const std::string	&Dog::getType() const {
	return _type;
}