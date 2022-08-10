#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
	protected :
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
	public :
		ClapTrap(void);
		ClapTrap(std::string name);
		~ClapTrap(void);
		ClapTrap(const ClapTrap &copy);
		ClapTrap	&operator = (const ClapTrap &op);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		demo(void);
		const int	&getDamageLevel(void) const;
		void		setDamageLevel(int damage);

		void setName( std::string name );
   		std::string getName( void ) const;
   		void setHit( int amount );
   		int getHit( void ) const;
   		void setEnergy( int amount );
   		int getEnergy( void ) const;
   		void setDamage( int amount );
   		int getDamage( void ) const;
} ;

#endif