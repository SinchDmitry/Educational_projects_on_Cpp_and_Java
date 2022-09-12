#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <cctype>

struct TaxiOperation {
		long id;
		int day;
		int hour;
		int minute;
		char operation;

		TaxiOperation(long id, int day, int hour, int minute, char operation) :
		id(id),
		day(day),
		hour(hour),
		minute(minute),
		operation(operation) {}
} ;

// static std::ostream& operator << (std::ostream& os, const TaxiOperation& soc) {
// 	os	<< "================== start ==================" << std::endl
// 		<< "Rocket ID : " << soc.id << std::endl
// 		<< "Day : " << soc.day << std::endl 
// 		<< "Hours : " << soc.hour << std::endl 
// 		<< "Minute : " << soc.minute << std::endl 
// 		<< "Type : " << soc.operation << std::endl
// 		<< "=================== end ===================" << std::endl;
//     return os;
// }

bool cmpLess(const TaxiOperation& x, const TaxiOperation& y) { 
	if (x.id < y.id) { return true;
	} else if (x.id == y.id && x.day < y.day) { return true;
	} else if (x.id == y.id && x.day == y.day && x.minute < y.minute) { return true;
	} 
	return false; 
}

int main() {
	int n;
	int day;
	int hour;
	int minute;
	long id;
	char operation;
	int count;
	std::set<TaxiOperation, 
			bool(*)(const TaxiOperation&, const TaxiOperation&) > year(cmpLess);
	std::cin >> n;
	for (size_t i = 0; i < n; ++i) {
		std::cin >> day;
		std::cin >> hour;
		std::cin >> minute;
		std::cin >> id;
		std::cin >> operation;
		toupper(operation);
		if (operation == 'A' || operation == 'C' || operation == 'S') {
			TaxiOperation op(id, day, hour, minute, operation);
			year.insert(op);
		}
	}
	std::string output = "";
	for (auto it = year.begin(); it != year.end();) {
		int idRocket = it->id;
		int sum = 0;
		while (it->id == idRocket) {
			TaxiOperation stOp = *it;	
			++it;
			if (it->operation == 'C' || it->operation == 'S') {
				sum += 24 * 60 * (it->day - stOp.day) 
					+ 60 * (it->hour - stOp.hour) + (it->minute - stOp.minute);
				++it;
			}
		}
		output += std::to_string(sum);
		output += " ";
	}
	std::cout << output.substr(0, output.length() - 1) << std::endl;
}