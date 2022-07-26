#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void) {
	ClapTrap a("playerOne");
	ScavTrap b("slave");
	FragTrap c("friend");
	DiamondTrap d("shine");
	
	a.demo();
	b.demo();
	c.demo();
	d.demo();
	std::cout << std::endl << "!!! Diamond use his own method !!!" << std::endl;
	d.hiMyNameIs();
	std::cout << std::endl << "!!! Diamond use method from Scav & Frag!!!" << std::endl;
	d.highFivesGuys();
	d.guardGate();
	
	return 0;
}