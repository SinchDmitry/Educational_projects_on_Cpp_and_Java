#include "Zombie.hpp"

// Zombie* zombieHorde(int N, std::string nombre)
// {
// 	Zombie *newZombie = new Zombie[N];
// 	for (int i = 0; i < N; ++i) {
// 		newZombie[i].setName(nombre);
// 		newZombie[i].announce();
// 	}
// 	return (newZombie);
// }

Zombie* zombieHorde(int N, std::string nombre)
{
	Zombie *newZombie = (Zombie *)operator new (sizeof(Zombie) * N);
	for (int i = 0; i < N; ++i) {
		new (&newZombie[i]) Zombie(nombre);
		newZombie[i].announce();
	}
	return (newZombie);
}