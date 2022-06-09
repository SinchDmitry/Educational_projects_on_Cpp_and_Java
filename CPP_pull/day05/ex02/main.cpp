#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main () {
	Bureaucrat	clerkOne("Mihail", 1);
	Bureaucrat	clerkTwo("Boris", 160);
	std::cout << clerkOne << std::endl << clerkTwo << std::endl;

	{
		try {
			Form* tree = new ShrubberyCreationForm("AppleTree");
			tree->printInfo();
			tree->beExec(clerkOne);
			tree->beExec(clerkTwo);
		} catch (std::exception &e) {
			std::cout << "Form can't be executed, bureaucrat" << e.what() << std::endl;
		}
	}

	{
		try {
			Form* drill = new RobotomyRequestForm("Android");
			drill->printInfo();
			drill->beExec(clerkOne);
			drill->beExec(clerkTwo);
		} catch (std::exception &e) {
			std::cout << "Form can't be executed, bureaucrat" << e.what() << std::endl;
		}
	}

	{
		try {
			Form* pardon = new PresidentialPardonForm("Joker");
			pardon->printInfo();
			pardon->beExec(clerkOne);
			pardon->beExec(clerkTwo);
		} catch (std::exception &e) {
			std::cout << "Form can't be executed, bureaucrat" << e.what() << std::endl;
		}
	}
}