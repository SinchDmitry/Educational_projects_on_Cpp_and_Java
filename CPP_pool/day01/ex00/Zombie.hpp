#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string> 

class Zombie {
	private :
		std::string Name;
	public :
		Zombie(std::string nombre);
		~Zombie(void);
		void	announce(void);
} ;

Zombie*	newZombie(std::string nombre);
void	randomChump( std::string nombre);

#endif