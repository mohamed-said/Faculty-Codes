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

// headers
#include "mbitvector.h"
#include "mpair.h"
#include "mvector.h"

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
#define MAX_TABLE 999;
#define getrandom(min, max) ((rand()%(int)(((max) + 1)-(min)))+ (min))

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pair<int, int> > vpii;
typedef set<int> si;
typedef set<string> sets;
typedef set<char> setc;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;

sets randomlyPickedWords;
vs allDictionaryWords;
set<pair<int, int> > collisionFree;
vpii allNodes;


class HashArrayMappedTrie {
private:

	mbitvector *Table[5]; // hash tables
	int tableNumber; 	  // table number setter

	string toStr(ll num); 	// int to string
	int getTable(ll num); 	// determine which table contains this index
	ul hashIt(ll num, char c); // generate an index for this letter

public:

	HashArrayMappedTrie();
	void insertString(string word);
	bool lookUp(string word);

};

HashArrayMappedTrie::HashArrayMappedTrie() {

	cout << "Entered Constructor..." << endl;

	Table[0] = new mbitvector(433000);
	Table[1] = new mbitvector(433000);
	Table[2] = new mbitvector(433000);
	Table[3] = new mbitvector(433000);
	Table[4] = new mbitvector(433000);

	Table[0]->set_state(0, 1, 0); // root

	tableNumber = 0;
}

string HashArrayMappedTrie::toStr(ll num) {
	stringstream ss;
	string s;
	ss << num;
	ss >> s;
	return s;
}

int HashArrayMappedTrie::getTable(ll num) {
	if (num == 0)
		return 0;
	if (num % 432100 == 0)
		return ((num / 432100) - 1);
	else if (num > 432100)
		return (num / 432100);
	return 0;
}

ul HashArrayMappedTrie::hashIt(ll num, char c) {

	num %= 432100;

	string temp = toStr(num);
	ul hash = (int) c;

	short int size = sz(temp);
	for (int i = 0; i < size; i++)
		hash += (int) ((temp[i] - '0') * (pow(36.0, size - i)));
	return hash;
}

void streamData(ll i, ll tn, ll idx) {
	cout << "node: " << i << endl;
	cout << "table number -> " << tn << endl;
	cout << "index -> " << idx << endl;
}

void HashArrayMappedTrie::insertString(string word) {

	cout << "Entered HAMT::insertString..." << endl; // Testing===================================================

	tableNumber = getTable(0);
	int index = hashIt(0, word[0]);

	streamData(0, tableNumber, index);


	Table[tableNumber]->set_state(index, 0, 0);

	streamData(0, tableNumber, index);

	// testing collision ============================================
//	collisionFree.ins(make_pair(index, tableNumber));
//	allNodes.pb(make_pair(index, tableNumber));
	//================================================================

	for (int i = 1; i < sz(word) ; i++) {
		if (i == sz(word) - 1) {
			tableNumber = getTable(index);
			index = hashIt(index, word[i]);

			streamData(i, tableNumber, index);

			Table[tableNumber]->set_state(index, 1, 1);

			// testing collision ============================================
//			collisionFree.ins(make_pair(index, tableNumber));
//			allNodes.pb(make_pair(index, tableNumber));
			//================================================================

		} else {
			tableNumber = getTable(index);
			index = hashIt(index, word[i]);

			streamData(i, tableNumber, index);

			Table[tableNumber]->set_state(index, 1, 0);

			// testing collision ============================================
//			collisionFree.ins(make_pair(index, tableNumber));
//			allNodes.pb(make_pair(index, tableNumber));
			//===============================================================
		}
	}
}

bool HashArrayMappedTrie::lookUp(string word) {

	int index = 0;
	for (int i = 0; i < sz(word) ; i++) {
		index = hashIt(index, word[i]);
		tableNumber = getTable(index);
		if (!Table[tableNumber]->get_state(index).first)
			return false;
		if (i == (sz(word) - 1) && Table[tableNumber]->get_state(index).second)
			return true;
	}

	return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
//************************************End of Class***************************************************//
///////////////////////////////////////////////////////////////////////////////////////////////////////



//******************************Testing Functions*****************************************************//

// loading the dictionary file in a vector of strings
void loadFile() {
	cout << "Entered LoadFile..." << endl; // Testing===================================================

	ifstream file;
	file.open("Dictionary.txt", ios::in);
	if (file.fail()) {
		cout << "Error opening file!!!" << endl;
		return;
	}
	string temp;
	while (file >> temp) {
		allDictionaryWords.pb(temp);
	}

	cout << "Dictionary Loaded..." << endl; // Testing===================================================
	cout << "Exited LoadFile..." << endl; // Testing===================================================
}

// picking a (number of words) randomly from the dictionary
// in a set of strings
void pickRandomWords(int numberOfWords) {

	cout << "Entered PickRandomWords..." << endl; // Testing===================================================

	srand(time(NULL));
	for (int i = 0; i < numberOfWords; i++)
		randomlyPickedWords.ins(allDictionaryWords[rand() % sz(allDictionaryWords) ]);

	cout << "Exited RandomlyPickedWords..." << endl; // Testing===================================================
}

// run progress
void runtest() {
	HashArrayMappedTrie hash_map;
	cout << "HAMT Declared..." << endl; // Testing===================================================
	loadFile();
	int numberOfword;
	cin >> numberOfword;
	pickRandomWords(numberOfword);

	cout << "Inserting In HAMT..." << endl; // Testing===================================================
	sets::iterator it;
	for (it = randomlyPickedWords.begin(); it != randomlyPickedWords.end(); it++) {
		hash_map.insertString(*it);
	}


	// Testing===================================================
	cout << sz(randomlyPickedWords) << " " << sz(allNodes) << " " << sz(collisionFree) << endl;
}


int main() {

//	runtest();

	HashArrayMappedTrie hash_map;
	hash_map.insertString("mohamed");
//	hash_map.insertString("ahmed");
//	hash_map.insertString("hamada");
//	hash_map.insertString("hassan");
//	hash_map.insertString("kamaly");
//	hash_map.insertString("mohsen");
//	hash_map.insertString("halawa");
//	hash_map.insertString("haltara");
//	hash_map.insertString("avwara");

	return 0;

}

