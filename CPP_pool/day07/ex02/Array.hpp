#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>
# include <iostream>
# include <ctime>
# include <exception>
# include <cctype>

template<typename T>
class Array {
	private :
		int	_size;
		T*	_arrayTemp;
	public :
		Array(void);
		~Array(void);
		Array(unsigned int n);
		Array(const Array& copy);
		Array&	operator = (const Array& op);

		T& operator [] (int index);
		const T& operator [] (int index) const;

		int size(void) const;

		class OutOfRange: public std::exception {
			public : virtual const char* what() const throw();
		};
} ;

# include "Array.tpp"

#endif