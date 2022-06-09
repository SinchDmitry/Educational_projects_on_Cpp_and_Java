#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>
# include "Fixed.hpp"

class Point {
	private:
		Fixed _x;
		Fixed _y;
	public:
		Point(void);
		~Point(void);
		Point(const float a, const float b);
		Point(const Point &copy);
		Point &operator = (const Point &op);
		const Fixed &getX(void) const;
		const Fixed &getY(void) const;
	} ;

	bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif