#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("incognito"), _grade(150) {
	std::cout << "Bureaucrat : default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat : default destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string nombre, int gr) : _name(nombre), _grade(gr) {
	std::cout << "Bureaucrat : unit constructor called" << std::endl;
	if (_grade < 1) {
		std::cout << "Warning : too high grade, value corrected to grade : 1" << std::endl;
		_grade = 1;
	} else if (_grade > 150) {
		std::cout << "Warning : too low grade, value corrected to grade : 150" << std::endl;
		_grade = 150;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) {
	*this = copy;
	std::cout << "Bureaucrat : copy constructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator = (const Bureaucrat& op) {
	if (this != &op) {
		_name = op._name;
		_grade = op._grade;
	}
	return *this;
}

const std::string&	Bureaucrat::getName(void) const {
	return	_name;
}

const int&	Bureaucrat::getGrade(void) const {
	return	_grade;
}

void	 Bureaucrat::UpGrade(void) {
	_grade--;
	if (_grade < 1) {
		_grade++;
		throw Bureaucrat::GradeTooHighException();
	}
}

void	Bureaucrat::DownGrade(void) {
	_grade++;
	if (_grade > 150) {
		_grade--;
		throw Bureaucrat::GradeTooLowException();
	}
}

bool	Bureaucrat::execForm(const Form &doc) const {
	try {
		std::cout << _name << " execute form \"" << doc.getName() << "\"" << std::endl;
		doc.beExec(*this);
		return true;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << _name << " cannot execute form \"" << doc.getName()
			<< "\" because " << e.what() << std::endl;
		return false;
	}
}

bool	Bureaucrat::signForm(Form &doc) {
	try {
		if (doc.beSigned(*this)) {
			std::cout << _name << " signs form " << doc.getName() << std::endl;
		}
		return true;
	}
	catch (Form::GradeTooLowException &e) {
		std::cout << _name << " cannot sign form " << doc.getName()
			<< " because " << e.what() << std::endl;
		return false;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return	"Grade can't be higher than 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return	"Grade can't be lower than 150";
}


std::ostream& operator<<(std::ostream& out, Bureaucrat const &other) {
	out << other.getName() << ", bureaucrat grade : " << other.getGrade();
	return out;
}