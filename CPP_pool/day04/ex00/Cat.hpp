#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	public :
		Cat(void);
		virtual ~Cat(void);
		Cat(const Cat &copy);
		Cat							&operator = (const Cat &op);
		virtual void				makeSound(void) const;
		virtual const std::string	&getType(void) const;
} ;

#endif