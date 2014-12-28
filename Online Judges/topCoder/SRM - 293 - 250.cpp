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

class Aquarium {
public:
	int peaceful(int minSize, int maxSize, vector<int> fishSizes) {

		unsigned int i , j;
		bool h = true;
		set<int> res;
		set<int>::iterator it;
		for (j = minSize; j <= maxSize; j++)
			{
				h = true;
				for (i = 0; i < fishSizes.size(); i++)
				{
					if ( (j >= (fishSizes[i] * 2) && j <= (fishSizes[i] * 10))
					|| (fishSizes[i] >= (2 * j) && fishSizes[i] <= (10 * j)) )
					{
						h = false;
						break;
					}
				}
				if(h)
				res.insert(j);
			}

//			cout << res.size();
			return res.size();
	}
};
