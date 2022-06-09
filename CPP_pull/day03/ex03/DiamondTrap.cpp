#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
	_name = "noname";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "A noname DiamondTrap created  with default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap("suffix" + name) {
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "A new DiamondTrap created : " << _name << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
		std::cout << _name << "DiamondTrap removed" << std::endl;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &op) {
if (this != &op) {
		_name = op._name;
		_hitPoints = op._hitPoints;
		_energyPoints = op._energyPoints;
		_attackDamage = op._attackDamage;
	}
	return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap::ClapTrap(copy), FragTrap::FragTrap(copy), ScavTrap::ScavTrap(copy) {
	// *this = copy;
}

void DiamondTrap::attack(std::string const target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		_energyPoints--;
		std::cout << "DiamondTrap " << _name << " attacks " << target << ", causing " \
		<< _attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "DiamondTrap " << _name << "i can't attack" << std::endl;
	}
}

void DiamondTrap::hiMyNameIs() {
	std::cout << "It's me - " << _name << std::endl;
	std::cout << "It's my grandpa - " << ClapTrap::_name << std::endl;
}

void DiamondTrap::demo(void) {
	std::cout << "#######################################" << std::endl;
	std::cout << "DiamondTrap name : " << _name << std::endl;
	std::cout << _name << " Health point : " << _hitPoints << std::endl;
	std::cout << _name << " Damage level : " << _attackDamage << std::endl;
	std::cout << _name << " Energy point : " << _energyPoints << std::endl;
	std::cout << "#######################################" << std::endl;
}