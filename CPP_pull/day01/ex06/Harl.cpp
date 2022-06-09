#include "Harl.hpp"

Harl::Harl(void){
	_level = 0;
}

Harl::Harl(std::string lvl){
	_level = Harl::complainLevel( lvl );
}

Harl::~Harl(){
}

void	Harl::message( void ) {
	std::cout << "[ Probably complaining \
about insignificant problems ]" << std::endl;
}

void	Harl::debug( void ) {
	std::cout << "I love to get extra bacon for my \
7XL-double-cheese-triple-pickle-special-ketchup burger. \
I just love it!" << std::endl;
}

void	Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon cost more money. \
You don't put enough! If you did I would not have to ask for it!"
<< std::endl;
}

void	Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. \
I've been coming here for years and you just started working \
here last month." << std::endl;
}

void	Harl::error( void ) {
	std::cout << "This is unacceptable, I want to speak to the manager now."
<< std::endl;
}

int	Harl::complainLevel( std::string level ) {
	std::string	variants[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	} ;
	for (int i = 0; i < 4; i++) {
		if (!level.compare(variants[i])) {
			return(i);
		}
	}
	return (5);
}

void	Harl::complain( std::string level ) {
	int lvl =  Harl::complainLevel( level );
	if (_level <= lvl) {
		switch (lvl) {
			case (0) : 
				Harl::debug();
				break ;
			case (1) :
				Harl::info();
				break ;
			case (2) :
				Harl::warning();
				break ; 
			case (3) :
				Harl::error();
				break ;
			default :
				Harl::message();
				break ;
		}
	}
}
