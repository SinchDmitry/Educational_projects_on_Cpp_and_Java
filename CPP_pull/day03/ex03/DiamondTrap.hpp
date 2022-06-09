#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private :
		std::string	_name;
	public :
		DiamondTrap(void);
		DiamondTrap(const std::string name);
		~DiamondTrap(void);
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap	&operator = (const DiamondTrap &op);
		void		attack(std::string const target);
		void		hiMyNameIs(void);
		void		demo(void);
} ;

#endif