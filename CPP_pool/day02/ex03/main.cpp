#include "Point.hpp"

void	painter(Point const a, Point const b, Point const c, Point const p) {    
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            Point tmp(j, i);
            if (tmp.getX() == p.getX() && tmp.getY() == p.getY()) {
                std::cout << "o ";
			}
            else if (bsp(a, b, c, tmp)) {
                std::cout << "# ";
			} else {
                std::cout << ". ";
			}
        }
        std::cout << "\n";
    }
}

int main( void ) {
	Point a(0, 1);
	Point b(0, 20);
	Point c(11, 4);
	Point p(0, 2);

	std::cout << "bsp(a, b, c, p) = " \
    	<< ((bsp(a, b, c, p) == true) ? \
		"point is in triangle" : "point is out of triangle") << std::endl;
    painter(a, b, c, p);
	return 0;
}