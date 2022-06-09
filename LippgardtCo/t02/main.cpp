#include "Point.hpp"
#include "PointArray.hpp"
#include <string>

int main () {

	Point				start;
	std::string			filename;
	PointArray			gcode;

	while (true) {
		std::cout << "Waiting for info about target point : [coordinate X, coordinate Y, coordinate Z]: " << std::endl;
		if (!start.setInputParam()) {
			break;
		}
	}

	while (true) {
		std::size_t	nameCheck = 0;
		std::cout << "Waiting for filename" << std::endl;
		std::getline(std::cin, filename);
		nameCheck = filename.find(".gcode", nameCheck);
		if (nameCheck != std::string::npos) {
			if (!gcode.openFile(filename)) {
				std::cout << "WRONG FILENAME : " << filename << std::endl;
				return 1;
			}
			break ;
		}
		std::cout << "file \""  << filename << "\" not found" << std::endl;
		continue ; 
	}

	for (int i = 0; i < gcode.getSizeStringArray(); ++i) {
		if (gcode.parseOneString(i)) {
			std::cout << start << "ERROR SCRIPT" << std::endl;
			return 1;
		} else {
			auto tmp = gcode.getPointDelta(i);
			if (tmp != gcode.getEndArrayIter()) {
				start = start + *tmp;
			} else {
				std::cout << "ERROR ITERATOR" << std::endl;
				return 1;
			}
		}
	}
	std::cout << start << std::endl;
	return 0;
}
