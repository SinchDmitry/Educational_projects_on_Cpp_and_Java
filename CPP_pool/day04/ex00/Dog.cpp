#include "Dog.hpp"

Dog::Dog() {
	_type = "Dog";
	std::cout <<  "dog default constructor" << std::endl;
}

Dog::~Dog() {
	std::cout <<  "dog default destructor" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal::Animal(copy){
	*this = copy;
}

Dog	&Dog::operator = (const Dog &op) {
	if (this != &op) {
		_type = op._type;
	}
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "*! How good I am, how powerful my paws are !*" << std::endl;
}

const std::string	&Dog::getType() const {
	return _type;
}