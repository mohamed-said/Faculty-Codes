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

struct node {
	bool is_end;
	node* children[26];
	node() {
		is_end = false;
		for(int i = 0; i < 26; i++)
			children[i] = NULL;
	}
};

node* root = new node;

void insrt (string word) {
	node* current = root;
	for (int i = 0; i < sz(word); i++) {
		if (current->children[word[i] - 'a'] == NULL) {
 			current->children[word[i] - 'a'] = new node;
			current = current->children[word[i] - 'a'];
		} else {
			current = current->children[word[i] - 'a'];
		}
		current->is_end = true;
	}
	current->is_end = true;
}

