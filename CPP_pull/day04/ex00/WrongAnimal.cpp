#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout <<  "wronganimal default constructor" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout <<  "wronganimal default destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	*this = copy;
}

WrongAnimal	&WrongAnimal::operator = (const WrongAnimal &op) {
	if (this != &op) {
		_type = op._type;
	}
	return *this;
}

void	WrongAnimal::makeSound() const {
	std::cout << "* sounds of all animals at once *" << std::endl;
}

const std::string	&WrongAnimal::getType() const {
	return _type;
}