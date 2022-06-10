#ifndef CONVERSION_HPP
# define CONVERSION_HPP

class	Conversion {
	private :
		char	_asChar;
		int		_asInt;
		float	_asFloat;
		double	_asDouble;

		

	public :
		Conversion(void);
		~Conversion(void);
		Conversion(std::string inputLit);
		Conversion(const Conversion& copy);
		Conversion& operator = (const Conversion& op);

		void	parseInput();

		char	getAsChar() const;
		int		getAsInt() const;
		float	getAsFloat() const;
		double	getAsDouble() const;


} ;

#endif