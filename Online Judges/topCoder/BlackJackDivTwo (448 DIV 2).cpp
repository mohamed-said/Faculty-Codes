#include <iostream>
#include <string>
#include <vector>
#include <map>
#define sz(x) (int)x.size()
using namespace std;
class TheBlackJackDivTwo {
public:
	int score(vector<string> cards) {
		map<char, int> m;
		int sum = 0;
		m['A'] = 11;
		m['J'] = 10;
		m['K'] = 10;
		m['Q'] = 10;
		m['T'] = 10;
		m['2'] = 2;
		m['3'] = 3;
		m['4'] = 4;
		m['5'] = 5;
		m['6'] = 6;
		m['7'] = 7;
		m['8'] = 8;
		m['9'] = 9;

		for (int i = 0; i < sz(cards) ; i++) {
			sum += m[cards[i][0]];
		}
		return sum;
	}
};
