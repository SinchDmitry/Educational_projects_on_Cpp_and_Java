#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void) {
	std::cout << std::endl << "!!! create Cat & Dog !!!" << std::endl;
	// Animal AbstractAnimal;
	std::cout << std::endl << "!!! constructors, ladies & gentlemanes !!!" << std::endl;
	Cat Kit;
	Dog Pes;

	std::cout << std::endl << "!!! introduction !!!" << std::endl;
	Kit.makeSound();
	Pes.makeSound();
	
	std::cout << std::endl << "!!! destructors, ladies & gentlemanes !!!" << std::endl;
	return 0;
}