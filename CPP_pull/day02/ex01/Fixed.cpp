#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
    _val = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	if (value < pow(2, 31 - _bits) && value > pow(2, 31 - _bits) * (-1) - 1) {
		 _val = value * (1 << _bits);
	} else {
		std::cout << "Overflow error" << std::endl;
    	_val = 0;
	}
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	if ((int)roundf(value) < pow(2, 31 - _bits) && \
		(int)roundf(value) > pow(2, 31 - _bits) * (-1) - 1) {
		 _val = (int)(roundf(value * (1 << _bits)));
	} else {
		std::cout << "Overflow error" << std::endl;
    	_val = 0;
	}
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy){
	std::cout << "Copy constructor called" << std::endl;
    _val = copy.getRawBits();
}

Fixed &Fixed::operator = (const Fixed& op) {
	std::cout << "Assignation operator called" << std::endl;
    if (this == &op)
        return *this;
    _val = op.getRawBits();
    return *this;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
    return _val;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	if (raw < pow(2, 31 - _bits) && raw > pow(2, 31 - _bits) * (-1) - 1) {
		_val = raw /* * (1 << _bits) */;
	} else {
		std::cout << "Overflow error" << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixe)
{
    out << fixe.toFloat();
    return out;
}

float Fixed::toFloat(void) const
{
    return (float)_val / (float)(1 << _bits);
}

int Fixed::toInt(void) const
{
    return (int)(_val >> _bits);
}
