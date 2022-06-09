#include "Replace.hpp"
# include <fstream>

Replace::Replace() {
}

Replace::~Replace() {
}

bool	Replace::swap(std::string s1, std::string s2) {
	std::size_t 	inPose = 0;
	std::string		outputFileName;
	std::ofstream 	outputFile;

	if (s1 == "" || s2 == "") {
			std::cerr << "error : empty string" << std::endl;
		return false;
	}
	while (inPose != std::string::npos) {
		inPose = _fileToString.find(s1, inPose);
		if (inPose != std::string::npos) {
			_fileToString.erase(inPose, s1.length());
			_fileToString.insert(inPose, s2);
		} 
	}
	outputFileName = _inputFileName + ".replace";
	outputFile.open(outputFileName);
	outputFile << _fileToString;
	return true;
}

bool	Replace::open(std::string filename) {
	if (filename != "") {
		_inputFile.open(filename);
		if (_inputFile) {
			_inputFileName = filename;
			while (std::getline(_inputFile, _buffer)) {
				_fileToString += _buffer;
				if (_inputFile.peek() != EOF) {
					_fileToString += "\n";
				}
			}
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}