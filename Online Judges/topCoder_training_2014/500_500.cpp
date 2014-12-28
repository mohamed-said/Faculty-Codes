#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define sz(x) (int)(x).size()

class MafiaGame {
public:	
	double probabilityToLose(int N, vector<int> decisions) {
		int cnt = 0;
		int cntMax = 0;
		int maxPlayer = 0;
		sort(decisions.begin(), decisions.end());
		for (int i = 0; i < sz(decisions); ++i) {
			if (i == 0 || decisions[i] == decisions[i - 1]) cnt++;
			else cnt = 1;

			if (cnt > cntMax) {
				maxPlayer = 1;
				cntMax = cnt;
			} else if (cnt == cntMax) {
				maxPlayer++;
			}
		}
		int c = maxPlayer;
		if (c == sz(decisions))	return 0.0;
		
		while(1) {
			if (!c) return 0.0;
			if (c == 1) return 1.0/(double)maxPlayer;
			c = N % c;
		}
	} // end of function
};
