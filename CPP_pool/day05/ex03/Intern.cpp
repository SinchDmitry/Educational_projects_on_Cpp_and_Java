#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Intern : default constructor called" << std::endl;
}

Intern::~Intern(void) {
	std::cout << "Intern : default destructor called" << std::endl;
}

Intern::Intern(const Intern& copy) {
	*this = copy;
}

Intern& Intern::operator = (const Intern& copy) {
	(void)copy;
	return *this;
}

const char* Intern::CantCreateForm::what() const throw() {
	return	"Intern can't find a form";
}

Form	*Intern::createForm(const std::string &formName, const std::string &target) {
	Form*	tmp;
	if (formName == "ShrubberyCreationForm") {
		tmp = ShrubberyCreationForm::formGenerator(target);
	} else if (formName == "RobotomyRequestForm") {
		tmp = PresidentialPardonForm::formGenerator(target);
	} else if (formName == "PresidentialPardonForm") {
		tmp = RobotomyRequestForm::formGenerator(target);
	} else {
		throw Intern::CantCreateForm();
	}
	return tmp;
}