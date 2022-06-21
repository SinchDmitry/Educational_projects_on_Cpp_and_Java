#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form {
	private :
		std::string	_target;
	public : 
		ShrubberyCreationForm(void);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm&	operator = (const ShrubberyCreationForm& op);

		void				beExec(const Bureaucrat& clerk) const;
		const std::string&	getTarget(void) const;
		void				printInfo(void) const;
		static Form* 		formGenerator(const std::string& target);

} ;


#endif