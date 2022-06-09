#include "Zombie.hpp"

Zombie::Zombie (std::string nombre) {
	this->Name = nombre;
}

Zombie::Zombie (void) {
}

void	Zombie::announce () {
	std::cout << this->Name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName (std::string nombre) {
	this->Name = nombre;
}

Zombie::~Zombie() {
	std::cout << this->Name << " -= go back to the hell =-" << std::endl;
}
