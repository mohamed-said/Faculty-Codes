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
#include <memory>
#include <map>

#define Round(x) int(x + 0.5)
#define all(x) x.begin(),x.end()

using namespace std;

class InsertionSortCount {
public:
	int countMoves(vector<int> A)
	{
		int cnt = 0;
		int size = (int) A.size();
		vector<int> test = A;
		sort(all(test));
		while (true)
		{
			for (int i = 0; i < size - 1; i++)
			{
				if (A[i] > A[i + 1])
				{
					swap(A[i], A[i + 1]);
					cnt++;
					break;
				}
			}
			if(test == A)
				break;
		}

		return cnt;
	}
};

int main() {

	vector<int> v(10);
		v[0] = 10;
		v[1] = 9;
		v[2] = 8;
		v[3] = 7;
		v[4] = 6;
		v[5] = 5;
		v[6] = 4;
		v[7] = 3;
		v[8] = 2;
		v[9] = 1;

		InsertionSortCount d;
		cout << d.countMoves(v);

	// {{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}}


	return 0;
}
