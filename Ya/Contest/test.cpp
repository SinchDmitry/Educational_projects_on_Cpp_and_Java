#include <iostream>
#include <vector>
#include <cstring>
#include <map>

int main () {
	std::map<int, int> MyMap;
	MyMap.insert(std::pair<int, int>(31323, 1));
	MyMap.insert(std::pair<int, int>(3136, 1));
	MyMap.insert(std::pair<int, int>(31362, 1));


	for (auto it = MyMap.begin(); it != MyMap.end(); ++it) {
		std::cout << it->first << " | " << it->second << std::endl;
	}
	std::cout << MyMap.find(3136)->first << std::endl;
	return (0);
}


6
50 7 25 3632 A
14 23 52 212372 S
15 0 5 3632 C
14 21 30 212372 A
50 7 26 3632 C
14 21 30 3632 A
