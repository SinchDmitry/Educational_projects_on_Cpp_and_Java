#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private :
		int                 _val;
        const static int    _bits = 8;

	public :
		/* default constructor */
		Fixed(void);
		/* int constructor */
		Fixed(const int value);
		/* float constructor */
		Fixed(const float value);
		/* destructor */
		~Fixed(void);
		/* copy constructor */
		Fixed(const Fixed& copy);
		/* overload operator */
		Fixed &operator = (const Fixed& op);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float toFloat( void ) const;
		int toInt( void ) const;
} ;

std::ostream &operator<<(std::ostream &out, const Fixed &fixe);

#endif