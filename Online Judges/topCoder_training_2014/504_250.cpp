#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

#define sz(x) (int)x.size()
#define MIN(x, y) (x < y) ? x : y
#define MAX(x, y) (x < y) ? y : x 

using namespace std;

class ComparerInator {
public:

	int makeProgram(vector<int> A, vector<int> B, vector<int> wanted) {

		bool a, b, c, d;
		a = b = c = d = 1;
		int size = sz(A);
		
		for (int i = 0; i < size; i++) {
			if (A[i] != wanted[i]) {
				a = 0;
				break;
			}
		}
		if (a) return 1;

		for (int i = 0; i < size; i++) {
			if (B[i] != wanted[i]) {
				b = 0;
				break;
			}
		}
		if (b) return 1;

		for (int i = 0; i < size; i++) {
			if ((MIN(A[i], B[i])) != wanted[i]) {
				c = 0;
				break;
			}
		}
		if (c) return 7;

		for (int i = 0; i < size; i++) {
			if ((MAX(A[i], B[i])) != wanted[i]) {
				d = 0;
				break;
			}
		}
		if (d) return 7;
		return -1;
	}
};


int main() {

	int A[] = {1,5,6,7,8};
	int B[] = {1,5,6,7,8};
	int C[] = {1,5,6,7,8};

	vector<int> v1(A, A + sizeof(A) / sizeof(*A));
	vector<int> v2(B, B + sizeof(B) / sizeof(*B));
	vector<int> v3(C, C + sizeof(C) / sizeof(*C));

	ComparerInator d;
	cout << d.makeProgram(v1, v2, v3) << endl;
	return 0;
}


/*

    	
{1}
{2}
{2}
Returns: 1
    	
{1,3}
{2,1}
{2,3}
Returns: 7
    	
{1,3,5}
{2,1,7}
{2,3,5}
Returns: -1
    	
{1,3,5}
{2,1,7}
{1,3,5}
Returns: 1
    	
{1,2,3,4,5,6,7,8,9,10,11}
{5,4,7,8,3,1,1,2,3,4,6}
{1,2,3,4,3,1,1,2,3,4,6}
Returns: 7
    	
{1,5,6,7,8}
{1,5,6,7,8}
{1,5,6,7,8}
Returns: 1

*/