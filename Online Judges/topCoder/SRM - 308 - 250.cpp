#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cmath>
#include <set>
#include <utility>
#include <iterator>
#include <list>
#include <cmath>

#define Round(x) int(x + 0.5)

using namespace std;

class MedianOfNumbers {
public:int findMedian(vector <int> numbers) {

	if((int)numbers.size() % 2 != 0)
	{
		return -1;
	}

	sort(numbers.begin() , numbers.end());
	return numbers[numbers.size() / 2];

}
};
