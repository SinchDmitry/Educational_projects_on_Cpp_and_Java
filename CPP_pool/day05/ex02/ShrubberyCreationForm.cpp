
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : 
	Form("Shrubbery Creation Form", 145, 137, 0),
	_target("") {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 
	Form("Shrubbery Creation Form", 145, 137, 0),
	_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) :
	Form(copy.getName(), copy.getSignGrade(), copy.getExecGrade(), copy.getSign()),
	_target(copy._target) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator = (const ShrubberyCreationForm& op) {
	if (this != &op) {
		_target = op._target;
	}
	return *this;
}

void	ShrubberyCreationForm::beExec(const Bureaucrat& clerk) const {
	std::ofstream	outputFile;
	std::string		outputFileName;

	if (clerk.getGrade() > getExecGrade()) {
		throw Form::GradeTooLowException(); // method ?
	} else {
		outputFileName = _target + "_shrubbery.txt";
		outputFile.open(outputFileName);
		
		outputFile << "                                   .         ;" << std::endl;  
		outputFile << "		.              .              ;8     ;;" << std::endl;   
		outputFile << "			,           ,                :;8  8;" << std::endl;   
		outputFile << "			:         ;                   :;8;'     .," << std::endl;   
		outputFile << "	,.        8;     8;            ;        8;'    ,;" << std::endl;
		outputFile << "	;       ;8;  88;        ,     8;    ;8;    ,8'" << std::endl;
		outputFile << "	8;       8;8;      ,  ;       8;  ;8;   ,8;'" << std::endl; 
		outputFile << "		;8;      8;        ;8;        8 ;8;  ,8;'" << std::endl;
		outputFile << "		`8;.     ;8;     8;'         `;88;.8;'" << std::endl;
		outputFile << "		`:;8.    ;88. 8@;        8; ;@8;8'" << std::endl;
		outputFile << "			`:8;.  :;bd8;          8;@8;'" << std::endl;
		outputFile << "			`@8:.  :;8.         ;@@8;'" << std::endl;   
		outputFile << "				`@8.  `;@8.      ;@@8;" << std::endl;         
		outputFile << "				`@88. `@88    ;@@8;" << std::endl;        
		outputFile << "					;@8. :@88  8@@8;" << std::endl;       
		outputFile << "					8@bd888bd88:;" << std::endl;     
		outputFile << "						#@88888:;;" << std::endl;
		outputFile << "						8@@888::;" << std::endl;
		outputFile << "						8@@@8(o);  . '" << std::endl;         
		outputFile << "						8@@@o8;:(.,'" << std::endl;         
		outputFile << "					`.. 8@@@o8::;" << std::endl;         
		outputFile << "						`)@@@o8::;" << std::endl;         
		outputFile << "						8@@(o)::;" << std::endl;        
		outputFile << "						.8@@@@8::;" << std::endl;         
		outputFile << "						;8@@@@8::;." << std::endl;          
		outputFile << "					;8@@@@88:;;;." << std::endl; 
		outputFile << "				...;8@@@@@88:;;;;,.. " << std::endl;

		std::cout << "It's execute! Look for file in directory!" << std::endl;
		outputFile.close();
	}
}

const std::string&	ShrubberyCreationForm::getTarget(void) const {
	return _target;
}


void	ShrubberyCreationForm::printInfo(void) const {
	std::cout << "*******************************"  << std::endl;
	std::cout << "Form's type : " << getName() << std::endl;
	std::cout << "Form's name : " << getTarget() << std::endl;
	std::cout << "Form's grade to execute : " << getExecGrade() << std::endl;
	std::cout << "Form's grade to sign : " << getSignGrade() << std::endl;
	std::cout << "Is form's already signed : " << ((getSign() == 1) ? "yes" : "no") << std::endl;
	std::cout << "*******************************"  << std::endl;
}
