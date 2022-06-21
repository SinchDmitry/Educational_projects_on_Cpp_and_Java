#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl {
	private :
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		void	message( void );
		int		_level;

	public :
		Harl( void );
		Harl( std::string lvl );
		~Harl( void );
		int complainLevel( std::string level );
		void complain( std::string level );
} ;

#endif