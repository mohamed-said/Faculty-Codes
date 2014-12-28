#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SRMCards {
public:
	int maxTurns(vector<int> cards) {
		sort(cards.begin(), cards.end());
		int turns = 0;
		for (int i = 0; i < (int)cards.size();) {
			if (cards[i] - cards[i + 1] == -1) i += 2;
			else i++;
			turns++;
			if (i == cards.size() - 1) {turns++;break;}
		}
		return turns;
	}
};

int main() {
	int arr[] = {498, 499};
	vector<int> x(arr, arr + sizeof(arr) / sizeof(*arr));
	SRMCards d;
	cout << d.maxTurns(x) << endl;
	return 0;
}