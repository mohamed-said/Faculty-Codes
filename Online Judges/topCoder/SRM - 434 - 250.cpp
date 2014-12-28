#include <iostream>

using namespace std;

class LeastMajorityMultiple {
public:
	static int leastMajorityMultiple(int a, int b, int c, int d, int e) {
		int res = 0;
		int cnt = 0;
		int arr[5] = {a, b, c, d, e};
		for (int i = 1; i < 1000000; i++) {
			for (int j = 0; j < 5; j++) {
				if (i % arr[j] == 0)
					++cnt;
			}
			if (cnt >= 3) {
				res = i;
				break;
			}
			cnt = 0;
		}
		return res;
	}


};

int main() {
	cout << LeastMajorityMultiple::leastMajorityMultiple(30, 45, 23, 26, 56);
	return 0;
}
