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
#include <memory.h>
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

typedef vector<int> vi;
typedef vector<string> vs;
typedef set<int> si;
typedef set<string> sets;
typedef set<char> setc;
typedef pair<int, int> pii;

class node {
public:
	int val;
	node * next;

	node() :
			next(0) {
	}
	node(int nn) :
			val(nn), next(0) {
	}
};

class ll {
public:
	node* head;
	ll() :
			head(0) {
	}

	void insert_head(int x) {
		node* n = new node(x);
		if (head == 0)
			head = n;
		else {
			n->next = head;
			head = n;
		}
	}

	void insert_tail(int x) {
		node* n = new node(x);
		if (head == 0)
			head = n;
		else {
			node* temp = head;
			while (temp->next != 0)
				temp = temp->next;
			temp->next = n;
		}
	}

	void insert(int x, int ind) {
		if (head == 0 || ind == 0)
			return insert_head(x);
		else {
			node* temp = head;
			for (int i = 0; i < ind - 1 && temp->next != 0; i++)
				temp = temp->next;
			node* n = new node(x);
			n->next = temp->next;
			temp->next = n;
		}
	}

	void erase_head() {
		if (head == 0)
			return;
		else {
			node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void erase_tail() {
		if (head == 0)
			return;
		else {
			node (*temp) = head->next, (*last) = head;
			while (temp != 0 && temp->next != 0)
				last = temp, temp = temp->next;

			if (temp == 0) { //one element list
				delete head;
				head = 0;
			} else {
				last->next = 0;
				delete temp;
			}
		}
	}

	void eraseByIndex(int index) {
		if (head == 0)
			return;
		else if (index == 0)
			erase_head();
		else {
			node * temp = head->next, *last = head;
			int i;
			for (i = 0; i < index - 1 && temp->next != 0; i++) {
				if (temp == 0)
					return;
				last = temp;
				temp = temp->next;
			}

			if (i != index - 1 || temp == 0) //list doesn't contain index ind (too short)
				return;

			last->next = temp->next;
			delete temp;
		}
	}

	void eraseByValue(int val) {
		if (head == 0)
			return;
		else if (head->val == val)
			return erase_head();
		else {
			node * temp = head->next, *last = head;
			while (temp != 0 && temp->val != val)
				last = temp, temp = temp->next;

			if (temp == 0) //not found
				return;
			else {
				last->next = temp->next;
				delete temp;
			}
		}
	}

	void print() {
		node * temp = head;
		while (temp != 0) {
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void clear() {
		while (head) {
			node * temp = head;
			head = head->next;
			delete temp;
		}
		head = 0;
	}
};

int main() {
	string cmd;
	ll l;
	while (cmd != "quit") {
		cout << "_________________________________________________________\n";
		cin >> cmd;
		if (cmd == "p")
			l.print();
		else if (cmd == "c")
			l.clear();
		else if (cmd == "ev") {
			int v;
			cin >> v;
			l.eraseByValue(v);
		} else if (cmd == "ei") {
			int i;
			cin >> i;
			l.eraseByIndex(i);
		} else if (cmd == "eh")
			l.erase_head();
		else if (cmd == "et")
			l.erase_tail();
		else if (cmd == "ih") {
			int v;
			cin >> v;
			l.insert_head(v);
		} else if (cmd == "it") {
			int v;
			cin >> v;
			l.insert_tail(v);
		} else if (cmd == "i") {
			int v, i;
			cin >> v >> i;
			l.insert(v, i);
		} else
			cout << "Unknown command" << endl;
		l.print();
	}
	return 0;
}
