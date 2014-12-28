#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int arr[907];
int mat[37][37];

int main() {

	int n, k, segmant;
	scanf("%i%i", &n, &k);
	for (int i = 0; i <= (n * k) + 1; i++)
		arr[i] = i;

	for (int i = 0; i < k; i++) {
		scanf("%i", &segmant);
		mat[i][0] = arr[segmant];
		arr[segmant] = -1;
	}

	int goOnArr = 1;
	for (int i = 0; i < k; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[goOnArr] == -1) {
				--j;
				++goOnArr;
			} else {
				mat[i][j] = arr[goOnArr];
				++goOnArr;
			}
		}
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			printf("%i ", mat[i][j]);
		}
		cout << endl;
	}
	return 0;
}
