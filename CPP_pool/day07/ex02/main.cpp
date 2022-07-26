#include <Array.hpp>

#define MAX_VAL 5
int main(int, char**)
{
	std::cout << "int array element copy" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; ++i) {
        const int value = rand() % 5;
        numbers[i] = value;
        mirror[i] = value;
    }

	for (int i = 0; i < MAX_VAL; ++i) {
		std::cout << numbers[i] << "/" << mirror[i] << std::endl;
	}
    //SCOPE
    {
		{
			std::cout << "int array empty constructor" << std::endl;
			Array<int> test;
			std::cout << "size of empty array : " << test.size() << std::endl;
		}

		std::cout << "int array constructor copy" << std::endl;
        Array<int> tmp = numbers;
        Array<int> test(tmp);
		for (int i = 0; i < MAX_VAL; ++i) {
			std::cout << numbers[i] << "/" << test[i] << std::endl;
		}
    }

	std::cout << "try to set out of range elements" << std::endl;
    try {
        numbers[-2] = 0;
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        numbers[MAX_VAL] = 0;
    }
    catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

	std::cout << "if some element not equel, error" << std::endl;
    for (int i = 0; i < MAX_VAL; ++i) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
	}

	std::cout << "change first element" << std::endl;
	mirror[1] = rand();

	std::cout << "if some element not equel, error" << std::endl;
	for (int i = 0; i < MAX_VAL; ++i) {
        if (mirror[i] != rand()) {
			delete [] mirror;
            std::cerr << "Error : didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    delete [] mirror;
    return 0;
}
