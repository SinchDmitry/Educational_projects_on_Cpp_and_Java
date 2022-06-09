#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(const std::string name);
		~FragTrap(void);
		FragTrap(const FragTrap &copy);
		FragTrap	&operator = (const FragTrap &op);
		void		attack(std::string const target);
		void		highFivesGuys();
		void		demo(void);
} ;

#endif