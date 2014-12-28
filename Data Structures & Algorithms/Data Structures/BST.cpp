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


class heap {
public:
	vi vec;
	int get_max() {
		return vec[0];
	}

	void pop_max() {
		vec[0] = vec[sz(vec) - 1];
		vec.pop_back();
		int i = 0;
		while (i < sz(vec) ) {
			if (vec[(2 * 1) + 1] > vec[(2 * 1) + 2]) {
				swap(vec[i], vec[(2 * 1) + 1]);
				i = vec[(2 * 1) + 1];
			} else if (vec[(2 * 1) + 1] < vec[(2 * 1) + 2]) {
				swap(vec[i], vec[(2 * i) + 2]);
				i = vec[(2 * i) + 2];
			} else
				break;
		}
	}

	void insert(int x) {
		vec.pb(x);
		if (sz(vec) == 1)
			return;
		int i = sz(vec) - 1;
		while (i > 0) {
			if (vec[i] > vec[(i - 1) / 2]) {
				swap(vec[i], vec[(i - 1) / 2]);
				i = (i - 1) / 2;
			} else
				break;
		}
	}

	void print() {
		for (int i = 0; i < sz(vec) ; i++)
			cout << vec[i] << " ";
		cout << endl;
	}
};

int BS(int key, int arr[], int low, int high) {
	int mid = low + (high - low) / 2;
	if (low >= high)
		return -1;
	if (key == arr[mid])
		return mid;
	if (key > arr[mid])
		return BS(key, arr, mid + 1, high);
	return BS(key, arr, low, mid);
}

int main() {

	heap d;
	d.insert(10);
	d.insert(30);
	d.insert(15);
	d.insert(20);
	d.insert(35);
	d.insert(100);
	d.insert(50);

	d.print();
	d.pop_max();
	d.print();

//	int arr[5] = { 1, 12, 25, 26, 70 };
//	int arr2[5] = { 1, 2, 16, 18, 20 };
//	int arr3[5] = { 10, 43, 45, 60, 66 };
//
//	cout << BS(12, arr, 0, 5);
//
//	vi vec1(arr, arr + sizeof(arr) / sizeof(*arr));
//	vi vec2(arr2, arr2 + sizeof(arr2) / sizeof(*arr2));
//	vi vec3(arr3, arr3 + sizeof(arr3) / sizeof(*arr3));
//	vi vec4;
//
//	for (int i = 0; i < sz(vec1); i++)
//		vec4.pb(vec1[i]);

	return 0;
}
