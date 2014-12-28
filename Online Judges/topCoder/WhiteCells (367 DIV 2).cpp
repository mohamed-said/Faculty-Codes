#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cmath>
#include <set>
#include <utility>
#include <iterator>
#include <list>
#include <cmath>
#include <iomanip>
#include <memory>
#include <map>
#include <exception>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define Round(x) int(x + 0.5)
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
#define pb push_back
#define sz(x) (int)x.size()
#define ins insert
#define getmax(a,b) ((a)>(b)?(a):(b))
#define OOR out_of_range

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef set<string> sets;
typedef set<char> setc;
typedef pair<int, int> pii;

//		cout << "(" << i << ", " << j << ")" << endl;
class WhiteCells {
public:
int countOccupied(vector <string> board) {

	int sum = 0;
	for (int i = 0; i < sz(board); i++) {
		for (int j = 0; j < sz(board); j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				if (board[i][j] == 'F')
					sum++;
			} else if (i % 2 == 1 && j % 2 == 1) {
				if (board[i][j] == 'F')
					sum++;
			}
		}
	}
	return sum;
}
};

int main () {

		string arr[] = {".F.F...F",
				 "F...F.F.",
				 "...F.F.F",
				 "F.F...F.",
				 ".F...F..",
				 "F...F.F.",
				 ".F.F.F.F",
				 "..FF..F."};
//		int arr2[] = {3, 4};
		vector<string> vec(arr, arr + sizeof(arr) / sizeof(*arr));
//		vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(*arr2));

		WhiteCells d;
		cout << d.countOccupied(vec);
	return 0;
}
