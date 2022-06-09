#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form {
	protected :
		const std::string	_name;
		bool				_sign;
		const int			_signGrade;
		const int			_execGrade;
		int					_checkGrade(const int& gr);

	public :
		Form(void);
		~Form(void);
		Form(std::string nombre, int signGr, int execGr, bool sign);
		Form(const Form& copy);
		Form&	operator = (const Form& op);

		bool 				beSigned(const Bureaucrat& clerk);
		virtual void		beExec(const Bureaucrat& clerk) const = 0;
		const std::string&	getName(void) const;
		bool				getSign(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		virtual void		printInfo(void) const = 0;

		class	GradeTooLowException : public std::exception {
			public : virtual const char* what() const throw();
		} ;

		class	CantExecuteForm : public std::exception {
			public : virtual const char* what() const throw();
		} ;

} ;

std::ostream&	operator<<( std::ostream& out, Form const& other);

#endif