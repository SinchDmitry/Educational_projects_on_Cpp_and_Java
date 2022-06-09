#include "Zombie.hpp"

Zombie*	newZombie(std::string nombre)
{
	Zombie *newZombie = new Zombie(nombre);
	return (newZombie);
}