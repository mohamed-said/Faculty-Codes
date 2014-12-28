#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cmath>
#include <set>
#include <utility>
#include <iterator>
#include <list>
#include <cmath>
#include <iomanip>
#include <memory>
#include <map>
#include <stdio.h>
#include <stdlib.h>

#define Round(x) int(x + 0.5)
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

class RugSizes {
public:int rugCount(int area)
{
	int temp , cnt = 0;
	for (int i = 1; i <= sqrt(area); i++)
	{
		if (area % i == 0)
		{
			temp = area / i;
			if(i == temp)
			{
				cnt++;
			}
			else if ((i % 2 == 1 && temp % 2 == 0) || (i % 2 == 1 && temp % 2 == 1) || (i % 2 == 0 && temp % 2 == 1))
			{
				cnt++;
			}

		}
	}

	return cnt;
}
};



//////////////////////////////TLE////////////////////////////

class RugSizes {
public:int rugCount(int area)
{
	vector<bool> x(area + 1 , 1);
	int cnt = 0;
	for (int i = 1; i <= (area); i++)
	{
		for (int j = 1; j <= area; j++)
		{
			if(i * j == area)
			{
				if(i == j)
				{
					cout << i << " " << j << endl;
					cnt++;
				}
				else if ((i % 2 == 1 && j % 2 == 0)
						|| (i % 2 == 1 && j % 2 == 1)) {
					if(x[i] == 1 && x[j] == 1)
					{
						cout << i << " " << j << endl;
						cnt++;
						x[i] = 0;
						x[j] = 0;
					}
				}
			}
		}
	}

	return cnt;

}
};


int main() {

	RugSizes d;
	cout << d.rugCount(99997);

	return 0;
}
