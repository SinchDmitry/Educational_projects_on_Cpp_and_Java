#include "ScavTrap.hpp"

int	main(void) {
	ClapTrap a("playerOne");
	ClapTrap b("playerTwo");
	ScavTrap c("slave");
	
	a.demo();
	b.demo();

	a.attack("slave");
	c.takeDamage(a.getDamageLevel());
	a.demo();
	c.demo();

	b.setDamageLevel(20);
	b.setDamageLevel(20);
	b.attack("slave");
	c.takeDamage(b.getDamageLevel());
	b.demo();
	c.demo();

	c.guardGate();
	b.beRepaired(1);
	b.demo();

	return 0;
}