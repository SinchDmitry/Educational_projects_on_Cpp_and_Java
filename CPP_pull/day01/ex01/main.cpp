#include "Zombie.hpp"
int	main(void)
{
	std::cout << "Leader of zombie horde" << std::endl;
	Zombie	paul("Paul");
	paul.announce();
	std::cout << "Zombie wich created with newZombie constructor" << std::endl;
	Zombie	*ded = zombieHorde(5, "Ded");
	delete [] ded;
}