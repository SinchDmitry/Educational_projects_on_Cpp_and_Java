#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat {
	protected:
		std::string	_name;
		int			_grade;x
	
	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(std::string nombre, int gr);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat&	operator = (const Bureaucrat& op);

		const std::string&	getName(void) const;
		int					getGrade(void) const;
		void				UpGrade(void);
		void				DownGrade(void);

		class	GradeTooHighException : public std::exception {
			public : virtual const char* what() const throw();
		} ;
		class	GradeTooLowException : public std::exception {
			public : virtual const char* what() const throw();
		} ;
} ;

std::ostream& operator<<(std::ostream& out, Bureaucrat const &other);

#endif