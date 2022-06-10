#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form {
	private :
		std::string	_target;
	public : 
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm&	operator = (const PresidentialPardonForm& op);
		
		void				beExec(const Bureaucrat& clerk) const;
		const std::string&	getTarget(void) const;
		void				printInfo(void) const;
		static Form* 		formGenerator(const std::string& target);
} ;

std::ostream& operator<<(std::ostream& out, PresidentialPardonForm const &other);

#endif