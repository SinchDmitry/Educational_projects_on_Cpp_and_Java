#include "Zombie.hpp"
int	main(void)
{
	std::cout << "Leader of zombie horde" << std::endl;
	Zombie	paul("Paul");
	paul.announce();
	std::cout << "Zombie wich created with newZombie constructor" << std::endl;
	Zombie	*ded = zombieHorde(5, "Ded");
	if (ded == NULL) {
		std::cerr << "wrong number of zombie in horde" << std::endl;
		return -1;
	}
	// operator delete[] (ded);
	delete[] (ded);
	return 0;
}