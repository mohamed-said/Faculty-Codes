#include <iostream>
#include <algorithm>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib> 
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;
using namespace __gnu_cxx;

#define sz(x) (int)x.size()
#define round(x) (int)(x + 0.5)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define ins insert
#define getmax(a,b) ((a) > (b) ? (a) : (b))
#define getmin(a,b) ((a) > (b) ? (b) : (a))
#define mms(x,n,s) memset(x, n, sizeof(x) * s)
#define CV(x,n) count(all(x),(n))
#define FOR(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define rep(i, x, n) for (int (i) = (x); (i) < (n); (i)++)

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<pair<int, int> > vpii;
typedef set<int> si;

int di[] = {1, 0, -1, 0};
int dj[] = {0, 1, 0, -1};
int d8i [] = {0, 0, 1, -1, 1, 1, -1, -1};
int d8j [] = {1, -1, 0, 0, 1, -1, 1, -1};

    /*           \\^//           /*
    | |    Magic Starts Here     | |
    */           // \\           * /


void merge(vll &numbers, vll &other, int leftPosition, int rightPosition, int rightEnd) {
	int leftEnd = rightPosition - 1;
	int tempPosition = leftPosition;
	int numElements = rightEnd - leftPosition + 1;

	while (leftPosition <= leftEnd && rightPosition <= rightEnd) {
		if (numbers[leftPosition] <= numbers[rightPosition])
			other[tempPosition++] = numbers[leftPosition++];
		else
			other[tempPosition++] = numbers[rightPosition++];
	}

	while (leftPosition <= leftEnd)
		other[tempPosition++] = numbers[leftPosition++];

	while (rightPosition <= rightEnd)
		other[tempPosition++] = numbers[rightPosition++];

	for (int i = 0; i < numElements; ++i, rightEnd--)
		numbers[rightEnd] = other[rightEnd];
}

void mergeSort(vll &numbers, vll &other, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(numbers, other, left, mid);
		mergeSort(numbers, other, mid + 1, right);
		merge(numbers, other, left, mid + 1, right);
	}
}


// merge sort adapter
void mergeSort(vll &numbers) {
	vll other(sz(numbers));
	mergeSort(numbers, other, 0, sz(numbers) - 1);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("sum2.txt", "rt", stdin);
		freopen("out.txt", "wt", stdout);
	#endif

	std::ios_base::sync_with_stdio(false);

	ll arr[3] = {2193980185LL, 21728033LL, 459550302LL};
	ll x;
	char delim;
	vll numbers;
	bool found = false;
	
	while (cin >> x) {
		numbers.pb(x);
		cin >> delim >> delim;
	}

	cout << "Done Reading " << sz(numbers) << " numbers" << endl;

	cout << "N^2 Solution Results" << endl;
	FOR (i, 3) {
		found = false;
		// cout << arr[i] << endl;
		FOR(j, sz(numbers)) {
			FOR(k, sz(numbers)) {
				if (numbers[j] + numbers[k] == arr[i]) {
					cout << "YES .. !" << " " << numbers[j] << " + " << numbers[k] << " = " << arr[i] << endl;
					found = true;
					break;
				}
			}
			// if (found) break;
		}
		if (!found) cout << "NO ===> " << arr[i] << endl;
	}

	cout << "\n\nDONE .. Now the N log N Solution" << endl;

	mergeSort(numbers);
	// FOR(i, sz(numbers)) cout << numbers[i] << endl;
	
	FOR(i, 3) {
		found = false;
		for (int left = 0, right = sz(numbers) - 1; left < right;) {
			if (numbers[left] + numbers[right] == arr[i]) {
				cout << "YES .. !" << " " << numbers[left] << " + " << numbers[right] << " = " << arr[i] << endl;
				found = true;
				break;
			}
			else if (numbers[left] + numbers[right] > arr[i])
				--right;
			else if (numbers[left] + numbers[right] < arr[i])
				++left;
		}
		if (!found) cout << "NO ===> " << arr[i] << endl;
	}

	return 0;
}















