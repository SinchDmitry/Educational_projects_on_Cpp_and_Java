#include "MutantStack.hpp"
#include <ctime>


template <typename T>
void    printStack(T& st,  T& fin) {
    while (st != fin) {
        std::cout << *st << std::endl;
        ++st;
    }
}

int main()
{
	srand(time(NULL));
    MutantStack<int> randStack;
    for (int i = 0; i < 10; ++i) {
          randStack.push(rand());
	}
	std::cout << "****************************************"<< std::endl;
    std::cout << "size of mutantStack : " <<   randStack.size() << std::endl;
    std::cout << "top in mutantStack : " <<   randStack.top() << std::endl;
    MutantStack<int>::iterator it = randStack.begin();
    MutantStack<int>::iterator ite = randStack.end();
    printStack(it, ite);

	std::cout << "****************************************"<< std::endl;
    std::cout << "pop 1 element" << std::endl;
    randStack.pop();
    std::cout << "size of mutantStack : " << randStack.size() << std::endl;
    std::cout << "top in mutantStack : " << randStack.top() << std::endl;
	it = randStack.begin();
	ite = randStack.end();
	printStack(it, ite);

	std::cout << "****************************************"<< std::endl;
	std::cout << "just reverse" << std::endl;
    MutantStack<int>::reverse_iterator rit =  randStack.rbegin();
    MutantStack<int>::reverse_iterator rite = randStack.rend();
    printStack(rit, rite);

    return 0;
}