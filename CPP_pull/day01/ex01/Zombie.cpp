#include "Zombie.hpp"

Zombie::Zombie (std::string nombre) : _name(nombre) {}

Zombie::Zombie (void) {}

void	Zombie::announce () {
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName (std::string nombre) {
	this->_name = nombre;
}

Zombie::~Zombie() {
	std::cout << this->_name << " -= go back to the hell =-" << std::endl;
}
