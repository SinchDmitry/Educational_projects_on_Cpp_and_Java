#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <sys/time.h>
# include <random>

class RobotomyRequestForm : public Form {
	private :
		std::string	_target;
	public : 
		RobotomyRequestForm(void);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm&	operator = (const RobotomyRequestForm& op);

		void				beExec(const Bureaucrat& clerk) const;
		const std::string&	getTarget(void) const;
		void				printInfo(void) const;
} ;

std::ostream& operator<<(std::ostream& out, RobotomyRequestForm const &other);

#endif