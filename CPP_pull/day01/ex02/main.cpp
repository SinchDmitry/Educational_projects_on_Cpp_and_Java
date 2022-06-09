
#include <iostream>
#include <string>
int		main( void )
{
	std::string	originalString = "HI THIS IS BRAIN";
	std::string *stringPTR = &originalString;
	std::string	&stringREF = originalString;
	std::cout << "Take adress of the string : " << &originalString << std::endl;
	std::cout << "Take adress of the pointer to string : " << &(*stringPTR) << std::endl;
	std::cout << "Take reference: " << &stringREF << std::endl;
	std::cout << "Original string: " << originalString << std::endl;
	std::cout << "Pointer to string: " << *stringPTR << std::endl;
	std::cout << "Reference to string: " << stringREF << std::endl;
}