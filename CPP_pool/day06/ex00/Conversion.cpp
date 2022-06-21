#include "Conversion.hpp"


Conversion::Conversion() : _inputLit(""), _asDouble(0) {}

Conversion::~Conversion() {}

Conversion::Conversion(std::string inputLit) : _inputLit(inputLit), _asDouble(0) {}

Conversion::Conversion(const Conversion& copy) {
	*this = copy;
}

Conversion& Conversion::operator = (const Conversion& op) {
	if (this != &op) {
		_inputLit = op._inputLit;
		_asDouble = op._asDouble;
	}
	return *this;
}

std::string Conversion::dtos(const double& x) const {
    std::stringstream s;
    s << x;
    return s.str();
}

std::string Conversion::ftos(const float& x) const {
    std::stringstream s;
    s << x;
    return s.str();
}

bool	Conversion::parseInput() {
	bool	dig = 0;
	if (!_inputLit.empty()) {
		for (int i = 0; i < (int)_inputLit.length(); ++i){
			if (!isdigit(_inputLit[i])) {
				if ((!i && (_inputLit[i] != '-' || _inputLit[i] != '+')) 
					|| (i == (int)_inputLit.length() - 1 && _inputLit[i] != 'f')) {
					dig = 1;
				}
			}
		}
		if (!dig) {
			_asDouble = std::strtod(_inputLit.c_str(), NULL);
		} else if ((int)_inputLit.length() == 1) {
			_asDouble = static_cast<double>(_inputLit[0]);
		} else {
			std::cout << "Incorrect argument" << std::endl;
			return 0;
		}
		return 1;
	}
	return 0;
}

char	Conversion::getAsChar(void) const {
	return static_cast<char>(_asDouble);
}

int		Conversion::getAsInt(void) const {
	return static_cast<int>(_asDouble);
}

std::string	Conversion::getAsFloat(void) const {
	std::string	tmp = ftos(static_cast<float>(_asDouble));
	if (!(_asDouble - this->getAsInt())) {
		tmp += ".0f";
	} else {
		tmp += "f";
	}
	return tmp;
}

std::string	Conversion::getAsDouble(void) const {
	std::string	tmp = dtos(_asDouble);
	if (!(_asDouble - this->getAsInt())) {
		tmp += ".0";
	} 
	return tmp;
}