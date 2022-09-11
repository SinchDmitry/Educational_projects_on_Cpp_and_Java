#include <iostream>
#include <vector>
#include <cstring>

class Taxi {
	private :
		int _number;
		int _day;
		int _hour;
		int _minute;
		char _operation;

	public :
		Taxi(int number, int day, int hour, int minute, char operation) :
		_number(number),
		_day(day),
		_hour(hour),
		_minute(minute),
		_operation(operation) {}
} ;

int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int> > array;
	for (int i = 0; i < n; i++) {
		std::vector<int> string;
		for (int j = 0; j < 3; j++) {
			int tempData;
			std::cin >> tempData;
			string.push_back(tempData);
		}
		array.push_back(string);
	}

}