#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < INV; ++i) {
		_base[i] = NULL;
	}
	std::cout << "MateriaSource : default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	*this = copy;
	std::cout << "MateriaSource : copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator = (const MateriaSource& op) {
	if (this != &op) {
		for (int i = 0; i < INV; ++i) {
			if (_base[i]) {
				delete	_base[i];
			} 
			if (op._base[i]) {
				_base[i] = op._base[i]->clone();
			} else {
				_base[i] = NULL;
			}
		}
	}
	return	*this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < INV; ++i) {
		if (_base[i]) {
			delete _base[i];
		}
	}
	std::cout << "MateriaSource : default destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* input) {
	if (input) {
		for (int i = 0; i < INV; ++i) {
			if (!_base[i]) {
				_base[i] = input;
				break ;
			}
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < INV; ++i) {
		if (_base[i]->getType() == type) {
			return _base[i]->clone();
		}
	}
	return	NULL;
}