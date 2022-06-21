#include "Span.hpp"

Span::Span(unsigned int size) :  _nSize(size) {}

Span::Span (const Span& copy) {
	*this = copy;
}

Span& Span::operator = (const Span& rhs) {
	if (this != &rhs) {
		_nSize = rhs._nSize;
		_objs = rhs._objs;
	}
	return *this;
}

void	Span::addNumber(int num) {
	if (_nSize <= _objs.size()) {
		throw Span::VectorIsFull();
	} else {
		_objs.push_back(num);
	}
}

int		Span::shortestSpan(void) const {
	if (_objs.size() <= 1) {
		throw Span::VectorIsEmpty();
	}
	int					minSpan = MAX_INT;
	std::vector<int>	sorted = _objs;
	std::sort(sorted.begin(), sorted.end());
	for (int i = 0; i < (int)_nSize; ++i) {
		int delta = std::abs(sorted[i + 1] - sorted[i]);
		if (minSpan > delta) {
			minSpan = delta;
		}
	}
	return	minSpan;
}

int		Span::longestSpan(void) const {
	if (_objs.size() <= 1) {
		throw Span::VectorIsEmpty();
	}
	return	*std::max_element(_objs.begin(), _objs.end()) \
		- *std::min_element(_objs.begin(), _objs.end());
}
