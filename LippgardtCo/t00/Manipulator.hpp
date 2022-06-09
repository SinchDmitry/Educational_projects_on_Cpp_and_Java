#ifndef MANIPULATOR_HPP
# define MANIPULATOR_HPP
# include "Point.hpp"

class	Point;

class	Manipulator {
	private :
		std::string	_name;
		Point		_manipPoint;
		double		_rad;
		double		_dist;

	public :
		Manipulator(void);
		~Manipulator(void) {}
		Manipulator(std::string nombre);
		Manipulator(std::string nombre, double x, double y, double rad);
		Manipulator(const Manipulator& copy);
		Manipulator& operator = (const Manipulator& op);

		const Point& 		getPoint(void) const;
		double 				getRad(void) const;
		const std::string&	getName(void) const;
		double				getDist(const Point &q);

		bool	setInputParam(void);
		void	moveToPoint(const Point &q);
		void	cmpDist(Manipulator& otherManip, const Point &o);
} ;

std::ostream&	operator << (std::ostream& out, const Manipulator& other);

#endif