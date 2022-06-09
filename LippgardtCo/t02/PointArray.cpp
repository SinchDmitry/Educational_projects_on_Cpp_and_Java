#include "PointArray.hpp"
#include <regex>

PointArray::PointArray(void) {
}

PointArray::~PointArray(void) {
}

PointArray::PointArray(const PointArray& copy) {
	*this = copy;
}

PointArray &PointArray::operator = (const PointArray &op) {
	if (this != &op) {
		for (int i = 0; i < (int)op._gcodePoints.size(); ++i) {
			_gcodePoints.push_back(op._gcodePoints.at(i));
		}
	}
	return *this;
}

std::vector<Point>::iterator PointArray::getPointDelta(int i) {
	std::vector<Point>::iterator itBegin = _gcodePoints.begin();
	while(i && itBegin != _gcodePoints.end()) {
		++itBegin;
		--i;
	}
	return	itBegin;
}

std::vector<Point>::iterator PointArray::getEndArrayIter(){
	return	_gcodePoints.end();
}

int PointArray::getSizeStringArray() const {
	return (int)_fileToVector.size();
}

bool	PointArray::openFile(std::string& filename) {
	std::string		tmpString;
	std::ifstream 	inputFile;

	if (filename != "") {
		try {
			inputFile.open(filename);
			if (inputFile) {
				while (std::getline(inputFile, tmpString)) {
					_fileToVector.push_back(tmpString);
				}
				inputFile.close();
				return true;
			} 
			inputFile.close();
		}
  		catch (const std::ifstream::failure& e) {
    		std::cout << "Exception opening/reading file";
  		}
	}
	return false;
}

bool	PointArray::parseOneString(int i) {
	if (i < this->getSizeStringArray()) {
		const std::regex re("^X(-?\\d+)[;|\\s]Y(-?\\d+)[;|\\s]Z(-?\\d+)[;|\\s]?$");
		if (std::regex_match(_fileToVector.at(i), re)) {
			std::smatch match;
			if (std::regex_search(_fileToVector.at(i), match, re)) {
				Point	tmp(std::stod(std::string(match[1])), std::stod(std::string(match[2])), \
					std::stod(std::string(match[3])));
				_gcodePoints.push_back(tmp);
				return 0;
			}
		} 
	} 
	return 1;
}