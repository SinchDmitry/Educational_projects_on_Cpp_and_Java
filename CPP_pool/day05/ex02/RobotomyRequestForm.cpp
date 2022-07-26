#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : 
	Form("Robotomy Request Form", 72, 45, 0),
	_target("") {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : 
	Form("Robotomy Request Form", 72, 45, 0),
	_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) :
	Form(copy.getName(), copy.getSignGrade(), copy.getExecGrade(), copy.getSign()),
	_target(copy._target) {}

RobotomyRequestForm&	RobotomyRequestForm::operator = (const RobotomyRequestForm& op) {
	if (this != &op) {
		_target = op._target;
	}
	return *this;
}

void	RobotomyRequestForm::beExec(const Bureaucrat& clerk) const {
	struct timeval time;
	gettimeofday(&time, NULL);
	srand((time.tv_sec * 1000) + (time.tv_usec / 1000)); 
	if (clerk.getGrade() > this->getExecGrade()) {
		throw Form::GradeTooLowException(); // method ?
	} else {
		std::cout << "* Drilling sound *" << std::endl;
		if (rand() % 2) {
			std::cout << this->_target << " has been successfully robotomized" << std::endl;
		} else {
			std::cout << this->_target << " hasn't been successfully robotomized" << std::endl;
		}
	}
}

const std::string&	RobotomyRequestForm::getTarget(void) const {
	return _target;
}

void	RobotomyRequestForm::printInfo(void) const {
	std::cout << "*******************************"  << std::endl;
	std::cout << "Form's type : " << getName() << std::endl;
	std::cout << "Form's name : " << getTarget() << std::endl;
	std::cout << "Form's grade to execute : " << getExecGrade() << std::endl;
	std::cout << "Form's grade to sign : " << getSignGrade() << std::endl;
	std::cout << "Is form's already signed : " << ((getSign() == 1) ? "yes" : "no") << std::endl;
	std::cout << "*******************************"  << std::endl;
}
