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


ll numberofInversions = 0LL; // 

void displayArrays(vector<int>& sorted, vector<int>& unsorted) {
	for (int i = 0; i < sz(sorted); ++i)
		cout << sorted[i] << " ";
	cout << endl << endl;
	
	for (int i = 0; i < sz(unsorted); ++i)
		cout << unsorted[i] << " ";
	cout << endl << endl;

	cout << "OK .. " << endl;
}

void merge(vector<int>& given, vector<int>& temp, int leftPosition, int rightPosition, int rightEnd) {
	int leftEnd = rightPosition - 1;
	int tempPosition = leftPosition;
	int numElements = rightEnd - leftPosition + 1;
		
	while (leftPosition <= leftEnd && rightPosition <= rightEnd) {
		if (given[leftPosition] <= given[rightPosition]) {
			temp[tempPosition++] = given[leftPosition++];
		} else {
			numberofInversions += leftEnd - leftPosition + 1;
			temp[tempPosition++] = given[rightPosition++];
		}
	}
	
	while (leftPosition <= leftEnd)
		temp[tempPosition++] = given[leftPosition++];
	while (rightPosition <= rightEnd)
		temp[tempPosition++] = given[rightPosition++];
		
	for (int i = 0; i < numElements; ++i, rightEnd--)
		given[rightEnd] = temp[rightEnd];
}

void mergeSort(vector<int>& given, vector<int>& temp, int left, int right) {
	
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(given, temp, left, mid);
		mergeSort(given, temp, mid + 1, right);
		merge(given, temp, left, mid + 1, right);
	}
}

// merge sort algorithm driver
// creates the temporary vector
void mergeSort(vector<int>& given) {
	
	vector<int> temp(sz(given));
	mergeSort(given, temp, 0, sz(given) - 1);
	
}

int main() {
	
	
	
	
	#ifndef ONLINE_JUDGE
		freopen("IntegerArray.txt", "rt", stdin);
		//freopen("out.txt", "wt", stdout);
	#endif
	std::ios_base::sync_with_stdio(false);

	int input;
	vector<int> integerArray;
	vector<int> unsortedIntegerArray;

	cout << "Done Declaring" << endl;
	
	while (cin >> input) {
		integerArray.pb(input);
		unsortedIntegerArray.pb(input);
	}
	
	cout << "Done reading" << endl;
	cout << sz(integerArray) << " Elements"  << endl;
	
	/*
		Now both of the two vectors (integerArray - unsortedIntegerArray)
		has the same elements with the same order
		let's now sort only the 'integerArray' vector.
	*/

	cout << "Sorting ... NOTE: This may take some long long time :D" << endl;
	mergeSort(integerArray); // now works
	cout << "Done Sorting ,, Congratulaitons ,, We are still alive :D" << endl;

	cout << "Number of inversions for the given set of integers: " << endl;
	cout << numberofInversions << endl;

	return 0;
}
