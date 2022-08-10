#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
	_name = "noname";
	setHit(FragTrap::_hitPoints);
	setEnergy(ScavTrap::_energyPoints);
	setDamage(FragTrap::_attackDamage);
	std::cout << "A noname DiamondTrap created with default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap("suffix" + name) {
	_name = name;
	setHit(FragTrap::_hitPoints);
	setEnergy(ScavTrap::_energyPoints);
	setDamage(FragTrap::_attackDamage);
	std::cout << "A new DiamondTrap created : " << _name << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
		std::cout << _name << "DiamondTrap removed" << std::endl;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &op) {
if (this != &op) {
		setHit(FragTrap::_hitPoints);
		setEnergy(ScavTrap::_energyPoints);
		setDamage(FragTrap::_attackDamage);
		_name = op._name;
	}
	return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap::ClapTrap(copy), FragTrap::FragTrap(copy), ScavTrap::ScavTrap(copy) {
	// *this = copy;
}

void DiamondTrap::attack(std::string const target) {
	if (getHit() > 0 && getEnergy() > 0) {
		int tmpEnergyPoint = getEnergy();
		setEnergy(tmpEnergyPoint--);
		std::cout << "DiamondTrap " << _name << " attacks " << target << ", causing " \
		<< getHit() << " points of damage!" << std::endl;
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
	std::cout << _name << " Health point : " << getHit() << std::endl;
	std::cout << _name << " Damage level : " << getDamage() << std::endl;
	std::cout << _name << " Energy point : " << getEnergy() << std::endl;
	std::cout << "#######################################" << std::endl;
}