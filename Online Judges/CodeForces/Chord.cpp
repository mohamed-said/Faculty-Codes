#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define sz(x) (int)x.size()
#define pb push_back
#define all(x) x.begin(), x.end()
//				  0    1     2    3     4    5    6     7    8     9    10   11
string arr[] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H" };
vector<string> notes(arr, arr + sizeof(arr) / sizeof(*arr));

int getDistance(string x, string y) {
	int x_idx, y_idx;
	for (int i = 0; i < sz(notes) ; i++) {
		if (notes[i] == x)
			x_idx = i;
		if (notes[i] == y)
			y_idx = i;
	}

	if (y_idx < x_idx)
		return 12 % (x_idx - y_idx);
	return (y_idx - x_idx);
}

string getType(vector<string> CHORDS) {
	vector<vector<string> > perms(6, vector<string>(3));

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			perms[i][j] = CHORDS[j];
		}
		next_permutation(all(CHORDS));
	}

	for (int i = 0; i < 6; i++) {
		if (getDistance(perms[i][0], perms[i][1]) == 4
				&& getDistance(perms[i][1], perms[i][2]) == 3) {
			return "major";
		} else if (getDistance(perms[i][0], perms[i][1]) == 3
				&& getDistance(perms[i][1], perms[i][2]) == 4) {
			return "minor";
		}
	}

	return "strange";
}

int main() {
	vector<string> CHORDS;
	string chord;

	int in = 3;

	while (in--) {
		cin >> chord;
		CHORDS.pb(chord);
	}
	cout << getType(CHORDS);
	return 0;
}
