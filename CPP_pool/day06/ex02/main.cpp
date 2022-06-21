#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void) {
	int r = rand() % 3;
	if (!r) { return new A; }
	if (r == 1) { return new B; }
	return new C;
}

void	identify(Base *p) {
	if (dynamic_cast<A*>(p) != NULL) { std::cout << "type : class A" << std::endl; }
	else if (dynamic_cast<B*>(p) != NULL) { std::cout << "type : class B" << std::endl; }
	else if (dynamic_cast<C*>(p) != NULL) { std::cout << "type : class C" << std::endl; }
}

void	identify(Base &p) {
	identify(&p);
}

int main() {
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		Base *o = generate();
		std::cout << std::endl << "Test " << i << std::endl;
		identify(o);
		identify(*o);
		delete o;
	}
	return 0;
}