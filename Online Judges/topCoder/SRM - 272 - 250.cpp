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

class HammingDistance {
public:int minDistance(vector<string> numbers)
{
	int min = 55 , cnt = 0;;

	for (int i = 0; i < (int)numbers.size(); i++)
	{
		for (int j = 0; j < (int)numbers.size(); j++)
		{
			cnt = 0;

			if(i == j)
				continue;

			for (int k = 0; k < (int)numbers[i].size(); k++)
			{
				if(numbers[i][k] != numbers[j][k])
					cnt++;
			}
			if(cnt < min)
				min = cnt;
		}
	}

	return min;
}
};

int main()
{
//	{{"0000000000", "1111111111", "1000000000"}}

	vector<string> x(3);
	x[0] = "0000000000";
	x[1] = "1111111111";
	x[2] = "1000000000";
//	x[3] = "11";

	HammingDistance d;
	cout << d.minDistance(x);

	return 0;
}

