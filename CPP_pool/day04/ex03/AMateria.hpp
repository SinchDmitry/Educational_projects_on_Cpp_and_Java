#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"
# define  INV 4

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria(void);
		AMateria(const std::string& type);
		virtual ~AMateria(void);
		AMateria(const AMateria &copy);
		AMateria& operator = (const AMateria &op);
		const std::string& getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
} ;

#endif