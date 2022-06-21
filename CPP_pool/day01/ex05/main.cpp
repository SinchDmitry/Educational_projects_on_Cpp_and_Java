#include "Harl.hpp"

int	main( void )
{
	Harl Harl;
	std::cout << "[=========================start========================]" << std::endl;
	Harl.complain("DEBUG");
	std::cout << "[===========================1==========================]" << std::endl;
	Harl.complain("INFO");
	std::cout << "[===========================2==========================]" << std::endl;
	Harl.complain("WARNING");
	std::cout << "[===========================3==========================]" << std::endl;
	Harl.complain("ERROR");
	std::cout << "[===========================4==========================]" << std::endl;
	Harl.complain("ABOBUS");
	std::cout << "[==========================end=========================]" << std::endl;
}