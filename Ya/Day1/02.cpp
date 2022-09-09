#include <iostream>
#include <list>
#include <cstring>

/* stupid version | failed 10 test 
int main () {
	std::string s;
	std::cin >> s;
	s.insert(0, "/");
	s.append("/");
	while (s.find("/./") != *s.end() - 1) {
		s.replace(s.find("/./"), sizeof("/./") - 1, "/");
	}
	while (s.find("//") != *s.end() - 1) {
		s.replace(s.find("//"), sizeof("//") - 1, "/");
	}
	int pos;
	while (true) {
		if ((pos = s.find("/../")) == *s.end() - 1) {
			break;
		}
		if (pos == 0) {
			s = s.substr(sizeof("/../") - 2, s.length() - sizeof("/../") + 2);
		} else {
			int startpos = s.rfind("/", pos - 1);
			s.replace(startpos, pos + sizeof("/../") - 2, "/");
		}
	}
	while (s.find("//") != *s.end() - 1) {
		s.replace(s.find("//"), sizeof("//") - 1, "/");
	}
	if (s != "/" && *(--s.end()) == '/') { s = s.substr(0, s.length() - 1); }
	if (s.empty()) { s = "/"; } 
	if (s != "/" && s.substr(s.length() - 2, 2) == ("/.") )
		{ s = s.substr(0, s.length() - 2);}
	std::cout << s << std::endl;
}
*/

/* split version  | runtime error ????? */
std::list<std::string> split(std::string str, std::string myDelim) {
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
	std::string trashAddress;
	std::string cleanAddress = "";
	std::cin >> trashAddress;
	std::list<std::string> splitAddress = split(trashAddress, "/");
	splitAddress.remove(".");
	splitAddress.remove("");

	for (std::list<std::string>::iterator splitIter = splitAddress.begin();
			splitIter != splitAddress.end(); ++splitIter) {
		if (splitIter == splitAddress.begin() && !(*splitIter).compare("..")) {
			splitAddress.erase(splitIter);
		} else if (!(*splitIter).compare("..")) {
			splitAddress.erase(--splitIter);
			splitAddress.erase(++splitIter);
		}
	}

	for (std::list<std::string>::iterator splitIter = splitAddress.begin();
			splitIter != splitAddress.end(); ++splitIter) {
		cleanAddress += "/";
		cleanAddress += *splitIter;
	}
	if (!cleanAddress.compare("")) { cleanAddress = "/"; }
	std::cout << cleanAddress << std::endl; 
	return 0;
}
