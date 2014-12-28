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

class RosePetals {
public: int getScore (vector<int> dice) {

	int sum = 0;
	vector<pair <int , int> > x(6);

		x[0].first = 1; x[0].second = 0;
		x[1].first = 2; x[1].second = 0;
		x[2].first = 3; x[2].second = 2;
		x[3].first = 4; x[3].second = 0;
		x[4].first = 5; x[4].second = 4;
		x[5].first = 6; x[5].second = 0;

		for (int i = 0; i < (int)dice.size(); i++)
		{
			for (int j = 0; j < (int)x.size(); j++)
			{
				if(dice[i] == x[j].first)
				{
					sum += x[j].second;
					break;
				}

			}
		}

		return sum;
}
};

int main () {

	vector <int> x(5);

		 x[0] = 1;
		 x[1] = 2;
		 x[2] = 3;
		 x[3] = 2;
		 x[4] = 1;

		 RosePetals d;
		 cout << d.getScore(x);

	return 0;
}
