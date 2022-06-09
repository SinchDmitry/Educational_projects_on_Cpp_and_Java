#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <cmath>
# include <vector>
# include <iostream>
# include <fstream>

class Point {
	private:
		double	_x;
		double	_y;
		double	_z;

	public:
		Point(void);
		~Point(void);
		Point(const double a, const double b, const double c);
		Point(const Point &copy);
		Point &operator = (const Point &op);
		Point &operator + (const Point &op);

		const double& getX(void) const;
		const double& getY(void) const;
		const double& getZ(void) const;

		bool	setInputParam(void);
		void	setParam(const double a, const double b, const double c);
	} ;

std::ostream&	operator << (std::ostream& out, const Point& other);

#endif