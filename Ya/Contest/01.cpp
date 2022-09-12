#include <iostream>
#include <list>
#include <cstring>
#include <set>

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

int getNumOfDifferentSym(std::string fullName) {
    std::set<char> sym;
    for(int i = 0; i < fullName.size(); ++i) {
        sym.insert(fullName[i]);
    }
    return sym.size();
}

int getSumDayAndMoth(std::string& numbersDayAdnMoth) {
    int result = 0;
    for (int i = 0; i < numbersDayAdnMoth.size(); i++) {
        result += ((int)numbersDayAdnMoth[i]) - 48;
    }
    return result;
}

int getPosition(std::string& sirName) {
    int pos = 0;
    std::string aplhabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    char firstSym = std::toupper(sirName[0]);
    for (; pos < aplhabet.size(); ++pos) {
        if(aplhabet[pos] == firstSym)
            break;
    }
    return ++pos;
}

std::string intToHexLastThree(int sumOfKeys) {
   char hexString[20];
   std::string res;
   sprintf(hexString, "%X", sumOfKeys); //convert number to hex
   std::string HexNum(hexString);
   if (HexNum.size() > 2) {
		for(int i = HexNum.size() - 3 ; i < HexNum.size(); ++i) {
			res += HexNum[i];
		}
   } else {
       res = HexNum;
       while (res.size() < 3) {
           res += '0';
       } 
   }
   return res;
}

std::string getHexEncode(std::list<std::string> listOfStrings) {
    std::string fullName;
    auto it = listOfStrings.begin();
    for(int i = 0; i < 3; ++i) {
        fullName += *it;
        ++it;
    }
    int NumOfDifferentSym = getNumOfDifferentSym(fullName);
    std::string numbersDayAdnMoth = *it;
    ++it;
    numbersDayAdnMoth += *it;
    int sumOfDayAndMothNumbers = getSumDayAndMoth(numbersDayAdnMoth);
    int positionInAlphabet = getPosition(*(listOfStrings.begin()));
    int sumOfKeys = NumOfDifferentSym + (sumOfDayAndMothNumbers * 64) + (positionInAlphabet * 256);
    return intToHexLastThree(sumOfKeys);
}

int main() {
    int numberOfItems;
    std::cin >> numberOfItems;
    std::string tmpInpurString;
    std::list<std::list<std::string> > inputData;
    for(size_t i  = 0; i < numberOfItems; ++i) {
        std::cin >> tmpInpurString;
        inputData.push_back(split(tmpInpurString, ","));
	}
    while(!inputData.empty())
    {
       std::cout << getHexEncode(inputData.front());
       inputData.pop_front();
       if(!inputData.empty())
          std::cout << ' ';
    }
    std::cout << std::endl;
    return 0;
}