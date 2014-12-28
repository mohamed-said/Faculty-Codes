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

class TestCurve {
public: vector <int> determineGrades(vector <int> scores)
{
	float max = *max_element(scores.begin() , scores.end()) , pro = 0;
	pro = max / 100;
	for (int i = 0; i < (int)scores.size(); i++)
	{
		if(scores[i] == (int)max)
			scores[i] = 100;
		else
		scores[i] = floor(scores[i] / pro);
	}
	return scores;

}
};

int main()
{
	vector<int> x(7) , y(7);
		 x[0] = 1234;
		 x[1] = 3483;
		 x[2] = 234;
		 x[3] = 5738;
		 x[4] = 3421;
		 x[5] = 5832;
		 x[6] = 4433;


	TestCurve d;
	y = d.determineGrades(x);
	for(int i = 0; i < 7; i++)
	{
		cout << y[i] << " ";
	}

	//arena
//	{21, 59, 4, 98, 58, 100, 76 }

//args {1234, 3483, 234, 5738, 3421, 5832, 4433}
//recieved	{21, 60, 4, 98, 59, 100, 76}

	return 0;
}

