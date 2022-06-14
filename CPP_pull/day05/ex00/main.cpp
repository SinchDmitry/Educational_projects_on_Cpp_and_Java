#include "Bureaucrat.hpp"

int main () {
	Bureaucrat clerkOne("Mihail", 2);
	Bureaucrat clerkTwo("Boris", 149);
	std::cout << clerkOne << std::endl;
	std::cout << clerkTwo << std::endl;
	
	{
		try {
			clerkOne.UpGrade();
			std::cout << clerkOne.getName() << "'s grade now is : " << clerkOne.getGrade() << std::endl;
			clerkOne.UpGrade();
			std::cout << clerkOne.getName() << "'s grade now is : " << clerkOne.getGrade() << std::endl;
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		try {
			clerkTwo.DownGrade();
			std::cout << clerkTwo.getName() << "'s grade now is : " << clerkTwo.getGrade() << std::endl;
			clerkTwo.DownGrade();
			std::cout << clerkTwo.getName() << "'s grade now is : " << clerkTwo.getGrade() << std::endl;
		} catch (Bureaucrat::GradeTooLowException &e) {
			std::cout << e.what() << std::endl;
		} catch (Bureaucrat::GradeTooHighException &e) {
			std::cout << e.what() << std::endl;
		}
	}

}

