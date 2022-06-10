#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	Intern {
	private :
		
	public :
		Intern(void);
		~Intern(void);
		Intern(const Intern& copy);
		Intern& operator = (const Intern& copy);

		Form	*createForm(const std::string &formName, const std::string &target);
	
		class	CantCreateForm : public std::exception {
			public : virtual const char* what() const throw();
		} ;
} ;

#endif