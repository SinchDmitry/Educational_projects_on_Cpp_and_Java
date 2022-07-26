#include "AMateria.hpp" 

AMateria::AMateria(void) : _type("materia") {
}

AMateria::AMateria(const std::string& type) : _type(type) {
}

AMateria::~AMateria(void) {
}

AMateria::AMateria(const AMateria& copy) {
	*this = copy;
}

AMateria& AMateria::operator = (const AMateria &op) {
	if (this != &op) {
		_type = op._type;
	}
	return *this;
}

const std::string& AMateria::getType() const {
	return	_type;
}

void AMateria::use(ICharacter& target) {
	std::cout << target.getName() << std::endl;
}