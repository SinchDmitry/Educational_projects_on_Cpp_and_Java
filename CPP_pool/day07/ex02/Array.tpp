#include "Array.hpp"

template<typename T>
Array<T>::Array(void) : _size(0), _arrayTemp(NULL) {}

template<typename T>
Array<T>::~Array(void) {
	if (_size > 0) {
		delete [] _arrayTemp;
	}
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n) {
	if (n < 0) {
		throw std::overflow_error("Index out of bounds");
	}
	_arrayTemp = new T[n](); 
}

template<typename T>
Array<T>::Array(const Array& copy) : _size(0), _arrayTemp(NULL) {
	*this = copy;
}

template<typename T>
Array<T>&	Array<T>::operator = (const Array& op) {
	if (this != &op) {
		if (_size > 0) {
			delete [] _arrayTemp;
		}
		_arrayTemp = NULL;
		if (op._size > 0) {
			_size = op._size;
			_arrayTemp = new T[op._size]();
			for (int i = 0; i < op._size; ++i) {
				_arrayTemp[i] = op._arrayTemp[i];
			}
		}
	}
	return (*this);
}

template<typename T>
T&	Array<T>::operator [] (int index) {
	if (index >= _size || index < 0) {
		throw Array::OutOfRange();
	}
	return _arrayTemp[index];
}

template<typename T>
const T& Array<T>::operator [] (int index) const {
	return operator[](index);
}

template<typename T>
int Array<T>::size(void) const {
	return _size;
}

template<typename T>
const char* Array<T>::OutOfRange::what() const throw() {
	return "ArrayException: index out of bounds";
}
