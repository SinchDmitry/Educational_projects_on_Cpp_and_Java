#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; ++i) {
		_ideas[i] = "wanna eat";
	}
	std::cout <<  "brain default constructor" << std::endl;
}

Brain::Brain(const std::string &idea) {
	for (int i = 0; i < 100; ++i) {
		_ideas[i] = idea;
	}
	std::cout <<  "brain default constructor" << std::endl;
}

Brain::~Brain() {
	std::cout <<  "brain default destructor" << std::endl;
}

Brain::Brain(const Brain &copy) {
	*this = copy;
	std::cout << "brain copy constructor" << std::endl;
}

Brain &Brain::operator = (const Brain &op) {
	if (this != &op) {
		for (int i = 0; i < 100; ++i) {
			_ideas[i] = op._ideas[i];
		}
	}
	return *this;
}

void	Brain::setIdea(int num, std::string idea) {
	if (num >=0 && num <= 100) {
		_ideas[num] = idea;
	}
}

std::string	Brain::getIdea(int num) const { /* because i don't know how to use exeption */
	if (num >=0 && num <= 100) {
		return _ideas[num];
	} else {
		return "-! i have no words to say that !-";
	}
}