#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main () {
	Bureaucrat	clerkOne("Mihail", 1);
	Bureaucrat	clerkTwo("Boris", 160);
	Intern		oleg;

	std::cout << clerkOne << std::endl << clerkTwo << std::endl;

	std::cout << std::endl << "***" << std::endl << std::endl;
	
	{
		try {
			Form* tree = oleg.createForm("SomeWrongName", "AppleTree");
			if (tree) {
				try {
					tree->printInfo();
					clerkOne.execForm(*tree);
					clerkTwo.execForm(*tree);
				} catch (std::exception &e) {
					std::cout << "Form can't be executed, bureaucrat" << e.what() << std::endl;
				}
			}
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
			
	}

	std::cout << std::endl << "***" << std::endl << std::endl;

	{
		try {
			Form* tree = oleg.createForm("ShrubberyCreationForm", "AppleTree");
			if (tree) {
				try {
					tree->printInfo();
					clerkOne.execForm(*tree);
					clerkTwo.execForm(*tree);
				} catch (std::exception &e) {
					std::cout << "Form can't be executed, bureaucrat" << e.what() << std::endl;
				}
			}
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
			
	}

	// {
	// 	try {
	// 		Form* tree = oleg.createForm("ShrubberyCreationForm", "AppleTree");
	// 		tree->printInfo();
	// 		clerkOne.execForm(*tree);
	// 		clerkTwo.execForm(*tree);
	// 	} catch (std::exception &e) {
	// 		std::cout << "Form can't be executed, bureaucrat" << e.what() << std::endl;
	// 	} 
	// }

	// {
	// 	try {
	// 		Form* drill = new RobotomyRequestForm("Android");
	// 		drill->printInfo();
	// 		clerkOne.execForm(*drill);
	// 		clerkTwo.execForm(*drill);
	// 	} catch (std::exception &e) {
	// 		std::cout << "Form can't be executed, bureaucrat" << e.what() << std::endl;
	// 	}
	// }

	// {
	// 	try {
	// 		Form* pardon = new PresidentialPardonForm("Joker");
	// 		pardon->printInfo();
	// 		clerkOne.execForm(*pardon);
	// 		clerkTwo.execForm(*pardon);
	// 	} catch (std::exception &e) {
	// 		std::cout << "Form can't be executed, bureaucrat" << e.what() << std::endl;
	// 	}
	// }
}