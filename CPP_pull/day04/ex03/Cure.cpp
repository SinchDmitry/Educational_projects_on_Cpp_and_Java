#include "Cure.hpp"

Cure::Cure(void) : AMateria::AMateria("cure") {
}

Cure::~Cure(void) {
}

Cure::Cure(const Cure& copy) : AMateria::AMateria(copy) {
	*this = copy;
}

Cure& Cure::operator = (const Cure& op) {
	if (this != &op) {
		_type = op._type;
	}
	return *this;
}

const std::string& Cure::getType() const {
	return	_type;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() \
	<< "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure();
}