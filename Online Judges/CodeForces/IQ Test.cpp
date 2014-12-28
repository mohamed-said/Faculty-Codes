#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, even = 0, odd = 0, res;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n; i++)
		(v[i] % 2 == 0) ? even++ : odd++;

	if (even > odd) {
		for (int i = 0; i < n; i++) {
			if (v[i] % 2 == 1) {
				res = i + 1;
				break;
			}
		}
	} else {
		for (int i = 0; i < n; i++) {
			if (v[i] % 2 == 0) {
				res = i + 1;
				break;
			}
		}
	}
	cout << res;
	return 0;
}
