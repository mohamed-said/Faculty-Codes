#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	bool iso = true;
	vector<string> flag(n);
	for (int i = 0; i < n; i++) {
		cin >> flag[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (flag[i][j] != flag[i][j + 1]) {
				iso = false;
				break;
			}
			if (i > 0) {
				if (flag[i][j] == flag[i - 1][j]) {
					iso = false;
					break;
				}
			}
		}
		if (!iso)
			break;
	}
	(iso) ? cout << "YES" : cout << "NO";
	return 0;
}
