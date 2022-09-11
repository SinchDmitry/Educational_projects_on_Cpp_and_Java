    #include <iostream>
	#include <vector>
	
	std::vector<std::vector<int > >* handleInput() {
		int n;
		std::cin >> n;
		std::vector<std::vector<int> >* array = new  std::vector<std::vector<int > >;
        for (int i = 0; i < n; i++) {
			std::vector<int> string;
            for (int j = 0; j < 3; j++) {
				int tempData;
				std::cin >> tempData;
				string.push_back(tempData);
            }
			array->push_back(string);
        }
        return array;
    }

	int main() {
        std::vector<std::vector<int > >* arrayOrders = handleInput();
        std::vector<std::vector<int > >* arrayRequests = handleInput();
        std::string output = "";
        
        for (int i = 0; i < (*arrayRequests).size(); i++) {
            int summ = 0;
            if ((*arrayRequests)[i][2] == 1) {
                for (int j = 0; j < (*arrayOrders).size(); j++) {
                    if ((*arrayOrders)[j][0] >= (*arrayRequests)[i][0]) {
                        if ((*arrayOrders)[j][0] <= (*arrayRequests)[i][1]) {
                            summ += (*arrayOrders)[j][2];
                        }
                    }
                }
            } else if ((*arrayRequests)[i][2] == 2) {
                for (int j = 0; j < (*arrayOrders).size(); j++) {
                    if ((*arrayOrders)[j][1] >= (*arrayRequests)[i][0]) {
                        if ((*arrayOrders)[j][1] <= (*arrayRequests)[i][1]) {
                            summ += (*arrayOrders)[j][1] - (*arrayOrders)[j][0];
                        }
                    }
                }
            }
			output += std::to_string(summ);
			output += " ";
        }
        std::cout << output << std::endl;
		delete arrayOrders;
		delete arrayRequests;
		exit(0);
    }
