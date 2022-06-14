#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>

struct Base {
	virtual ~Base() { std::cout << "destructor called" << std::endl; };
} ;

#endif