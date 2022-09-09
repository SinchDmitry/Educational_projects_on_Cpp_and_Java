#include <iostream>
#include <cmath>

/* base try | ok 
int main() {
	int inputData;
	std::cin >> inputData;
	int i = 1;
	for (;inputData >= 0; i++) {
		inputData -= i;
	}
	std::cout << i - 2 << std::endl;
	return 0;
 }
*/

/* try with recourtion | wrong 
int reqourseFunk(int i, int level) {
	int result = 1;
	level++;
	for (int j = 1; j < i / 2; ++j){
		result += reqourseFunk(j, level);
	}
	std::cout << "level : " << level << " | i : " << i << " | result : " << result << std::endl;
	return result;
}

int main() {
	static int level;
	int inputData;
	std::cin >> inputData;
	std::cout << reqourseFunk(inputData, level) << std::endl;
	return 0;
 }
*/

/* ortodox math try | ok 
int main() {
	double a = 1;
	double b = 1;
	double inputData;
	std::cin >> inputData;
	double c = inputData / (-2);
	double d = b * b - 4 * a * c;
	double x;
	if (d < 0) {
		return -1;
	} else if (d == 0) {
		x = floor(-(b / (2 * a)));
	} else {
		x = round((-b) + sqrt(d));
		double x2 = floor((-b) - sqrt(d));
		if (x2 > 0) {
			x = x2;
		}
	}
	std::cout << x << std::endl;
	return 0;
 }
*/

/* optimal math try | ok */
 int main() {
	double inputData;
	std::cin >> inputData;
	double d = 1 - 4 * inputData / (-2);
	double x = round(sqrt(d) - 1);
	std::cout << x << std::endl;
	return 0;
 }