#include <iostream>
using namespace std;

bool isPrime(int num) {
	for(int i = 2; i * i <= num; i++)
		if(num % i == 0)
			return 0;
	return 1;
}

int getNextPrime(int n) {
	while (!isPrime(n)) ++n;
	return n;
}

int main() {

	int n;
	cin >> n;
	cout << getNextPrime(n) << endl;
	return 0;
}