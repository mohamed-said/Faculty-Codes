#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <cmath>
#include <set>
#include <list>

#define Round(x) int(x + 0.5)

using namespace std;

class AimToTen {
public: int need(vector<int> marks)
{
	int cnt = 0;
	double avg = 0 , avg2 = 0;
	for (unsigned int i = 0; i < marks.size(); i++)
	{
		avg += marks[i];
	}

	avg2 = avg;

	avg /= marks.size();

	if(avg >= 9.5)
		return 0;

	while (true)
	{
		marks.push_back(10);
		cnt++;
		avg2 += 10;

		if(avg2 / (marks.size()) >= 9.5)
			break;
	}

	return cnt;

}
};

int main ()
{

	vector<int> marks(2);
	marks[0] = 9;
	marks[1] = 8;
//	marks[2] = 10;
//	marks[3] = 9;

	AimToTen d;
	cout << d.need(marks);


	return 0;
}
