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

class MultiRead {
public:int minCycles(string trace, int procs)
{
	int cnt = 0 , Rs = 0;

	for (int i = 0; i < (int)trace.size(); i++)
	{
		if(trace[i] == 'R')
		{
			Rs++;
			if(i == (int)trace.size() - 1)
			{
				cnt += Rs / procs;
				if(Rs % procs >= 1)
				{
					cnt++;
				}
				Rs = 0;
			}
		}
		else
		{
			cnt++;
			if(Rs <= procs && Rs != 0) {
				cnt++;
				Rs = 0;
			}
			else
			{
			cnt += Rs / procs;
			if(Rs % procs >= 1)
			{
				cnt++;
			}
			Rs = 0;
			}
		}
	}

	return cnt;
}
};

int main ()
{
	MultiRead d;
	cout << d.minCycles("RRRRRRRRRRRRRRRRRRWRRRRRRRRRRRRRRRRRRRWRRWRWRRRWRW", 5);


	return 0;
}
