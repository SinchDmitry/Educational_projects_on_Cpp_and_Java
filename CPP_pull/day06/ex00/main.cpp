#include "Conversion.hpp"

int	main(int argc, char **argv) {
	if (argc == 2) {
		Conversion a(argv[1]);
		if (a.parseInput()) {
			std::cout 
			<<"char : " << a.getAsChar() << std::endl 
			<< "int : " << a.getAsInt()  << std::endl 
			<< "float : " << a.getAsFloat() << std::endl 
			<< "double : "<< a.getAsDouble() << std::endl;
		}
	} else {
		std::cout << "Wrong numbers of input data" << std::endl;
	}
	return (0);
}