#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	private :
		int                 _val;
        const static int    _bits = 8;

	public :
		/* constructor */
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &copy);
		~Fixed(void);
		/* overload operator */
		Fixed &operator = (const Fixed &op);

		/* operators */
		Fixed operator+(const Fixed &op) const;
        Fixed operator-(const Fixed &op) const;
        Fixed operator*(const Fixed &op) const;
        Fixed operator/(const Fixed &op) const;

		/* increment & decrement */
        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);

		/* logic */
        bool operator>(Fixed const &op) const;    
        bool operator<(Fixed const &op) const;    
        bool operator>=(Fixed const &op) const;    
        bool operator<=(Fixed const &op) const;    
        bool operator==(Fixed const &op) const;    
        bool operator!=(Fixed const &op) const;

		/* max & min */
		static Fixed &min(Fixed &lvalue, Fixed &rvalue);
        const static Fixed &min(const Fixed &lvalue, const Fixed &rvalue);
        static Fixed &max(Fixed &lvalue, Fixed &rvalue);
        const static Fixed &max(const Fixed &lvalue, const Fixed &rvalue);
		
		/* setter & getter */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
} ;

std::ostream &operator<<(std::ostream &out, const Fixed &fixe);

#endif