#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	std::cout << std::endl << "!!! Constructors called !!!" << std::endl;
	ClapTrap a("playerOne");
	ClapTrap b("playerTwo");
	ScavTrap c("slave");
	FragTrap d("friend");

	std::cout << std::endl << "!!! Init information !!!" << std::endl;
	a.demo();
	b.demo();
	c.demo();
	d.demo();

	std::cout << std::endl << "!!! Attack without damage !!!" << std::endl;
	a.attack("slave");
	c.takeDamage(a.getDamageLevel());
	a.demo();
	c.demo();

	std::cout << std::endl << "!!! Attack with damage !!!" << std::endl;
	std::cout << std::endl << "!!! use base (ClapTrap) method setDamageLevel !!!" << std::endl;
	b.setDamageLevel(5);
	b.attack("friend");
	std::cout << std::endl << "!!! use base (ClapTrap) method takeDamage !!!" << std::endl;
	d.takeDamage(b.getDamageLevel());
	std::cout << std::endl << "!!! use base (ClapTrap) method setDamageLevel !!!" << std::endl;
	d.setDamageLevel(1);
	d.attack("playerTwo");
	std::cout << "!!! use base (ClapTrap) method takeDamage !!!" << std::endl;
	b.takeDamage(d.getDamageLevel());
	b.demo();
	d.demo();
	std::cout << std::endl << "!!! use base (ClapTrap) method beRepaired !!!" << std::endl;
	d.beRepaired(10);
	d.demo();

	std::cout << std::endl << "!!! objects uses their derived methods !!!" << std::endl;
	c.guardGate();
	d.highFivesGuys();
	std::cout << std::endl << "!!! Destructors called !!!" << std::endl;

	return 0;
}