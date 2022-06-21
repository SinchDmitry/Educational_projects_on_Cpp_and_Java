#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon) {
	this->_name = name;
}

HumanA::~HumanA(void) {	
}

void	HumanA::attack(void) const {
	std::cout <<  this->_name << " attacks with their " << \
		this->_weapon.getType() << std::endl;
}

Weapon&	HumanA::getWeapon( void ) const {
	return this->_weapon;
}