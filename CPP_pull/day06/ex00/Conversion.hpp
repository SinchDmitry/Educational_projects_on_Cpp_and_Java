#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <cstdlib>
# include <cctype>
#include <sstream>

class	Conversion {
	private :
		std::string	_inputLit;
		double		_asDouble;

		std::string dtos(const double& x) const;
		std::string ftos(const float& x) const;  

	public :
		Conversion(void);
		~Conversion(void);
		Conversion(std::string inputLit);
		Conversion(const Conversion& copy);
		Conversion& operator = (const Conversion& op);

		void		parseInput(void);

		char		getAsChar(void) const;
		int			getAsInt(void) const;
		std::string	getAsFloat(void) const;
		std::string getAsDouble(void) const;
} ;

#endif