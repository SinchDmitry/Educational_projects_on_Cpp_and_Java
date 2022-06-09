#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>

class Point {
	private:
		double	_x;
		double	_y;

	public:
		Point(void);
		~Point(void);
		Point(const double a, const double b);
		Point(const Point& copy);
		Point &operator = (const Point& op);

		const double& getX(void) const;
		const double& getY(void) const;

		bool	setInputParam(void);
		void	setParam(const double a, const double b);
	} ;

std::ostream&	operator << (std::ostream& out, const Point& other);

#endif