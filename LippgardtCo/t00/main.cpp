#include "Point.hpp"
#include "Manipulator.hpp"
#include <string>

int main () {

	std::string	tmpX;
	std::string tmpY;
	std::string	tmpRad;
	std::string	command;
	Manipulator a("first");
	Manipulator b("second");
	Point		o;
	
	while (true) {
		std::cout << std::endl << "Input correct arguments :" << std::endl;
		if (!a.setInputParam() && !b.setInputParam()) {
			break ;
		}
	}
	std::cout << std::endl << a << std::endl;
	std::cout << b << std::endl;

	while (true) {
		std::cout << "Waiting for command : [CHECK, EXIT]: " << std::endl;
		std::getline(std::cin, command);
		for (int j = 0; j < (int)command.length(); ++j) {
			command[j] = std::toupper(command[j]);
		}
		if (command == "CHECK") {
			while (true) {
				std::cout << "Waiting for info about target point : [coordinate X, coordinate Y]: " << std::endl;
				if (!o.setInputParam()) {
					break;
				}
			}
			a.cmpDist(b, o);
		} else if (command == "EXIT") {
			std::cout << "Hasta la vista! " << std::endl;
			break ;
		} else {
			std::cout << "Wrong command " << std::endl;
		}
	}
}