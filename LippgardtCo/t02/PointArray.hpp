#ifndef POINTARRAY_HPP
# define POINTARRAY_HPP

# include <iostream>
# include <cmath>
# include "Point.hpp"

class PointArray {
	private:
		std::vector<Point>			_gcodePoints;
		std::vector<std::string>	_fileToVector;

	public:
		PointArray(void);
		~PointArray(void);
		PointArray(const PointArray &copy);
		PointArray &operator = (const PointArray &op);

		bool	parseOneString(int i);
		bool	openFile(std::string& filename);

		int 	getSizeStringArray(void) const;

		std::vector<Point>::iterator	getPointDelta(int i);
		std::vector<Point>::iterator	getEndArrayIter();
	} ;

// std::ostream&	operator << (std::ostream& out, const Point& other);

#endif