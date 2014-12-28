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

class BasketsWithApples {
public:int removeExcess(vector <int> apples)
{
	int max = 0 , sum = 0;

	sort(apples.begin() , apples.end());
	vector<int>::iterator it;
	for (int i = 0; i < (int)apples.size(); i++)
	{
		sum = 0;
		for (it = apples.begin() + i ; it != apples.end(); it++)
		{
			sum += apples[i];
		}
		if(sum > max)
			max = sum;
	}

	return max;
}
};


int main()
{
	vector <int> x(6);
		 x[0] = 24;
		 x[1] = 92;
		 x[2] = 38;
		 x[3] = 0;
		 x[4] = 79;
		 x[5] = 45;


	BasketsWithApples d;
	cout << d.removeExcess(x);

	return 0;
}

