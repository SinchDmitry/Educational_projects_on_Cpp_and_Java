#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	protected :
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
	public:
		ScavTrap(void);
		ScavTrap(const std::string name);
		~ScavTrap(void);
		ScavTrap(const ScavTrap &copy);
		ScavTrap	&operator = (const ScavTrap &op);
		void		attack(std::string const target);
		void		guardGate();
		void		demo(void);
} ;

#endif