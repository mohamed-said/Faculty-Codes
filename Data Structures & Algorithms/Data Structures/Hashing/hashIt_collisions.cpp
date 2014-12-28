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
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;
using namespace __gnu_cxx;

#define Round(x) int(x + 0.5)
#define all(x) x.begin(),x.end()
#define rall(x) x.end(),x.begin()
#define pb push_back
#define sz(x) (int)x.size()
#define ins insert
#define getmax(a,b) ((a)>(b)?(a):(b))
#define getmin(a,b) ((a)>(b)?(b):(a))
#define OOR out_of_range

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef set<string> sets;
typedef set<char> setc;
typedef pair<int, int> pii;

vs allDictionaryWords;
vs randomlyPickedWords;
//int testRaanges[4] = {2000, 400, 6000, 8000};
vs hashTable;

int getNextPrime(int num);
unsigned long djb2(string str);
unsigned long sdbm(string str);
void loadFile();
void pickRandomWords(int numberOfWords);
int getNextPrime(int num);
void runProgram();
int buildTableANDtest(int numberOfWords);

int main() {

	runProgram();
	return 0;
}

unsigned long djb2(string str) {
	int hash = 5381;
	int c;
	for (int i = 0; i < sz(str) ; i++) {
		c = str[i];
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return hash;
}

unsigned long sdbm(string str) {
	int hash = 0;
	int c;
	for (int i = 0; i < sz(str) ; i++) {
		c = (int)str[i];
		hash = c + (hash << 6) + (hash << 16) - hash;
	}
	return hash;
}

// loading usernames and password from the file
void loadFile() {
	ifstream file;
	file.open("Dictionary.txt", ios::in);
	if (file.fail()) {
		cout << "Error opening file !!!" << endl;
		return;
	}
	while (!file.eof()) {
		string line;
		file >> line;
		allDictionaryWords.pb(line);
	}
}

void pickRandomWords(int numberOfWords) {
	srand(time(NULL));
	randomlyPickedWords.resize(numberOfWords);
	int dictionarySize = sz(allDictionaryWords);
	for (int i = 0; i < numberOfWords; i++) {
		randomlyPickedWords[i] = (allDictionaryWords[rand() % dictionarySize]);
	}
}

int getNextPrime(int num) {
	bool prime = false;
	while (num++) {
		prime = true;
		for (int i = 2; i < num; i++) {
			if (num % i == 0) {
				prime = false;
				break;
			}
		}
		if (prime)
			break;
	}
	return num;
}

int buildTableANDtest(int numberOfWords) {

	randomlyPickedWords.clear();
	pickRandomWords(numberOfWords); // put 2000 random words
	int tableSize = getNextPrime(numberOfWords);
	hashTable.resize(tableSize, "|||"); // the first prime after number of words
	int collisions = 0;
	int hashedSuccessfully = 0;
	for (int i = 0; i < numberOfWords; i++) {
		cout << "Test Hashing word number ( " << i + 1 << " ) "
				<< randomlyPickedWords[i] << endl;
		int index = djb2(randomlyPickedWords[i]) % tableSize;
		while (true) {
			if (hashTable[index] == "|||") {
				hashTable[index] = randomlyPickedWords[i];
				cout << "Hashed Successfully -> " << ++hashedSuccessfully
						<< endl;
				break;
			} else {
				cout << "Collision Detected at index -> ( " << i << " ) "
						<< endl;
				collisions++;
				index++;
			}
		}
	}
	return collisions;
}

void runProgram() {

	loadFile();

//	cout << "Statistics for \" djb2 \" Algorithm: " << endl;
//	cout << "=====================================" << endl;
//
//	cout << "Test Hashing 2000 Words: " << endl;
//	cout << "Number Of Collisions: " << buildTableANDtest(2000) << endl;
//
//	cout << "Test Hashing 4000 Words: " << endl;
//	cout << "Number Of Collisions: " << buildTableANDtest(4000) << endl;
//
//	cout << "Test Hashing 6000 Words: " << endl;
//	cout << "Number Of Collisions: " << buildTableANDtest(6000) << endl;
//
//	cout << "Test Hashing 8000 Words: " << endl;
//	cout << "Number Of Collisions: " << buildTableANDtest(8000) << endl;
//
//
//	//===================================================================
//	cout << "*************************************************" << endl;
//	cout << "*************************************************" << endl;
//	//===================================================================

	cout << "Statistics for \" sdbm \" Algorithm: " << endl;
	cout << "=====================================" << endl;

	cout << "Test Hashing 2000 Words: " << endl;
	cout << "Number Of Collisions: " << buildTableANDtest(2000) << endl;

//	cout << "Test Hashing 4000 Words: " << endl;
//	cout << "Number Of Collisions: " << buildTableANDtest(4000) << endl;
//
//	cout << "Test Hashing 6000 Words: " << endl;
//	cout << "Number Of Collisions: " << buildTableANDtest(6000) << endl;
//
//	cout << "Test Hashing 8000 Words: " << endl;
//	cout << "Number Of Collisions: " << buildTableANDtest(8000) << endl;

}
