#include <iostream>
#include <vector>

using namespace std;

#define sz(x) (int)x.size()



class Sortness {
public: double getSortness(vector <int> a) {

	double sum = 0, sumTemp = 0, size = sz(a);
	for (int element = 0; element < sz(a); element++) {
		for (int i = element; i < sz(a); i++) {
			if (a[i] < a[element])
				sumTemp++;
		}
		for (int i = element; i >= 0; i--) {
			if (a[i] > a[element])
				sumTemp++;
		}
	}
	sum = ((double)sumTemp / (double)size);
	return sum;
}
};

int main () {

		int arr[] = {3,2,1,4,6,7,5,8};
//		int arr2[] = {3, 4};
		vector<int> vec(arr, arr + sizeof(arr) / sizeof(*arr));
//		vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(*arr2));

		Sortness d;
		cout << d.getSortness(vec);

	return 0;
}
