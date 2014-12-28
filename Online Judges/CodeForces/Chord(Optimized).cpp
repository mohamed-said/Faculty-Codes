#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define sz(x) (int)x.size()
#define pb push_back
#define all(x) x.begin(), x.end()

string arr[] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H" };

int getDistance(string x, string y) {
	int x_idx, y_idx;
	for (int i = 0; i < 12; i++) {
		if (arr[i] == x)
			x_idx = i;
		if (arr[i] == y)
			y_idx = i;
	}
	if (y_idx < x_idx)
		return 12 % (x_idx - y_idx);
	return (y_idx - x_idx);
}

string getType(string CHORDS[]) {

	do {
		if (getDistance(CHORDS[0], CHORDS[1]) == 4
				&& getDistance(CHORDS[1], CHORDS[2]) == 3) {
			return "major";
		} else if (getDistance(CHORDS[0], CHORDS[1]) == 3
				&& getDistance(CHORDS[1], CHORDS[2]) == 4) {
			return "minor";
		}
	} while (next_permutation(CHORDS, CHORDS + 3));

	return "strange";
}

int main() {
	string arr[3];

	cin >> arr[0];
	cin >> arr[1];
	cin >> arr[2];

	sort(arr, arr + 3);
	cout << getType(arr);

	return 0;
}
