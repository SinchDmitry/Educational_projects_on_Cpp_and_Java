#include "Array.hpp"

Array<T>::Array(void) : _size(0), _arrayTemp(NULL) {}

Array<T>::~Array(void) {
	if (_size > 0) {
		delete [] _arrayTemp;
	}
}

Array<T>::Array(unsigned int n) : _size(n) {
	if (n < 0) {
		throw std::overflow_error("Index out of bounds");
	}
	_arrayTemp = new T[n](); 
}

Array<T>::Array(const Array& copy) {
	
}

Array&	Array<T>::operator = (const Array& op) {
	if (this != &op) {
		if (op._size() > 0) {
			_size = op._size;
			_arrayTemp = new T[op._size]()
			for (int i = 0; i < op._size; ++i) {
				_arrayTemp[i] = op._arrayTemp[i];
			}
		}
	}
}