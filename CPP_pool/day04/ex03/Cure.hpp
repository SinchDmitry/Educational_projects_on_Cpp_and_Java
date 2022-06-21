#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		virtual ~Cure(void);
		Cure(const Cure& copy);
		Cure& operator = (const Cure& op);
		const std::string& getType() const;
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
} ;

#endif