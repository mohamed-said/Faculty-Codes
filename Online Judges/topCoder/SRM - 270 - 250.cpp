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
class BuyingCheap {
public: int thirdBestPrice(vector<int> prices)
{

	set<int> res;
	set<int>::iterator it;
	res.insert(prices.begin() , prices.end());

	if(res.size() < 3)
		return -1;

	it = res.begin();
	it++;
	it++;
	return *it;

}
};



int main ()
{

	vector<int> x(10);
		 x[0] = 80;
		 x[1] = 90;
		 x[2] = 80;
		 x[3] = 90;
		 x[4] = 80;
		 x[5] = 80;
		 x[6] = 30;
		 x[7] = 90;
		 x[8] = 60;
		 x[9] = 40;

	BuyingCheap d;
	cout << d.thirdBestPrice(x);


	return 0;
}
