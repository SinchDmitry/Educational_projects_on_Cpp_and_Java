#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	_hitPoints = 120;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "A noname FragTrap created  with default constructor" << std::endl;
}

FragTrap::FragTrap(const std::string name) {
	_name = name;
	_hitPoints = 120;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "A new FragTrap created : " << _name << std::endl;
}

FragTrap::~FragTrap(void) {
		std::cout << _name << "FragTrap removed" << std::endl;
}

FragTrap &FragTrap::operator = (const FragTrap &op) {
if (this != &op) {
		_name = op._name;
		_hitPoints = op._hitPoints;
		_energyPoints = op._energyPoints;
		_attackDamage = op._attackDamage;
	}
	return *this;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap::ClapTrap(copy) {
	// *this = copy;
}

void FragTrap::attack(std::string const target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		_energyPoints--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " \
		<< _attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "FragTrap " << _name << "i can't attack" << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	std::cout << "Just do it, bro! High Five!" << std::endl;
}

void FragTrap::demo(void) {
	std::cout << "#######################################" << std::endl;
	std::cout << "FragTrap name : " << _name << std::endl;
	std::cout << _name << " Health point : " << _hitPoints << std::endl;
	std::cout << _name << " Damage level : " << _attackDamage << std::endl;
	std::cout << _name << " Energy point : " << _energyPoints << std::endl;
	std::cout << "#######################################" << std::endl;
}