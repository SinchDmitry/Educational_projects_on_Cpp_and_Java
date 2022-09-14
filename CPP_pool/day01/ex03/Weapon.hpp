#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon {
	private :
		std::string _weapon;

	public:
		Weapon(std::string weapon);
		~Weapon();
		void	setType(const std::string& type);
		const std::string& getType(void) const;

} ;
#endif
