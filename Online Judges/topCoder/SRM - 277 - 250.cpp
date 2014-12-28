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

class SandwichBar {
public: int whichOrder(vector <string> available, vector <string> orders) {

	string x;
	bool key = false;
	for (int i = 0; i < (int)orders.size(); i++)
	{
		stringstream ss;
		ss << orders[i];
		while(ss >> x)
		{
			key = false;
			for (int j = 0; j < (int)available.size(); j++)
			{
				if(available[j] == x)
					key = true;
			}
			if(!key)
				break;
		}
		if(key)
			return i;
	}
	return -1;

}
};
