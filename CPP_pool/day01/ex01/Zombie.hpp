#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string> 

class Zombie {
	private :
		std::string _name;
	public :
		Zombie(std::string nombre);
		Zombie(void);
		~Zombie(void);
		void	announce(void);
		void	setName(std::string nombre);
} ;

Zombie* zombieHorde(int N, std::string nombre);

#endif