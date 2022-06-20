#include "Span.hpp"
#include <ctime>

int keyboardInput() {
	std::string	tmp;
	std::getline(std::cin, tmp);
	if (tmp == "end" || tmp.empty()) {
		exit (0);
	} else {
		for (int i = 0; i < (int)tmp.length(); ++i) {
			if (!isdigit(tmp[i])) {
				std::cerr << "Error : wrong input" << std::endl;
				exit (1);
			}
		}
		return atoi(tmp.c_str());
	}
}

int main()
{
	srand(time(NULL));

	std::cout << "*******************5*********************"<< std::endl;

	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "min span : " << sp.shortestSpan() << std::endl;
		std::cout << "max span : " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "*****************10000******************"<< std::endl;

	try {
		Span sp = Span(10000);
		for (int i = 0; i < 10000; ++i) {
			sp.addNumber(rand());
		}
		std::cout << "min span : " << sp.shortestSpan() << std::endl;
		std::cout << "max span : " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "****************1000000******************"<< std::endl;

	try {
		Span sp = Span(1000000);
		for (int i = 0; i < 1000000; ++i) {
			sp.addNumber(rand());
		}
		std::cout << "min span : " << sp.shortestSpan() << std::endl;
		std::cout << "max span : " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	while (true) {

		std::cout << "****************custom******************"<< std::endl;

		std::cout << "Input size of vector : " << std::flush;
		int size = keyboardInput();
		std::cout << "Input num of random elements : " << std::flush;
		int val = keyboardInput();
		
		try {
			Span sp = Span(size);
			for (int i = 0; i < val; ++i) {
				sp.addNumber(rand());
			}
			std::cout << "min span : " << sp.shortestSpan() << std::endl;
			std::cout << "max span : " << sp.longestSpan() << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}