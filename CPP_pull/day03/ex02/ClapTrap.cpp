#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	_name = "noname";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "A noname ClapTrap created  with default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "A new ClapTrap created : " << _name << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << _name << "ClapTrap removed" << std::endl;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &op){
	if (this != &op) {
		_name = op._name;
		_hitPoints = op._hitPoints;
		_energyPoints = op._energyPoints;
		_attackDamage = op._attackDamage;
	}
	return *this;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	*this = copy;
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints > 0 && _energyPoints > 0) {
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " \
		<< _attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << _name << "i can't attack" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	_hitPoints -= amount;
	if (_hitPoints < 0) {
		_hitPoints = 0;
	}
	std::cout << _name << " was attack and lost " \
		<< amount << " health points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints > 0) {
		_energyPoints--;
	}
	_hitPoints += amount;
	std::cout << _name << " repares itself on " \
		<< amount << " health points" << std::endl;
}

const int	&ClapTrap::getDamageLevel(void) const {
	const int	&tmp = _attackDamage;
	return tmp;
}

void	ClapTrap::setDamageLevel(int damage) {
	_attackDamage = damage;
}

void ClapTrap::demo(void) {
	std::cout << "#######################################" << std::endl;
	std::cout << "ClapTrap name : " << _name << std::endl;
	std::cout << _name << " Health point : " << _hitPoints << std::endl;
	std::cout << _name << " Damage level : " << _attackDamage << std::endl;
	std::cout << _name << " Energy point : " << _energyPoints << std::endl;
	std::cout << "#######################################" << std::endl;
}