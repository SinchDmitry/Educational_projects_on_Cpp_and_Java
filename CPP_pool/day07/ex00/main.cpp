#include "whatever.hpp"

template<typename T>
void	demo(T& a, T& b) {
	std::cout << "1) : " << a << " | 2) : " << b << std::endl;
	swap(a, b);
	std::cout << "1) : " << a << " | 2) : " << b << std::endl;
	std::cout << "min = " << ::min(a, b) << std::endl;
	std::cout << "max = " << ::max(a, b) << std::endl;
}

int	main() {
	{
		int a = 21;
		int b = 42;
		demo(a, b);
	}
	{
	std::cout << "****************************************"<< std::endl;
		std::string a = "more";
		std::string b = "dacha";
		demo(a, b);
	}
	{
		std::cout << "****************************************"<< std::endl;
		std::string a = "21";
		std::string b = "21";
		std::cout << "addresses of a, b before swap:" << std::endl << "1) : " << &a << " | 2) : " << &b << std::endl;
		std::cout << "min : " << ::min(a, b) << "/" << &::min(a, b) << std::endl;
		std::cout << "max : " << ::max(a, b) << "/" << &::max(a, b) << std::endl;
		demo(a, b);
		std::cout << "addresses of a, b after swap:" << std::endl << "1) : " << &a << " | 2) : " << &b << std::endl;
		std::cout << "min : " << ::min(a, b) << "/" << &::min(a, b) << std::endl;
		std::cout << "max : " << ::max(a, b) << "/" << &::max(a, b) << std::endl;
	}
	return (0);
}