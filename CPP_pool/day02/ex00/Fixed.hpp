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
		Fixed(void);
		~Fixed(void);
		/* copy constructor */
		Fixed(const Fixed& copy);
		/* overload operator */
		Fixed &operator = (const Fixed& op);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
} ;

#endif