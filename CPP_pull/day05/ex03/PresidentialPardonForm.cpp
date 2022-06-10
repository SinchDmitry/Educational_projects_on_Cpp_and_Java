# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : 
	Form("President Pardon Form", 25, 5, 0),
	_target("") {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : 
	Form("President Pardon Form", 25, 5, 0),
	_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : 
	Form(copy.getName(), copy.getSignGrade(), copy.getExecGrade(), copy.getSign()),
	_target(copy._target) {}

PresidentialPardonForm&	PresidentialPardonForm::operator = (const PresidentialPardonForm& op) {
	if (this != &op) {
		_target = op._target;
	}
	return *this;
}

void	PresidentialPardonForm::beExec(const Bureaucrat& clerk) const {
	if (clerk.getGrade() > this->getExecGrade()) {
		throw Form::GradeTooLowException(); // method ?
	} else {
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
	}
}

const std::string&	PresidentialPardonForm::getTarget(void) const {
	return _target;
}

void	PresidentialPardonForm::printInfo(void) const {
	std::cout << "*******************************"  << std::endl;
	std::cout << "Form's type : " << getName() << std::endl;
	std::cout << "Form's name : " << getTarget() << std::endl;
	std::cout << "Form's grade to execute : " << getExecGrade() << std::endl;
	std::cout << "Form's grade to sign : " << getSignGrade() << std::endl;
	std::cout << "Is form's already signed : " << ((getSign() == 1) ? "yes" : "no") << std::endl;
	std::cout << "*******************************"  << std::endl;
}

Form*	PresidentialPardonForm::formGenerator(const std::string& target) {
	return	new PresidentialPardonForm(target);
}