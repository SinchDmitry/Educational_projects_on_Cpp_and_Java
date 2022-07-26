#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
	public :
		Dog(void);
		virtual	~Dog(void);
		Dog(const Dog &copy);
		Dog							&operator = (const Dog &op);
		virtual void				makeSound(void) const;
		virtual const std::string	&getType(void) const;
} ;

#endif