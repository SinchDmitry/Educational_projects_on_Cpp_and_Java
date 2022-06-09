#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>

class Replace {
	private :
		std::string		_buffer;
		std::string		_fileToString;
		std::string 	_inputFileName;
		std::ifstream 	_inputFile;
	public :
		Replace(void);
		~Replace(void);
		bool	open(std::string filename);
		bool	swap(std::string s1, std::string s2);
} ;

#endif