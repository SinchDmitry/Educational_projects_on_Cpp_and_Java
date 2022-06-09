#include "Bureaucrat.hpp"
#include "Form.hpp"

int main () {
	Bureaucrat	clerkOne("Mihail", 1);
	Bureaucrat	clerkTwo("Boris", 160);
	Form 		newDoc("Pact", 3, 200, 0);

	std::cout << "<clerk two :>" << std::endl;
	std::cout << clerkTwo.getName() << " try to sign form : " << newDoc.getName() << std::endl;
	clerkTwo.signForm(newDoc);
	std::cout << "<low rang, but he can execute>" << std::endl;
	clerkTwo.execForm(newDoc);
	std::cout << "<clerk one :>" << std::endl;
	std::cout << clerkOne.getName() << " try to sign form : " << newDoc.getName() << std::endl;
	clerkOne.signForm(newDoc);
	std::cout << "<try to sign one more time>" << std::endl;
	clerkOne.signForm(newDoc);
}