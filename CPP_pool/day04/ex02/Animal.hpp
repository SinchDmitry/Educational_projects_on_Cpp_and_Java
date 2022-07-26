#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	protected :
		std::string	_type;
	public :
		Animal(void);
		virtual ~Animal(void);
		Animal(const Animal &copy);
		Animal						&operator = (const Animal &op);
		virtual void				makeSound(void) const = 0;
		virtual const std::string	&getType(void) const;
} ;

#endif