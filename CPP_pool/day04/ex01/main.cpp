#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void) {
	std::cout << std::endl << "!!! constructor demonstration !!!" << std::endl;
	Animal	*discovery[4];
	for (int i = 0; i < 4; ++i) {
		std::cout << std::endl << "		create new animal		" << std::endl;
		std::cout << i << " : ";
		if (i % 2) {
			discovery[i] = new Dog;
		} else {
			discovery[i] = new Cat;
		}
	}
	
	std::cout << std::endl << "!!! deep copy demonstration !!!" << std::endl;
	std::cout << std::endl << "	create Unique	" << std::endl;
	Cat *Unique = new Cat;
	std::cout << std::endl << "	Paradist copy Unique	" << std::endl;
	Cat *Parodist = new Cat(*Unique);
	std::cout << std::endl << "	delete both	" << std::endl;
	delete Unique;
	delete Parodist;

	std::cout << std::endl << "!!! destructor demonstration !!!" << std::endl;
	for (int i = 0; i < 4; ++i) {
		std::cout << std::endl << "	delete animal #	" << i << std::endl;
		delete discovery[i];
	}

	return 0;
}