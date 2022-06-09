#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form {
	private :
		const std::string	_name;
		const std::string	_target;
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
		const bool			getSign(void) const;
		const int			getSignGrade(void) const;
		const int			getExecGrade(void) const;
		
		class	GradeTooLowException : public std::exception {
			public : virtual const char* what() const throw();
		} ;

		class	CantExecuteForm : public std::exception {
			public : virtual const char* what() const throw();
		} ;

} ;

std::ostream&	operator<<( std::ostream& out, Form const& other);

#endif