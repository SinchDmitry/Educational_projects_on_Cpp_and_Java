#include "easyfind.hpp"
#include <vector>
#include <ctime>
#include <cctype>

int main() {
	srand(time(NULL));
	std::vector<int>			arr;
	std::vector<int>::iterator	n;
	for (int i = 0; i < 10; ++i) {
		arr.push_back(rand() % 9);
		std::cout << "#" << i << " : " << arr[i] <<  std::endl;
	}
	while (true) {
		int			val;
		std::string	tmp;
		std::cout << "Input value: " << std::flush;
		std::getline(std::cin, tmp);
		if (tmp == "end" || tmp.empty()) {
			break ;
		} else {
			for (int i = 0; i < (int)tmp.length(); ++i) {
				if (!isdigit(tmp[i])) {
					std::cerr << "Error : wrong input" << std::endl;
					return 1;
				}
			}
			val = atoi(tmp.c_str());
		}
		try {
			n = easyFind(arr, val);
			std::cout << "iterator: " << *n << " on " 
				<< n - arr.begin() << " place." << std::endl;
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
