#include "Zombie.hpp"

void	randomChump(std::string nombre)
{
	Zombie randomChump = Zombie(nombre);
	randomChump.announce();
}
