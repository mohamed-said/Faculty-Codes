
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//my_code
class TheProgrammingContestDivTwo {
public:
	vector<int> find(int T, vector<int> requiredTime) {
		int solved = (int)requiredTime.size();
		int penalty = 0;

		vector<int> res(2);
		
		sort(requiredTime.begin(),requiredTime.end());
		if (requiredTime.size() == 1) {
			res[0] = requiredTime[0] <= T;
			if (res[0]) res[1] = requiredTime[0];
			return res;
		}
		
		penalty = requiredTime[0];
		for (int i = 1; i < (int)requiredTime.size(); i++) {
			requiredTime[i] += requiredTime[i - 1];
			if (requiredTime[i] > T) {
				solved = i;
				break;
			}
			penalty += requiredTime[i];
		} 		
		res[0] = solved;
		res[1] = penalty;
		return res;
	}


};

//---------

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//editorial code
class TheProgrammingContestDivTwo {
public:
	vector<int> find(int T, vector<int> requiredTime) {
//		int solved = (int)requiredTime.size();
		int solved = 0;
		int penalty = 0;
		int time = 0;
		
		vector<int> res(2);
		
		sort(requiredTime.begin(),requiredTime.end());

/*		if (requiredTime.size() == 1) {
			res[0] = requiredTime[0] <= T;
			if (res[0]) res[1] = requiredTime[0];
			return res;
		}
*/		
//		penalty = requiredTime[0];
		for (int i = 0; i < (int)requiredTime.size() && time + requiredTime[i] <= T; i++) {
			solved++;
			time += requiredTime[i];
			penalty += time;
		}
		res[0] = solved;
		res[1] = penalty;
		return res;
	}
};

