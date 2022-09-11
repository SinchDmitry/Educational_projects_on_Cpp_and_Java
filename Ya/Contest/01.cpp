#include <iostream>
#include <list>
#include <cstring>

std::list<std::string> split(const std::string& str, std::string myDelim) {
	std::list<std::string> dest;
	char* delim = (char *)myDelim.c_str();
    char* pTempStr = strdup(str.c_str());
    char* pWord = strtok(pTempStr, delim);
    while(pWord != NULL) {
        dest.push_back(pWord);
        pWord = strtok(NULL, delim);
    }
    free(pTempStr);
	return dest;
}

int main() {
	int numberOfItems;
	std::cin >> numberOfItems;
	std::string tmpInpurString;
	std::list<std::list<std::string> > inputData;
	for (int i = 0; i < numberOfItems; ++i) {
		std::cin >> tmpInpurString;
		inputData.push_back(split(tmpInpurString, " "));
	}


	return 0;
}