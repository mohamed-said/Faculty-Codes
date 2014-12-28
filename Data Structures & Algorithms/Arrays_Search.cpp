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


//int S(int key,int arr[],int size) {
//	int i;
//	for (i = 0; i < size; i++) {
//		if (arr[i] == key)
//			break;
//	}
//	if (i < size)
//		return i;
//	return -1;
//}
//
//int* S2(int key,int arr[],int size) {
//	int i;
//	for (i = 0; i < size; i++) {
//		if (arr[i] == key)
//			break;
//	}
//	if (i < size)
//		return &i;
//	return NULL;
//}


int BS (int key, int arr[], int low, int high) {
	int mid = low + (high - low) / 2;
	if (low >= high)
		return -1;
	if (key == arr[mid])
		return mid;
	if (key > arr[mid])
		return BS(key, arr, mid + 1, high);
	return BS(key, arr, low, mid);
}

int* BS2 (int key, int arr[], int low, int high) {
	int mid = low + (high - low) / 2;
	if (low >= high)
		return NULL;
	if (key == arr[mid])
		return &arr[mid];
	if (key > mid)
		return BS2(key, arr, mid + 1, high);
	return BS2(key, arr, low, mid);
}


int main() {
	int P[10] = {1, 1, 3, 4, 5, 6, 7, 8, 9, 10};
	int search;
	cin >> search;

//	cout << "Index is: " << S(search, P, 10) << endl;
//	cout << "Index is: " << S2(search, P, 10) << endl;

	cout << "Index is: " << BS(search, P, 0, 9) << endl;
//	cout << "Address is: " << BS2(search, P, 0, 9) << endl;



	return 0;
}
