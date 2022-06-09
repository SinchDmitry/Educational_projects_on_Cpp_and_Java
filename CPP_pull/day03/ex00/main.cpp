#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap a("playerOne");
	ClapTrap b("playerTwo");

	a.demo();
	b.demo();

	a.attack("playerTwo");
	b.takeDamage(a.getDamageLevel());
	a.demo();
	b.demo();

	a.setDamageLevel(2);
	a.attack("playerTwo");
	b.takeDamage(a.getDamageLevel());
	a.demo();
	b.demo();

	b.beRepaired(1);
	b.demo();

	return 0;
}