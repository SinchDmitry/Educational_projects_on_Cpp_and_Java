#include "Harl.hpp"

int	main( void )
{
	for (int i = 0; ; i++) {
		std::string lvl;
		std::cin >> lvl;
		Harl Harl(lvl);

		std::cout << "[=====================" << "itera : " << i 
			<< "====================]" << std::endl;
		std::cout << "[**********************1*********************]" << std::endl;
		Harl.complain("DEBUG");
		std::cout << "[**********************2*********************]" << std::endl;
		Harl.complain("INFO");
		std::cout << "[**********************3*********************]" << std::endl;
		Harl.complain("WARNING");
		std::cout << "[**********************4*********************]" << std::endl;
		Harl.complain("ERROR");
		std::cout << "[**********************5*********************]" << std::endl;
		Harl.complain("ABOBUS");
	}
}
