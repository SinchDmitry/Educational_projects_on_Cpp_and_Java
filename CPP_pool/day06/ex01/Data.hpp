#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>

class Data {
	private :
		std::string	_data;

	public :
		Data(void) {}
		~Data(void) {}
		Data(const Data& copy) { *this = copy; }
		Data& operator = (const Data& op) { 
			if (this != &op) { _data = op._data; } 
			return *this; 
		}
		const std::string&	getData(void) { return _data; }
		void				setData(std::string	data) { _data = data; }

} ;

uintptr_t	serialize(Data* ptr);

Data* 		deserialize(uintptr_t raw);

#endif