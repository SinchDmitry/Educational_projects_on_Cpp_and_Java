#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public :
		WrongCat(void);
		virtual ~WrongCat(void);
		WrongCat(const WrongCat &copy);
		WrongCat					&operator = (const WrongCat &op);
		void						makeSound(void) const;
		virtual const std::string	&getType(void) const;
} ;

#endif