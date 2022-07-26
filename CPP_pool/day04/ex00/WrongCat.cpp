#include "WrongCat.hpp"

WrongCat::WrongCat() {
	_type = "WrongCat";
	std::cout <<  "wrongcat default constructor" << std::endl;

}

WrongCat::~WrongCat() {
	std::cout <<  "wrongcat default destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal::WrongAnimal(copy){
	*this = copy;
}

WrongCat	&WrongCat::operator = (const WrongCat &op) {
	if (this != &op) {
		_type = op._type;
	}
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "*! Ya kot, a ne hleb. Ne esh, podumoy !*" << std::endl;
}

const std::string	&WrongCat::getType() const {
	return _type;
}