#include <iostream>
    #include <vector>
    #include <algorithm>
	#include <set>
    
	struct Order {
		int beginTime; 
		int endTime;
		int coast;

		bool operator < (const Order& obj) { return beginTime < obj.beginTime; }
		bool operator > (const Order& obj) { return endTime > obj.endTime; }

		// bool operator () (const Order& obj) { return endTime > obj.endTime; }

		// bool operator < (int obj) { return beginTime < obj; }
		// bool operator <= (int obj) { return beginTime <= obj; }
		// bool operator > (int obj) { return endTime > obj; }
		// bool operator >= (int obj) { return endTime >= obj; }

	} ;

	bool cmpLess(const Order& x, const Order& y) { return x.beginTime < y.beginTime; }
	bool cmpGreat(const Order& x, const Order& y) { return x.endTime < y.endTime; }

    void handleInputReq(std::vector<std::vector<int > > & array) {
        int n;
        std::cin >> n;
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

	void handleInputOrd(std::multiset<Order,bool(*)(const Order&, const Order&)> & arrayCoast, std::multiset<Order,bool(*)(const Order&, const Order&)> & arrayTime) {
        int n;
        std::cin >> n;
        for (int i = 0; i < n; i++) {
			Order tmpInputOrder;
			std::cin >> tmpInputOrder.beginTime;
			std::cin >> tmpInputOrder.endTime;
			std::cin >> tmpInputOrder.coast;
            arrayCoast.insert(tmpInputOrder);
            arrayTime.insert(tmpInputOrder);
        }
    }

    int main() {
		std::multiset<Order,bool(*)(const Order&, const Order&) > arrayCoast(cmpLess); 
		std::multiset<Order,bool(*)(const Order&, const Order&) > arrayTime(cmpGreat);
        handleInputOrd(arrayCoast, arrayTime);
        std::vector<std::vector<int> > arrayRequests;
        handleInputReq(arrayRequests);
        std::vector<int> sumOfCosts;
        std::vector<int> sumOfTime;
        int bufCoast = 0;
        int bufTime = 0;
        sumOfCosts.push_back(0);
        sumOfTime.push_back(0);
		std::multiset<Order, std::less<Order> >::iterator itCoast = arrayCoast.begin();
		std::multiset<Order, std::greater<Order> >::iterator itTime = arrayTime.begin();
		for (auto it = arrayTime.begin(); it != arrayTime.end(); ++it) {
			std::cout << "I AM TIME : " << it->beginTime << " - " << it->endTime << std::endl;
		}
        for (; itCoast != arrayCoast.end() && itTime != arrayTime.end(); itCoast++, itTime++)
        {
            bufCoast+= itCoast->coast;
            sumOfCosts.push_back(bufCoast);
            bufTime+= itTime->endTime - itTime->beginTime;
            sumOfTime.push_back(bufTime);
        }
		for (int i = 0; i < sumOfTime.size(); ++i) {
			std::cout << "I AM SUM : " << i << " - " << sumOfTime[i] << std::endl;
		}
        for (int i = 0; i < arrayRequests.size(); i++) {
            int start = 0;
            int fin = 0;
			Order tmpLower;
			Order tmpUpper;
            if (arrayRequests[i][2] == 1) {
				tmpLower.beginTime = arrayRequests[i][0];
				tmpUpper.beginTime = arrayRequests[i][1];
				auto Upper = arrayCoast.upper_bound(tmpUpper);
				auto Lower = arrayCoast.lower_bound(tmpLower);
				start = std::distance(arrayCoast.begin(), Lower);
				fin = std::distance(arrayCoast.begin(), Upper);
            //     for (; fin < arrayOrders.size(); ++fin)
            //     {
            //         if(arrayOrders[fin][0] < arrayRequests[i][0])
            //             ++start;
            //         if(arrayOrders[fin][0] > arrayRequests[i][1])
            //         {
            //             break;
            //         }
            //     }
                std::cout << sumOfCosts[fin]- sumOfCosts[start] << ' '; 
            }
            else if(arrayRequests[i][2] == 2) {
				tmpLower.endTime = arrayRequests[i][0];
				tmpUpper.endTime = arrayRequests[i][1];
				auto Upper = arrayTime.upper_bound(tmpUpper);
				auto Lower = arrayTime.lower_bound(tmpLower);
				start = std::distance(arrayTime.begin(), Lower);
				fin = std::distance(arrayTime.begin(), Upper);
            //     int start = 0;
            //     int fin = 0;
            //     for (; fin < arrayOrders.size(); ++fin)
            //     {
            //         if(arrayOrdersSecond[fin][1] < arrayRequests[i][0])
            //             ++start;
            //         if(arrayOrdersSecond[fin][1] > arrayRequests[i][1])
            //         {
            //             break;
            //         }
            //     }
                std::cout << sumOfTime[fin]- sumOfTime[start] << ' ';
            }
        }
		std::cout << std::endl;
        exit(0);
    }