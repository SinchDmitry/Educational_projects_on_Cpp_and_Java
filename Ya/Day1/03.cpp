#include <iostream>
#include <list>
#include <cstring>

int main () {
	int 			length;
	int				inputData;
	std::list<int> 	data;
	std::cin >> length;
	for (int i = 0; i < length; ++i) {
		std::cin >> inputData;
		data.push_back(inputData);
	}
	int cost = *data.begin();
	int profit = 0;
	int first = 0;
	int tmpFirst = 1;
	int second = 0;
	int counter = 1;
	for (std::list<int>::iterator dataIter = ++data.begin(); 
		dataIter != data.end(); ++dataIter) {
		counter++;
		if (*dataIter - cost > profit) {
			profit = (*dataIter - cost);
			second = counter;
			first = tmpFirst;
		}
		if (*dataIter < cost) {
			cost = *dataIter;
			tmpFirst = counter;
		}
	}
	std::cout << first << " " << second << std::endl;
	return 0;
}