#include <iostream>
#include <set>
using namespace std;
class TheBeauty {
public:
	int find(int n) {
		set<int> s;
		while (n > 0) {
			s.insert(n % 10);
			n /= 10;
		}
		return s.size();
	}
};
