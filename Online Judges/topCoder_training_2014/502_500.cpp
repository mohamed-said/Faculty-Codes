#include <iostream>
#include <vector>
#include <set>
#include <cmath>

#define sz(x) (int)x.size()

using namespace std;

class TheLotteryBothDivs {
public:

	bool isSuffix(string a, string b) {
		if (sz(b) <= sz(a)) return false;
		return (b.substr(sz(b) - sz(a)) == a);
	}
	double find(vector <string> goodSuffixes) {
		long double prob = 0.0;
		set<string> S;
		for (int i = 0; i < sz(goodSuffixes); S.insert(goodSuffixes[i++]));		
		vector<string> tmp;
		set<string>::iterator it = S.begin();
		for (; it != S.end(); it++) tmp.push_back(*it);
		
		for (int i = 0; i < sz(tmp); i++) {
			bool suffix = false;
			for (int j = 0; j < sz(tmp); j++) {
				if (isSuffix(tmp[j], tmp[i])) {
				// tmp[j] = "-1";
					suffix = true;
					break;
				}
			}
			if (!suffix)
				prob += pow(10, 9 - sz(tmp[i]));
		}
		
		// for (int i = 0; i < tmp.size(); i++)
		// 	if (tmp[i] != "-1")
		return prob / 1000000000.0;
	}
};

int main() {
	TheLotteryBothDivs d;
	string arr[] = {"8542861", "1954", "6", "523", "000000000", "5426", "8"};
	vector<string> vec(arr, arr + sizeof(arr) / sizeof(*arr));
	cout << d.find(vec) << endl;

}
/*    

{"47", "58", "4747", "502"}
Returns: 0.021

{"8542861", "1954", "6", "523", "000000000", "5426", "8"}
Returns: 0.201100101

*/

// --- 

#include <iostream>
#include <vector>
#include <set>
#include <cmath>

#define sz(x) (int)x.size()

using namespace std;

class TheLotteryBothDivs {
public:

	bool isSuffix(string a, string b) {
		if (sz(b) <= sz(a)) return false;
		return (b.substr(sz(b) - sz(a)) == a);
	}
	double find(vector <string> goodSuffixes) {
		long double prob = 0.0;
		set<string> S;
		for (int i = 0; i < sz(goodSuffixes); S.insert(goodSuffixes[i++]));		
		vector<string> tmp;
		set<string>::iterator it = S.begin();
		for (; it != S.end(); it++) tmp.push_back(*it);
		for (int i = 0; i < sz(tmp); i++) {
			for (int j = 0; j < sz(tmp); j++) {
				if (isSuffix(tmp[i], tmp[j])) tmp[j] = "-1";
			}
		}
		
		for (int i = 0; i < tmp.size(); i++)
			if (tmp[i] != "-1")
				prob += pow(10, 9 - sz(tmp[i]));
		return prob / 1000000000.0;
	}
};