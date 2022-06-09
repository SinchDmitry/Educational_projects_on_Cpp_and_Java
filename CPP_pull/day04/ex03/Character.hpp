#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string	_name;
		AMateria*	_bank[INV];

	public:
		Character(void);
		Character(std::string name);
		virtual ~Character(void);
		Character(const Character& copy);
		Character& operator = (const Character& op);
		virtual const std::string& getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
} ;

#endif