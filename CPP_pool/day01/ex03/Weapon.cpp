#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) {
	this->_weapon = weapon;
}

Weapon::~Weapon(void) {
}

void	Weapon::setType(const std::string &type) {
	if (type != "") {
		this->_weapon = type;
	}
}

const std::string	&Weapon::getType(void) const {
	return this->_weapon;
}