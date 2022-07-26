#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : _name("unit") {
	for (int i = 0; i < INV; ++i) {
		_bank[i] = NULL;
	}
	std::cout << "Character : default constructor called" << std::endl;
}

Character::Character(std::string name) :  _name(name) {
	for (int i = 0; i < INV; ++i) {
		_bank[i] = NULL;
	}
	std::cout << "Character " << _name << " : name constructor called" << std::endl;
}

Character::~Character() {
	for (int i = 0; i < INV; ++i) {
		if (_bank[i]) {
			delete _bank[i];
		}
	}
	std::cout << "Character " << _name << " : default destructor called" << std::endl;
}

Character::Character(const Character& copy) {
	*this = copy;
	std::cout << "Character : copy constructor called" << std::endl;
}

Character& Character::operator = (const Character& op) {
	if (this != &op) {
		for (int i = 0; i < INV; ++i) {
			if (_bank[i]) {
				delete	_bank[i];
			} 
			if (op._bank[i]) {
				_bank[i] = op._bank[i]->clone();
			} else {
				_bank[i] = NULL;
			}
		}
	}
	_name = op._name;
	return	*this;
}

const std::string& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (m) {
		for (int i = 0; i < INV; ++i) {
			if (!_bank[i]) {
				_bank[i] = m;
				break ;
			}
		}
	}
}

void Character::unequip(int idx) {
	if (idx < INV && _bank[idx]) {
		delete	_bank[idx];
		_bank[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < INV) {
		_bank[idx]->use(target);
	}
}
