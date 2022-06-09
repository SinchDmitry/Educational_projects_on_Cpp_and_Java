#include "Point.hpp"
#include "Manipulator.hpp"
#include <string>
#include <vector>

void	startPoseManipInit(Manipulator &a, Manipulator &b);
void	pointArrayInit(std::vector<Point> &vecPoints);

int main () {

	std::string			tmpX;
	std::string 		tmpY;
	std::string			tmpRad;
	std::string			command;
	std::vector<Point>	vecPoints;
	Manipulator 		a("first");
	Manipulator 		b("second");
	Point				o;
	
	startPoseManipInit(a, b);

	while (true) {
		vecPoints.clear();
		pointArrayInit(vecPoints);
		std::cout << "Waiting for command : [DEMO, EXIT]: " << std::endl;
		std::getline(std::cin, command);
		for (int j = 0; j < (int)command.length(); ++j) {
			command[j] = std::toupper(command[j]);
		}
		if (command == "DEMO") {
			a.reInit();
			b.reInit();
			for (int i = 0; i < (int)vecPoints.size(); ++i) {
				a.moveToNearestPoint(vecPoints.at(i), b, i);
				// if (a.moveToNearestPoint(vecPoints.at(i), b, i)) {
				// 	break ;
				// }
			}
			std::cout << std::endl << std::setw(3) << "#" << " | " << "manipulator 1" 
				<< " | " << "manipulator 2" << " | ";
			for (int i = 0; i < (int)vecPoints.size(); ++i) {
				std::cout << std::endl << std::setw(3) << i + 1 << " | ";
				a.pointsDemo(i);
				b.pointsDemo(i);
			}
			std::cout << std::endl;
		} else if (command == "EXIT") {
			std::cout << "Hasta la vista! " << std::endl;
			break ;
		} else {
			std::cout << "Wrong command " << std::endl;
		}
	}
}

void	startPoseManipInit(Manipulator &a, Manipulator &b) {
	while (true) {
		std::cout << std::endl << "Input correct arguments :" << std::endl;
		if (!a.setInputParam() && !b.setInputParam()) {
			break ;
		}
	}
	std::cout << std::endl << a << std::endl;
	std::cout << b << std::endl;
}

void	pointArrayInit(std::vector<Point> &vecPoints) {
	std::string	command;
	Point		o;

	while (true) {
		std::cout << "Waiting for command : [ADD, EXIT]: " << std::endl;
		std::getline(std::cin, command);
		for (int j = 0; j < (int)command.length(); j++) {
			command[j] = std::toupper(command[j]);
		}
		if (command == "ADD") {
			while (true) {
				std::cout << "Waiting for info about point : [coordinate X, coordinate Y]: " << std::endl;
				if (!o.setInputParam()) {
					vecPoints.push_back(o);
					break;
				}
			}
		} else if (command == "EXIT") {
			break ;
			// if (!vecPoints.empty()) {
			// 	break ;
			// } else {
			// 	std:: cout << "vector is empty, add some points!" << std::endl;
			// }
		}
	}
}