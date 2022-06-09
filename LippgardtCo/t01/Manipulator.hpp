#ifndef MANIPULATOR_HPP
# define MANIPULATOR_HPP
# include "Point.hpp"
# include <iomanip>
# include <string>
# include <map>

class	Point;

class	Manipulator {
	private :
		std::string				_name;
		Point					_manipPoint;
		Point					_basePoint;
		double					_rad;
		double					_dist;
		std::map<int, Point>	_pointsMap;

		const std::string 	dtos(const double& x);

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

		void	reInit(void);
		bool	setInputParam(void);
		void	moveToPoint(const Point &q);
		void	moveToNearestPoint(const Point &q, Manipulator& otherManip, const int &i);
		void	pointsDemo(const int &i);
		int		cmpDist(Manipulator& otherManip, const Point &o, bool out);
} ;

std::ostream&	operator << (std::ostream& out, const Manipulator& other);

#endif