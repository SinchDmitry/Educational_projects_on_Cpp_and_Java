# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : 
	_name("President pardon form"),
	_target("";)
	_sign(0),
	_execGrade(5),
	_signGrade(25) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : 
	_name("President pardon form"),
	_target(target),
	_sign(0),
	_execGrade(5),
	_signGrade(25) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) :
	_name(copy._name),
	_sign(copy._sign),
	_execGrade(copy._execGrade),
	_signGrade(copy._signGrade) {}

PresidentialPardonForm&	PresidentialPardonForm::operator = (const PresidentialPardonForm& op) {
	if (this != &op) {
		_sign = op._sign;
	}
	return *this;
}

void	PresidentialPardonForm::beExec(const Bureaucrat& clerk) const {
	if (clerk.getGrade() > _execGrade) {
		throw Form::GradeTooLowException(); // method ?
	} else {
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
	}
}
