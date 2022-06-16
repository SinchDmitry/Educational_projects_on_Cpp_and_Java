#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>

class ObjNotFound : public std::exception
{
	public : virtual const char* what() const throw() { 
		return ("Object not found");
		}
};

template<typename T>
typename T::iterator	easyFind(T& arr, int obj) {
	typename T::iterator tmp;
	tmp = std::find(arr.begin(), arr.end(), obj);
	if (tmp == arr.end()) {
		throw ObjNotFound() ;
	}
	return tmp;
}

#endif