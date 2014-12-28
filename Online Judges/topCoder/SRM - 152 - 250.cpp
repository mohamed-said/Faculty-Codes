#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class GrabbingTaxi {
public:
	int minTime(vector<int> tXs, vector<int> tYs, int gX, int gY, int walkTime,
			int taxiTime) {

		int distance = abs(gX) + abs(gY);
		int res = distance * walkTime;
		for (int i = 0; i < tXs.size(); i++) {
			int TD = (abs(tXs[i]) + abs(tYs[i]));
			int cmp = (TD * walkTime);
			int tto = (abs(gX - tXs[i]) + abs(gY  - tYs[i])) * taxiTime;
			if (cmp + tto < res)
				res = cmp + tto;
		}
		return res;
	}
};
