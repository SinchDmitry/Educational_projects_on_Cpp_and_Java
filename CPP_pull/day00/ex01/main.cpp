#include "phonebook.hpp"

int	main(void) {
	phoneBook 	phoneBook;
	std::string	command;

	while (true) {
		std::cout << "wait for command : [ADD, SEARCH, EXIT]: " << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD") {
			phoneBook.addContact();
		} else if (command == "SEARCH") {
			phoneBook.searchContact();
			std::getline(std::cin, command);
		} else if (command == "EXIT") {
			std::cout << "Hasta la vista! " << std::endl;
			break ;
		} else {
			std::cout << "Wrong command " << std::endl;
		}
	}
	return (0);
}