#include "Iter.hpp"

template<typename T>
void	demo(T &obj){
	std::cout << "element of array is : " << obj << std::endl;
}

int	main( void )
{
	{
		std::string	strArr[5];

		strArr[0] = "Is";
		strArr[1] = "this";
		strArr[2] = "function";
		strArr[3] = "useful";
		strArr[4] = "?";

		::iter(strArr, 5, &demo);
	}
	{
		std::cout << "****************************************"<< std::endl;
		int*		intArr = new int[5];
		
		for (int i = 0; i < 5; i ++) {
			intArr[i] = 5 - i;
		}

		::iter(intArr, 5, &demo);
		delete [] intArr;
	}
}