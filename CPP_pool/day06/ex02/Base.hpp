#ifndef BASE_HPP
# define BASE_HPP

# include <cstdlib>
# include <iostream>
# include <ctime>

struct Base {
	virtual ~Base() { std::cout << "destructor called" << std::endl; };
} ;

#endif