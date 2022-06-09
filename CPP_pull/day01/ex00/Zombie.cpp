#include "Zombie.hpp"

Zombie::Zombie (std::string nombre) {
	this->Name = nombre;
}

void	Zombie::announce () {
	std::cout << this->Name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->Name << " -= go back to the hell =-" << std::endl;
}
