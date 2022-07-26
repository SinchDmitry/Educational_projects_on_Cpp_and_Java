#include "Zombie.hpp"
int	main(void)
{
	std::cout << "Zombie wich created with class exemplar" << std::endl;
	Zombie	paul("Paul");
	paul.announce();
	std::cout << "Zombie wich created with newZombie constructor" << std::endl;
	Zombie	*ded = newZombie("Ded");
	ded->announce();
	delete ded;
	std::cout << "Zombie wich created with randomChump function" << std::endl;
	randomChump("Sanya");
}