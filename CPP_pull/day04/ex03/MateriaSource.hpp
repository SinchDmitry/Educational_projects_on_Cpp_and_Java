#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria*	_base[INV];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& copy);
		MateriaSource& operator = (const MateriaSource& op);
		virtual ~MateriaSource(void);
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(const std::string& type);
} ;

#endif