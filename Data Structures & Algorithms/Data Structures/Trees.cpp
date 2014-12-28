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
	int value;
	node* right;
	node* left;
	node(int val, node* left, node* right) {
		value = val;
		this->left = left;
		this->right = right;
	}
};

node* root = NULL;

void insert_element(int x) {
	if (root == NULL) {
		node* n = new node(x, NULL, NULL);
		root = n;
		return;
	} else {
		node* current = root;
		while (current != NULL) {
			if (current->value < x) {
				if (current->right == NULL) {
					node* n = new node(x, NULL, NULL);
					current->right = n;
					break;
				} else {
					current = current->right;
				}
			} else {
				if (current->left == NULL) {
					node* n = new node(x, NULL, NULL);
					current->left = n;
					break;
				} else {
					current = current->left;
				}
			}
		}
	}
}

bool find(int x) {
	if (root == NULL)
		return false;
	node* current = root;
	if (root->value == x)
		return true;
	while (current != 0) {
		if (current->value < x) {
			current = current->right;
			if (current == NULL)
				return false;
			if (current->value == x)
				return true;
		} else {
			current = current->left;
			if (current == NULL)
				return false;
			if (current->value == x)
				return true;
		}
	}
	return false;
}

void in_order(node* n) {
	if (n == 0)
		return;
	in_order(n->left);
	cout << n->value << " ";
	in_order(n->right);
}

void print() {
	in_order(root);
}

//void delete_element(int x) {
//	if (root == NULL)
//		return;
//	if (root->value == x) {
//		delete root;
//		root = 0;
//	}
//	node* last = root;
//	node* current;
//	if (x > root->value)
//		current = root->right;
//	else
//		current = root->left;
//}

int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 9, 11, 12, 14, 15, 16, 17, 19, 20, 22 };
	vector<int> vec(arr, arr + sizeof(arr) / sizeof((*arr)));
	for (int i = 0; i < sz(vec) ; i++)
		insert_element(vec[i]);
	print();
	cout << endl;

	if (find(35))
		cout << "eshta";
	else
		cout << "again";
	return 0;
}
