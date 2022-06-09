#include "Ice.hpp"

Ice::Ice(void) : AMateria::AMateria("ice") {
}

Ice::~Ice(void) {
}

Ice::Ice(const Ice& copy) : AMateria::AMateria(copy) {
	*this = copy;
}

Ice& Ice::operator = (const Ice &op) {
	if (this != &op) {
		_type = op._type;
	}
	return *this;
}

const std::string& Ice::getType() const {
	return	_type;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() \
		<< " *" << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice();
}