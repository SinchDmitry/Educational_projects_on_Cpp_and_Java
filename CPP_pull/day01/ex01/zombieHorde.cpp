#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string nombre)
{
	Zombie *newZombie = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		newZombie[i].setName(nombre);
		newZombie[i].announce();
	}
	return (newZombie);
}
