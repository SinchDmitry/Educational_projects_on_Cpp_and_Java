# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : 
	_name("Robotomy Request Form"),
	_sign(0),
	_execGrade(45),
	_signGrade(72) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : 
	_name(target),
	_sign(0),
	_execGrade(45),
	_signGrade(72) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) :
	_name(copy._name),
	_sign(copy._sign),
	_execGrade(copy._execGrade),
	_signGrade(copy._signGrade) {}

RobotomyRequestForm&	RobotomyRequestForm::operator = (const RobotomyRequestForm& op) {
	if (this != &op) {
		_sign = op._sign;
	}
	return *this;
}

void	RobotomyRequestForm::beExec(const Bureaucrat& clerk) const {
	if (clerk.getGrade() > _execGrade) {
		throw Form::GradeTooLowException(); // method ?
	} else {
		std::cout << "* Drilling sounda *" << std::endl;
		if (std::rand() % 2)
			std::cout << this->_target << " has been successfully robotomized" << std::endl;
		else
			std::cout << this->_target << " hasn't been successfully robotomized" << std::endl;
		}
}
