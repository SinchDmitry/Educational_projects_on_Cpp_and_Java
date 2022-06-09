#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		virtual ~Ice(void);
		Ice(const Ice &copy);
		Ice& operator = (const Ice &op);
		const std::string& getType() const;
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
} ;

#endif