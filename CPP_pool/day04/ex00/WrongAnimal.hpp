#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {
	protected :
		std::string	_type;
	public :
		WrongAnimal(void);
		virtual ~WrongAnimal(void);
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal					&operator = (const WrongAnimal &op);
		void						makeSound(void) const;
		virtual const std::string	&getType(void) const;
} ;

#endif