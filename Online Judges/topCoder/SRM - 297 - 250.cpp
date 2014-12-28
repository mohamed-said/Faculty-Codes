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

class PackingParts {
public: int pack(vector <int> partSizes, vector <int> boxSizes) {

	int cnt = 0;
	for (int i = 0; i < (int)partSizes.size(); i++)
	{
		for (int j = 0; j < (int)boxSizes.size(); j++)
		{
			if(partSizes[i] <= boxSizes[j])
			{
				cnt++;
				boxSizes[j] = 0;
				break;
			}
		}

	}
	return cnt;
}
};
