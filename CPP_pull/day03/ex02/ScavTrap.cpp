#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	_name = "noname";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "A noname ScavTrap created  with default constructor" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "A new ScavTrap created : " << _name << std::endl;
}

ScavTrap::~ScavTrap(void) {
		std::cout << _name << "ScavTrap removed" << std::endl;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &op) {
if (this != &op) {
		_name = op._name;
		_hitPoints = op._hitPoints;
		_energyPoints = op._energyPoints;
		_attackDamage = op._attackDamage;
	}
	return *this;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap::ClapTrap(copy) {
	// *this = copy;
}

void ScavTrap::attack(std::string const target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " \
		<< _attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ScavTrap " << _name << "i can't attack" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" \
	<< std::endl;
}

void ScavTrap::demo(void) {
	std::cout << "#######################################" << std::endl;
	std::cout << "ScavTrap name : " << _name << std::endl;
	std::cout << _name << " Health point : " << _hitPoints << std::endl;
	std::cout << _name << " Damage level : " << _attackDamage << std::endl;
	std::cout << _name << " Energy point : " << _energyPoints << std::endl;
	std::cout << "#######################################" << std::endl;
}