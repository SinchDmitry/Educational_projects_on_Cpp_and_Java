#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB(void) {	
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void	HumanB::attack(void) const {
	if (this->_weapon) {
		std::cout <<  this->_name << " attacks with their " << \
			this->_weapon->getType() << std::endl;
	} else {
		std::cout <<  this->_name << " i'm retard and have no weapon" \
			<< std::endl;
	}
}
