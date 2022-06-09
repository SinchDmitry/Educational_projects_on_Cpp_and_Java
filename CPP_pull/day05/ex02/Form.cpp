
#include "Form.hpp"

Form::Form(void) : 
	_name("typical form"), 
	_target(""), 
	_sign(0), 
	_signGrade(150), 
	_execGrade(150) {
	std::cout << "Form : default constructor called" << std::endl;
}

Form::~Form(void) {
	std::cout << "Form : default destructor called" << std::endl;
}

int	Form::_checkGrade(const int& grade) {
	if (grade < 1) {
		std::cout << "Warning : " << grade << " - is too high grade, value corrected to grade : 1" << std::endl;
		return 1;
	} else if (grade > 150) {
		std::cout << "Warning : " << grade << " - is too low grade, value corrected to grade : 150" << std::endl;
		return 150;
	} else { return grade; }
}

Form::Form(std::string nombre, int signGr, int execGr, bool sign) : 
	_name(nombre),
	_target(""), 
	_sign(sign), 
	_signGrade(_checkGrade(signGr)), 
	_execGrade(_checkGrade(execGr)) {}

Form::Form(const Form& copy) : 
	_name(copy._name), 
	_signGrade(copy._signGrade), 
	_execGrade(copy._execGrade) {
	*this = copy;
	std::cout << "Form : copy constructor called" << std::endl;
}

Form&	Form::operator = (const Form& op) {
	if (this != &op) {
		_sign = op._sign;
	}
	return *this;
}

const std::string&	Form::getName(void) const {
	return	_name;
}

const int&	Form::getSignGrade(void) const {
	return	_signGrade;
}

const int&	Form::getExecGrade(void) const {
	return	_execGrade;
}

const bool& Form::getSign(void) const {
	return	_sign;
}

bool	Form::beSigned(const Bureaucrat& clerk) {
	if (clerk.getGrade() <= _signGrade && !_sign) {
		_sign = 1;
		return 1;
	} else if (_sign){
		std::cout << "form " << _name << " is alredy signed" << std::endl;
		return 0;
	} else {
		throw Form::GradeTooLowException();
	}
}

const char*	Form::GradeTooLowException::what() const throw() {
	return	"To low grade to use form";
}

const char* what() const throw() {
	return "The form cannot be executed";
}

std::ostream &	operator<<( std::ostream& out, Form const& other)
{
	out << other.getName() << " Form has to be signed by a "
		<< other.getSignGrade() << " grade and executed by a "
		<< other.getExecGrade() << " grade, form is "
		<< ((other.getSign()) ? "" : "not ") << "signed";
	return out;
}